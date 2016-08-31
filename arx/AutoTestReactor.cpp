
#include "stdafx.h"

extern Adesk::Boolean acedPostCommand(const ACHAR *szCmd);

//////////////////////////////////////////////////////////////////////////
//��ʼ���
void bcCmdBeginMonitor()
{
	/*
	ACHAR *p = NULL;
	_tcscpy(p, L"milan");
	*/

	ads_point pnt1;
	ads_point pnt2;

	acedInitGet(NULL, NULL);
	if (acedGetPoint(NULL, L"\n���������: ", pnt1) == RTNORM)
	{
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n�������յ�: ", pnt2) == RTNORM)
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
			/*/����Ƕ�׵�������
			ads_command(RTSTR, L"BCENDMONITOR", RTNONE);
			/*/
			//acedPostCommand(L"BCENDMONITOR\n");
			//acDocManager->sendStringToExecute(curDoc(), L"BCENDMONITOR ");
			//*/
			//////////////////////////////////////////////////////////////////////////

			acutPrintf(L"\nbcbeginmonitor����ִ�����\n");
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//�������
void bcCmdEndMonitor()
{
	ads_point pnt1;
	ads_point pnt2;

	acedInitGet(NULL, NULL);
	if (acedGetPoint(NULL, L"\n������Բ��: ", pnt1) == RTNORM)
	{
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n������Բ�ϵ�: ", pnt2) == RTNORM)
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
	
	acutPrintf(L"\nbcendmonitor����ִ�����\n");
}

//////////////////////////////////////////////////////////////////////////
//��ص�
void bcCmdPointMonitor()
{
	do 
	{
		//��õ�
		AcGePoint3d pnt;
		acedInitGet(NULL, NULL);
		if (acedGetPoint(NULL, L"\n��ָ���㣺", asDblArray(pnt)) != RTNORM)
			break;

		//����ת��
		acdbUcs2Wcs(asDblArray(pnt), asDblArray(pnt), false);

		//��ӡ����
		ACHAR szX[1024] = L"\0";
		ACHAR szY[1024] = L"\0";
		ACHAR szZ[1024] = L"\0";

		acdbRToS(pnt.x, 2, 8, szX);
		acdbRToS(pnt.y, 2, 8, szY);
		acdbRToS(pnt.z, 2, 8, szZ);

		AcString szPrompt;
		szPrompt.format(L"������ (%s,%s,%s)", szX, szY, szZ);
		acutPrintf(szPrompt.constPtr());
	}
	while (true);
}