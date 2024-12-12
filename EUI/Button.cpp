#include "Button.h"


Button::Button(int x, int y, int w, int h)
	: BasicWidget(x,y,w,h)
{
	m_text = L"��ť";
	m_bkColor = RGB(71, 143, 221);
	m_hoverBkColor = RGB(56, 122, 192);
	m_pressedBkColor = RGB(42, 105, 172);
	m_fillColor = m_bkColor;
	m_borderColor = m_bkColor;
	m_radius = 6;
	m_isMessageBtn = 0; // Ĭ�ϲ��ǵ���ť
	m_func = NULL;
	m_fontSize = 20;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(255, 255, 255);
	m_fontFamily = L"����";
}

Button::~Button()
{
}

void Button::setBkColor(COLORREF color)
{
	m_bkColor = color;
	m_fillColor = m_bkColor;
}

void Button::setText(wstring text)
{
	m_text = text;
}


void Button::setRadius(int radius)
{
	m_radius = radius;
}

void Button::setHoverBkColor(COLORREF color)
{
	m_hoverBkColor = color;
}

void Button::setPressedBkColor(COLORREF color)
{
	m_pressedBkColor = color;
}

void Button::setBorderColor(COLORREF color)
{
	m_borderColor = color;
}

void Button::setMessageBtn()
{
	m_isMessageBtn = 1; // ���ð�ťΪ����ť
}

int Button::isOn(int x,int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void Button::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (isOn(msg.x, msg.y)) // �������
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				updatePressedBkColor();
				if (m_func != NULL) // һ��Ҫ�пգ�����û�а��¼�ʱ����ÿպ���ָ��
				{
					Sleep(100);
					(*m_func)();
					// ���ڵ����еİ�ť����Ҫֱ���˳�������Ҫ�ڵ����ˢ�°�ť��ɫΪ����ɫ
					if (m_isMessageBtn)
					{
						break;
					}
				}	
			}
			else
			{
				updateHoverBkColor();
			}
		}
		else // ��������
		{
			updateBkColor();
			break;
		}
	}
}

void Button::showComponent()
{
	// ���ư�ťͼ��
	setlinecolor(m_borderColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_fillColor); // ����ͼ�ε������ɫ
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// ������ʾ�ı�
	int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontWeight(m_fontWeight);
	setFontFamily(m_fontFamily);
	
	// ʹ��˫����������˸
	BeginBatchDraw();
	outtextxy(textPosx, textPosy, m_text.data());
	EndBatchDraw();
}

void Button::show()
{
	showComponent();
	showComponent();
}

void Button::bindOnClick(void (*func)())
{
	m_func = func;
}


void Button::updateBkColor()
{
	m_fillColor = m_bkColor;
	show();
}

void Button::updateHoverBkColor()
{
	m_fillColor = m_hoverBkColor;
	show();
}

void Button::updatePressedBkColor()
{
	m_fillColor = m_pressedBkColor;
	show();
}


