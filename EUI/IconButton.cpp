#include "IconButton.h"

IconButton::IconButton(int x, int y, int w, int h)
	: BasicWidget(x, y, w, h)
{
	m_bkColor = RGB(255, 255, 255);
	m_func = NULL;
}

IconButton::~IconButton()
{
}

void IconButton::setIcon(IMAGE icon, IMAGE iconPressed)
{
	m_icon = icon;
	m_iconPressed = iconPressed;
}

void IconButton::showComponent()
{
	// 类外加载资源路径
	// 类内透明输出
	transparentimage(NULL, m_x, m_y, &m_icon);
}

void IconButton::show()
{
	showComponent();
	showComponent();
}

int IconButton::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void IconButton::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (isOn(msg.x, msg.y)) // 鼠标悬浮
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				updatePressedStyle();
				if (m_func != NULL) // 一定要判空，否则当没有绑定事件时会调用空函数指针
				{
					Sleep(100);
					(*m_func)();
				}
			}
			else
			{
				updateStyle();
			}
		}
		else // 鼠标非悬浮
		{
			updateStyle();
			break;
		}
	}
}

void IconButton::bindOnClick(void(*func)())
{
	m_func = func;
}

void IconButton::transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void IconButton::updateStyle()
{
	showComponent();
}

void IconButton::updatePressedStyle()
{
	// 类外加载资源路径
	// 类内透明输出
	transparentimage(NULL, m_x, m_y, &m_iconPressed);
}
