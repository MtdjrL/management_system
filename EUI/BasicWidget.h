#pragma once

#include <string>
#include <vector>
#include <easyx.h>

using namespace std;

class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	~BasicWidget();

	int width();
	int height();
	int x();
	int y();
	void setFontColor(COLORREF color);
	void setFontSize(int size);
	void setFontFamily(wstring fontFamily);
	void setFontWeight(int weight);
	virtual void show(); // Ϊ��������ʾ��ʹ�øú�������ʾ���������������

protected:
	virtual void showComponent(); // ��ʾ���

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	LOGFONT m_logfont; // �������ԵĽṹ��
	int m_fontSize;
	int m_fontWeight;
	COLORREF m_fontColor;
	wstring m_fontFamily;
};

