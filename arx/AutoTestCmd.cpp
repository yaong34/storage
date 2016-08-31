
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//在命令行打印输入的字符串
void bcCmdPrintString()
{
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n", szInput) == RTNORM)
	{
		acutPrintf(szInput);
	}
}

//////////////////////////////////////////////////////////////////////////
//合并脚本
void bcCmdMergeScript()
{
	//////////////////////////////////////////////////////////////////////////
	//获得脚本目录文件
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n请指定脚本目录文件(rx): ", szInput) != RTNORM)
		return;

	//脚本目录文件
	AcString contentPath = szInput;

	//检验文件是否存在
	if (!PathFileExists(contentPath))
	{
		acutPrintf(L"\n指定的脚本目录文件不存在。");
		return;
	}

	//检验文件格式是否合法
	if (contentPath.substr(contentPath.length() - 3, 3).compareNoCase(L".rx"))
	{
		acutPrintf(L"\n指定的脚本目录文件格式错误。");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//获得目标脚本文件
	if (acedGetString(1, L"\n请指定目标脚本文件(scr): ", szInput) != RTNORM)
		return;

	//目标脚本文件
	AcString scriptPath = szInput;

	//检验文件是否存在
	/*if (!PathFileExists(scriptPath))
	{
		acutPrintf(L"\n指定的目标脚本文件不存在。");
		return;
	}*/

	//检验文件格式是否合法
	if (scriptPath.substr(scriptPath.length() - 4, 4).compareNoCase(L".scr"))
	{
		acutPrintf(L"\n指定的目标脚本文件格式错误。");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//合并脚本
	AcStringArray arScript;
	
	//读取脚本目录文件
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

	//检验脚本目录文件中的脚本列表
	if (arScript.isEmpty())
		return;

	//写入目标脚本文件
	AcCStdioFile scriptFile;
	if (scriptFile.Open(scriptPath, CFile::modeCreate | CFile::modeWrite))
	{
		//打开每个脚本文件
		for (int i = 0; i < arScript.logicalLength(); i++)
		{
			//每个脚本，打印信息
			if (i != 0)
				scriptFile.WriteString(L"\n");

			AcString szPrint;
			szPrint.format(L"bcprintstring ------- 执行脚本:%s -------", arScript[i].constPtr());
			scriptFile.WriteString(szPrint);

			//每个脚本，逐行写入
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
		
		//结尾处理
		scriptFile.WriteString(L"\n");
		scriptFile.Close();
	}
}

//////////////////////////////////////////////////////////////////////////
//批量运行脚本
void bcCmdRunScripts()
{
	//////////////////////////////////////////////////////////////////////////
	//获得脚本目录文件
	ACHAR szInput[1024] = L"\0";
	if (acedGetString(1, L"\n请指定要运行的脚本目录文件(rx): ", szInput) != RTNORM)
		return;

	//脚本目录文件
	AcString contentPath = szInput;

	//检验文件是否存在
	if (!PathFileExists(contentPath))
	{
		acutPrintf(L"\n指定的脚本目录文件不存在。");
		return;
	}

	//检验文件格式是否合法
	if (contentPath.substr(contentPath.length() - 3, 3).compareNoCase(L".rx"))
	{
		acutPrintf(L"\n指定的脚本目录文件格式错误。");
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	//获得目标脚本文件
	AcString scriptPath = L"F:\\yangyong\\temporary\\技术管理小组\\自动化测试\\详细说明\\scr\\目标脚本.scr";

	//////////////////////////////////////////////////////////////////////////
	//合并脚本
	int ret = 0;
	ret = acedCommand(RTSTR, L"bcmergescript", RTSTR, contentPath.constPtr(), RTSTR, scriptPath.constPtr(), RTNONE);

	//运行脚本
	ret = acedCommand(RTSTR, L"script", RTSTR, scriptPath.constPtr(), RTNONE);
}

//////////////////////////////////////////////////////////////////////////
//启动自动测试
void bcCmdStartupAutoTest()
{
	struct resbuf rb;
	rb.restype = RTSHORT;
	rb.resval.rint = 0;
	acedSetVar(L"FILEDIA", &rb);

	int ret = 0;

	//scr脚本测试
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\技术管理小组\\自动化测试\\详细说明\\scr\\部分脚本1.scr", RTNONE);
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\技术管理小组\\自动化测试\\详细说明\\scr\\部分脚本2.scr", RTNONE);
	//ret = acedCommand(RTSTR, L"script", RTSTR, L"F:\\yangyong\\temporary\\技术管理小组\\自动化测试\\详细说明\\scr\\部分脚本3.scr", RTNONE);

	//动作录制器测试
	//ret = acedCommand(RTSTR, L"ActMacro001", RTNONE);
	//ret = acedCommand(RTSTR, L"ActMacro002", RTNONE);
	//ret = acedCommand(RTSTR, L"ActMacro003", RTNONE);

	//批量运行脚本测试
	ret = acedCommand(RTSTR, L"bcrunscripts", RTSTR, L"F:\\yangyong\\temporary\\技术管理小组\\自动化测试\\详细说明\\scr\\脚本目录.rx", RTNONE);

	rb.restype = RTSHORT;
	rb.resval.rint = 1;
	acedSetVar(L"FILEDIA", &rb);
}
