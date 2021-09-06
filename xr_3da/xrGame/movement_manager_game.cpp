////////////////////////////////////////////////////////////////////////////
//	Module 		: movement_manager_game.cpp
//	Created 	: 03.12.2003
//  Modified 	: 03.12.2003
//	Author		: Dmitriy Iassenev
//	Description : Movement manager for game paths
////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "movement_manager.h"
#include "alife_simulator.h"
#include "alife_graph_registry.h"
#include "alife_level_registry.h"
#include "profiler.h"
#include "game_location_selector.h"
#include "game_path_manager.h"
#include "level_location_selector.h"
#include "level_path_manager.h"
#include "detail_path_manager.h"
#include "ai_object_location.h"
#include "custommonster.h"

void CMovementManager::process_game_path()
{
	START_PROFILE("AI/Build Path/Process Game Path");

//	if (!detail().actual() && (m_path_state > ePathStateBuildDetailPath))
//		m_path_state		= ePathStateBuildDetailPath;

	if (!level_path().actual() && (m_path_state > ePathStateBuildLevelPath))
		m_path_state		= ePathStateBuildLevelPath;

	if (!game_path().actual() && (m_path_state > ePathStateBuildGamePath))
		m_path_state		= ePathStateBuildGamePath;

	EPathState	prev_state	= m_path_state;
	for (;;) {
		switch (m_path_state) {
			case ePathStateSelectGameVertex : {
				game_selector().select_location(object().ai_location().game_vertex_id(),game_path().m_dest_vertex_id);

				if (game_selector().failed())
					break;

				m_path_state	= ePathStateBuildGamePath;

				if (time_over())
					break;
			}
			case ePathStateBuildGamePath : {
				game_path().build_path(object().ai_location().game_vertex_id(),game_dest_vertex_id());

				if (game_path().failed())
					break;
				
				m_path_state	= ePathStateContinueGamePath;
				
				if (time_over())
					break;
			}
			case ePathStateContinueGamePath : {
				game_path().select_intermediate_vertex();
				if (ai().game_graph().vertex(object().ai_location().game_vertex_id())->level_id() != ai().game_graph().vertex(game_path().intermediate_vertex_id())->level_id()) {
					m_path_state	= ePathStateTeleport;
					VERIFY			(ai().get_alife());
					VERIFY			(ai().alife().graph().level().level_id() == ai().game_graph().vertex(object().ai_location().game_vertex_id())->level_id());
					teleport		(game_path().intermediate_vertex_id());
					break;
				}
				
				m_path_state		= ePathStateBuildLevelPath;
				
				if (time_over())
					break;
			}
			case ePathStateBuildLevelPath : {
				u32	dest_level_vertex_id = ai().game_graph().vertex(
						game_path().intermediate_vertex_id()
				)->level_vertex_id();

				if (!accessible(dest_level_vertex_id)) {
					Fvector					dest_pos;
					dest_level_vertex_id	= restrictions().accessible_nearest(
						ai().level_graph().vertex_position(dest_level_vertex_id),
						dest_pos
					);
				}

				level_path().build_path(
					object().ai_location().level_vertex_id(),
					dest_level_vertex_id
				);

				if (level_path().failed())
					break;
				
				m_path_state		= ePathStateContinueLevelPath;
				
				if (time_over())
					break;
			}
			case ePathStateContinueLevelPath : {
				level_path().select_intermediate_vertex();
				
				m_path_state		= ePathStateBuildDetailPath;
				
				if (time_over())
					break;
			}
			case ePathStateBuildDetailPath : {
				detail().set_state_patrol_path(true);
				detail().set_start_position(object().Position());
				detail().set_start_direction(Fvector().setHP(-m_body.current.yaw,0));
				detail().set_dest_position( 
					ai().level_graph().vertex_position(
						level_path().intermediate_vertex_id()
					)
				);
				
				detail().build_path(
					level_path().path(),
					level_path().intermediate_index()
				);
				
				if (detail().failed()) {
					m_path_state	= ePathStateBuildLevelPath;
					break;
				}

				m_path_state		= ePathStatePathVerification;
				
				break;
			}
			case ePathStatePathVerification : {
				if (!game_selector().actual(object().ai_location().game_vertex_id(),path_completed()))
					m_path_state	= ePathStateSelectGameVertex;
				else
				if (!game_path().actual())
					m_path_state	= ePathStateBuildGamePath;
				else
				if (!level_path().actual())
					m_path_state	= ePathStateBuildLevelPath;
				else
				if (!detail().actual())
					m_path_state	= ePathStateBuildLevelPath;
				else
					if (detail().completed(object().Position(),!detail().state_patrol_path())) {
						m_path_state	= ePathStateContinueLevelPath;
						if (level_path().completed()) {
							m_path_state	= ePathStateContinueGamePath;
							if (game_path().completed())
								m_path_state	= ePathStatePathCompleted;
						}
					}
				break;
			}
			case ePathStatePathCompleted : {
				if (!game_selector().actual(object().ai_location().game_vertex_id(),path_completed()))
					m_path_state	= ePathStateSelectGameVertex;
				break;
			}
			case ePathStateTeleport : {
				break;
			}
			default : NODEFAULT;
		}

		if (time_over() || (m_path_state == prev_state))
			break;

		prev_state		= m_path_state;
	}
	
	STOP_PROFILE
}