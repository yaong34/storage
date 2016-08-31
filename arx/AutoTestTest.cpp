
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//������
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
//������
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

//�˺������ܣ��������������ĵ�ˣ������Ϊ�������������
void bcgeDotProduct(const BcGeVector& v1, const BcGeVector& v2, double val)
{
	val = v1.m_dX * v2.m_dX + v1.m_dY * v2.m_dY + v1.m_dZ * v2.m_dZ;
	//û�����õ�ַ���������޷��õ��������
}

//�˺������ܣ��ж����������Ƿ���ȡ�
bool bcgeIsEqual(const BcGeVector& v1, const BcGeVector& v2)
{
	return (v1.m_dX == v2.m_dX &&
		v1.m_dY == v2.m_dY &&
		v1.m_dZ == v2.m_dZ);
	//���������ݱȽ���Ȳ���ֱ���á�==����
}

void main1()
{
	BcGeVector pt1, pt2;
	double dResult01 = 100.0;
	bcgeDotProduct(pt1, pt2, dResult01);	//�����������ĵ�ˣ��˴����벻��

	BcGeVector v1, v2;
	double dResult02 = bcgeIsEqual(v1,v2);	//double����ֱ�Ӹ�ֵ��bool����
}

//////////////////////////////////////////////////////////////////////////
//������
class baseClass
{
public:
	baseClass()
	{
		printf("\nbaseClass::����()");
	}

	virtual ~baseClass()
	{
		printf("\nbaseClass::����()");
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
		printf("\nderiveClass::����()");
	}

	virtual ~deriveClass()
	{ 
		printf("\nderiveClass::����()");
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
//������
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