#include "Table.h"

Table::Table(int x, int y, int w,int row, int col)
	:BasicWidget(x,y,w,0),
	m_rows(row),m_cols(col)
{
	m_gridH = 50;
	m_spacing = 20;
	m_fontSize = 16;
	m_fontColor = RGB(0, 0, 0);
	m_fontFamily = L"宋体";
}

Table::~Table()
{
}

void Table::setGridWidth(int *arrWidth)
{
	m_gridW = arrWidth;
}

void Table::setGridHeight(int height)
{
	m_gridH = height;
}

void Table::showComponent(headerList hl[])
{
	drawTableGrid();
	drawTableText(hl);
}

void Table::show(headerList hl[])
{
	showComponent(hl);
	showComponent(hl);
}

void Table::drawTableGrid()
{
	setlinecolor(RGB(223, 230, 236));

	// 绘制横线
	for (int i = 0; i <= m_rows + 1; i++) // 加表头
	{
		int posy = m_y + m_gridH * i;
		line(m_x, posy, m_x + m_w, posy);
	}

	m_h = (m_rows + 1) * m_gridH; // 加表头

	// 绘制竖线
	int posx = m_x;
	line(m_x, m_y, m_x, m_y + m_h); // 绘制第一条
	for (int i = 0; i < m_cols; i++)
	{
		posx = posx + m_w * 0.01 * m_gridW[i]; // 将其转换为百分比，所以乘0.01
		line(posx, m_y, posx, m_y + m_h);
	}
}

void Table::drawTableText(headerList hl[])
{
	// 设置文字属性
	setbkmode(TRANSPARENT);
	settextstyle(m_fontSize, 0, NULL);
	settextcolor(m_fontColor);
	setFontFamily(m_fontFamily);

	// 设置表头文字加粗
	setTextBold(); 

	// 表头内容
	int posx = m_x + m_spacing;
	int posy = m_y + (m_gridH - textheight(hl[0].header)) / 2;
	for (int i = 0; i < m_cols; i++)
	{
		outtextxy(posx, posy, hl[i].header);
		posx += m_w * m_gridW[i] * 0.01;
	}

	// 设置表内容文字常规
	setTextNormal();

	// 表格内容
	posx = m_x + m_spacing;
	posy = m_y + m_gridH + (m_gridH - textheight(hl[0].header)) / 2;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			outtextxy(posx, posy, m_tl[i].col[j]);
			posx += m_w * m_gridW[j] * 0.01;
		}
		posx = m_x + m_spacing;
		posy += m_gridH;
	}
}

tableList* Table::tableListCont()
{
	return m_tl;
}

void Table::setTextBold()
{
	gettextstyle(&m_logfont);						// 获取当前字体设置
	m_logfont.lfWeight = FW_BOLD;
	settextstyle(&m_logfont);
}

void Table::setTextNormal()
{
	gettextstyle(&m_logfont);						// 获取当前字体设置
	m_logfont.lfWeight = FW_NORMAL;
	settextstyle(&m_logfont);
}
