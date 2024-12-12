#include "font.h"

// 设置文本样式
void setFontStyle(enum Font font)
{
	LOGFONT f;
	gettextstyle(&f); // 获取当前字体设置		
	f.lfQuality = ANTIALIASED_QUALITY; // 设置输出效果为抗锯齿  
	switch (font)
	{
		case Title:
			f.lfHeight = 45; // 设置字体高度
			_tcscpy_s(f.lfFaceName, _T("Times New Roman")); // 设置字体
			f.lfWeight = FW_BOLD; // 设置文字粗细
			settextcolor(RGB(0, 0, 0)); // 设置字体颜色：黑色
			break;
		case SubTitle:
			f.lfHeight = 22; // 设置字体高度
			_tcscpy_s(f.lfFaceName, _T("Times New Roman"));	 // 设置字体
			f.lfWeight = FW_NORMAL; // 设置文字粗细
			settextstyle(&f); // 设置字体样式
			settextcolor(RGB(0, 0, 0)); // 设置字体颜色：黑色
			break;
		case RecText:
			f.lfHeight = 20; // 设置字体高度
			_tcscpy_s(f.lfFaceName, _T("Times New Roman"));	 // 设置字体
			f.lfWeight = FW_BOLD; // 设置文字粗细
			settextstyle(&f); // 设置字体样式
			settextcolor(RGB(140, 140, 140)); // 设置字体颜色：黑色
		case Normal:
			break;
	}
	settextstyle(&f); // 设置字体样式
	
}