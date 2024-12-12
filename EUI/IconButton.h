#pragma once

#include "BasicWidget.h"
#pragma comment(lib,"MSIMG32.LIB") // 透明贴图 

class IconButton : public BasicWidget
{
public:
	IconButton(int x, int y, int w, int h);
	~IconButton();

	void setIcon(IMAGE icon, IMAGE iconPressed);
	void bindOnClick(void (*func)()); // 绑定点击事件
	void show();
	int isOn(int x, int y); // 鼠标是否悬浮在控件区域
	void eventLoop(); // 事件循环监听

protected:
	void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg); // 透明输出
	void updateStyle();
	void updatePressedStyle();
	void showComponent();

private:
	COLORREF m_bkColor;
	IMAGE m_icon; 
	IMAGE m_iconPressed; 
	void (*m_func)(); // 函数指针，按钮点击事件
};

