#if !defined(AFX_CPNAVIGATORPPG_H__B3380733_7157_11D1_A4A8_00A024363DFC__INCLUDED_)
#define AFX_CPNAVIGATORPPG_H__B3380733_7157_11D1_A4A8_00A024363DFC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// CpNavigatorPpg.h: Deklaration der Eigenschaftenseitenklasse CCpNavigatorPropPage.

////////////////////////////////////////////////////////////////////////////
// CCpNavigatorPropPage: Siehe CpNavigatorPpg.cpp.cpp f�r Implementierung

class CCpNavigatorPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCpNavigatorPropPage)
	DECLARE_OLECREATE_EX(CCpNavigatorPropPage)

// Konstruktor
public:
	CCpNavigatorPropPage();

// Dialogfelddaten
	//{{AFX_DATA(CCpNavigatorPropPage)
	enum { IDD = IDD_PROPPAGE_CPNAVIGATOR };
		// HINWEIS - Der Klassen-Assistent f�gt Datenelemente hier ein.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_DATA

// Implementierung
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Nachrichtenzuordnungstabellen
protected:
	//{{AFX_MSG(CCpNavigatorPropPage)
		// HINWEIS - Der Klassen-Assistent f�gt Member-Funktionen hier ein und entfernt diese.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_CPNAVIGATORPPG_H__B3380733_7157_11D1_A4A8_00A024363DFC__INCLUDED)
