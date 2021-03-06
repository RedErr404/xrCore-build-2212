#pragma once

#include "state_hide_from_point.h"
#include "state_look_unprotected_area.h"
#include "state_custom_action.h"

#define TEMPLATE_SPECIALIZATION template <\
	typename _Object\
>

#define CStateMonsterHearDangerousSoundAbstract CStateMonsterHearDangerousSound<_Object>

TEMPLATE_SPECIALIZATION
CStateMonsterHearDangerousSoundAbstract::CStateMonsterHearDangerousSound(_Object *obj) : inherited(obj)
{
	add_state	(eStateHide,			xr_new<CStateMonsterHideFromPoint<_Object> >(obj));
	add_state	(eStateFaceOpenPlace,	xr_new<CStateMonsterLookToUnprotectedArea<_Object> >(obj));
	add_state	(eStateStandScared,		xr_new<CStateMonsterCustomAction<_Object> >(obj));
}

TEMPLATE_SPECIALIZATION
void CStateMonsterHearDangerousSoundAbstract::reselect_state()
{
	if (prev_substate == u32(-1)){
		select_state(eStateHide);
		return;
	}

	if (prev_substate == eStateHide) {
		select_state(eStateFaceOpenPlace);
		return;
	}

	select_state(eStateStandScared);
}

TEMPLATE_SPECIALIZATION
void CStateMonsterHearDangerousSoundAbstract::setup_substates()
{
	state_ptr state = get_state_current();

	if (current_substate == eStateHide) {
		SStateHideFromPoint data;
		data.point				= object->SoundMemory.GetSound().position;
		data.accelerated		= true;
		data.braking			= false;
		data.accel_type			= eAT_Aggressive;
		data.distance			= 40.f;
		data.action.action		= ACT_RUN;
		data.action.sound_type	= MonsterSpace::eMonsterSoundPanic;
		data.action.sound_delay = object->get_sd()->m_dwAttackSndDelay;

		state->fill_data_with(&data, sizeof(SStateHideFromPoint));

#ifdef DEBUG
		if (psAI_Flags.test(aiMonsterDebug)) {
			object->HDebug->M_Add(0,"Danger Snd :: Hide From Point", D3DCOLOR_XRGB(255,0,0));
		}
#endif
		return;
	}

	if (current_substate == eStateFaceOpenPlace) {
		SStateDataAction data;
		data.action			= ACT_STAND_IDLE;
		data.spec_params	= ASP_STAND_SCARED;
		data.time_out		= 2000;
		data.sound_type	= MonsterSpace::eMonsterSoundPanic;
		data.sound_delay = object->get_sd()->m_dwAttackSndDelay;

		state->fill_data_with(&data, sizeof(SStateDataAction));

#ifdef DEBUG
		if (psAI_Flags.test(aiMonsterDebug)) {
			object->HDebug->M_Add(0,"Danger Snd :: Face Open Place", D3DCOLOR_XRGB(255,0,0));
		}
#endif
		
		return;
	}

	if (current_substate == eStateStandScared) {
		SStateDataAction data;
		data.action			= ACT_STAND_IDLE;
		data.spec_params	= ASP_STAND_SCARED;
		data.sound_type	= MonsterSpace::eMonsterSoundPanic;
		data.sound_delay = object->get_sd()->m_dwAttackSndDelay;

		state->fill_data_with(&data, sizeof(SStateDataAction));

#ifdef DEBUG
		if (psAI_Flags.test(aiMonsterDebug)) {
			object->HDebug->M_Add(0,"Danger Snd :: Stand Scared", D3DCOLOR_XRGB(255,0,0));
		}
#endif
		return;
	}
}

#undef TEMPLATE_SPECIALIZATION
#undef CStateMonsterHearDangerousSoundAbstract 
