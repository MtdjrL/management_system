#include "NavButton.h"

NavButton::NavButton(int w, int h)
	: BasicWidget(0, 0, w, h) // 不用设定初始坐标，添加到Navbar中自动设定坐标
{
	m_text = L"导航";
	m_pressedFontColor = RGB(64, 158, 255);
	m_bkColor = RGB(48, 65, 86);
	m_hoverBkColor = RGB(38, 52, 69);
	m_pressedBkColor = m_hoverBkColor;
	m_fillColor = m_bkColor;
	m_func = NULL;
	m_isPressed = 0;
	m_fontSize = 18;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(191, 203, 217);
	m_fontFamily = L"宋体";
	m_fillFontColor = m_fontColor;
	m_textGap = 50;
}

NavButton::~NavButton()
{
}

void NavButton::setBkColor(COLORREF color)
{
	m_bkColor = color;
	m_fillColor = m_bkColor;
}

void NavButton::setText(wstring text)
{
	m_text = text;
}

void NavButton::setGap(int gap)
{
	m_textGap = gap;
}


void NavButton::setHoverBkColor(COLORREF color)
{
	m_hoverBkColor = color;
}

void NavButton::setPressedTextColor(COLORREF color)
{
	m_pressedFontColor = color;
}

int NavButton::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

int NavButton::isPressed()
{
	return m_isPressed;
}

void NavButton::toIsNotPressed()
{
	m_isPressed = 0;
}


void NavButton::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (isOn(msg.x, msg.y)) // 鼠标悬浮
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				m_isPressed = 1;
				updatePressedTextColor();
				if (m_func != NULL) // 一定要判空，否则当没有绑定事件时会调用空函数指针
				{
					(*m_func)();
					break;
				}
				break;
			}
			else
			{
				updateHoverBkColor();
			}
		}
		else // 鼠标非悬浮
		{
			updateLeaveBkColor();
			if (m_isPressed)
			{
				updatePressedTextColor();
			}
			else
			{
				updateStyle();
			}
			break;
		}
	}
}


void NavButton::move(int x, int y)
{
	m_x = x;
	m_y = y;
}

void NavButton::showComponent()
{
	// 绘制按钮图形
	setlinecolor(m_fillColor); // 设置线条颜色，即图形的边框颜色
	setfillcolor(m_fillColor); // 设置图形的填充颜色
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	// 居中显示文本
	//int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosx = m_x + m_textGap;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;

	// 设置文字属性并输出
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fillFontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);
	
	// 使用双缓冲消除闪烁
	BeginBatchDraw();
	outtextxy(textPosx, textPosy, m_text.data());
	EndBatchDraw();
}

void NavButton::show()
{
	showComponent();
	showComponent();
}

void NavButton::bindOnClick(void(*func)())
{
	m_func = func;
}

void NavButton::updateStyle()
{
	m_fillFontColor = m_fontColor;
	m_fillColor = m_bkColor;
	show();
}

void NavButton::updateHoverBkColor()
{
	m_fillColor = m_hoverBkColor;
	show();
}

void NavButton::updateLeaveBkColor()
{
	m_fillColor = m_bkColor;
	show();
}

void NavButton::updatePressedTextColor()
{
	m_fillFontColor = m_pressedFontColor;
	show();
}
