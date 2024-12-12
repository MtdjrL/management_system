#pragma once

#include "BasicWidget.h"
#include "NavButton.h"

class Navbar : public BasicWidget
{
public:
	Navbar(int x, int y, int w, int h);
	~Navbar();

	void setTitleText(wstring text);
	void setTitleFontColor(COLORREF color);
	void setTitleFontSize(int size);
	void setTitleFontFamily(wstring fontFamily);
	void setTitleFontWeight(int weight);
	void setHeaderHeight(int h);
	void setGap(int gap);
	void setBkColor(COLORREF color);
	void addNavButton(NavButton* btn);
	void show();
	int isOn(int x, int y);
	void eventLoop();

protected:
	void showComponent();

private:
	int m_headerHeight;
	wstring m_titleText;
	int m_titleFontSize;
	COLORREF m_titleFontColor;
	wstring m_titleFontFamily;
	int m_titleFontWeight;
	COLORREF m_bkColor;
	vector<NavButton*> m_navButtonGroup;
	
	
};

