#include "teacher.h"

/*事件监听*/

int stu_management_listen = 1; // 学生管理页面监听
int homepage_listen = 1;

/*数据类型*/

extern Student stu[MAX_STU]; // 学生

/*全局变量*/

int add_stu_message_show = 0; // 添加学生弹框的显示状态
int modify_stu_message_show = 0; // 修改学生弹框的显示状态
int del_stu_message_show = 0; // 删除学生弹框的显示状态
int add_stu_pair_flag = 0; // 添加学生弹框中文本-输入框对是否添加标志量，防止多次调用学生管理函数时重复添加
int modify_stu_pair_flag = 0; // 修改学生弹框中文本-输入框对是否添加标志量，防止多次调用学生管理函数时重复添加
int del_stu_pair_flag = 0; // 删除学生弹框中文本-输入框对是否添加标志量，防止多次调用学生管理函数时重复添加

extern int cur_stu_id; // 当前学生id
extern int stu_num; // 学生总数

extern Navbar teacher_navbar; // 导航栏
extern Toast toast; // 弱提示框

extern Input search_stu_input; // 搜索学生输入框
extern int stu_tb_row; // 学生列表行数
extern int stu_tb_col; // 学生列表列数
extern Button search_btn; // 搜索按钮
extern Button add_btn; // 添加按钮
extern Button modify_btn; // 修改按钮
extern Button del_btn; // 删除按钮
extern Table* stu_tb_ptr; // 学生列表
extern headerList stu_tb_hl[MAX_COL]; // 学生列表表头
extern Message add_stu_message; // 添加学生弹框
extern Input* add_stu_stu_id_input_ptr; // 添加学生弹框学号输入框
extern Input* add_stu_name_input_ptr; // 添加学生弹框姓名输入框
extern Input* add_stu_class_input_ptr; // 添加学生弹框班级输入框
extern Input* add_stu_calculus_input_ptr; // 添加学生弹框微积分输入框
extern Input* add_stu_martix_input_ptr; // 添加学生弹框线性代数输入框
extern Input* add_stu_c_c_input_ptr; // 添加学生弹框程序设计输入框
extern Message modify_stu_message; // 修改学生弹框
extern Input* modify_stu_stu_id_input_ptr; // 修改学生弹框学号输入框
extern Input* modify_stu_name_input_ptr; // 修改学生弹框姓名输入框
extern Input* modify_stu_class_input_ptr; // 修改学生弹框班级输入框
extern Input* modify_stu_calculus_input_ptr; // 修改学生弹框微积分输入框
extern Input* modify_stu_martix_input_ptr; // 修改学生弹框线性代数输入框
extern Input* modify_stu_c_c_input_ptr; // 修改学生弹框程序设计输入框
extern Message del_stu_message; // 删除学生弹框
extern Input* del_stu_stu_id_input_ptr;  // 删除学生弹框学号输入框

/*函数实现*/

// 管理员主界面
void TeacherMainInterface()
{
	// 导航栏按钮
	NavButton nav_btn1(NAV_WIDTH, NAV_BUTTON_HEIGHT); // 首页
	NavButton nav_btn2(NAV_WIDTH, NAV_BUTTON_HEIGHT); // 学生管理

	// 导航栏按钮指针
	NavButton* nav_btn1_ptr = &nav_btn1;
	NavButton* nav_btn2_ptr = &nav_btn2;

	teacher_navbar.setTitleFontSize(22);
	teacher_navbar.setTitleText(L"UESTG");

	nav_btn1_ptr->setText(L"首页");
	nav_btn2_ptr->setText(L"学生管理");

	teacher_navbar.addNavButton(nav_btn1_ptr);
	teacher_navbar.addNavButton(nav_btn2_ptr);

	// 为导航栏按钮绑定点击事件
	nav_btn1_ptr->bindOnClick(homepage); // 绑定 首页
	nav_btn2_ptr->bindOnClick(stuManagementPage); // 绑定 学生管理

	teacher_navbar.setGap(70); // 设置导航栏按钮文字间距
	teacher_navbar.show(); // 显示导航栏

	homepage(); // 默认进入首页
	//stuManagementPage();
}

