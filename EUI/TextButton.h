#pragma once

#include "BasicWidget.h"

class TextButton : public BasicWidget
{
public:
	TextButton(int x, int y, int w, int h);
	~TextButton();

	void setText(wstring text);
	void setBkColor(COLORREF color);
	void setFontPressedColor(COLORREF color);
	void bindOnClick(void (*func)()); // 绑定点击事件
	void show();
	int isOn(int x, int y); // 鼠标是否悬浮在控件区域
	void eventLoop(); // 事件循环监听
	
protected:
	void updateFontColor(); 
	void updateFontPressedColor();
	void showComponent();

private:
	wstring m_text; 
	COLORREF m_bkColor; // 由于要使用背景色刷新覆盖，所以需要设置背景色
	COLORREF m_fontPressedColor;
	COLORREF m_fillColor; // 将要填充的颜色
	void (*m_func)(); // 函数指针，按钮点击事件
};