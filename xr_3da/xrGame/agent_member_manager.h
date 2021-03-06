////////////////////////////////////////////////////////////////////////////
//	Module 		: agent_member_manager.h
//	Created 	: 24.05.2004
//  Modified 	: 14.01.2005
//	Author		: Dmitriy Iassenev
//	Description : Agent member manager
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "member_order.h"
#include "memory_space.h"

class CAgentManager;

class CAgentMemberManager {
public:
	typedef xr_vector<CMemberOrder>			MEMBER_STORAGE;
	typedef MEMBER_STORAGE::iterator		iterator;
	typedef MEMBER_STORAGE::const_iterator	const_iterator;
	typedef MemorySpace::squad_mask_type	squad_mask_type;

private:
	CAgentManager					*m_object;
	MEMBER_STORAGE					m_members;

protected:
	IC		CAgentManager			&object				() const;

public:
	IC								CAgentMemberManager	(CAgentManager *object);
			void					update				();
			void					add					(CEntity *member);
			void					remove				(CEntity *member, bool no_assert = false);
	IC		const CMemberOrder		&member				(const CAI_Stalker *object) const;
	IC		const MEMBER_STORAGE	&members			() const;
	IC		MEMBER_STORAGE			&members			();
	IC		const CSetupAction		&action				(CAI_Stalker *object) const;
	IC		squad_mask_type			mask				(const CAI_Stalker *object) const;
	IC		bool					group_behaviour		() const;
	IC		iterator				member				(squad_mask_type mask);
			void					remove_links		(CObject *object);
};

#include "agent_member_manager_inline.h"