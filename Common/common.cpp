#include "common.h"

// 导航栏
int navbar_posx = 0;
int navbar_posy = 0;

// 弱提示框
int toast_width = 350;
int toast_height = 50;
int toast_posy = 30;

Toast toast(WIN_WIDTH, toast_posy, toast_width, toast_height);

// 学生
Student stu[MAX_STU];

// 老师
Teacher teacher;


int stu_num = 6; // 学生总数


int cur_stu_id = 0; // 当前学生id，因为是自增所以要记录

int login_stu_id = 0; // 登录的学生id

wchar_t teacher_code[TEXT_LEN]; // 老师验证码
wchar_t stu_code[TEXT_LEN]; // 学生验证码


// 刷新屏幕
void refresh(enum RefreshArea area)
{
	COLORREF color = 0xffffff; // 设置画刷颜色为白色，用白色来刷新界面
	// 区域坐标
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
	setlinecolor(color); // 设置线条颜色，即图形的边框颜色
	setfillcolor(color); // 设置图形的填充颜色
	fillrectangle(startx, starty, endx, endy);
}

// 数据初始化
void initData()
{
	initStuData(); // 学生数据初始化
	initTeacherData(); // 老师数据初始化
	initCode(); // 验证码初始化
}

// 学生数据初始化
void initStuData()
{
	// 学生初始数据
	stu[0].id = cur_stu_id++;
	wcscpy_s(stu[0].account, L"2024990901001@UESTG"); // 账号
	wcscpy_s(stu[0].password, L"901001"); // 账号
	wcscpy_s(stu[0].name, L"张三"); // 姓名
	wcscpy_s(stu[0].classs, L"2024990901"); // 班级
	wcscpy_s(stu[0].stu_id, L"2024990901001"); // 学号
	wcscpy_s(stu[0].calculus, L"98"); // 微积分
	wcscpy_s(stu[0].martix, L"100"); // 线性代数与空间解析几何
	wcscpy_s(stu[0].c_c, L"99"); // 程序设计

	stu[1].id = cur_stu_id++;
	wcscpy_s(stu[1].account, L"2024990901002@UESTG"); // 账号
	wcscpy_s(stu[1].password, L"901002"); // 账号
	wcscpy_s(stu[1].name, L"李四"); // 姓名
	wcscpy_s(stu[1].classs, L"2024990901"); // 班级
	wcscpy_s(stu[1].stu_id, L"2024990901002"); // 学号
	wcscpy_s(stu[1].calculus, L"75"); // 微积分
	wcscpy_s(stu[1].martix, L"85"); // 线性代数与空间解析几何
	wcscpy_s(stu[1].c_c, L"100"); // 程序设计

	stu[2].id = cur_stu_id++;
	wcscpy_s(stu[2].account, L"2024990902001@UESTG"); // 账号
	wcscpy_s(stu[2].password, L"902001"); // 账号
	wcscpy_s(stu[2].name, L"王二麻子"); // 姓名
	wcscpy_s(stu[2].classs, L"2024990902"); // 班级
	wcscpy_s(stu[2].stu_id, L"2024990902001"); // 学号
	wcscpy_s(stu[2].calculus, L"98"); // 微积分
	wcscpy_s(stu[2].martix, L"100"); // 线性代数与空间解析几何
	wcscpy_s(stu[2].c_c, L"99"); // 程序设计

	stu[3].id = cur_stu_id++;
	wcscpy_s(stu[3].account, L"2024990902002@UESTG"); // 账号
	wcscpy_s(stu[3].password, L"902002"); // 账号
	wcscpy_s(stu[3].name, L"杨畅畅"); // 姓名
	wcscpy_s(stu[3].classs, L"2024990902"); // 班级
	wcscpy_s(stu[3].stu_id, L"2024990902002"); // 学号
	wcscpy_s(stu[3].calculus, L"98"); // 微积分
	wcscpy_s(stu[3].martix, L"100"); // 线性代数与空间解析几何
	wcscpy_s(stu[3].c_c, L"99"); // 程序设计

	stu[4].id = cur_stu_id++;
	wcscpy_s(stu[4].account, L"2024990903001@UESTG"); // 账号
	wcscpy_s(stu[4].password, L"903001"); // 账号
	wcscpy_s(stu[4].name, L"朱心心"); // 姓名
	wcscpy_s(stu[4].classs, L"2024990903"); // 班级
	wcscpy_s(stu[4].stu_id, L"2024990903001"); // 学号
	wcscpy_s(stu[4].calculus, L"75"); // 微积分
	wcscpy_s(stu[4].martix, L"75"); // 线性代数与空间解析几何
	wcscpy_s(stu[4].c_c, L"60"); // 程序设计

	stu[5].id = cur_stu_id++;
	wcscpy_s(stu[5].account, L"2024990903002@UESTG"); // 账号
	wcscpy_s(stu[5].password, L"903002"); // 账号
	wcscpy_s(stu[5].name, L"吴昊昊"); // 姓名
	wcscpy_s(stu[5].classs, L"2024990903"); // 班级
	wcscpy_s(stu[5].stu_id, L"2024990903002"); // 学号
	wcscpy_s(stu[5].calculus, L"100"); // 微积分
	wcscpy_s(stu[5].martix, L"100"); // 线性代数与空间解析几何
	wcscpy_s(stu[5].c_c, L"100"); // 程序设计
}

