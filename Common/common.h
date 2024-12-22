#pragma once

#include <stdlib.h>
#include "EUI/EUI.h"

#define WIN_WIDTH 1366 // ���ڿ��
#define WIN_HEIGHT 768 // ���ڸ߶�
#define NAV_WIDTH 200 // ���������
#define NAV_BUTTON_HEIGHT 50 // ��������ť�߶�

#define MAX_STU 100 // ���ѧ������
#define MAX_TEA 50 // ����û�����
#define TEXT_LEN 30 // ����ı�����
#define MAX_COL 10 // ����������

// ѧ��
typedef struct student {
	int id; // ����
	wchar_t account[TEXT_LEN]; // �˺�
	wchar_t password[TEXT_LEN]; // ����
	wchar_t name[TEXT_LEN]; // ����
	wchar_t classs[TEXT_LEN]; // �༶
	wchar_t stu_id[TEXT_LEN]; // ѧ��
	wchar_t calculus[TEXT_LEN]; // ΢����
	wchar_t martix[TEXT_LEN]; // ���Դ���
	wchar_t c_c[TEXT_LEN]; // �������
}Student;

// ��ʦ
typedef struct teacher {
	wchar_t account[TEXT_LEN]; // �˺�
	wchar_t password[TEXT_LEN]; // ����
}Teacher;


// ��Ļˢ������
enum RefreshArea {
	AccountArea, // �˺�����
	NavbarMatchArea, // ��������Ӧ����
	TableArea, // �б�����
	LeftTop // ���Ͻ�
};

// �б�����
enum TableType {
	StuTable, // ͼ���б�
};


void refresh(enum RefreshArea area); // ��Ļˢ��

void initData(); // ���ݳ�ʼ��

void initStuData(); // ѧ�����ݳ�ʼ��

void initTeacherData(); // ��ʦ���ݳ�ʼ��


void initCode(); // ��֤���ʼ��

void mappingTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl); // ӳ���б�����

void clearTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl); // ����б�����

void setTableHeader(enum TableType type, headerList* hl); // �����б��ͷ

void writeFile(); // ������д���ļ�

void readFile(); // ���ļ���������