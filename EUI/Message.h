#pragma once

#include "BasicWidget.h"
#include "Button.h"
#include "Input.h"

enum MBType {
	INFO = 0, // 确认消息
	CONTENT // 提交内容
};

class Message : public BasicWidget
{
public:
	Message(int winWidth, int winHeight, int w, int h);
	~Message();

	void setTitle(wstring title);
	void setText(wstring text);
	void setTitleFontSize(int size);
	void setTitleFontColor(COLORREF color);
	void setTitleFontFamily(wstring fontFamily);
	int isShow(); // 判断弹框是否为显示状态
	Button* enterBtn();
	Button* cancelBtn();
	void addLabel(wstring lab);
	void addInput(Input* in);
	void open(MBType mt);
	void close();
	int isOn(int x, int y); // 鼠标是否悬浮在控件区域
	void eventLoop();

	void showInfo(); // 展示确认消息弹框
	void showContent(); // 展示提交内容弹框

protected:
	void showComponent(MBType mt);

private:
	MBType m_mt;
	int m_radius;
	wstring m_title;
	int m_titleFontSize;
	COLORREF m_titleFontColor;
	wstring m_titleFontFamily;
	int m_padding; // 内边距
	int m_titleVerGap; // 标题与内容的垂直间距
	COLORREF m_bkColor;
	Button *m_enterBtn;
	Button *m_cancelBtn;
	int m_isShow;

	// INFO模式下
	wstring m_text;

	// CONTENT模式下
	vector<wstring> m_labelGroup; // 文本组（输入框前的描述文本，与输入框一一对应）
	vector<Input*> m_inputGroup; // 输入框组
	int m_contentHorGap; // 内容之间的水平间距
	int m_contentVerGap; // 内容之间的垂直间距





};

