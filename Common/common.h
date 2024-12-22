#pragma once

#include <stdlib.h>
#include "EUI/EUI.h"

#define WIN_WIDTH 1366 // 窗口宽度
#define WIN_HEIGHT 768 // 窗口高度
#define NAV_WIDTH 200 // 导航栏宽度
#define NAV_BUTTON_HEIGHT 50 // 导航栏按钮高度

#define MAX_STU 100 // 最大学生数量
#define MAX_TEA 50 // 最大用户数量
#define TEXT_LEN 30 // 最大文本长度
#define MAX_COL 10 // 表格最大列数

// 学生
typedef struct student {
	int id; // 自增
	wchar_t account[TEXT_LEN]; // 账号
	wchar_t password[TEXT_LEN]; // 密码
	wchar_t name[TEXT_LEN]; // 姓名
	wchar_t classs[TEXT_LEN]; // 班级
	wchar_t stu_id[TEXT_LEN]; // 学号
	wchar_t calculus[TEXT_LEN]; // 微积分
	wchar_t martix[TEXT_LEN]; // 线性代数
	wchar_t c_c[TEXT_LEN]; // 程序设计
}Student;

// 老师
typedef struct teacher {
	wchar_t account[TEXT_LEN]; // 账号
	wchar_t password[TEXT_LEN]; // 密码
}Teacher;


// 屏幕刷新区域
enum RefreshArea {
	AccountArea, // 账号区域
	NavbarMatchArea, // 导航栏对应区域
	TableArea, // 列表区域
	LeftTop // 左上角
};

// 列表类型
enum TableType {
	StuTable, // 图书列表
};


void refresh(enum RefreshArea area); // 屏幕刷新

void initData(); // 数据初始化

void initStuData(); // 学生数据初始化

void initTeacherData(); // 教师数据初始化


void initCode(); // 验证码初始化

void mappingTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl); // 映射列表数据

void clearTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl); // 清空列表数据

void setTableHeader(enum TableType type, headerList* hl); // 设置列表表头

void writeFile(); // 将数据写入文件

void readFile(); // 从文件读入数据