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
	void bindOnClick(void (*func)()); // �󶨵���¼�

	void updateStyle();
	void updateLeaveBkColor();
	void setGap(int gap);
	int isPressed(); // �Ƿ�ѡ��
	void toIsNotPressed(); // �޸�ѡ��״̬Ϊ0
	void move(int x, int y);
	void show();
	int isOn(int x, int y); // ����Ƿ������ڿؼ�����
	void eventLoop(); // �¼�ѭ������

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
	COLORREF m_fillColor; // ��Ҫ������ɫ
	void (*m_func)();	// ����ָ�룬��ť����¼�
	int m_isPressed; // �Ƿ񱻵��
	int m_textGap; // �ı��밴ť���ļ��
};

