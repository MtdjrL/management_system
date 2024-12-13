#include "teacher.h"

/*事件监听*/

int book_management_listen = 1; // 图书管理页面监听
int homepage_listen = 1;

/*数据类型*/

extern Student book[MAX_STU]; // 图书

/*全局变量*/

int add_book_message_show = 0; // 添加图书弹框的显示状态
int modify_book_message_show = 0; // 修改图书弹框的显示状态
int del_book_message_show = 0; // 删除图书弹框的显示状态
int add_book_pair_flag = 0; // 添加图书弹框中文本-输入框对是否添加标志量，防止多次调用图书管理函数时重复添加
int modify_book_pair_flag = 0; // 修改图书弹框中文本-输入框对是否添加标志量，防止多次调用图书管理函数时重复添加
int del_book_pair_flag = 0; // 删除图书弹框中文本-输入框对是否添加标志量，防止多次调用图书管理函数时重复添加

extern int cur_book_id; // 当前图书id
extern int book_num; // 图书总数
extern int user_num; // 用户总数
extern int borrow_book_num;  // 借阅图书总数
extern int exist_book_num; // 现存图书总数

extern Navbar admin_navbar; // 导航栏
extern Toast toast; // 弱提示框

extern Input search_book_input; // 搜索图书输入框
extern int book_tb_row; // 图书列表行数
extern int book_tb_col; // 图书列表列数
extern Button search_btn; // 搜索按钮
extern Button add_btn; // 添加按钮
extern Button modify_btn; // 修改按钮
extern Button del_btn; // 删除按钮
extern Table* book_tb_ptr; // 图书列表
extern headerList book_tb_hl[MAX_COL]; // 图书列表表头
extern Message add_book_message; // 添加图书弹框
extern Input* add_book_sn_input_ptr; // 添加图书弹框编号输入框
extern Input* add_book_name_input_ptr; // 添加图书弹框书名输入框
extern Input* add_book_author_input_ptr; // 添加图书弹框作者输入框
extern Input* add_book_publisher_input_ptr; // 添加图书弹框出版社输入框
extern Input* add_book_publish_time_input_ptr; // 添加图书弹框出版时间输入框
extern Message modify_book_message; // 修改图书弹框
extern Input* modify_book_sn_input_ptr; // 修改图书弹框编号输入框
extern Input* modify_book_name_input_ptr; // 修改图书弹框书名输入框
extern Input* modify_book_author_input_ptr; // 修改图书弹框作者输入框
extern Input* modify_book_publisher_input_ptr; // 修改图书弹框出版社输入框
extern Input* modify_book_publish_time_input_ptr; // 修改图书弹框出版时间输入框
extern Message del_book_message; // 删除图书弹框
extern Input* del_book_sn_input_ptr;  // 删除图书弹框编号输入框

/*函数实现*/

// 管理员主界面
void adminMainInterface()
{
	// 导航栏按钮
	NavButton nav_btn1(NAV_WIDTH, NAV_BUTTON_HEIGHT); // 首页
	NavButton nav_btn2(NAV_WIDTH, NAV_BUTTON_HEIGHT); // 图书管理

	// 导航栏按钮指针
	NavButton* nav_btn1_ptr = &nav_btn1;
	NavButton* nav_btn2_ptr = &nav_btn2;

	admin_navbar.setTitleFontSize(22);
	admin_navbar.setTitleText(L"书  知");

	nav_btn1_ptr->setText(L"首页");
	nav_btn2_ptr->setText(L"图书管理");

	admin_navbar.addNavButton(nav_btn1_ptr);
	admin_navbar.addNavButton(nav_btn2_ptr);

	// 为导航栏按钮绑定点击事件
	nav_btn1_ptr->bindOnClick(homepage); // 绑定 首页
	nav_btn2_ptr->bindOnClick(bookManagementPage); // 绑定 图书管理

	admin_navbar.setGap(70); // 设置导航栏按钮文字间距
	admin_navbar.show(); // 显示导航栏

	homepage(); // 默认进入首页
	//bookManagementPage();
}

