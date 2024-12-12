#pragma once

#include "BasicWidget.h"
#pragma comment(lib,"MSIMG32.LIB") // ͸����ͼ 

class IconButton : public BasicWidget
{
public:
	IconButton(int x, int y, int w, int h);
	~IconButton();

	void setIcon(IMAGE icon, IMAGE iconPressed);
	void bindOnClick(void (*func)()); // �󶨵���¼�
	void show();
	int isOn(int x, int y); // ����Ƿ������ڿؼ�����
	void eventLoop(); // �¼�ѭ������

protected:
	void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg); // ͸�����
	void updateStyle();
	void updatePressedStyle();
	void showComponent();

private:
	COLORREF m_bkColor;
	IMAGE m_icon; 
	IMAGE m_iconPressed; 
	void (*m_func)(); // ����ָ�룬��ť����¼�
};

