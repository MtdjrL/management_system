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
	virtual void show(); // 为了正常显示，使用该函数将显示组件函数调用两次

protected:
	virtual void showComponent(); // 显示组件

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	LOGFONT m_logfont; // 字体属性的结构体
	int m_fontSize;
	int m_fontWeight;
	COLORREF m_fontColor;
	wstring m_fontFamily;
};

