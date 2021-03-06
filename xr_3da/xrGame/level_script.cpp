////////////////////////////////////////////////////////////////////////////
//	Module 		: level_script.cpp
//	Created 	: 28.06.2004
//  Modified 	: 28.06.2004
//	Author		: Dmitriy Iassenev
//	Description : Level script export
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "level.h"
#include "script_space.h"
#include "actor.h"
#include "script_game_object.h"
#include "patrol_path_storage.h"
#include "xrServer.h"
#include "client_spawn_manager.h"
#include "../igame_persistent.h"
#include "game_cl_base.h"
#include "ui/UIDialogWnd.h"
#include "date_time.h"
#include "ai_space.h"
#include "level_graph.h"
#include "PHCommander.h"
#include "PHScriptCall.h"
#include "HUDManager.h"
using namespace luabind;

CScriptGameObject *tpfGetActor()
{
	CActor *l_tpActor = smart_cast<CActor*>(Level().CurrentEntity());
	if (l_tpActor)
		return	(smart_cast<CGameObject*>(l_tpActor)->lua_game_object());
	else
		return	(0);
}

CScriptGameObject *get_object_by_name(LPCSTR caObjectName)
{
	CGameObject		*l_tpGameObject	= smart_cast<CGameObject*>(Level().Objects.FindObjectByName(caObjectName));
	if (l_tpGameObject)
		return		(l_tpGameObject->lua_game_object());
	else
		return		(0);
}
CScriptGameObject *get_object_by_id(u32 id)
{
	CGameObject* pGameObject = smart_cast<CGameObject*>(Level().Objects.net_Find(id));
	if(!pGameObject)
		return NULL;

	return pGameObject->lua_game_object();
}
//CScriptGameObject *get_object_by_id(ALife::_OBJECT_ID id)
//{
//	CGameObject		*l_tpGameObject	= smart_cast<CGameObject*>(Level().Objects.FindObjectByID(id));
//	if (l_tpGameObject)
//		return		(l_tpGameObject->lua_game_object());
//	else
//		return		(0);
//}

LPCSTR get_weather	()
{
	return			(*g_pGamePersistent->Environment.GetWeather());
}

void set_weather	(LPCSTR weather_name)
{
	VERIFY3			(g_pGamePersistent->Environment.Weathers.find(weather_name) != g_pGamePersistent->Environment.Weathers.end(),"There is no weather with the specified name ",weather_name);
	return			(g_pGamePersistent->Environment.SetWeather(weather_name));
}

void set_time_factor(float time_factor)
{
	if (!OnServer())
		return;

	Level().Server->game->SetGameTimeFactor(time_factor);
}
float get_time_factor()
{
	return			(Level().GetGameTimeFactor());
}


//////////////////////////////////////////////////////////////////////////

u32 get_time_days()
{
	u32 year = 0, month = 0, day = 0, hours = 0, mins = 0, secs = 0, milisecs = 0;
	split_time(Level().GetGameTime(), year, month, day, hours, mins, secs, milisecs);
	return			day;
}

u32 get_time_hours()
{
	u32 year = 0, month = 0, day = 0, hours = 0, mins = 0, secs = 0, milisecs = 0;
	split_time(Level().GetGameTime(), year, month, day, hours, mins, secs, milisecs);
	return			hours;
}

u32 get_time_minutes()
{
	u32 year = 0, month = 0, day = 0, hours = 0, mins = 0, secs = 0, milisecs = 0;
	split_time(Level().GetGameTime(), year, month, day, hours, mins, secs, milisecs);
	return			mins;
}


//////////////////////////////////////////////////////////////////////////


float cover_in_direction(u32 level_vertex_id, const Fvector &direction)
{
	float			y,p;
	direction.getHP	(y,p);
	return			(ai().level_graph().cover_in_direction(y,level_vertex_id));
}

float rain_factor()
{
	return			(g_pGamePersistent->Environment.CurrentEnv.rain_density);
}

u32	vertex_in_direction(u32 level_vertex_id, Fvector direction, float max_distance)
{
	direction.normalize_safe();
	direction.mul	(max_distance);
	Fvector			start_position = ai().level_graph().vertex_position(level_vertex_id);
	Fvector			finish_position = Fvector(start_position).add(direction);
	u32				result = u32(-1);
	ai().level_graph().farthest_vertex_in_direction(level_vertex_id,start_position,finish_position,result,0);
	return			(ai().level_graph().valid_vertex_id(result) ? result : level_vertex_id);
}

