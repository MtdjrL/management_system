#include "TextButton.h"

TextButton::TextButton(int x, int y, int w, int h)
	: BasicWidget(x, y, w, h)
{
	m_text = L"�ı���ť";
	m_bkColor = RGB(255, 255, 255);
	m_fontPressedColor = RGB(64, 158, 255);
	m_bkColor = RGB(255, 255, 255);
	m_func = NULL;
	m_fontSize = 15;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fillColor = m_fontColor;
	m_fontFamily = L"����";
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
	// ���ư�ťͼ��
	setlinecolor(m_bkColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_bkColor); // ����ͼ�ε������ɫ
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	// ������ʾ�ı�
	int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fillColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// ʹ��˫����������˸
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
		if (isOn(msg.x, msg.y)) // �������
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				updateFontPressedColor();
				if (m_func != NULL) // һ��Ҫ�пգ�����û�а��¼�ʱ����ÿպ���ָ��
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
		else // ��������
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
