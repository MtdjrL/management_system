#pragma once

#include "BasicWidget.h"

#define CUR_RATE 0.5 // 光标高度占输入框高度的比率 

class Input : public BasicWidget
{
public:
	Input(int x, int y, int w, int h);
	~Input();

	wchar_t* text();
	void setMaxLen(int len);
	void setPassword(int isPassword);
	void setHolderText(wstring text);
	void show();
	int isOn(int x, int y); // 鼠标是否悬浮在控件区域
	void eventLoop(); // 事件循环监听

	void move(int x,int y);

protected:
	void updateBorderColor();
	void updateHoverBorderColor();
	void updatePressedBorderColor();
	void showComponent();

private:
	wchar_t *m_text;
	wstring m_holderText;
	wchar_t *m_password; // 用于输出展示隐藏的密码
	int m_maxLen; // 最大输入长度
	COLORREF m_bkColor;
	COLORREF m_borderColor;
	COLORREF m_hoverBorderColor;
	COLORREF m_pressedBorderColor;
	COLORREF m_fillColor; // 将要填充的颜色
	int m_radius;
	int m_isPassword;
};