// 首页
void homepage()
{
	stu_management_listen = 0; // 关闭学生管理页页面监听

	refresh(NavbarMatchArea); // 刷新屏幕

	IMAGE stu_num_icon; // 学生总数图标

	wchar_t stu_num_text[TEXT_LEN]; // 学生总数
	wsprintfW(stu_num_text, L"%d", stu_num);

	// 更改背景色
	int startx = NAV_WIDTH + 1;
	int starty = 0;
	int endx = WIN_WIDTH;
	int endy = WIN_HEIGHT;

	COLORREF color = RGB(238, 240, 243); // 背景颜色
	setlinecolor(color); // 设置线条颜色，即图形的边框颜色
	setfillcolor(color); // 设置图形的填充颜色
	fillrectangle(startx, starty, endx, endy);

	// 展示框
	color = RGB(255, 255, 255); // 展示框颜色
	setlinecolor(color);
	setfillcolor(color);
	setFontStyle(RecText);

	int title_posx = 0;
	int title_posy = 0;
	int title_left_margin = 150; // 展示框标题左边距
	int title_top_margin = 35; // 展示框标题上边距
	int text_posx = 0;
	int text_posy = 0;
	int text_left_margin = 190; // 展示框文本左边距
	int text_top_margin = 70; // 展示框文本上边距
	int icon_left_margin = 20;
	int icon_top_margin = 20;

	int width = 249; 
	int height = 120;
	int gap = 30; // 展示框间距
	int radius = 15; // 展示框圆角

	starty = 50;
	endy = starty + height;

	// 展示框1
	startx = NAV_WIDTH + 40;
	endx = startx + width;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	//loadimage(&stu_num_icon, L"./pic/stu_num.png");
	//transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &stu_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"学生总数");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, stu_num_text);

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	homepage_listen = 1; // 开启首页页面监听
	while (homepage_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 导航栏
		if (teacher_navbar.isOn(msg.x, msg.y))
		{
			teacher_navbar.eventLoop(); // 进入事件循环
		}
	}
}

