#include "NavButton.h"

NavButton::NavButton(int w, int h)
	: BasicWidget(0, 0, w, h) // �����趨��ʼ���꣬��ӵ�Navbar���Զ��趨����
{
	m_text = L"����";
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
	m_fontFamily = L"����";
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
		if (isOn(msg.x, msg.y)) // �������
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				m_isPressed = 1;
				updatePressedTextColor();
				if (m_func != NULL) // һ��Ҫ�пգ�����û�а��¼�ʱ����ÿպ���ָ��
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
		else // ��������
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
	// ���ư�ťͼ��
	setlinecolor(m_fillColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_fillColor); // ����ͼ�ε������ɫ
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	// ������ʾ�ı�
	//int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosx = m_x + m_textGap;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;

	// �����������Բ����
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fillFontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);
	
	// ʹ��˫����������˸
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
