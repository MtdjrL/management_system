#include "Toast.h"

Toast::Toast(int winWidth,int y,int w,int h)
	:BasicWidget((winWidth - w) / 2,y,w,h)
{
	m_text = L"这是一段消息";
	m_radius = 4;
	m_fontSize = 14;
	m_fontWeight = FW_NORMAL;
	m_fontFamily = L"宋体";
	setSuccStyle(); // 设置为成功样式，即初始化了m_fontColor和m_bkColor
}

Toast::~Toast()
{
}

void Toast::showComponent()
{
}

void Toast::show(InfoType it)
{
	switch (it)
	{
	case SUCCESS:
		setSuccStyle();
		showToast();
		break;
	case WARNING:
		setWarnStyle();
		showToast();
		break;
	default:
		break;
	}
}

void Toast::showToast()
{
	// 绘制按钮图形
	setlinecolor(m_bkColor); // 设置线条颜色，即图形的边框颜色
	setfillcolor(m_bkColor); // 设置图形的填充颜色
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// 设置文字属性并输出
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// 居中显示文本
	int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;
	
	outtextxy(textPosx, textPosy, m_text.data());

	Sleep(1000);
	clearrectangle(m_x, m_y, m_x + m_w, m_y + m_h); // 消除
}


void Toast::setSuccStyle()
{
	m_fontColor = RGB(103, 194, 58);
	m_bkColor = RGB(240, 249, 235);
}

void Toast::setWarnStyle()
{
	m_fontColor = RGB(232, 169, 74);
	m_bkColor = RGB(253, 246, 236);
}

void Toast::setText(wstring text)
{
	m_text = text;
}

