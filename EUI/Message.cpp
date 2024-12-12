#include "Message.h"

Message::Message(int winWidth, int winHeight, int w, int h)
	:BasicWidget((winWidth - w) / 2,(winHeight - h) / 2,w,h)
{
	m_mt = INFO;
	m_radius = 8;
	m_title = L"��ʾ";
	m_titleFontSize = 20;
	m_titleFontColor = RGB(0, 0, 0);
	m_titleFontFamily = L"����";
	m_padding = 10;
	m_titleVerGap = 46;
	m_bkColor = RGB(255, 255, 255);
	m_isShow = 0;
	m_fontSize = 16;
	m_fontWeight = FW_NORMAL;
	m_fontColor = RGB(0, 0, 0);
	m_fontFamily = L"����";

	int btnWidth = 55;
	int btnHeight = 25;
	int enterBtnx = m_x + m_w - m_padding - btnWidth;
	int enterBtny = m_y + m_h - m_padding - btnHeight;
	int cancelBtnx = m_x + m_w - m_padding - btnWidth * 2 - 8;
	int cancelBtny = m_y + m_h - m_padding - btnHeight;
	m_enterBtn = new Button(enterBtnx, enterBtny, btnWidth, btnHeight);
	m_cancelBtn = new Button(cancelBtnx, cancelBtny, btnWidth, btnHeight);

	// ����Ϊ����ť
	m_enterBtn->setMessageBtn();
	m_cancelBtn->setMessageBtn();

	// INFOģʽ��
	m_text = L"�˲������ɻָ��������Ƿ����";

	// CONTENTģʽ��
	m_contentHorGap = 90;
	m_contentVerGap = 45;
}

Message::~Message()
{
}

void Message::showComponent(MBType mt)
{
	// switch���ǧ�������break������ͻᴮ��ִ��
	m_mt = mt;
	switch (mt)
	{
	case INFO:
		showInfo();
		break;
	case CONTENT:
		showContent();
		break;
	default:
		break;
	}
}

void Message::open(MBType mt)
{
	showComponent(mt);
	showComponent(mt);
}

