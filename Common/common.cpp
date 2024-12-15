#include "common.h"

// ������
int navbar_posx = 0;
int navbar_posy = 0;

// ����ʾ��
int toast_width = 350;
int toast_height = 50;
int toast_posy = 30;

Toast toast(WIN_WIDTH, toast_posy, toast_width, toast_height);

// ѧ��
Student stu[MAX_STU];

// ��ʦ
Teacher teacher;


int stu_num = 6; // ѧ������


int cur_stu_id = 0; // ��ǰѧ��id����Ϊ����������Ҫ��¼

int login_stu_id = 0; // ��¼��ѧ��id

wchar_t teacher_code[TEXT_LEN]; // ��ʦ��֤��
wchar_t stu_code[TEXT_LEN]; // ѧ����֤��


// ˢ����Ļ
void refresh(enum RefreshArea area)
{
	COLORREF color = 0xffffff; // ���û�ˢ��ɫΪ��ɫ���ð�ɫ��ˢ�½���
	// ��������
	int startx = 0;
	int starty = 0;
	int endx = 0;
	int endy = 0;

	switch (area)
	{
	case AccountArea:
		startx = 480;
		starty = 280;
		endx = 1100;
		endy = 600;
		break;
	case NavbarMatchArea:
		startx = NAV_WIDTH + 1;
		starty = 0;
		endx = WIN_WIDTH;
		endy = WIN_HEIGHT;
		break;
	case TableArea:
		startx = 210;
		starty = 110;
		endx = 1350;
		endy = 750;
		break;
	case LeftTop:
		startx = 0;
		starty = 0;
		endx = 50;
		endy = 50;
	}
	setlinecolor(color); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(color); // ����ͼ�ε������ɫ
	fillrectangle(startx, starty, endx, endy);
}

// ���ݳ�ʼ��
void initData()
{
	initStuData(); // ѧ�����ݳ�ʼ��
	initTeacherData(); // ��ʦ���ݳ�ʼ��
	initCode(); // ��֤���ʼ��
}

// ѧ�����ݳ�ʼ��
void initStuData()
{
	// ѧ����ʼ����
	stu[0].id = cur_stu_id++;
	wcscpy_s(stu[0].account, L"2024990901001@UESTG"); // �˺�
	wcscpy_s(stu[0].password, L"901001"); // �˺�
	wcscpy_s(stu[0].name, L"����"); // ����
	wcscpy_s(stu[0].classs, L"2024990901"); // �༶
	wcscpy_s(stu[0].stu_id, L"2024990901001"); // ѧ��
	wcscpy_s(stu[0].calculus, L"98"); // ΢����
	wcscpy_s(stu[0].martix, L"100"); // ���Դ�����ռ��������
	wcscpy_s(stu[0].c_c, L"99"); // �������

	stu[1].id = cur_stu_id++;
	wcscpy_s(stu[1].account, L"2024990901002@UESTG"); // �˺�
	wcscpy_s(stu[1].password, L"901002"); // �˺�
	wcscpy_s(stu[1].name, L"����"); // ����
	wcscpy_s(stu[1].classs, L"2024990901"); // �༶
	wcscpy_s(stu[1].stu_id, L"2024990901002"); // ѧ��
	wcscpy_s(stu[1].calculus, L"75"); // ΢����
	wcscpy_s(stu[1].martix, L"85"); // ���Դ�����ռ��������
	wcscpy_s(stu[1].c_c, L"100"); // �������

	stu[2].id = cur_stu_id++;
	wcscpy_s(stu[2].account, L"2024990902001@UESTG"); // �˺�
	wcscpy_s(stu[2].password, L"902001"); // �˺�
	wcscpy_s(stu[2].name, L"��������"); // ����
	wcscpy_s(stu[2].classs, L"2024990902"); // �༶
	wcscpy_s(stu[2].stu_id, L"2024990902001"); // ѧ��
	wcscpy_s(stu[2].calculus, L"98"); // ΢����
	wcscpy_s(stu[2].martix, L"100"); // ���Դ�����ռ��������
	wcscpy_s(stu[2].c_c, L"99"); // �������

	stu[3].id = cur_stu_id++;
	wcscpy_s(stu[3].account, L"2024990902002@UESTG"); // �˺�
	wcscpy_s(stu[3].password, L"902002"); // �˺�
	wcscpy_s(stu[3].name, L"���"); // ����
	wcscpy_s(stu[3].classs, L"2024990902"); // �༶
	wcscpy_s(stu[3].stu_id, L"2024990902002"); // ѧ��
	wcscpy_s(stu[3].calculus, L"98"); // ΢����
	wcscpy_s(stu[3].martix, L"100"); // ���Դ�����ռ��������
	wcscpy_s(stu[3].c_c, L"99"); // �������

	stu[4].id = cur_stu_id++;
	wcscpy_s(stu[4].account, L"2024990903001@UESTG"); // �˺�
	wcscpy_s(stu[4].password, L"903001"); // �˺�
	wcscpy_s(stu[4].name, L"������"); // ����
	wcscpy_s(stu[4].classs, L"2024990903"); // �༶
	wcscpy_s(stu[4].stu_id, L"2024990903001"); // ѧ��
	wcscpy_s(stu[4].calculus, L"75"); // ΢����
	wcscpy_s(stu[4].martix, L"75"); // ���Դ�����ռ��������
	wcscpy_s(stu[4].c_c, L"60"); // �������

	stu[5].id = cur_stu_id++;
	wcscpy_s(stu[5].account, L"2024990903002@UESTG"); // �˺�
	wcscpy_s(stu[5].password, L"903002"); // �˺�
	wcscpy_s(stu[5].name, L"����"); // ����
	wcscpy_s(stu[5].classs, L"2024990903"); // �༶
	wcscpy_s(stu[5].stu_id, L"2024990903002"); // ѧ��
	wcscpy_s(stu[5].calculus, L"100"); // ΢����
	wcscpy_s(stu[5].martix, L"100"); // ���Դ�����ռ��������
	wcscpy_s(stu[5].c_c, L"100"); // �������
}

