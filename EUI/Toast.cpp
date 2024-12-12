#include "Toast.h"

Toast::Toast(int winWidth,int y,int w,int h)
	:BasicWidget((winWidth - w) / 2,y,w,h)
{
	m_text = L"����һ����Ϣ";
	m_radius = 4;
	m_fontSize = 14;
	m_fontWeight = FW_NORMAL;
	m_fontFamily = L"����";
	setSuccStyle(); // ����Ϊ�ɹ���ʽ������ʼ����m_fontColor��m_bkColor
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
	// ���ư�ťͼ��
	setlinecolor(m_bkColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_bkColor); // ����ͼ�ε������ɫ
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// �����������Բ����
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// ������ʾ�ı�
	int textPosx = m_x + (m_w - textwidth(m_text.data())) / 2;
	int textPosy = m_y + (m_h - textheight(m_text.data())) / 2;
	
	outtextxy(textPosx, textPosy, m_text.data());

	Sleep(1000);
	clearrectangle(m_x, m_y, m_x + m_w, m_y + m_h); // ����
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

