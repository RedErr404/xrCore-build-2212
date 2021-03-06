// DetailManager.h: interface for the CDetailManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef DetailManagerH
#define DetailManagerH
#pragma once

#include "xrpool.h"
#include "detailformat.h"
#include "detailmodel.h"

#ifdef _EDITOR
	const int	dm_max_decompress	= 14;
	const int	dm_size				= 20;
#else
	const int	dm_max_decompress	= 7;
	const int	dm_size				= 25;
#endif
const int		dm_max_objects		= 64;
const int		dm_obj_in_slot		= 4;
const int		dm_cache_line		= dm_size+1+dm_size;
const int		dm_cache_size		= dm_cache_line*dm_cache_line;
const float		dm_fade				= float(2*dm_size)-.5f;
const float		dm_slot_size		= DETAIL_SLOT_SIZE;
const float		dm_slot_radius		= DETAIL_SLOT_SIZE*0.70710678118654752440084436210485f; // (slot_size/2)*_sqrt(2)

class CDetailManager
{
public:
	struct	SlotItem	{
		float				scale;
		float				scale_calculated;
		Fmatrix				mRotY;
		u32					vis_ID;
		Fvector				c_rgb;
		float				c_hemi;
		float				c_sun;
	};
	struct	SlotPart	{
		u32						id;
		xr_vector<SlotItem*>	items;
	};
	enum	SlotType	{
		stReady			= 0,	// Ready to use
		stPending,				// Pending for decompression

		stFORCEDWORD	= 0xffffffff
	};
	struct	Slot		{
		u32					type;
		int					sx,sz;
		vis_data			vis;
		SlotPart			G[dm_obj_in_slot];

		Slot()				{ type=stReady; sx=sz=0; vis.clear(); }
	};

	typedef		xr_vector <xr_vector<SlotItem*> >	vis_list;
	typedef		svector<CDetail*,dm_max_objects>	DetailVec;
	typedef		DetailVec::iterator					DetailIt;
	typedef		poolSS<SlotItem,4096>				PSS;
public:
	int								dither			[16][16];
public:
	// swing values
	struct SSwingValue{
		float						rot1;
		float						rot2;
		float						amp1;
		float						amp2;
		float						speed;
		void						lerp	(const SSwingValue& v1, const SSwingValue& v2, float factor);
	};
	SSwingValue						swing_desc[2];
	SSwingValue						swing_current; 
public:
	IReader*						dtFS;
	DetailHeader					dtH;
	DetailSlot*						dtSlots;		// note: pointer into VFS
	DetailSlot						DS_empty;

public:
	DetailVec						objects;
	vis_list						visible	[3];	// 0=still, 1=Wave1, 2=Wave2

	xrXRC							xrc;
	Slot*							cache		[dm_cache_line][dm_cache_line];	// grid-cache itself
	svector<Slot*,dm_cache_size>	cache_task;									// non-unpacked slots
	Slot							cache_pool	[dm_cache_size];				// just memory for slots
	int								cache_cx;
	int								cache_cz;

	PSS								poolSI;
public:
#ifdef _EDITOR
	virtual ObjectList* 			GetSnapList		()=0;
#endif

	IC bool							UseVS			()		{ return HW.Caps.geometry_major >= 1; }

	// Software processor
    ref_geom						soft_Geom;
	void							soft_Load		();
	void							soft_Unload		();
	void							soft_Render		();

	// Hardware processor
	ref_geom						hw_Geom;
	u32								hw_BatchSize;
	IDirect3DVertexBuffer9*			hw_VB;
	IDirect3DIndexBuffer9*			hw_IB;
	R_constant*						hwc_consts;
	R_constant*						hwc_wave;
	R_constant*						hwc_wind;
	R_constant*						hwc_array;
	R_constant*						hwc_s_consts;
	R_constant*						hwc_s_xform;
	R_constant*						hwc_s_array;
	void							hw_Load			();
	void							hw_Unload		();
	void							hw_Render		();
	void							hw_Render_dump	(R_constant* array, u32 var_id, u32 lod_id, u32 c_base);

public:
	DetailSlot&						QueryDB			(int sx, int sz);

	void							cache_Initialize();
	void							cache_Update	(int sx, int sz, Fvector& view, int limit);
	void							cache_Task		(int gx, int gz, Slot* D);
	Slot*							cache_Query		(int sx, int sz);
	void							cache_Decompress(Slot* D);
	BOOL							cache_Validate	();
	int								cg2w_X			(int x)			{ return cache_cx-dm_size+x;					}
	int								cg2w_Z			(int z)			{ return cache_cz-dm_size+(dm_cache_line-1-z);	}
	int								w2cg_X			(int x)			{ return x-cache_cx+dm_size;					}
	int								w2cg_Z			(int z)			{ return cache_cz-dm_size+(dm_cache_line-1-z);	}

	void							Load			();
	void							Unload			();
	void							Render			();

	CDetailManager					();
	virtual ~CDetailManager			();
};

#endif //DetailManagerH
