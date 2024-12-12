#pragma once

#include "BasicWidget.h"

#define MAX_ROW 100 // �������
#define MAX_COL 10 // �������
#define MAX_TEXT_LEN 20 // ����ı�����

// ��ͷ���ݣ�һ����
typedef struct {
	wchar_t header[MAX_COL];
}headerList; 

// ������ݣ�һ����
typedef struct {
	wchar_t col[MAX_COL][MAX_TEXT_LEN];
}tableList;

class Table : public BasicWidget
{
public:
	Table(int x, int y, int w,int row, int col);
	~Table();

	void setGridWidth(int *arrWidth);
	void setGridHeight(int height);
	tableList* tableListCont(); // ��ȡ�б�����ָ��,Cont��Container����д
	void show(headerList hl[]);

protected:
	void setTextBold(); // ��������Ӵ�
	void setTextNormal(); // ��������Ϊ�����ϸ
	void drawTableGrid();
	void drawTableText(headerList hl[]);
	void showComponent(headerList hl[]);

private:
	int m_rows;
	int m_cols; 
	int m_gridH;
	int *m_gridW; // �����¼���еĿ��ռ��
	int m_spacing; // �ı�����ļ��
	tableList m_tl[MAX_ROW]; // �б����ݣ�����ṹ�������
};

