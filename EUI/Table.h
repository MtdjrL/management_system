#pragma once

#include "BasicWidget.h"

#define MAX_ROW 100 // 最大行数
#define MAX_COL 10 // 最大列数
#define MAX_TEXT_LEN 20 // 最大文本长度

// 表头数据（一条）
typedef struct {
	wchar_t header[MAX_COL];
}headerList; 

// 表格数据（一条）
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
	tableList* tableListCont(); // 获取列表数据指针,Cont是Container的缩写
	void show(headerList hl[]);

protected:
	void setTextBold(); // 设置字体加粗
	void setTextNormal(); // 设置字体为常规粗细
	void drawTableGrid();
	void drawTableText(headerList hl[]);
	void showComponent(headerList hl[]);

private:
	int m_rows;
	int m_cols; 
	int m_gridH;
	int *m_gridW; // 数组记录各列的宽度占比
	int m_spacing; // 文本与表格的间距
	tableList m_tl[MAX_ROW]; // 列表数据，传入结构体的容器
};

