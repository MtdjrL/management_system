#pragma once

#include "BasicWidget.h"
#include "Button.h"
#include "Input.h"

enum MBType {
	INFO = 0, // ȷ����Ϣ
	CONTENT // �ύ����
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
	int isShow(); // �жϵ����Ƿ�Ϊ��ʾ״̬
	Button* enterBtn();
	Button* cancelBtn();
	void addLabel(wstring lab);
	void addInput(Input* in);
	void open(MBType mt);
	void close();
	int isOn(int x, int y); // ����Ƿ������ڿؼ�����
	void eventLoop();

	void showInfo(); // չʾȷ����Ϣ����
	void showContent(); // չʾ�ύ���ݵ���

protected:
	void showComponent(MBType mt);

private:
	MBType m_mt;
	int m_radius;
	wstring m_title;
	int m_titleFontSize;
	COLORREF m_titleFontColor;
	wstring m_titleFontFamily;
	int m_padding; // �ڱ߾�
	int m_titleVerGap; // ���������ݵĴ�ֱ���
	COLORREF m_bkColor;
	Button *m_enterBtn;
	Button *m_cancelBtn;
	int m_isShow;

	// INFOģʽ��
	wstring m_text;

	// CONTENTģʽ��
	vector<wstring> m_labelGroup; // �ı��飨�����ǰ�������ı����������һһ��Ӧ��
	vector<Input*> m_inputGroup; // �������
	int m_contentHorGap; // ����֮���ˮƽ���
	int m_contentVerGap; // ����֮��Ĵ�ֱ���





};

