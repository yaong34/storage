
#include "stdafx.h"

extern Adesk::Boolean acedPostCommand(const ACHAR *szCmd);

//////////////////////////////////////////////////////////////////////////
//开始监控
void bcCmdBeginMonitor()
{
	/*
	ACHAR *p = NULL;
	_tcscpy(p, L"milan");
	*/

	ads_point pnt1;
	ads_point pnt2;

	acedInitGet(NULL, NULL);
	if (acedGetPoint(NULL, L"\n请输入起点: ", pnt1) == RTNORM)
	{
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n请输入终点: ", pnt2) == RTNORM)
		{
			AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
			assert(pDb != NULL);

			AcDbLine *pLine = new AcDbLine;
			pLine->setDatabaseDefaults(pDb);
			pLine->setStartPoint(asPnt3d(pnt1));
			pLine->setEndPoint(asPnt3d(pnt2));

			AcDbBlockTableRecord *pRec = NULL;
			if (acdbOpenObject(pRec, pDb->currentSpaceId(), AcDb::kForWrite) == Acad::eOk)
			{
				pRec->appendAcDbEntity(pLine);
				pRec->close();
				pLine->close();
			}

			//////////////////////////////////////////////////////////////////////////
			/*/测试嵌套调用命令
			ads_command(RTSTR, L"BCENDMONITOR", RTNONE);
			/*/
			//acedPostCommand(L"BCENDMONITOR\n");
			//acDocManager->sendStringToExecute(curDoc(), L"BCENDMONITOR ");
			//*/
			//////////////////////////////////////////////////////////////////////////

			acutPrintf(L"\nbcbeginmonitor命令执行完毕\n");
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//结束监控
void bcCmdEndMonitor()
{
	ads_point pnt1;
	ads_point pnt2;

	acedInitGet(NULL, NULL);
	if (acedGetPoint(NULL, L"\n请输入圆心: ", pnt1) == RTNORM)
	{
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n请输入圆上点: ", pnt2) == RTNORM)
		{
			AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
			assert(pDb != NULL);

			AcDbCircle *pCircle = new AcDbCircle;
			pCircle->setDatabaseDefaults(pDb);
			pCircle->setCenter(asPnt3d(pnt1));
			pCircle->setRadius(asPnt3d(pnt1).distanceTo(asPnt3d(pnt2)));

			AcDbBlockTableRecord *pRec = NULL;
			if (acdbOpenObject(pRec, pDb->currentSpaceId(), AcDb::kForWrite) == Acad::eOk)
			{
				pRec->appendAcDbEntity(pCircle);
				pRec->close();
				pCircle->close();
			}
		}
	}
	
	acutPrintf(L"\nbcendmonitor命令执行完毕\n");
}

//////////////////////////////////////////////////////////////////////////
//监控点
void bcCmdPointMonitor()
{
	do 
	{
		//获得点
		AcGePoint3d pnt;
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n请指定点：", asDblArray(pnt)) != RTNORM)
			break;

		//坐标转换
		acdbUcs2Wcs(asDblArray(pnt), asDblArray(pnt), false);

		//打印坐标
		ACHAR szX[1024] = L"\0";
		ACHAR szY[1024] = L"\0";
		ACHAR szZ[1024] = L"\0";

		acdbRToS(pnt.x, 2, 8, szX);
		acdbRToS(pnt.y, 2, 8, szY);
		acdbRToS(pnt.z, 2, 8, szZ);

		AcString szPrompt;
		szPrompt.format(L"点坐标 (%s,%s,%s)", szX, szY, szZ);
		acutPrintf(szPrompt.constPtr());
	}
	while (true);
}