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
	void bindOnClick(void (*func)()); // �󶨵���¼�
	void show();
	int isOn(int x, int y); // ����Ƿ������ڿؼ�����
	void eventLoop(); // �¼�ѭ������
	
protected:
	void updateFontColor(); 
	void updateFontPressedColor();
	void showComponent();

private:
	wstring m_text; 
	COLORREF m_bkColor; // ����Ҫʹ�ñ���ɫˢ�¸��ǣ�������Ҫ���ñ���ɫ
	COLORREF m_fontPressedColor;
	COLORREF m_fillColor; // ��Ҫ������ɫ
	void (*m_func)(); // ����ָ�룬��ť����¼�
};