/* $Header: /4CReleased/V2.20.00/Target/TEMPLATES/AddOnHandler/AProjectData.h 1     28.02.07 18:54 Ln $
 * ------------------------------------------------------------------------------
 *
 * =FILENAME			$Workfile: AProjectData.h $
 *						 $Logfile: /4CReleased/V2.20.00/Target/TEMPLATES/AddOnHandler/AProjectData.h $
 *
 * =PROJECT 			4CONTROL V2.x
 *
 * =SWKE				Target
 *
 * =COMPONENT			AddOnHandler
 *
 * =CURRENT 	 $Date: 28.02.07 18:54 $
 *			 $Revision: 1 $
 *
 * ------------------------------------------------------------------------------
 */

#ifndef _AROJECTDATA_H_
#define _AROJECTDATA_H_

#include "BaseProjectData.h"

/* ---------------------------------------------------------------------------- */
/**
 * class CAProjectData
 *
 */
class CAProjectData : public CBaseProjectData
{
public:

    CAProjectData();
    ~CAProjectData();

    virtual CBaseAddonParameter* CreateAddonParameter();

    virtual int GetMaxResourceCount();

    virtual CString GetCommChannelDescription(const CString& crstrCommChannel);

    virtual CString GetDefaultCommChannel();

    virtual HRESULT CreateProjectFiles();

    HRESULT CreateGHFile();
	CString GetDefaultPassword();


/* ============================================================================
 * T A R G E T   S P E C I F I C
 * ============================================================================
 *
 */


};

#endif

/* ---------------------------------------------------------------------------- */
