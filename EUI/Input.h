#pragma once

#include "BasicWidget.h"

#define CUR_RATE 0.5 // ���߶�ռ�����߶ȵı��� 

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
	int isOn(int x, int y); // ����Ƿ������ڿؼ�����
	void eventLoop(); // �¼�ѭ������

	void move(int x,int y);

protected:
	void updateBorderColor();
	void updateHoverBorderColor();
	void updatePressedBorderColor();
	void showComponent();

private:
	wchar_t *m_text;
	wstring m_holderText;
	wchar_t *m_password; // �������չʾ���ص�����
	int m_maxLen; // ������볤��
	COLORREF m_bkColor;
	COLORREF m_borderColor;
	COLORREF m_hoverBorderColor;
	COLORREF m_pressedBorderColor;
	COLORREF m_fillColor; // ��Ҫ������ɫ
	int m_radius;
	int m_isPassword;
};

