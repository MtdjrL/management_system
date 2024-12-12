#include "TextButton.h"

TextButton::TextButton(int x, int y, int w, int h)
	: BasicWidget(x, y, w, h)
{
	m_text = L"文本按钮";
	m_bkColor = RGB(255, 255, 255);
	m_fontPressedColor = RGB(64, 158, 255);
	m_bkColor = RGB(255, 255, 255);
	m_func = NULL;
	m_fontSize = 15;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fillColor = m_fontColor;
	m_fontFamily = L"宋体";
}

TextButton::~TextButton()
{
}

void TextButton::setBkColor(COLORREF color)
{
	m_bkColor = color;
	m_fillColor = m_bkColor;
}

void TextButton::setText(wstring text)
{
	m_text = text;
}


void TextButton::setFontPressedColor(COLORREF color)
{
	m_fontPressedColor = color;
}

void TextButton::showComponent()
{
	// 绘制按钮图形
	setlinecolor(m_bkColor); // 设置线条颜色，即图形的边框颜色
	setfillcolor(m_bkColor); // 设置图形的填充颜色
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	// 居中显示文本
	int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;

	// 设置文字属性
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fillColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// 使用双缓冲消除闪烁
	BeginBatchDraw();
	outtextxy(textPosx, textPosy, m_text.data());
	EndBatchDraw();
}

void TextButton::show()
{
	showComponent();
	showComponent();
}

int TextButton::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void TextButton::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (isOn(msg.x, msg.y)) // 鼠标悬浮
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				updateFontPressedColor();
				if (m_func != NULL) // 一定要判空，否则当没有绑定事件时会调用空函数指针
				{
					Sleep(100);
					(*m_func)();
				}
			}
			else
			{
				updateFontColor();
			}
		}
		else // 鼠标非悬浮
		{
			updateFontColor();
			break;
		}
	}
}

void TextButton::bindOnClick(void(*func)())
{
	m_func = func;
}

void TextButton::updateFontColor()
{
	m_fillColor = m_fontColor;
	show();
}

void TextButton::updateFontPressedColor()
{
	m_fillColor = m_fontPressedColor;
	show();
}