// 首页
void homepage()
{
	book_management_listen = 0; // 关闭图书管理页页面监听

	refresh(NavbarMatchArea); // 刷新屏幕

	IMAGE book_num_icon; // 图书总数图标
	IMAGE user_num_icon; // 用户总数图标
	IMAGE exist_book_num_icon; // 现存图书图标
	IMAGE borrow_book_num_icon; // 借阅图书图标

	wchar_t book_num_text[TEXT_LEN]; // 图书总数
	wchar_t user_num_text[TEXT_LEN]; // 用户总数
	wchar_t exist_book_num_text[TEXT_LEN]; // 现存图书
	wchar_t borrow_book_num_text[TEXT_LEN]; // 借阅图书
	wsprintfW(book_num_text, L"%d", book_num);
	wsprintfW(user_num_text, L"%d", user_num);
	wsprintfW(exist_book_num_text, L"%d", exist_book_num);
	wsprintfW(borrow_book_num_text, L"%d", borrow_book_num);

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

	loadimage(&book_num_icon, L"../pic/book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"图书总数");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, book_num_text);

	// 展示框2
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&user_num_icon, L"../pic/user_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &user_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"用户总数");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, user_num_text);

	// 展示框3
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&exist_book_num_icon, L"../pic/exist_book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &exist_book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"现存图书");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, exist_book_num_text);

	// 展示框4
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&borrow_book_num_icon, L"../pic/borrow_book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &borrow_book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"借阅图书");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, borrow_book_num_text);

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	homepage_listen = 1; // 开启首页页面监听
	while (homepage_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 导航栏
		if (admin_navbar.isOn(msg.x, msg.y))
		{
			admin_navbar.eventLoop(); // 进入事件循环
		}
	}
}

// 图书管理
void bookManagementPage()
{
	refresh(NavbarMatchArea); // 刷新屏幕

	// 搜索图书输入框
	search_book_input.setHolderText(L"书名");
	search_book_input.show();

	// 搜索按钮
	search_btn.setText(L"搜 索");
	search_btn.bindOnClick(searchBook);
	search_btn.show();

	// 搜索按钮
	add_btn.setText(L"添 加");
	add_btn.bindOnClick(openAddBookMessage);
	add_btn.show();

	// 修改按钮
	modify_btn.setText(L"修 改");
	modify_btn.bindOnClick(openModifyBookMessage);
	modify_btn.show();

	// 删除按钮
	del_btn.setText(L"删 除");
	del_btn.setBkColor(RGB(199, 74, 61));
	del_btn.setBorderColor(RGB(213, 67, 52));
	del_btn.setHoverBkColor(RGB(178,58,45));
	del_btn.setPressedBkColor(RGB(162, 46, 34));
	del_btn.bindOnClick(openDelBookMessage);
	del_btn.show();

	// 图书列表
	int tb_width[] = { 10,20,10,20,20,20 }; // 列宽比例，单位为%，和为100
	book_tb_ptr->setGridWidth(tb_width); // 设定列宽
	setTableHeader(BookTable, book_tb_hl); // 设置列表表头
	searchBook(); // 默认搜索图书，默认输入框的值为空，因此为查询所有数据

	// 添加图书弹框
	add_book_message.setTitle(L"添加图书"); // 设置标题
	// 未添加添加图书弹框的文本-输入框对
	if (add_book_pair_flag == 0)
	{
		// 添加文本和输入框
		add_book_message.addLabel(L"图书编号"); 
		add_book_message.addInput(add_book_sn_input_ptr); 
		add_book_message.addLabel(L"书名"); 
		add_book_message.addInput(add_book_name_input_ptr); 
		add_book_message.addLabel(L"作者"); 
		add_book_message.addInput(add_book_author_input_ptr); 
		add_book_message.addLabel(L"出版社");
		add_book_message.addInput(add_book_publisher_input_ptr);
		add_book_message.addLabel(L"出版时间");
		add_book_message.addInput(add_book_publish_time_input_ptr);
		
		add_book_pair_flag = 1; // 表示已添加文本-输入框对
	}
	add_book_message.cancelBtn()->bindOnClick(closeAddBookMessage); // 取消按钮绑定关闭弹框函数
	add_book_message.enterBtn()->bindOnClick(addBook);

	// 修改图书弹框
	modify_book_message.setTitle(L"修改图书"); // 设置标题
	// 未添加修改图书弹框的文本-输入框对
	if (modify_book_pair_flag == 0)
	{
		// 添加文本和输入框
		modify_book_message.addLabel(L"图书编号");
		modify_book_message.addInput(modify_book_sn_input_ptr);
		modify_book_message.addLabel(L"书名");
		modify_book_message.addInput(modify_book_name_input_ptr);
		modify_book_message.addLabel(L"作者");
		modify_book_message.addInput(modify_book_author_input_ptr);
		modify_book_message.addLabel(L"出版社");
		modify_book_message.addInput(modify_book_publisher_input_ptr);
		modify_book_message.addLabel(L"出版时间");
		modify_book_message.addInput(modify_book_publish_time_input_ptr);

		modify_book_pair_flag = 1; // 表示已添加文本-输入框对
	}
	modify_book_message.cancelBtn()->bindOnClick(closeModifyBookMessage); // 取消按钮绑定关闭弹框函数
	modify_book_message.enterBtn()->bindOnClick(modifyBook);

	// 删除图书弹框
	del_book_message.setTitle(L"删除图书"); // 设置标题
	// 未添加删除图书弹框的文本-输入框对
	if (del_book_pair_flag == 0)
	{
		// 添加文本和输入框
		del_book_message.addLabel(L"图书编号");
		del_book_message.addInput(del_book_sn_input_ptr);

		del_book_pair_flag = 1; // 表示已添加文本-输入框对
	}
	del_book_message.cancelBtn()->bindOnClick(closeDelBookMessage); // 取消按钮绑定关闭弹框函数
	del_book_message.enterBtn()->bindOnClick(delBook); // 确认按钮绑定打开弹框函数

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	book_management_listen = 1; // 开启图书管理页面事件监听
	while (book_management_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 有弹框打开
		if (del_book_message_show || add_book_message_show || modify_book_message_show)
		{
			// 删除图书弹框
			if (del_book_message_show)
			{
				if (del_book_message.isOn(msg.x, msg.y))
				{
					del_book_message.eventLoop(); // 进入事件循环
					del_book_message_show = del_book_message.isShow(); // 更新弹框的显示状态
				}
			}
			// 添加图书弹框
			if (add_book_message_show)
			{
				if (add_book_message.isOn(msg.x, msg.y))
				{
					add_book_message.eventLoop(); // 进入事件循环
					add_book_message_show = add_book_message.isShow(); // 更新弹框的显示状态
				}
			}
			// 修改图书弹框
			if (modify_book_message_show)
			{
				if (modify_book_message.isOn(msg.x, msg.y))
				{
					modify_book_message.eventLoop(); // 进入事件循环
					modify_book_message_show = modify_book_message.isShow(); // 更新弹框的显示状态
				}
			}
		}
		// 无弹框打开
		else
		{
			// 导航栏
			if (admin_navbar.isOn(msg.x, msg.y))
			{
				admin_navbar.eventLoop(); // 进入事件循环
			}
			// 搜索框
			if (search_book_input.isOn(msg.x, msg.y))
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					search_book_input.eventLoop(); // 进入事件循环
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

// 搜索图书
void searchBook()
{
	refresh(TableArea);// 查询前先刷新屏幕

	wchar_t* search_str = search_book_input.text(); // 获取输入框文本,即为搜索文本

	int mapping[MAX_BOOK] = { 0 }; // 映射数组，0表示不映射，1表示映射

	// 关键词为空; 
	if (wcscmp(search_str, L"") == 0)
	{
		for (int i = 0; i < book_num; i++)
		{
			mapping[i] = 1;
		}
	}
	// 关键词非空
	else
	{
		for (int i = 0; i < book_num; i++)
		{
			if (wcscmp(search_str, book[i].name) == 0)
			{
				mapping[i] = 1;
			}
		}
	}
	mappingTableData(mapping, book_tb_col, book_tb_ptr, book_tb_hl); // 映射图书列表数据
}

// 添加图书
void addBook()
{
	int flag = 0; // 操作成功标识

	wchar_t* add_book_sn = add_book_sn_input_ptr->text(); // 编号
	wchar_t* add_book_name = add_book_name_input_ptr->text(); // 书名
	wchar_t* add_book_author = add_book_author_input_ptr->text(); // 作者
	wchar_t* add_book_publisher = add_book_publisher_input_ptr->text(); // 出版社
	wchar_t* add_book_publish_time = add_book_publish_time_input_ptr->text(); // 出版时间
	wchar_t add_book_state[TEXT_LEN];
	wcscpy_s(add_book_state, L"未借出"); // 添加的图书的默认借阅状态

	// 判空
	if (wcslen(add_book_sn) == 0)
	{
		// 用户提示
		toast.setText(L"图书编号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	// 编号查重
	for (int i = 0; i < book_num; i++)
	{
		if (wcscmp(add_book_sn, book[i].sn) == 0)
		{
			// 用户提示
			toast.setText(L"图书编号重复，请重新输入");
			toast.show(WARNING);
			search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
			return;
		}
	}

	int index = book_num; // 添加的图书的索引

	book[index].id = ++cur_book_id;
	wcscpy_s(book[index].sn, add_book_sn);
	wcscpy_s(book[index].name, add_book_name);
	wcscpy_s(book[index].author, add_book_author);
	wcscpy_s(book[index].publisher, add_book_publisher);
	wcscpy_s(book[index].publish_time, add_book_publish_time);
	wcscpy_s(book[index].state, add_book_state);

	book_num++;
	exist_book_num++;
	writeFile(); // 将数据写入文件
	flag = 1; // 操作成功
	
	closeAddBookMessage(); // 关闭添加图书弹框

	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"添加成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 修改图书
void modifyBook()
{
	int flag = 0; // 操作成功标识

	wchar_t* modify_book_sn = modify_book_sn_input_ptr->text(); // 编号
	wchar_t* modify_book_name = modify_book_name_input_ptr->text(); // 书名
	wchar_t* modify_book_author = modify_book_author_input_ptr->text(); // 作者
	wchar_t* modify_book_publisher = modify_book_publisher_input_ptr->text(); // 出版社
	wchar_t* modify_book_publish_time = modify_book_publish_time_input_ptr->text(); // 出版时间

	// 判空
	if (wcslen(modify_book_sn) == 0)
	{
		// 用户提示
		toast.setText(L"图书编号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	int index = -1; // 需要修改的图书索引

	// 查询
	for (int i = 0; i < book_num; i++)
	{
		// 查询命中
		if (wcscmp(modify_book_sn, book[i].sn) == 0)
		{
			index = i; // 记录索引
			break;
		}
	}

	// 说明查询命中
	if (index >= 0 && index < book_num)
	{
		// 非空才写入
		if (wcslen(modify_book_name) != 0)
		{
			wcscpy_s(book[index].name, modify_book_name);
		}
		if (wcslen(modify_book_author) != 0)
		{
			wcscpy_s(book[index].author, modify_book_author);
		}
		if (wcslen(modify_book_publisher) != 0)
		{
			wcscpy_s(book[index].publisher, modify_book_publisher);
		}
		if (wcslen(modify_book_publish_time) != 0)
		{
			wcscpy_s(book[index].publish_time, modify_book_publish_time);
		}
		writeFile(); // 将数据写入文件
		flag = 1; // 操作成功
	}
	// 说明查询未命中
	else
	{
		// 用户提示
		toast.setText(L"图书编号有误，无该图书");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	closeModifyBookMessage(); // 关闭修改图书弹框
	
	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"修改成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 删除图书
void delBook()
{
	int flag = 0; // 操作成功标识

	wchar_t* del_book_sn = del_book_sn_input_ptr->text(); // 编号

	// 判空
	if (wcslen(del_book_sn) == 0)
	{
		// 用户提示
		toast.setText(L"图书编号为空，请重新输入");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示

		return;
	}

	int index = -1; // 需要删除的图书索引

	// 查询
	for (int i = 0; i < book_num; i++)
	{
		// 查询命中
		if (wcscmp(del_book_sn, book[i].sn) == 0)
		{
			index = i; // 记录索引
			break;
		}
	}

	// 说明查询命中
	if (index >= 0 && index < book_num)
	{
		// 图书未借出
		if (wcscmp(book[index].state, L"未借出") == 0)
		{
			// 删除对应图书
			for (int i = index; i < book_num; i++)
			{
				book[i].id = book[i + 1].id;
				wcscpy_s(book[i].sn, book[i + 1].sn);
				wcscpy_s(book[i].name, book[i + 1].name);
				wcscpy_s(book[i].author, book[i + 1].author);
				wcscpy_s(book[i].publisher, book[i + 1].publisher);
				wcscpy_s(book[i].publish_time, book[i + 1].publish_time);
				wcscpy_s(book[i].state, book[i + 1].state);
			}
			book_num--;
			exist_book_num--;
			writeFile(); // 将数据写入文件
			flag = 1; // 操作成功
		}
		// 图书已借出
		else
		{
			// 用户提示
			toast.setText(L"该图书已被借阅，无法删除");
			toast.show(WARNING);
			search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
			return;
		}
	}
	else
	{
		// 用户提示
		toast.setText(L"图书编号有误，无该图书");
		toast.show(WARNING);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
		return;
	}

	closeDelBookMessage(); // 关闭删除图书弹框

	// 操作成功
	if (flag == 1)
	{
		// 用户提示
		toast.setText(L"删除成功");
		toast.show(SUCCESS);
		search_btn.show(); // 弱提示框会擦除掉覆盖的搜索按钮，因此需要重新显示
	}
}

// 打开添加图书弹框
void openAddBookMessage()
{
	add_book_message.open(CONTENT); // 打开弹框
	add_book_message_show = 1; // 更新弹框的显示状态
}

// 关闭添加图书弹框
void closeAddBookMessage()
{
	add_book_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了添加图书操作，那么需要重新查询
	searchBook(); // 重新查询
}

// 打开修改图书弹框
void openModifyBookMessage()
{
	modify_book_message.open(CONTENT); // 打开弹框
	modify_book_message_show = 1; // 更新弹框的显示状态
}

// 关闭修改图书弹框
void closeModifyBookMessage()
{
	modify_book_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了添加图书操作，那么需要重新查询
	searchBook(); // 重新查询
}

// 打开删除图书弹框
void openDelBookMessage()
{
	del_book_message.open(CONTENT); // 打开弹框
	del_book_message_show = 1; // 更新弹框的显示状态
}

// 关闭删除图书弹框
void closeDelBookMessage()
{
	del_book_message.close(); // 关闭弹框
	//一方面是关闭弹框时会对部分表格进行擦除，需要重新查询；另一方面是如果用户确认了删除图书操作，那么需要重新查询
	searchBook(); // 重新查询
}



