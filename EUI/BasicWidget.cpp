#include "BasicWidget.h"
#include <easyx.h>

BasicWidget::BasicWidget(int x, int y, int w, int h)
	: m_x(x),m_y(y),m_w(w),m_h(h)
{
	m_fontSize = 14;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fontFamily = L"����";
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
	gettextstyle(&m_logfont);						// ��ȡ��ǰ��������
	_tcscpy_s(m_logfont.lfFaceName, m_fontFamily.data());			// ��������
	m_logfont.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&m_logfont);						// ����������ʽ
}

void BasicWidget::setFontWeight(int weight)
{
	m_fontWeight = weight;
	gettextstyle(&m_logfont);						// ��ȡ��ǰ��������
	m_logfont.lfWeight = m_fontWeight;				// �������ִ�ϸ
	m_logfont.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&m_logfont);
}

void BasicWidget::showComponent()
{
}

void BasicWidget::show()
{

}