// 老师数据初始化
void initTeacherData()
{
	// 老师初始数据
	wcscpy_s(teacher.account, L"Teacher");
	wcscpy_s(teacher.password, L"998244353");
}


// 验证码初始化
void initCode()
{
	// 验证码初始数据
	wcscpy_s(teacher_code, L"123321"); // 老师验证码
	wcscpy_s(stu_code, L"789987"); // 学生验证码
}

// 映射列表数据
void mappingTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl)
{
	tableList* stu_tl = tb->tableListCont(); // 获取列表数据指针
	// 将列表数据一对一映射到tableList中
	for (int i = 0; i < stu_num; i++)
	{
		// 这条数据无需映射
		if (mapping[i] == 0)
		{
			continue;
		}
		// 这条数据需要映射
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
	clearTableData(mapping, col, tb, hl); // 清空列表数据
}

// 清空列表数据
void clearTableData(int mapping[MAX_STU], int col, Table* tb, headerList* hl)
{
	tableList* book_tl = tb->tableListCont(); // 获取列表数据指针
	// 清空数据
	for (int i = 0; i < stu_num; i++)
	{
		// 指针无需改变
		if (mapping[i] == 0)
		{
			continue;
		}
		// 清空操作，并让指针继续走
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

// 设置列表表头
void setTableHeader(enum TableType type, headerList* hl)
{
	switch (type)
	{
	case StuTable:
		wcscpy_s(hl[0].header, L"学号");
		wcscpy_s(hl[1].header, L"姓名");
		wcscpy_s(hl[2].header, L"班级");
		wcscpy_s(hl[3].header, L"微积分");
		wcscpy_s(hl[4].header, L"线代");
		wcscpy_s(hl[5].header, L"程设");
		break;
	}
}

// 将数据写入文件
void writeFile()
{
	FILE* fp; // 文件指针
	fopen_s(&fp, "data.dat", "wb");

	if (fp == NULL)
	{
		return;
	}

	fwrite(&stu_num, sizeof(int), 1, fp); // 学生总数
	fwrite(&cur_stu_id, sizeof(int), 1, fp); // 当前学生id
	fwrite(teacher_code, sizeof(wchar_t), wcslen(teacher_code), fp); // 老师验证码
	fwrite(stu_code, sizeof(wchar_t), wcslen(stu_code), fp); // 学生验证码

	// 学生
	for (int i = 0; i < stu_num; i++)
	{
		fwrite(&stu[i], sizeof(Student), 1, fp);
	}

	// 老师
	fwrite(&teacher, sizeof(Teacher), 1, fp);


	fclose(fp);
}

// 从文件读入数据
void readFile()
{
	FILE* fp; // 文件指针
	fopen_s(&fp, "data.dat", "rb");

	if (fp == NULL)
	{
		return;
	}

	fread(&stu_num, sizeof(int), 1, fp); // 学生总数
	fread(&cur_stu_id, sizeof(int), 1, fp); // 当前学生id
	fread(teacher_code, sizeof(wchar_t), wcslen(teacher_code), fp); // 老师验证码
	fread(stu_code, sizeof(wchar_t), wcslen(stu_code), fp); // 学生验证码

	// 学生
	for (int i = 0; i < stu_num; i++)
	{
		fread(&stu[i], sizeof(Student), 1, fp);
	}

	// 老师
	fread(&teacher, sizeof(Teacher), 1, fp);


	fclose(fp);
}
