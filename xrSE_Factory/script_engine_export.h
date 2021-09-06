////////////////////////////////////////////////////////////////////////////
//	Module 		: script_engine_export.h
//	Created 	: 01.04.2004
//  Modified 	: 22.06.2004
//	Author		: Dmitriy Iassenev
//	Description : XRay Script Engine export
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "script_fvector.h"
#include "script_fmatrix.h"
#include "script_flags.h"
#include "script_engine.h"
#include "script_token_list.h"
#include "script_rtoken_list.h"
#include "script_ini_file.h"
#include "script_reader.h"
#include "script_net_packet.h"
#include "object_factory.h"
#include "script_sound_type.h"
#include "xrServer_Objects_ALife_All.h"

#ifndef XRGAME_EXPORTS
#	include "script_properties_list_helper.h"
#else
#	include "base_client_classes.h"
#	include "alife_simulator.h"
#	include "script_hit.h"
#	include "script_monster_hit_info.h"
#	include "script_sound_info.h"
#	include "script_sound.h"
#	include "script_binder_object.h"
#	include "motivation_action_manager.h"
#	include "motivation_manager.h"
#	include "motivation_action.h"
#	include "motivation.h"
#	include "action_planner_action.h"
#	include "action_planner.h"
#	include "action_base.h"
#	include "property_storage.h"
#	include "property_evaluator.h"
#	include "script_world_state.h"
#	include "script_world_property.h"
#	include "ai/stalker/ai_stalker.h"
#	include "script_effector.h"
#	include "particlesobject.h"
#	include "artifactmerger.h"
#	include "level.h"
#	include "memory_space.h"
#	include "script_render_device.h"
#	include "script_game_object.h"
#	include "cover_point.h"
#	include "path_manager_params_level_evaluator.h"
#	include "patrol_path_params.h"
#	include "particle_params.h"
#	include "script_movement_action.h"
#	include "script_watch_action.h"
#	include "script_animation_action.h"
#	include "script_sound_action.h"
#	include "script_particle_action.h"
#	include "script_object_action.h"
#	include "script_action_condition.h"
#	include "script_monster_action.h"
#	include "script_entity_action.h"
#	include "helicopter.h"
#	include "game_base.h"
#	include "game_sv_base.h"
#	include "game_sv_mp.h"
#	include "game_sv_deathmatch.h"
#	include "game_sv_mp_script.h"
#	include "game_cl_mp.h"
#	include "game_cl_mp_script.h"
#	include "UIGameCustom.h"
#	include "UIGame_custom_script.h"
#	include "UI/UIScriptWnd.h"
#	include "UI/UIStatic.h"
#	include "UI/UIButton.h"
#	include "UI/UIWindow.h"
#	include "UI/UIProgressBar.h"
#	include "UI/UIEditBox.h"
#	include "UI/UIMessageBox.h"
#	include "UI/UIPropertiesBox.h"
#	include "UI/UITabControl.h"
#	include "UI/UIListWnd.h"
#   include "UI/UIListWndEx.h"
#   include "UI/UIComboBox.h"
#	include "script_ui_registrator.h"
#	include "key_binding_registrator.h"
#	include "fs_registrator.h"
#	include "console_registrator.h"
#	include	"PhysicsShell.h"
#	include	"HangingLamp.h"
#	include "script_task.h"
#	include "script_string_table.h"
#	include "client_spawn_manager.h"
#	include "script_zone.h"
#	include "ef_storage.h"
#	include "trigger.h"
#	include "ai/stalker/ai_stalker.h"
#	include "ai/monsters/bloodsucker/bloodsucker.h"
#	include "ai/monsters/boar/boar.h"
#	include "ai/monsters/dog/dog.h"
#	include "ai/monsters/flesh/flesh.h"
#	include "ai/monsters/pseudodog/pseudodog.h"
#	include "ai/monsters/burer/burer.h"
#	include "ai/monsters/chimera/chimera.h"
#	include "ai/monsters/pseudogigant/pseudo_gigant.h"
#	include "ai/monsters/poltergeist/poltergeist.h"
#	include "ai/monsters/zombie/zombie.h"
#	include "ai/monsters/fracture/fracture.h"
#	include "ai/monsters/snork/snork.h"
#	include "ai/monsters/controller/controller.h"
#	include "ai/monsters/cat/cat.h"
#endif