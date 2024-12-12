#include "Input.h"
#include <iostream>

Input::Input(int x, int y, int w, int h)
	: BasicWidget(x,y,w,h)
{
	m_holderText = L""; // Ԥ���ı�Ĭ��Ϊ��
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
	m_fontFamily = L"����";
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
	// ���������ͼ��
	setlinecolor(m_fillColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_bkColor); // ����ͼ�ε������ɫ
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	int textPosx = m_x + 10;
	int textPosy = m_y + (m_h - textheight(m_holderText.data())) / 2;

	// ��ʾԤ���ı�
	settextcolor(RGB(192,196,204)); // ��ɫ
	if (m_text[0] == 0) // ���m_textΪ�գ���ʾԤ���ı�������Ԥ���ı����������ı��ص�
	{
		outtextxy(textPosx, textPosy, m_holderText.data());
	}
	
	textPosx = m_x + 10;
	textPosy = m_y + (m_h - textheight(m_text)) / 2;
	int passwordPosx = textPosx;
	int passwordPosy = m_y + (m_h - textheight(m_password)) / 2;

	// ��ʾ�����ı�
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
	int width = 0; // �ַ����ܿ��

	// ��ȡ�ı����
	if (m_isPassword)
	{
		width = textwidth(m_password);
	}
	else
	{
		width = textwidth(m_text);
	}

	int counter = 0; // �����˸������S
	int isFocus = 1; // �Ƿ�۽�
	
	updatePressedBorderColor();
	if (m_text[0] == 0) // ���m_textΪ�գ���ʱ������Ĳ���Ԥ���ı�������Ὣ�����ı�һͬ�����
	{
		clearrectangle(m_x + 2, m_y + 2, m_x + m_w - 4, m_y + m_h - 4); // ���Ԥ���ı�
	}

	int textPosx = m_x + 10; // �ı�����ʼx����
	int textPosy = 0; // �ı���y���꣬�Ա�֤����
	int passwordPosy = 0; // �ı���y���꣬�Ա�֤����
	int cursorTop = int(m_y + (m_h - m_h * CUR_RATE) / 2);
	int cursorBottom = int(m_y + m_h - (m_h - m_h * CUR_RATE) / 2);

	ExMessage msg;
	while (isFocus) // ��ѭ��,ѭ�����������Ϣ
	{
		while (isFocus && peekmessage(&msg, EX_MOUSE | EX_CHAR, 0))	// ��ȡ��Ϣ����������Ϣ�����ó�
		{	
			if (msg.message == WM_LBUTTONDOWN)
			{
				// ���������ı������棬�����ı�����
				if (!isOn(msg.x, msg.y))
				{
					isFocus = 0;
					break;
				}
			}
			else if (msg.message == WM_CHAR)
			{
				size_t len = wcslen(m_text); // size_t���޷���int
				switch (msg.ch)
				{
				case '\b': // �û����˸����ɾ��һ���ַ�
					if (len > 0)
					{
						m_text[len - 1] = 0;
						m_password[len - 1] = 0;
						
						// ��ȡ�ı����
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
				case '\n': // �û����س����������ı�����
					isFocus = 0;
					break;
				default: // �����ı�����
					if (len < m_maxLen - 1)
					{
						m_text[len] = msg.ch;
						m_password[len] = '*';
						len++;
						m_text[len] = 0;
						m_password[len] = 0;
						clearrectangle(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // ������Ĺ��

						// ���¼����ı����
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
							outtextxy(textPosx, passwordPosy, m_password); // ������ص��µ��ַ���
						}
						else
						{
							outtextxy(textPosx, textPosy, m_text); // ����µ��ַ���
						}
					}
				}
			}
			
			peekmessage(NULL, EX_MOUSE | EX_CHAR); // ����Ϣ���������ոմ������һ����Ϣ
		}

		// ���ƹ�꣨�����˸����Ϊ 20ms * 32��
		setlinecolor(RGB(96,98,102));
		counter = (counter + 1) % 32;
		if (counter < 16)
		{
			line(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // �����
		}		
		else
		{
			clearrectangle(textPosx + width + 1, cursorTop, textPosx + width + 1, cursorBottom); // �����
		}

		// ��ʱ 20ms
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
