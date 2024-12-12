#include "font.h"

// �����ı���ʽ
void setFontStyle(enum Font font)
{
	LOGFONT f;
	gettextstyle(&f); // ��ȡ��ǰ��������		
	f.lfQuality = ANTIALIASED_QUALITY; // �������Ч��Ϊ�����  
	switch (font)
	{
		case Title:
			f.lfHeight = 45; // ��������߶�
			_tcscpy_s(f.lfFaceName, _T("Times New Roman")); // ��������
			f.lfWeight = FW_BOLD; // �������ִ�ϸ
			settextcolor(RGB(0, 0, 0)); // ����������ɫ����ɫ
			break;
		case SubTitle:
			f.lfHeight = 22; // ��������߶�
			_tcscpy_s(f.lfFaceName, _T("Times New Roman"));	 // ��������
			f.lfWeight = FW_NORMAL; // �������ִ�ϸ
			settextstyle(&f); // ����������ʽ
			settextcolor(RGB(0, 0, 0)); // ����������ɫ����ɫ
			break;
		case RecText:
			f.lfHeight = 20; // ��������߶�
			_tcscpy_s(f.lfFaceName, _T("Times New Roman"));	 // ��������
			f.lfWeight = FW_BOLD; // �������ִ�ϸ
			settextstyle(&f); // ����������ʽ
			settextcolor(RGB(140, 140, 140)); // ����������ɫ����ɫ
		case Normal:
			break;
	}
	settextstyle(&f); // ����������ʽ
	
}