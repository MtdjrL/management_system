#include "Navbar.h"

Navbar::Navbar(int x, int y, int w, int h)
	: BasicWidget(x,y,w,h)
{
	m_headerHeight = 70;
	m_titleText = L"������";
	m_titleFontSize = 18;
	m_titleFontColor = RGB(255, 255, 255);
	m_titleFontFamily = L"����";
	m_titleFontWeight = FW_NORMAL;
	m_bkColor = RGB(48, 65, 86);
}

Navbar::~Navbar()
{
}

void Navbar::setHeaderHeight(int h)
{
	m_headerHeight = h;
}


void Navbar::setGap(int gap)
{
	for (int i = 0; i < m_navButtonGroup.size(); i++)
	{
		m_navButtonGroup[i]->setGap(gap);
	}
}

void Navbar::setBkColor(COLORREF color)
{
	m_bkColor = color;
}

void Navbar::setTitleText(wstring text)
{
	m_titleText = text;
}

void Navbar::setTitleFontColor(COLORREF color)
{
	m_titleFontColor = color;
}

void Navbar::setTitleFontSize(int size)
{
	m_titleFontSize = size;
}


void Navbar::setTitleFontFamily(wstring fontFamily)
{
	m_titleFontFamily = fontFamily;
	gettextstyle(&m_logfont); // ��ȡ��ǰ��������
	_tcscpy_s(m_logfont.lfFaceName, m_titleFontFamily.data()); // ��������
	m_logfont.lfQuality = ANTIALIASED_QUALITY; // �������Ч��Ϊ�����  
	settextstyle(&m_logfont); // ����������ʽ
}

void Navbar::setTitleFontWeight(int weight)
{
	m_titleFontWeight = weight;
	gettextstyle(&m_logfont); // ��ȡ��ǰ��������
	m_logfont.lfWeight = m_fontWeight; // �������ִ�ϸ
	m_logfont.lfQuality = ANTIALIASED_QUALITY; // �������Ч��Ϊ�����  
	settextstyle(&m_logfont);
}

void Navbar::addNavButton(NavButton *btn)
{
	m_navButtonGroup.push_back(btn);
}

int Navbar::isOn(int x, int y)
{
	return (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h);
}

void Navbar::eventLoop()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (isOn(msg.x, msg.y)) // �������
		{
			for (int i = 0; i < m_navButtonGroup.size(); i++)
			{
				if (m_navButtonGroup[i]->isOn(msg.x, msg.y))
				{
					m_navButtonGroup[i]->eventLoop();
					if (m_navButtonGroup[i]->isPressed())
					{
						for (int j = 0; j < m_navButtonGroup.size(); j++)
						{
							if (j != i)
							{
								m_navButtonGroup[j]->toIsNotPressed();
								m_navButtonGroup[j]->updateStyle();	
							}
						}
						
					}
				}
			}
		}
		else // ��������
		{
			break;
		}
	}
}

void Navbar::showComponent()
{
	// ���Ƶ�����ͼ��
	setlinecolor(m_bkColor);
	setfillcolor(m_bkColor);
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	// ������������
	setbkmode(TRANSPARENT);
	settextstyle(m_titleFontSize, 0, NULL);
	settextcolor(m_titleFontColor);
	setTitleFontFamily(m_titleFontFamily);
	setTitleFontWeight(m_titleFontWeight);

	// ������ʾ�ı�
	int textPosx = m_x + (m_w - textwidth(m_titleText.data())) / 2;
	int textPosy = m_y + (m_headerHeight - textheight(m_titleText.data())) / 2;
	
	outtextxy(textPosx, textPosy, m_titleText.data());

	int posx = m_x;
	int posy = m_y + m_headerHeight;
	// �趨������ťλ�ò���ʾ��ť
	for (int i = 0; i < m_navButtonGroup.size(); i++)
	{
		m_navButtonGroup[i]->move(posx, posy);
		posy += m_navButtonGroup[i]->height();
		m_navButtonGroup[i]->show();
	}
}

void Navbar::show()
{
	showComponent();
}
