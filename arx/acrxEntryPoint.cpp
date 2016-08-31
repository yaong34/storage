// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("Bc")

//-----------------------------------------------------------------------------
//×¢²áÃüÁî
void bcCmdPrintString();
void bcCmdMergeScript();
void bcCmdRunScripts();
void bcCmdStartupAutoTest();

void bcCmdBeginMonitor();
void bcCmdEndMonitor();
void bcCmdPointMonitor();

void bcCmdArxTestCmd();

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CAutoTestArxApp : public AcRxArxApp {

public:
	CAutoTestArxApp () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}

	static void BcAutoTestArxBcPrintString(void)
	{
		bcCmdPrintString();
	}

	static void BcAutoTestArxBcMergeScript(void)
	{
		bcCmdMergeScript();
	}

	static void BcAutoTestArxBcRunScripts(void)
	{
		bcCmdRunScripts();
	}

	static void BcAutoTestArxBcStartupAutoTest(void)
	{
		bcCmdStartupAutoTest();
	}

	static void BcAutoTestArxBcBeginMonitor(void)
	{
		bcCmdBeginMonitor();
	}

	static void BcAutoTestArxBcEndMonitor(void)
	{
		bcCmdEndMonitor();
	}

	static void BcAutoTestArxBcPointMonitor(void)
	{
		bcCmdPointMonitor();
	}

	static void BcAutoTestArxBcArxTestCmd(void)
	{
		bcCmdArxTestCmd();
	}
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CAutoTestArxApp)

ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcPrintString, BcPrintString, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcMergeScript, BcMergeScript, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcRunScripts,  BcRunScripts,  ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcStartupAutoTest, BcStartupAutoTest, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcBeginMonitor, BcBeginMonitor, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcEndMonitor,   BcEndMonitor,   ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcPointMonitor, BcPointMonitor, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(CAutoTestArxApp, BcAutoTestArx, BcArxTestCmd, BcArxTestCmd, ACRX_CMD_TRANSPARENT, NULL)

