#include "BasicWidget.h"
#include <easyx.h>

BasicWidget::BasicWidget(int x, int y, int w, int h)
	: m_x(x),m_y(y),m_w(w),m_h(h)
{
	m_fontSize = 14;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fontFamily = L"宋体";
}

BasicWidget::~BasicWidget()
{
}

int BasicWidget::width() 
{
	return m_w;
}

int BasicWidget::height() 
{
	return m_h;
}

int BasicWidget::x() 
{
	return m_x;
}

int BasicWidget::y() 
{
	return m_y;
}

void BasicWidget::setFontColor(COLORREF color)
{
	m_fontColor = color;
}

void BasicWidget::setFontSize(int size)
{
	m_fontSize = size;
}

void BasicWidget::setFontFamily(wstring fontFamily)
{
	m_fontFamily = fontFamily;
	gettextstyle(&m_logfont);						// 获取当前字体设置
	_tcscpy_s(m_logfont.lfFaceName, m_fontFamily.data());			// 设置字体
	m_logfont.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&m_logfont);						// 设置字体样式
}

void BasicWidget::setFontWeight(int weight)
{
	m_fontWeight = weight;
	gettextstyle(&m_logfont);						// 获取当前字体设置
	m_logfont.lfWeight = m_fontWeight;				// 设置文字粗细
	m_logfont.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&m_logfont);
}

void BasicWidget::showComponent()
{
}

void BasicWidget::show()
{

}




