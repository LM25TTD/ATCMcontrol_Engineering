// stdafx.h : Include-Datei f�r Standard-System-Include-Dateien,
//      oder h�ufig verwendete, projektspezifische Include-Dateien,
//      die nur in unregelm��igen Abst�nden ge�ndert werden.

#if !defined(AFX_STDAFX_H__F07936D7_73E8_11D2_9F91_00A024363DFC__INCLUDED_)
#define AFX_STDAFX_H__F07936D7_73E8_11D2_9F91_00A024363DFC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define STRICT

#include <afxwin.h>
#include <afxdisp.h>

#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
//Sie k�nnen eine Klasse von CComModule ableiten und diese verwenden, um etwas zu �berschreiben,
//Sie sollten jedoch den Namen von _Module nicht �ndern
extern CComModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STDAFX_H__F07936D7_73E8_11D2_9F91_00A024363DFC__INCLUDED)