// 学生管理
void stuManagementPage()
{
	refresh(NavbarMatchArea); // 刷新屏幕

	// 搜索学生输入框
	search_stu_input.setHolderText(L"姓名");
	search_stu_input.show();

	// 搜索按钮
	search_btn.setText(L"搜 索");
	search_btn.bindOnClick(searchStu);
	search_btn.show();

	// 搜索按钮
	add_btn.setText(L"添 加");
	add_btn.bindOnClick(openAddStuMessage);
	add_btn.show();

	// 修改按钮
	modify_btn.setText(L"修 改");
	modify_btn.bindOnClick(openModifyStuMessage);
	modify_btn.show();

	// 删除按钮
	del_btn.setText(L"删 除");
	del_btn.setBkColor(RGB(199, 74, 61));
	del_btn.setBorderColor(RGB(213, 67, 52));
	del_btn.setHoverBkColor(RGB(178,58,45));
	del_btn.setPressedBkColor(RGB(162, 46, 34));
	del_btn.bindOnClick(openDelStuMessage);
	del_btn.show();

	// 学生列表
	int tb_width[] = { 20,10,20,20,20,20 }; // 列宽比例，单位为%，和为100
	stu_tb_ptr->setGridWidth(tb_width); // 设定列宽
	setTableHeader(StuTable, stu_tb_hl); // 设置列表表头
	searchStu(); // 默认搜索学生，默认输入框的值为空，因此为查询所有数据

	// 添加学生弹框
	add_stu_message.setTitle(L"添加学生"); // 设置标题
	// 未添加添加学生弹框的文本-输入框对
	if (add_stu_pair_flag == 0)
	{
		// 添加文本和输入框
		add_stu_message.addLabel(L"学号"); 
		add_stu_message.addInput(add_stu_stu_id_input_ptr); 
		add_stu_message.addLabel(L"姓名"); 
		add_stu_message.addInput(add_stu_name_input_ptr); 
		add_stu_message.addLabel(L"班级"); 
		add_stu_message.addInput(add_stu_class_input_ptr); 
		add_stu_message.addLabel(L"微积分");
		add_stu_message.addInput(add_stu_calculus_input_ptr);
		add_stu_message.addLabel(L"线性代数");
		add_stu_message.addInput(add_stu_martix_input_ptr);
		add_stu_message.addLabel(L"程序设计");
		add_stu_message.addInput(add_stu_c_c_input_ptr);
		
		add_stu_pair_flag = 1; // 表示已添加文本-输入框对
	}
	add_stu_message.cancelBtn()->bindOnClick(closeAddStuMessage); // 取消按钮绑定关闭弹框函数
	add_stu_message.enterBtn()->bindOnClick(addStu);

	// 修改学生弹框
	modify_stu_message.setTitle(L"修改学生"); // 设置标题
	// 未添加修改学生弹框的文本-输入框对
	if (modify_stu_pair_flag == 0)
	{
		// 添加文本和输入框
		modify_stu_message.addLabel(L"学号");
		modify_stu_message.addInput(modify_stu_stu_id_input_ptr);
		modify_stu_message.addLabel(L"姓名");
		modify_stu_message.addInput(modify_stu_name_input_ptr);
		modify_stu_message.addLabel(L"班级");
		modify_stu_message.addInput(modify_stu_class_input_ptr);
		modify_stu_message.addLabel(L"微积分");
		modify_stu_message.addInput(modify_stu_calculus_input_ptr);
		modify_stu_message.addLabel(L"线性代数");
		modify_stu_message.addInput(modify_stu_martix_input_ptr);
		modify_stu_message.addLabel(L"程序设计");
		modify_stu_message.addInput(modify_stu_c_c_input_ptr);

		modify_stu_pair_flag = 1; // 表示已添加文本-输入框对
	}
	modify_stu_message.cancelBtn()->bindOnClick(closeModifyStuMessage); // 取消按钮绑定关闭弹框函数
	modify_stu_message.enterBtn()->bindOnClick(modifyStu);

	// 删除学生弹框
	del_stu_message.setTitle(L"删除学生"); // 设置标题
	// 未添加删除学生弹框的文本-输入框对
	if (del_stu_pair_flag == 0)
	{
		// 添加文本和输入框
		del_stu_message.addLabel(L"学生编号");
		del_stu_message.addInput(del_stu_stu_id_input_ptr);

		del_stu_pair_flag = 1; // 表示已添加文本-输入框对
	}
	del_stu_message.cancelBtn()->bindOnClick(closeDelStuMessage); // 取消按钮绑定关闭弹框函数
	del_stu_message.enterBtn()->bindOnClick(delStu); // 确认按钮绑定打开弹框函数

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	stu_management_listen = 1; // 开启学生管理页面事件监听
	while (stu_management_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 有弹框打开
		if (del_stu_message_show || add_stu_message_show || modify_stu_message_show)
		{
			// 删除学生弹框
			if (del_stu_message_show)
			{
				if (del_stu_message.isOn(msg.x, msg.y))
				{
					del_stu_message.eventLoop(); // 进入事件循环
					del_stu_message_show = del_stu_message.isShow(); // 更新弹框的显示状态
				}
			}
			// 添加学生弹框
			if (add_stu_message_show)
			{
				if (add_stu_message.isOn(msg.x, msg.y))
				{
					add_stu_message.eventLoop(); // 进入事件循环
					add_stu_message_show = add_stu_message.isShow(); // 更新弹框的显示状态
				}
			}
			// 修改学生弹框
			if (modify_stu_message_show)
			{
				if (modify_stu_message.isOn(msg.x, msg.y))
				{
					modify_stu_message.eventLoop(); // 进入事件循环
					modify_stu_message_show = modify_stu_message.isShow(); // 更新弹框的显示状态
				}
			}
		}
		// 无弹框打开
		else
		{
			// 导航栏
			if (teacher_navbar.isOn(msg.x, msg.y))
			{
				teacher_navbar.eventLoop(); // 进入事件循环
			}
			// 搜索框
			if (search_stu_input.isOn(msg.x, msg.y))
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					search_stu_input.eventLoop(); // 进入事件循环
				}
			}
			// 搜索按钮
			if (search_btn.isOn(msg.x, msg.y))
			{
				search_btn.eventLoop(); // 进入事件循环
			}
			// 添加按钮
			if (add_btn.isOn(msg.x, msg.y))
			{
				add_btn.eventLoop(); // 进入事件循环
			}
			// 修改按钮
			if (modify_btn.isOn(msg.x, msg.y))
			{
				modify_btn.eventLoop(); // 进入事件循环
			}
			// 删除按钮
			if (del_btn.isOn(msg.x, msg.y))
			{
				del_btn.eventLoop(); // 进入事件循环
			}
		}
	}
}