Fvector vertex_position(u32 level_vertex_id)
{
	return			(ai().level_graph().vertex_position(level_vertex_id));
}

void map_add_entity_icon(CScriptGameObject* lua_object)
{
	Level().AddEntityMapLocation(&lua_object->object(), eMapLocationScript);
}

void map_add_object_icon(CScriptGameObject* lua_object, 
						LPCSTR name, LPCSTR text, int icon_x, int icon_y)
{
	Level().AddObjectMapLocationIcon(&lua_object->object(), eMapLocationScript,
									name, text, icon_x, icon_y);
}

void map_remove_object_icon(CScriptGameObject* lua_object)
{
	Level().RemoveMapLocationByID(lua_object->object().ID(), eMapLocationScript);
}

bool patrol_path_exists(LPCSTR patrol_path)
{
	return		(!!Level().patrol_paths().path(patrol_path,true));
}

LPCSTR get_name()
{
	return		(*Level().name());
}

CClientSpawnManager	&get_client_spawn_manager()
{
	return		(Level().client_spawn_manager());
}

void start_stop_menu(CUIDialogWnd* pDialog, bool bDoHideIndicators)
{
	HUD().GetUI()->StartStopMenu(pDialog,bDoHideIndicators);
}


void add_dialog_to_render(CUIDialogWnd* pDialog)
{
	HUD().GetUI()->AddDialogToRender(pDialog);
}

void remove_dialog_to_render(CUIDialogWnd* pDialog)
{
	HUD().GetUI()->RemoveDialogToRender(pDialog);
}

CUIDialogWnd* main_input_receiver()
{
	return HUD().GetUI()->MainInputReceiver();
}
void hide_indicators()
{
	HUD().GetUI()->HideIndicators();
	psHUD_Flags.set(HUD_CROSSHAIR_RT, FALSE);
}

void show_indicators()
{
	HUD().GetUI()->ShowIndicators();
	psHUD_Flags.set(HUD_CROSSHAIR_RT, TRUE);
}


bool is_level_present()
{
	return (!!g_pGameLevel);
}

void add_call(const luabind::functor<bool> &condition,const luabind::functor<void> &action)
{
	Level().ph_commander().add_call(xr_new<CPHScriptCondition>(condition),xr_new<CPHScriptAction>(action));
}

void add_call(const luabind::object &lua_object, LPCSTR condition,LPCSTR action)
{
	Level().ph_commander().add_call(xr_new<CPHScriptObjectCondition>(lua_object,condition),xr_new<CPHScriptObjectAction>(lua_object,action));
}

void CLevel::script_register(lua_State *L)
{
	module(L,"level")
	[
		// declarations
		def("object",							get_object_by_name),
		def("object_by_id",						get_object_by_id),
		def("actor",							tpfGetActor),
		//def("set_artifact_merge",				SetArtefactMergeFunctor),
		def("get_weather",						get_weather),
		def("set_weather",						set_weather),
		
		def("set_time_factor",					set_time_factor),
		def("get_time_factor",					get_time_factor),
		
		def("get_time_days",					get_time_days),
		def("get_time_hours",					get_time_hours),
		def("get_time_minutes",					get_time_minutes),

		def("cover_in_direction",				cover_in_direction),
		def("vertex_in_direction",				vertex_in_direction),
		def("rain_factor",						rain_factor),
		def("patrol_path_exists",				patrol_path_exists),
		def("vertex_position",					vertex_position),
		def("name",								get_name),

		def("client_spawn_manager",				get_client_spawn_manager),

		def("map_add_entity_icon",				map_add_entity_icon),
		def("map_add_object_icon",				map_add_object_icon),
		def("map_remove_object_icon",			map_remove_object_icon),
		def("start_stop_menu",					start_stop_menu),
		def("add_dialog_to_render",				add_dialog_to_render),
		def("remove_dialog_to_render",			remove_dialog_to_render),
		def("main_input_receiver",				main_input_receiver),
		def("hide_indicators",					hide_indicators),
		def("show_indicators",					show_indicators),
		def("add_call",							((void (*) (const luabind::functor<bool> &,const luabind::functor<void> &)) &add_call)),
		def("add_call",							((void (*) (const luabind::object &, LPCSTR, LPCSTR)) &add_call)),
		def("present",							is_level_present)
	];
}