// ��ʦ���ݳ�ʼ��
void initTeacherData()
{
	// ��ʦ��ʼ����
	wcscpy_s(teacher.account, L"Teacher");
	wcscpy_s(teacher.password, L"998244353");
}


// ��֤���ʼ��
void initCode()
{
	// ��֤���ʼ����
	wcscpy_s(teacher_code, L"123321"); // ��ʦ��֤��
	wcscpy_s(stu_code, L"789987"); // ѧ����֤��
}

// ӳ���б�����
void mappingTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl)
{
	tableList* stu_tl = tb->tableListCont(); // ��ȡ�б�����ָ��
	// ���б�����һ��һӳ�䵽tableList��
	for (int i = 0; i < stu_num; i++)
	{
		// ������������ӳ��
		if (mapping[i] == 0)
		{
			continue;
		}
		// ����������Ҫӳ��
		else
		{
			wcscpy_s(stu_tl->col[0], stu[i].stu_id);
			wcscpy_s(stu_tl->col[1], stu[i].name);
			wcscpy_s(stu_tl->col[2], stu[i].classs);
			wcscpy_s(stu_tl->col[3], stu[i].calculus);
			wcscpy_s(stu_tl->col[4], stu[i].martix);
			wcscpy_s(stu_tl->col[5], stu[i].c_c);

			stu_tl++;
		}
	}
	tb->show(hl);
	clearTableData(mapping, col, tb, hl); // ����б�����
}

// ����б�����
void clearTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl)
{
	tableList* book_tl = tb->tableListCont(); // ��ȡ�б�����ָ��
	// �������
	for (int i = 0; i < stu_num; i++)
	{
		// ָ������ı�
		if (mapping[i] == 0)
		{
			continue;
		}
		// ��ղ���������ָ�������
		else
		{
			for (int j = 0; j < col; j++)
			{
				book_tl->col[j][0] = 0;
			}
			book_tl++;
		}
	}
}

// �����б��ͷ
void setTableHeader(enum TableType type, headerList* hl)
{
	switch (type)
	{
	case StuTable:
		wcscpy_s(hl[0].header, L"ѧ��");
		wcscpy_s(hl[1].header, L"����");
		wcscpy_s(hl[2].header, L"�༶");
		wcscpy_s(hl[3].header, L"΢����");
		wcscpy_s(hl[4].header, L"�ߴ�");
		wcscpy_s(hl[5].header, L"����");
		break;
	}
}

// ������д���ļ�
void writeFile()
{
	FILE* fp; // �ļ�ָ��
	fopen_s(&fp, "data.dat", "wb");

	if (fp == NULL)
	{
		return;
	}

	fwrite(&stu_num, sizeof(int), 1, fp); // ѧ������
	fwrite(&cur_stu_id, sizeof(int), 1, fp); // ��ǰѧ��id
	fwrite(teacher_code, sizeof(wchar_t), wcslen(teacher_code), fp); // ��ʦ��֤��
	fwrite(stu_code, sizeof(wchar_t), wcslen(stu_code), fp); // ѧ����֤��

	// ѧ��
	for (int i = 0; i < stu_num; i++)
	{
		fwrite(&stu[i], sizeof(Student), 1, fp);
	}

	// ��ʦ
	fwrite(&teacher, sizeof(Teacher), 1, fp);


	fclose(fp);
}

// ���ļ���������
void readFile()
{
	FILE* fp; // �ļ�ָ��
	fopen_s(&fp, "data.dat", "rb");

	if (fp == NULL)
	{
		return;
	}

	fread(&stu_num, sizeof(int), 1, fp); // ѧ������
	fread(&cur_stu_id, sizeof(int), 1, fp); // ��ǰѧ��id
	fread(teacher_code, sizeof(wchar_t), wcslen(teacher_code), fp); // ��ʦ��֤��
	fread(stu_code, sizeof(wchar_t), wcslen(stu_code), fp); // ѧ����֤��

	// ѧ��
	for (int i = 0; i < stu_num; i++)
	{
		fread(&stu[i], sizeof(Student), 1, fp);
	}

	// ��ʦ
	fread(&teacher, sizeof(Teacher), 1, fp);


	fclose(fp);
}
