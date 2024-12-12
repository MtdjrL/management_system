#pragma once

#include "BasicWidget.h"
#include <iostream>

// 提示框类型
enum InfoType
{
	SUCCESS = 0,
	WARNING
};

class Toast : public BasicWidget
{
public:
	Toast(int winWidth,int y,int w,int h);
	~Toast();

	void setText(wstring text);
	void show(InfoType it);

protected:
	void showComponent();
	void showToast();
	void setSuccStyle();
	void setWarnStyle();

private:
	wstring m_text;
	int m_radius;
	COLORREF m_bkColor;
};