// 搜索学生
void searchStu()
{
	refresh(TableArea);// 查询前先刷新屏幕

	wchar_t* search_str = search_stu_input.text(); // 获取输入框文本,即为搜索文本

	int mapping[MAX_STU] = { 0 }; // 映射数组，0表示不映射，1表示映射

	// 关键词为空; 
	if (wcscmp(search_str, L"") == 0)
	{
		for (int i = 0; i < stu_num; i++)
		{
			mapping[i] = 1;
		}
	}
	// 关键词非空
	else
	{
		for (int i = 0; i < stu_num; i++)
		{
			if (wcscmp(search_str, stu[i].name) == 0)
			{
				mapping[i] = 1;
			}
		}
	}
	mappingTableData(mapping, stu_tb_col, stu_tb_ptr, stu_tb_hl); // 映射学生列表数据
}

// 添加学生
void addStu()
{
	int flag = 0; // 操作成功标识

	wchar_t* add_stu_stu_id = add_stu_stu_id_input_ptr->text(); // 学号
	wchar_t* add_stu_name = add_stu_name_input_ptr->text(); // 姓名
	wchar_t* add_stu_class = add_stu_class_input_ptr->text(); // 班级
	wchar_t* add_stu_calculus = add_stu_calculus_input_ptr->text(); // 微积分
	wchar_t* add_stu_martix = add_stu_martix_input_ptr->text(); // 线性代数
	wchar_t* add_stu_c_c = add_stu_c_c_input_ptr->text(); // 程序设计

	// 判空
	if (wcslen(add_stu_stu_id) == 0)
	{
		// 用户提示
		toast.setText(L"学号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	// 学号位数
	if (!(wcslen(add_stu_stu_id) == 13)) {
		// 用户提示
		toast.setText(L"学号不是13位，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	// 学号和班级匹配
	wchar_t tttmp[100] = L"";
	wcsncpy_s(tttmp, add_stu_stu_id, 10);
	tttmp[10] = L'\0';
	if (wcscmp(tttmp, add_stu_class)) {
		// 用户提示
		toast.setText(L"学号与班级不匹配，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	// 学号查重
	for (int i = 0; i < stu_num; i++)
	{
		if (wcscmp(add_stu_stu_id, stu[i].stu_id) == 0)
		{
			// 用户提示
			toast.setText(L"学生编号重复，请重新输入");
			toast.show(WARNING);
			search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
			return;
		}
	}

	int index = stu_num; // 添加的学生的索引
	
	stu[index].id = cur_stu_id++;
	wcscpy_s(stu[index].stu_id, add_stu_stu_id);
	wcscpy_s(stu[index].name, add_stu_name);
	wcscpy_s(stu[index].classs , add_stu_class);
	wcscpy_s(stu[index].calculus, add_stu_calculus);
	wcscpy_s(stu[index].martix, add_stu_martix);
	wcscpy_s(stu[index].c_c, add_stu_c_c);
	wchar_t add_stu_account[100] = L"";
	wcscat_s(add_stu_account, add_stu_stu_id);
	wcscat_s(add_stu_account, L"@UESTG");
	wcscpy_s(stu[index].account, add_stu_account);
	wchar_t add_stu_password[100] = L"";
	wcsncpy_s(add_stu_password, add_stu_stu_id + 7, 6);
	add_stu_password[6] = L'\0';
	wcscpy_s(stu[index].password, add_stu_password);
	stu_num++;
	writeFile(); // 将数据写入文件
	flag = 1; // 操作成功
	
	closeAddStuMessage(); // 关闭添加学生弹框

	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"添加成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 修改学生
void modifyStu()
{
	int flag = 0; // 操作成功标识

	wchar_t* modify_stu_stu_id = modify_stu_stu_id_input_ptr->text(); // 学号
	wchar_t* modify_stu_name = modify_stu_name_input_ptr->text();  // 姓名
	wchar_t* modify_stu_class = modify_stu_class_input_ptr->text();// 班级
	wchar_t* modify_stu_calculus = modify_stu_calculus_input_ptr->text(); // 微积分
	wchar_t* modify_stu_martix = modify_stu_martix_input_ptr->text();  // 线性代数
	wchar_t* modify_stu_c_c = modify_stu_c_c_input_ptr->text(); // 程序设计

	// 判空
	if (wcslen(modify_stu_stu_id) == 0)
	{
		// 用户提示
		toast.setText(L"学生编号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	// 学号位数
	if (!(wcslen(modify_stu_stu_id) == 13)) {
		// 用户提示
		toast.setText(L"学号不是13位，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	// 学号和班级匹配
	wchar_t tttmp[100] = L"";
	wcsncpy_s(tttmp, modify_stu_stu_id, 10);
	tttmp[10] = L'\0';
	if (wcscmp(tttmp, modify_stu_class)) {
		// 用户提示
		toast.setText(L"学号与班级不匹配，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	int index = -1; // 需要修改的学生索引

	// 查询
	for (int i = 0; i < stu_num; i++)
	{
		// 查询命中
		if (wcscmp(modify_stu_stu_id, stu[i].stu_id) == 0)
		{
			index = i; // 记录索引
			break;
		}
	}

	// 说明查询命中
	if (index >= 0 && index < stu_num)
	{
		// 非空才写入
		if (wcslen(modify_stu_name) != 0)
		{
			wcscpy_s(stu[index].name, modify_stu_name);
		}
		if (wcslen(modify_stu_class) != 0)
		{
			wcscpy_s(stu[index].classs, modify_stu_class);
		}
		if (wcslen(modify_stu_calculus) != 0)
		{
			wcscpy_s(stu[index].calculus, modify_stu_calculus);
		}
		if (wcslen(modify_stu_martix) != 0)
		{
			wcscpy_s(stu[index].martix, modify_stu_martix);
		}
		if (wcslen(modify_stu_c_c) != 0)
		{
			wcscpy_s(stu[index].c_c, modify_stu_c_c);
		}
		writeFile(); // 将数据写入文件
		flag = 1; // 操作成功
	}
	// 说明查询未命中
	else
	{
		// 用户提示
		toast.setText(L"学号有误，无该学生");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	closeModifyStuMessage(); // 关闭修改学生弹框
	
	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"修改成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 删除学生
void delStu()
{
	int flag = 0; // 操作成功标识

	wchar_t* del_stu_stu_id = del_stu_stu_id_input_ptr->text(); // 学号

	// 判空
	if (wcslen(del_stu_stu_id) == 0)
	{
		// 用户提示
		toast.setText(L"学号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	int index = -1; // 需要删除的学生索引

	// 查询
	for (int i = 0; i < stu_num; i++)
	{
		// 查询命中
		if (wcscmp(del_stu_stu_id, stu[i].stu_id) == 0)
		{
			index = i; // 记录索引
			break;
		}
	}

	// 说明查询命中
	if (index >= 0 && index < stu_num)
	{

			// 删除对应学生
			for (int i = index; i < stu_num; i++)
			{
				stu[i].id = stu[i + 1].id;
				wcscpy_s(stu[i].stu_id, stu[i + 1].stu_id);
				wcscpy_s(stu[i].name, stu[i + 1].name);
				wcscpy_s(stu[i].classs, stu[i + 1].classs);
				wcscpy_s(stu[i].calculus, stu[i + 1].calculus);
				wcscpy_s(stu[i].martix, stu[i + 1].martix);
				wcscpy_s(stu[i].c_c, stu[i + 1].c_c);
			}
			stu_num--;
			writeFile(); // 将数据写入文件
			flag = 1; // 操作成功


	}
	else
	{
		// 用户提示
		toast.setText(L"学号有误，无该学生");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	closeDelStuMessage(); // 关闭删除学生弹框

	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"删除成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 打开添加学生弹框
void openAddStuMessage()
{
	add_stu_message.open(CONTENT); // 打开弹框
	add_stu_message_show = 1; // 更新弹框的显示状态
}

// 关闭添加学生弹框
void closeAddStuMessage()
{
	add_stu_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了添加学生操作，那么需要重新查询
	searchStu(); // 重新查询
}

// 打开修改学生弹框
void openModifyStuMessage()
{
	modify_stu_message.open(CONTENT); // 打开弹框
	modify_stu_message_show = 1; // 更新弹框的显示状态
}

// 关闭修改学生弹框
void closeModifyStuMessage()
{
	modify_stu_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了添加学生操作，那么需要重新查询
	searchStu(); // 重新查询
}

// 打开删除学生弹框
void openDelStuMessage()
{
	del_stu_message.open(CONTENT); // 打开弹框
	del_stu_message_show = 1; // 更新弹框的显示状态
}

// 关闭删除学生弹框
void closeDelStuMessage()
{
	del_stu_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了删除学生操作，那么需要重新查询
	searchStu(); // 重新查询
}



