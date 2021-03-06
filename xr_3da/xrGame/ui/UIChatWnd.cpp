//=============================================================================
//  Filename:   UIChatWnd.cpp
//	Created by Roman E. Marchenko, vortex@gsc-game.kiev.ua
//	Copyright 2004. GSC Game World
//	---------------------------------------------------------------------------
//  Simple chat window for multiplayer purposes
//=============================================================================

#include <stdafx.h>
#include "UIChatWnd.h"
#include "UIChatLog.h"
#include "UIEditBox.h"
#include "UIXmlInit.h"
#include "../game_cl_base.h"
#include "../xr_level_controller.h"
#include "../Level.h"
#include "../../xr_object.h"

//////////////////////////////////////////////////////////////////////////

const char * const	CHAT_MP_WND_XML	= "chat_mp.xml";
const int			fadeDelay		= 5000;

//////////////////////////////////////////////////////////////////////////

CUIChatWnd::CUIChatWnd(CUIChatLog *pList)
	:	pUILogList				(pList),
		sendNextMessageToTeam	(false),
		pOwner					(NULL)
{
	R_ASSERT(pUILogList);
}

//////////////////////////////////////////////////////////////////////////

CUIChatWnd::~CUIChatWnd()
{
}

//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::Init()
{
	CUIXml uiXml;
//	uiXml.Init("$game_data$", CHAT_MP_WND_XML);
	bool xml_result = uiXml.Init(CONFIG_PATH, UI_PATH, CHAT_MP_WND_XML);
	R_ASSERT2(xml_result, "xml file not found");


	CUIXmlInit xml_init;

	// Prefix static
	AttachChild(&UIPrefix);
	xml_init.InitStatic(uiXml, "prefix_static", 0, &UIPrefix);

	// Edit box
	AttachChild(&UIEditBox);
	xml_init.InitStatic(uiXml, "edit_box", 0, &UIEditBox);

	m_AuthorName = Level().CurrentEntity()->cName();
}

//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::SetEditBoxPrefix(const shared_str &prefix)
{
	UIPrefix.SetText(*prefix);
}


//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::Say(const shared_str &phrase)
{
	R_ASSERT(pUILogList);
	pUILogList->Show();
	pUILogList->AddLogMessage(phrase, m_AuthorName);
}

//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::Show()
{
	UIEditBox.CaptureFocus(true);
	inherited::Show();
}

//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::Hide()
{
	UIEditBox.CaptureFocus(false);
	inherited::Hide();
}

//////////////////////////////////////////////////////////////////////////

void CUIChatWnd::SetKeyboardCapture(CUIWindow* pChildWindow, bool capture_status)
{
	if (&UIEditBox == pChildWindow && false == capture_status)
	{
		if (xr_strlen(UIEditBox.GetText()) > 0)
		{
			shared_str phrase = UIEditBox.GetText();
///			Say(phrase);
			sendNextMessageToTeam ? Game().ChatSayTeam(phrase) : Game().ChatSayAll(phrase);
			UIEditBox.SetText("");
			if (pOwner)
				pOwner->OnKeyboardPress(kCHAT);
		}
	}

	inherited::SetKeyboardCapture(pChildWindow, capture_status);
}