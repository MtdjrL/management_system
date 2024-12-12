#pragma once

#include "BasicWidget.h"

class NavButton : public BasicWidget
{
public:
	NavButton(int w, int h);
	~NavButton();

	void setText(wstring text);
	void setBkColor(COLORREF color);
	void setHoverBkColor(COLORREF color);
	void setPressedTextColor(COLORREF color);
	void bindOnClick(void (*func)()); // 绑定点击事件

	void updateStyle();
	void updateLeaveBkColor();
	void setGap(int gap);
	int isPressed(); // 是否被选中
	void toIsNotPressed(); // 修改选中状态为0
	void move(int x, int y);
	void show();
	int isOn(int x, int y); // 鼠标是否悬浮在控件区域
	void eventLoop(); // 事件循环监听

protected:
	void updateHoverBkColor();
	void updatePressedTextColor();
	void showComponent();

private:
	wstring m_text;
	COLORREF m_pressedFontColor;
	COLORREF m_fillFontColor;
	COLORREF m_bkColor;
	COLORREF m_hoverBkColor;
	COLORREF m_pressedBkColor;
	COLORREF m_fillColor; // 将要填充的颜色
	void (*m_func)();	// 函数指针，按钮点击事件
	int m_isPressed; // 是否被点击
	int m_textGap; // 文本与按钮左侧的间距
};

