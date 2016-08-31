
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//笔试题
void GetMemory(char* p, int num)
{
	p = (char *)malloc(num);
}

void main0()
{
	char *str = NULL;
	GetMemory(str, 100);
	strcpy(str, "BcSoft");	
	printf(str);
	free(str);
}

//////////////////////////////////////////////////////////////////////////
//笔试题
struct BcGePoint
{
	BcGePoint()
	{
		m_dX = 0.;
		m_dY = 0.;
		m_dZ = 0.;
	}

	double m_dX;
	double m_dY;
	double m_dZ;
};

struct BcGeVector : public BcGePoint
{
};

//此函数功能：计算两个向量的点乘，结果做为输出参数传出。
void bcgeDotProduct(const BcGeVector& v1, const BcGeVector& v2, double val)
{
	val = v1.m_dX * v2.m_dX + v1.m_dY * v2.m_dY + v1.m_dZ * v2.m_dZ;
	//没有引用地址，函数外无法得到输出参数
}

//此函数功能：判断两个向量是否相等。
bool bcgeIsEqual(const BcGeVector& v1, const BcGeVector& v2)
{
	return (v1.m_dX == v2.m_dX &&
		v1.m_dY == v2.m_dY &&
		v1.m_dZ == v2.m_dZ);
	//浮点型数据比较相等不能直接用“==”。
}

void main1()
{
	BcGeVector pt1, pt2;
	double dResult01 = 100.0;
	bcgeDotProduct(pt1, pt2, dResult01);	//求两个向量的点乘，此处编译不过

	BcGeVector v1, v2;
	double dResult02 = bcgeIsEqual(v1,v2);	//double类型直接赋值给bool类型
}

//////////////////////////////////////////////////////////////////////////
//笔试题
class baseClass
{
public:
	baseClass()
	{
		printf("\nbaseClass::构造()");
	}

	virtual ~baseClass()
	{
		printf("\nbaseClass::析构()");
	}

	virtual void vrfun()
	{ 
		printf("\nbaseClass::vrfun()");
	}

	void fun()
	{ 
		printf("\nbaseClass::fun()");
	}
};

class deriveClass : public baseClass
{
public:
	deriveClass() 
	{ 
		printf("\nderiveClass::构造()");
	}

	virtual ~deriveClass()
	{ 
		printf("\nderiveClass::析构()");
	}

	virtual void vrfun()
	{ 
		printf("\nderiveClass::vrfun()");
	}

	void fun()
	{ 
		printf("\nderiveClass::fun()");
	}
};

void main2()
{
	baseClass baseObj;
	deriveClass deriveObj;
	baseClass *pBase=&baseObj;
	pBase->vrfun();
	pBase->fun();
	pBase=&deriveObj;
	pBase->vrfun();
	pBase->fun();
}

/////////////////////////////////////////////////////////////////////////
//笔试题
void main3()
{
	CListCtrl listctrl;
	listctrl.SetExtendedStyle(listctrl.GetExtendedStyle()| LVS_EX_FULLROWSELECT);
	listctrl.SetBkColor(RGB(255,255,255));

	POSITION pos = listctrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
		return;
	else
	{
		while (pos)
		{
			int nItem = listctrl.GetNextSelectedItem(pos);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
void bcCmdArxTestCmd()
{
}