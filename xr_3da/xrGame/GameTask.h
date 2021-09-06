///////////////////////////////////////////////////////////////
// GameTask.h
// ����� �������� ������� �������
///////////////////////////////////////////////////////////////

#pragma once

#include "ui/xrXMLParser.h"

#include "shared_data.h"
#include "xml_str_id_loader.h"

#include "encyclopedia_article_defs.h"
#include "GameTaskDefs.h"

class  CGameObject;


//������� ������� 
struct SGameTaskObjective 
{
	SGameTaskObjective() {}
	//��������� ��������
	shared_str description;
	//index ������ � ������������ ��� �������� (���� ����)
	ARTICLE_INDEX article_index;
	//������������� ������
	shared_str icon_texture_name;
	int icon_x, icon_y, icon_width, icon_height;
};

//////////////////////////////////////////////////////////////////////////
// SPhraseDialogData: ������ ��� ������������� �������
//////////////////////////////////////////////////////////////////////////
struct SGameTaskData : CSharedResource
{
	SGameTaskData ();
	virtual ~SGameTaskData ();

	DEFINE_VECTOR(SGameTaskObjective, OBJECTIVE_VECTOR, OBJECTIVE_VECTOR_IT);
	OBJECTIVE_VECTOR m_Objectives;
	//�������� �������
	shared_str title;
};


class CGameTask: public CSharedClass<SGameTaskData, TASK_INDEX, false>,
				 public CXML_IdToIndex<TASK_ID, TASK_INDEX, CGameTask>
{
private:
	typedef CSharedClass<SGameTaskData, TASK_INDEX, false>	inherited_shared;
	typedef CXML_IdToIndex<TASK_ID, TASK_INDEX, CGameTask>	id_to_index;

	friend id_to_index;
public:
			CGameTask	();
	virtual ~CGameTask	();

	virtual void Load	(TASK_ID	str_id);
	virtual void Load	(TASK_INDEX  index);

	virtual void Init	(const TASK_DATA&  data);

protected:
	TASK_INDEX	m_TaskIndex;
	void load_shared	(LPCSTR);
	static void InitXmlIdToIndex();
public:
	const TASK_INDEX Index() {return m_TaskIndex;}
	SGameTaskData* data() { VERIFY(inherited_shared::get_sd()); return inherited_shared::get_sd();}

public:
	virtual u32				ObjectivesNum	();
	virtual shared_str		ObjectiveDesc	(u32 index);
	virtual shared_str		ObjectiveTitle	() {return data()->title;}
	virtual ARTICLE_INDEX	ObjectiveArticle(u32 index);
	virtual ETaskState		ObjectiveState  (u32 index);
	virtual void			ObjectiveIcon	(u32 index, shared_str& tex_name, int& x, int& y, int& width, int& height);
	//���������������� ���������� �� ������� ������
	TASK_STATE_VECTOR	m_ObjectiveStates;
	ALife::_TIME_ID		m_ReceiveTime;
	ALife::_TIME_ID		m_FinishTime;
};