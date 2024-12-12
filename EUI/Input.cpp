#include "Input.h"
#include <iostream>

Input::Input(int x, int y, int w, int h)
	: BasicWidget(x,y,w,h)
{
	m_holderText = L""; // 预设文本默认为空
	m_maxLen = 20;
	m_text = new wchar_t[m_maxLen];
	m_text[0] = 0;
	m_password = new wchar_t[m_maxLen];
	m_password[0] = 0;
	m_bkColor = RGB(255, 255, 255);
	m_borderColor = RGB(220, 223, 230);
	m_hoverBorderColor = RGB(192, 196, 204);
	m_pressedBorderColor = RGB(64, 158, 255);
	m_fillColor = m_borderColor;
	m_radius = 4;
	m_isPassword = 0;
	m_fontSize = 14;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fontFamily = L"宋体";
}

Input::~Input()
{
	delete[] m_text;
	delete[] m_password;
	m_text = NULL;
	m_password = NULL;
}

void Input::showComponent()
{
	// 绘制输入框图形
	setlinecolor(m_fillColor); // 设置线条颜色，即图形的边框颜色
	setfillcolor(m_bkColor); // 设置图形的填充颜色
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// 设置文字属性
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	int textPosx = m_x + 10;
	int textPosy = m_y + (m_h - textheight(m_holderText.data())) / 2;

	// 显示预设文本
	settextcolor(RGB(192,196,204)); // 灰色
	if (m_text[0] == 0) // 如果m_text为空，显示预设文本，否则预设文本会与输入文本重叠
	{
		outtextxy(textPosx, textPosy, m_holderText.data());
	}
	
	textPosx = m_x + 10;
	textPosy = m_y + (m_h - textheight(m_text)) / 2;
	int passwordPosx = textPosx;
	int passwordPosy = m_y + (m_h - textheight(m_password)) / 2;

	// 显示输入文本
	settextcolor(m_fontColor);
	if (m_isPassword)
	{
		outtextxy(passwordPosx, passwordPosy, m_password);
	}
	else
	{
		outtextxy(textPosx, textPosy, m_text);
	}
}

void Input::show()
{
	showComponent();
	showComponent();
}

void Input::eventLoop()
{
	int width = 0; // 字符串总宽度

	// 获取文本宽度
	if (m_isPassword)
	{
		width = textwidth(m_password);
	}
	else
	{
		width = textwidth(m_text);
	}

	int counter = 0; // 光标闪烁计数器S
	int isFocus = 1; // 是否聚焦
	
	updatePressedBorderColor();
	if (m_text[0] == 0) // 如果m_text为空，这时候清除的才是预设文本，否则会将输入文本一同清除掉
	{
		clearrectangle(m_x + 2, m_y + 2, m_x + m_w - 4, m_y + m_h - 4); // 清除预设文本
	}

	int textPosx = m_x + 10; // 文本的起始x坐标
	int textPosy = 0; // 文本的y坐标，以保证居中
	int passwordPosy = 0; // 文本的y坐标，以保证居中
	int cursorTop = int(m_y + (m_h - m_h * CUR_RATE) / 2);
	int cursorBottom = int(m_y + m_h - (m_h - m_h * CUR_RATE) / 2);

	ExMessage msg;
	while (isFocus) // 主循环,循环监听鼠标信息
	{
		while (isFocus && peekmessage(&msg, EX_MOUSE | EX_CHAR, 0))	// 获取消息，但不从消息队列拿出
		{	
			if (msg.message == WM_LBUTTONDOWN)
			{
				// 如果鼠标点击文本框外面，结束文本输入
				if (!isOn(msg.x, msg.y))
				{
					isFocus = 0;
					break;
				}
			}
			else if (msg.message == WM_CHAR)
			{
				size_t len = wcslen(m_text); // size_t是无符号int
				switch (msg.ch)
				{
				case '\b': // 用户按退格键，删掉一个字符
					if (len > 0)
					{
						m_text[len - 1] = 0;
						m_password[len - 1] = 0;
						
						// 获取文本宽度
						if (m_isPassword)
						{
							width = textwidth(m_password);
						}
						else
						{
							width = textwidth(m_text);
						}

						counter = 0;
						clearrectangle(textPosx + width, m_y + 1, m_x + m_w - 1, m_y + m_h - 1);
					}
					break;
				case '\r': 
				case '\n': // 用户按回车键，结束文本输入
					isFocus = 0;
					break;
				default: // 接受文本输入
					if (len < m_maxLen - 1)
					{
						m_text[len] = msg.ch;
						m_password[len] = '*';
						len++;
						m_text[len] = 0;
						m_password[len] = 0;
						clearrectangle(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // 清除画的光标

						// 重新计算文本宽度
						if (m_isPassword)
						{
							width = textwidth(m_password);
						}
						else
						{
							width = textwidth(m_text);
						}

						counter = 0;
						textPosy = m_y + (m_h - textheight(m_text)) / 2;
						passwordPosy = m_y + (m_h - textheight(m_password)) / 2;

						if (m_isPassword)
						{
							outtextxy(textPosx, passwordPosy, m_password); // 输出隐藏的新的字符串
						}
						else
						{
							outtextxy(textPosx, textPosy, m_text); // 输出新的字符串
						}
					}
				}
			}
			
			peekmessage(NULL, EX_MOUSE | EX_CHAR); // 从消息队列抛弃刚刚处理过的一个消息
		}

		// 绘制光标（光标闪烁周期为 20ms * 32）
		setlinecolor(RGB(96,98,102));
		counter = (counter + 1) % 32;
		if (counter < 16)
		{
			line(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // 画光标
		}		
		else
		{
			clearrectangle(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // 擦光标
		}

		// 延时 20ms
		Sleep(20);
	}	
	updateBorderColor();
	showComponent();
}


void Input::setHolderText(wstring text)
{
	m_holderText = text;
}

void Input::setMaxLen(int len)
{
	m_maxLen = len;
	delete[] m_text;
	m_text = new wchar_t[m_maxLen];
	m_text[0] = 0;
}

void Input::setPassword(int isPassword)
{
	if (isPassword)
	{
		m_isPassword = 1;
	}
	else
	{
		m_isPassword = 0;
	}
}

wchar_t* Input::text()
{
	return m_text;
}

int Input::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void Input::move(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Input::updateBorderColor()
{
	m_fillColor = m_borderColor;
	show();
}

void Input::updateHoverBorderColor()
{
	m_fillColor = m_hoverBorderColor;
	show();
}

void Input::updatePressedBorderColor()
{
	m_fillColor = m_pressedBorderColor;
	show();
}
