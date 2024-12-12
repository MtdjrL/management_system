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
	void bindOnClick(void (*func)()); // �󶨵���¼�
	void show();
	int isOn(int x,int y); // ����Ƿ������ڿؼ�����
	void eventLoop(); // �¼�ѭ������
	
	void setMessageBtn(); // ����Ϊ����ť

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
	COLORREF m_fillColor; // ��Ҫ������ɫ
	COLORREF m_borderColor; 
	int m_radius; // Բ�ǰ뾶
	int m_isMessageBtn; // �Ƿ�Ϊ����ť����Ϊ����ť���¼�ѭ������Ҫ�������⴦��
	void (*m_func)();	// ����ָ�룬��ť����¼�
};

