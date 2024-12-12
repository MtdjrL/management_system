#pragma once

#include "BasicWidget.h"
#include "Toast.h"

class Button : public BasicWidget
{
public:
	Button(int x, int y, int w, int h);
	~Button();

	void setText(wstring text);
	void setRadius(int radius);
	void setBkColor(COLORREF color);
	void setHoverBkColor(COLORREF color);
	void setPressedBkColor(COLORREF color);
	void setBorderColor(COLORREF color);
	void bindOnClick(void (*func)()); // 绑定点击事件
	void show();
	int isOn(int x,int y); // 鼠标是否悬浮在控件区域
	void eventLoop(); // 事件循环监听
	
	void setMessageBtn(); // 设置为弹框按钮

protected:
	void updateBkColor();
	void updateHoverBkColor();
	void updatePressedBkColor();
	void showComponent();

private:
	wstring m_text;	
	COLORREF m_bkColor;
	COLORREF m_hoverBkColor;
	COLORREF m_pressedBkColor;
	COLORREF m_fillColor; // 将要填充的颜色
	COLORREF m_borderColor; 
	int m_radius; // 圆角半径
	int m_isMessageBtn; // 是否为弹框按钮，因为弹框按钮在事件循环中需要进行特殊处理
	void (*m_func)();	// 函数指针，按钮点击事件
};

