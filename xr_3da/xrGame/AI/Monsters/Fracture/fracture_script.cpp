#include "stdafx.h"
#include "fracture.h"
#include "../../../script_space.h"

using namespace luabind;

void CFracture::script_register(lua_State *L)
{
	module(L)
	[
		class_<CFracture,CGameObject>("CFracture")
			.def(constructor<>())
	];
}