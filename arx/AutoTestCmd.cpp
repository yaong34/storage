
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//�������д�ӡ������ַ���
void bcCmdPrintString()
{
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n", szInput) == RTNORM)
	{
		acutPrintf(szInput);
	}
}

//////////////////////////////////////////////////////////////////////////
//�ϲ��ű�
void bcCmdMergeScript()
{
	//////////////////////////////////////////////////////////////////////////
	//��ýű�Ŀ¼�ļ�
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n��ָ���ű�Ŀ¼�ļ�(rx): ", szInput) != RTNORM)
		return;

	//�ű�Ŀ¼�ļ�
	AcString contentPath = szInput;

	//�����ļ��Ƿ����
	if (!PathFileExists(contentPath))
	{
		acutPrintf(L"\nָ���Ľű�Ŀ¼�ļ������ڡ�");
		return;
	}

	//�����ļ���ʽ�Ƿ�Ϸ�
	if (contentPath.substr(contentPath.length() - 3, 3).compareNoCase(L".rx"))
	{
		acutPrintf(L"\nָ���Ľű�Ŀ¼�ļ���ʽ����");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//���Ŀ��ű��ļ�
	if (acedGetString(1, L"\n��ָ��Ŀ��ű��ļ�(scr): ", szInput) != RTNORM)
		return;

	//Ŀ��ű��ļ�
	AcString scriptPath = szInput;

	//�����ļ��Ƿ����
	/*if (!PathFileExists(scriptPath))
	{
		acutPrintf(L"\nָ����Ŀ��ű��ļ������ڡ�");
		return;
	}*/

	//�����ļ���ʽ�Ƿ�Ϸ�
	if (scriptPath.substr(scriptPath.length() - 4, 4).compareNoCase(L".scr"))
	{
		acutPrintf(L"\nָ����Ŀ��ű��ļ���ʽ����");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//�ϲ��ű�
	AcStringArray arScript;
	
	//��ȡ�ű�Ŀ¼�ļ�
	AcCStdioFile contentFile;
	if (contentFile.Open(contentPath, CFile::shareDenyRead))
	{
		do
		{
			CString szPath;
			if (contentFile.ReadString(szPath))
			{
				if (!szPath.IsEmpty())
					arScript.append(szPath);
			}
			else
				break;
		}
		while (true);

		contentFile.Close();
	}

	//����ű�Ŀ¼�ļ��еĽű��б�
	if (arScript.isEmpty())
		return;

	//д��Ŀ��ű��ļ�
	AcCStdioFile scriptFile;
	if (scriptFile.Open(scriptPath, CFile::modeCreate | CFile::modeWrite))
	{
		//��ÿ���ű��ļ�
		for (int i = 0; i < arScript.logicalLength(); i++)
		{
			//ÿ���ű�����ӡ��Ϣ
			if (i != 0)
				scriptFile.WriteString(L"\n");

			AcString szPrint;
			szPrint.format(L"bcprintstring ------- ִ�нű�:%s -------", arScript[i].constPtr());
			scriptFile.WriteString(szPrint);

			//ÿ���ű�������д��
			AcCStdioFile file;
			if (file.Open(arScript[i], CFile::modeRead))
			{
				do 
				{
					CString szWord;
					if (file.ReadString(szWord))
					{
						scriptFile.WriteString(L"\n");
						scriptFile.WriteString(szWord);
					}
					else
						break;
				}
				while (true);

				file.Close();
			}
		}
		
		//��β����
		scriptFile.WriteString(L"\n");
		scriptFile.Close();
	}
}

//////////////////////////////////////////////////////////////////////////
//�������нű�
void bcCmdRunScripts()
{
	//////////////////////////////////////////////////////////////////////////
	//��ýű�Ŀ¼�ļ�
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n��ָ��Ҫ���еĽű�Ŀ¼�ļ�(rx): ", szInput) != RTNORM)
		return;

	//�ű�Ŀ¼�ļ�
	AcString contentPath = szInput;

	//�����ļ��Ƿ����
	if (!PathFileExists(contentPath))
	{
		acutPrintf(L"\nָ���Ľű�Ŀ¼�ļ������ڡ�");
		return;
	}

	//�����ļ���ʽ�Ƿ�Ϸ�
	if (contentPath.substr(contentPath.length() - 3, 3).compareNoCase(L".rx"))
	{
		acutPrintf(L"\nָ���Ľű�Ŀ¼�ļ���ʽ����");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//���Ŀ��ű��ļ�
	AcString scriptPath = L"F:\\yangyong\\temporary\\��������С��\\�Զ�������\\��ϸ˵��\\scr\\Ŀ��ű�.scr";

	//////////////////////////////////////////////////////////////////////////
	//�ϲ��ű�
	int ret = 0;
	ret = acedCommand(RTSTR, L"bcmergescript", RTSTR, contentPath.constPtr(), RTSTR, scriptPath.constPtr(), RTNONE);

	//���нű�
	ret = acedCommand(RTSTR, L"script", RTSTR, scriptPath.constPtr(), RTNONE);
}

//////////////////////////////////////////////////////////////////////////
//�����Զ�����
void bcCmdStartupAutoTest()
{
	struct resbuf rb;
	rb.restype = RTSHORT;
	rb.resval.rint = 0;
	acedSetVar(L"FILEDIA", &rb);

	int ret = 0;

	//scr�ű�����
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\��������С��\\�Զ�������\\��ϸ˵��\\scr\\���ֽű�1.scr", RTNONE);
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\��������С��\\�Զ�������\\��ϸ˵��\\scr\\���ֽű�2.scr", RTNONE);
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\��������С��\\�Զ�������\\��ϸ˵��\\scr\\���ֽű�3.scr", RTNONE);

	//����¼��������
	//ret = acedCommand(RTSTR, L"ActMacro001", RTNONE);
	//ret = acedCommand(RTSTR, L"ActMacro002", RTNONE);
	//ret = acedCommand(RTSTR, L"ActMacro003", RTNONE);

	//�������нű�����
	ret = acedCommand(RTSTR, L"bcrunscripts", RTSTR, L"F:\\yangyong\\temporary\\��������С��\\�Զ�������\\��ϸ˵��\\scr\\�ű�Ŀ¼.rx", RTNONE);

	rb.restype = RTSHORT;
	rb.resval.rint = 1;
	acedSetVar(L"FILEDIA", &rb);
}
