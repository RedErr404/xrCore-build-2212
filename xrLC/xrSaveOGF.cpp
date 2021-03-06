#include "stdafx.h"
#include "build.h"
#include "OGF_Face.h"

SWIContainer			g_SWI;
VBContainer				g_VB;
IBContainer				g_IB;
xr_vector<LPCSTR>		g_Shaders;

u32						g_batch_count;
u32						g_batch_verts;
u32						g_batch_faces;

u32						g_batch_50;
u32						g_batch_100;
u32						g_batch_500;
u32						g_batch_1000;
u32						g_batch_5000;

u16		RegisterShader		(LPCSTR T) 
{
	for (u32 it=0; it<g_Shaders.size(); it++)
		if (0==stricmp(T,g_Shaders[it]))	return it;
	g_Shaders.push_back		(xr_strdup(T));
	return g_Shaders.size	()-1;
}

void	geom_batch_average	(u32 verts, u32 faces)
{
	g_batch_count	++;
	g_batch_verts	+=	verts;
	g_batch_faces	+=	faces;

	if (faces<=50)				g_batch_50	++;
	else if (faces<=100)		g_batch_100	++;
	else if (faces<=500)		g_batch_500	++;
	else if (faces<=1000)		g_batch_1000++;
	else if (faces<=5000)		g_batch_5000++;
}

bool	remap_order		(u32 id0, u32 id1)
{
	OGF*	o0			= (OGF*)g_tree[id0];
	OGF*	o1			= (OGF*)g_tree[id1];
	return	xr_strcmp(*o0->textures.front().name,*o1->textures.front().name)<0;
}

void CBuild::SaveTREE	(IWriter &fs)
{
	CMemoryWriter		MFS;

	Status				("Geometry buffers...");
	xr_vector<u32>		remap;
	remap.reserve		(g_tree.size());
	for (u32 rid=0; rid<g_tree.size(); rid++)	{
		OGF*	o		= dynamic_cast<OGF*>	(g_tree[rid]);
		if		(o)		remap.push_back(rid);
	}
	std::stable_sort	(remap.begin(),remap.end(),remap_order);
	for (u32 sid=0; sid<remap.size(); sid++)	
		g_tree[remap[sid]]->PreSave();

	Status				("Visuals...");
	fs.open_chunk		(fsL_VISUALS);
	for (xr_vector<OGF_Base*>::iterator it = g_tree.begin(); it!=g_tree.end(); it++)	{
		u32			idx = u32(it-g_tree.begin());
		MFS.open_chunk	(idx);
		(*it)->Save		(MFS);
		MFS.close_chunk	();
		Progress		(float(idx)/float(g_tree.size()));
	}
	fs.w				(MFS.pointer(),MFS.size());
	fs.close_chunk		();
	clMsg				("Average: %d verts/%d faces, 50(%2.1f), 100(%2.1f), 500(%2.1f), 1000(%2.1f), 5000(%2.1f)",
		g_batch_verts/g_batch_count,
		g_batch_faces/g_batch_count,
		100.f * float(g_batch_50)/float(g_batch_count),
		100.f * float(g_batch_100)/float(g_batch_count),
		100.f * float(g_batch_500)/float(g_batch_count),
		100.f * float(g_batch_1000)/float(g_batch_count),
		100.f * float(g_batch_5000)/float(g_batch_count)
		);
	//mem_Compact			();

	Status				("Geometry : vertices ...");
	MFS.clear			();
	fs.open_chunk		(fsL_VB | CFS_CompressMark);
	g_VB.Save			(MFS);
	fs.w_compressed		(MFS.pointer(),MFS.size());
	fs.close_chunk		();
	//mem_Compact			();

	Status				("Geometry : SWIs ...");
	MFS.clear			();
	fs.open_chunk		(fsL_SWIS | CFS_CompressMark);
	g_SWI.Save			(MFS);
	fs.w_compressed		(MFS.pointer(),MFS.size());
	fs.close_chunk		();

	Status				("Geometry : indices ...");
	MFS.clear			();
	fs.open_chunk		(fsL_IB | CFS_CompressMark);
	g_IB.Save			(MFS);
	fs.w_compressed		(MFS.pointer(),MFS.size());
	fs.close_chunk		();
	//mem_Compact			();

	Status				("Shader table...");
	fs.open_chunk		(fsL_SHADERS);
	fs.w_u32			(g_Shaders.size());
	for (xr_vector<LPCSTR>::iterator T=g_Shaders.begin(); T!=g_Shaders.end(); T++)
		fs.w_stringZ	(*T);
	fs.close_chunk		();
	//mem_Compact			();
}