void Message::showInfo()
{
	m_isShow = 1;

	// ���Ƶ���
	setlinecolor(m_bkColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_bkColor); // ����ͼ�ε������ɫ
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// ������Ӱ
	setlinecolor(RGB(205, 205, 205));
	roundrect(m_x - 1, m_y - 1, m_x + m_w + 1, m_y + m_h + 1, m_radius, m_radius);
	setlinecolor(RGB(216, 216, 216));
	roundrect(m_x - 2, m_y - 2, m_x + m_w + 2, m_y + m_h + 2, m_radius, m_radius);
	setlinecolor(RGB(225, 225, 225));
	roundrect(m_x - 3, m_y - 3, m_x + m_w + 3, m_y + m_h + 3, m_radius, m_radius);

	// ���ñ�����������
	setbkmode(TRANSPARENT);
	settextstyle(m_titleFontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	int titlex = m_x + m_padding;
	int titley = m_y + m_padding;
	outtextxy(titlex, titley, m_title.data());

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// ��ʾ�ı�
	settextstyle(m_fontSize, 0, NULL);
	int textx = m_x + m_padding;
	int texty = m_y + m_padding + textheight(m_title.data()) + m_titleVerGap;
	outtextxy(textx, texty, m_text.data());

	// ��ʾ��ť
	m_enterBtn->setFontSize(14);
	m_enterBtn->setText(L"ȷ��");
	m_cancelBtn->setFontSize(14);
	m_cancelBtn->setText(L"ȡ��");
	// ���á�ȡ������ť��ʽ
	m_cancelBtn->setBkColor(RGB(255, 255, 255));
	m_cancelBtn->setBorderColor(RGB(220, 223, 230));
	m_cancelBtn->setHoverBkColor(RGB(230, 240, 255));
	m_cancelBtn->setPressedBkColor(RGB(220, 230, 255));
	m_cancelBtn->setFontColor(RGB(0, 0, 0));

	m_enterBtn->show();
	m_cancelBtn->show();
}

void Message::showContent()
{
	m_isShow = 1;

	// ���Ƶ���
	setlinecolor(m_bkColor); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(m_bkColor); // ����ͼ�ε������ɫ
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, m_radius, m_radius);

	// ������Ӱ
	setlinecolor(RGB(205, 205, 205));
	roundrect(m_x - 1, m_y - 1, m_x + m_w + 1, m_y + m_h + 1, m_radius, m_radius);
	setlinecolor(RGB(216, 216, 216));
	roundrect(m_x - 2, m_y - 2, m_x + m_w + 2, m_y + m_h + 2, m_radius, m_radius);
	setlinecolor(RGB(225, 225, 225));
	roundrect(m_x - 3, m_y - 3, m_x + m_w + 3, m_y + m_h + 3, m_radius, m_radius);

	// ���ñ�����������
	setbkmode(TRANSPARENT);
	settextstyle(m_titleFontSize, 0, NULL);
	settextcolor(m_titleFontColor);
	setFontFamily(m_titleFontFamily);
	setFontWeight(m_fontWeight);

	// ��ʾ����
	int titlex = m_x + m_padding;
	int titley = m_y + m_padding;
	outtextxy(titlex, titley, m_title.data());

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);
	setFontWeight(m_fontWeight);

	// ��ʾ�ı���
	int textH = textheight(m_labelGroup[0].data()); // �����ı��߶�

	int labelx = m_x + m_padding;
	int labely = m_y + m_padding + textheight(m_title.data()) + m_titleVerGap; // �����ı��߶Ⱥ���������ļ��
	for (int i = 0; i < m_labelGroup.size(); i++)
	{
		outtextxy(labelx, labely, m_labelGroup[i].data());
		labely += textH + m_contentVerGap + 30;
	}
	// ��ʾ�������
	int inputx = m_x + m_padding + m_contentHorGap;
	int inputy = m_y + m_padding + textheight(m_title.data()) + m_titleVerGap; // ������ϱ��غ��ı��ϱ���ƽ�룬
	inputy -= (m_inputGroup[0]->height() - textH) / 2; // Ĭ����Ϊ�����߶ȴ������ָ߶ȣ�ʵ�����Ķ���
	for (int i = 0; i < m_inputGroup.size(); i++)
	{	
		m_inputGroup[i]->move(inputx, inputy);
		m_inputGroup[i]->show();
		inputy += textH + m_contentVerGap + 30; // Ҫ���ı���ļ�ౣ��һ�£��������ܶ���
	}

	// ��ʾ��ť
	m_enterBtn->setFontSize(14);
	m_enterBtn->setText(L"ȷ��");
	m_cancelBtn->setFontSize(14);
	m_cancelBtn->setText(L"ȡ��");
	// ���á�ȡ������ť��ʽ
	m_cancelBtn->setBkColor(RGB(255, 255, 255));
	m_cancelBtn->setBorderColor(RGB(220, 223, 230));
	m_cancelBtn->setHoverBkColor(RGB(230, 240, 255));
	m_cancelBtn->setPressedBkColor(RGB(220, 230, 255));
	m_cancelBtn->setFontColor(RGB(0, 0, 0));

	m_enterBtn->show();
	m_cancelBtn->show();
}

void Message::close()
{
	m_isShow = 0;
	clearrectangle(m_x - 3, m_y - 3, m_x + m_w + 3, m_y + m_h + 3);
}

void Message::setText(wstring text)
{
	m_text = text;
}

void Message::setTitle(wstring title)
{
	m_title = title;
}

int Message::isShow()
{
	return m_isShow;
}

int Message::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void Message::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);

		if (m_enterBtn->isOn(msg.x, msg.y))
		{
			m_enterBtn->eventLoop();
			break;
		}

		if (m_cancelBtn->isOn(msg.x, msg.y))
		{
			m_cancelBtn->eventLoop();
			break;
		}
		// CONTENTģʽ��Ҫ�������������¼�ѭ��
		if (m_mt == CONTENT)
		{
			for (int i = 0; i < m_inputGroup.size(); i++)
			{
				if (m_inputGroup[i]->isOn(msg.x,msg.y))
				{
					if (msg.message == WM_LBUTTONDOWN)
					{
						m_inputGroup[i]->eventLoop();
					}	
				}
			}
		}
	}
}

void Message::setTitleFontSize(int size)
{
	m_titleFontSize = size;
}

void Message::setTitleFontColor(COLORREF color)
{
	m_titleFontColor = color;
}

void Message::setTitleFontFamily(wstring fontFamily)
{
	m_titleFontFamily = fontFamily;
}

Button* Message::enterBtn()
{
	return m_enterBtn;
}

Button *Message::cancelBtn()
{
	return m_cancelBtn;
}

void Message::addLabel(wstring lab)
{
	m_labelGroup.push_back(lab);
}

void Message::addInput(Input *in)
{
	m_inputGroup.push_back(in);
}
