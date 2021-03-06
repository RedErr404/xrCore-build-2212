#include "stdafx.h"
#include "PhysicsGamePars.h"
float object_demage_factor		=		4.f		; //times increace damage from object collision
float collide_volume_max		=		200.f	; //max collide sound level
float collide_volume_min		=		0.f		; //min collide sound level

//float vel_cret_sound			=		10.f	; //min vel_cret for collide sound
//float vel_cret_wallmark			=		30.f	; //min vel_cret for wallmark
//float vel_cret_particles		=		15.f	; //...................		

const float EffectPars::vel_cret_sound=10.f;
const float EffectPars::vel_cret_particles=15.f;
const float EffectPars::vel_cret_wallmark=30.f;



const float CharacterEffectPars::vel_cret_sound=20.f;
const float CharacterEffectPars::vel_cret_particles=30.f;
const float CharacterEffectPars::vel_cret_wallmark=30.f;