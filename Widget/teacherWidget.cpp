#include "EUI/EUI.h"
#include "Common/common.h"

// 导航栏
extern int navbar_posx;
extern int navbar_posy;

Navbar admin_navbar(navbar_posx, navbar_posy, NAV_WIDTH, WIN_HEIGHT);

// 搜索学生输入框
int search_stu_input_posx = 240;
int search_stu_input_posy = 20;
int search_stu_input_width = 150;
int search_stu_input_height = 35;

Input search_stu_input(search_stu_input_posx, search_stu_input_posy, search_stu_input_width, search_stu_input_height);

// 搜索按钮
int search_btn_posx = 420;
int search_btn_posy = search_stu_input_posy;
int search_btn_width = 120;
int search_btn_height = 35;

Button search_btn(search_btn_posx, search_btn_posy, search_btn_width, search_btn_height);

// 添加按钮
int add_btn_posx = 900;
int add_btn_posy = 20;
int add_btn_width = search_btn_width;
int add_btn_height = search_btn_height;

Button add_btn(add_btn_posx, add_btn_posy, add_btn_width, add_btn_height);

// 修改按钮
int modify_btn_posx = 1050;
int modify_btn_posy = search_stu_input_posy;
int modify_btn_width = search_btn_width;
int modify_btn_height = search_btn_height;

Button modify_btn(modify_btn_posx, modify_btn_posy, modify_btn_width, modify_btn_height);

// 删除按钮
int del_btn_posx = 1200;
int del_btn_posy = search_stu_input_posy;
int del_btn_width = search_btn_width;
int del_btn_height = search_btn_height;

Button del_btn(del_btn_posx, del_btn_posy, del_btn_width, del_btn_height);

// 学生列表
int stu_tb_posx = search_stu_input_posx;
int stu_tb_posy = search_stu_input_posy + 100;
int stu_tb_width = 1082;

int stu_tb_row = 10; // 学生列表行数
int stu_tb_col = 6; // 学生列表列数

Table stu_tb(stu_tb_posx, stu_tb_posy, stu_tb_width, stu_tb_row, stu_tb_col); // 学生列表
Table* stu_tb_ptr = &stu_tb;
headerList stu_tb_hl[MAX_COL]; // 学生列表表头

// 添加学生弹框
int add_stu_message_width = 520;
int add_stu_message_height = 530;

Message add_stu_message(WIN_WIDTH, WIN_HEIGHT, add_stu_message_width, add_stu_message_height);

// 添加学生输入框
int add_stu_input_width = 200;
int add_stu_input_height = 30;

Input add_stu_sn_input(0, 0, add_stu_input_width, add_stu_input_height);
Input* add_stu_sn_input_ptr = &add_stu_sn_input;

Input add_stu_name_input(0, 0, add_stu_input_width, add_stu_input_height);
Input* add_stu_name_input_ptr = &add_stu_name_input;

Input add_stu_author_input(0, 0, add_stu_input_width, add_stu_input_height);
Input* add_stu_author_input_ptr = &add_stu_author_input;

Input add_stu_publisher_input(0, 0, add_stu_input_width, add_stu_input_height);
Input* add_stu_publisher_input_ptr = &add_stu_publisher_input;

Input add_stu_publish_time_input(0, 0, add_stu_input_width, add_stu_input_height);
Input* add_stu_publish_time_input_ptr = &add_stu_publish_time_input;

// 修改学生弹框
int modify_stu_message_width = 520;
int modify_stu_message_height = 530;

Message modify_stu_message(WIN_WIDTH, WIN_HEIGHT, modify_stu_message_width, modify_stu_message_height);

// 修改学生输入框
int modify_stu_input_width = 200;
int modify_stu_input_height = 30;

Input modify_stu_sn_input(0, 0, modify_stu_input_width, modify_stu_input_height);
Input* modify_stu_sn_input_ptr = &modify_stu_sn_input;

Input modify_stu_name_input(0, 0, modify_stu_input_width, modify_stu_input_height);
Input* modify_stu_name_input_ptr = &modify_stu_name_input;

Input modify_stu_author_input(0, 0, modify_stu_input_width, modify_stu_input_height);
Input* modify_stu_author_input_ptr = &modify_stu_author_input;

Input modify_stu_publisher_input(0, 0, modify_stu_input_width, modify_stu_input_height);
Input* modify_stu_publisher_input_ptr = &modify_stu_publisher_input;

Input modify_stu_publish_time_input(0, 0, modify_stu_input_width, modify_stu_input_height);
Input* modify_stu_publish_time_input_ptr = &modify_stu_publish_time_input;

// 删除学生弹框
int del_stu_message_width = 520;
int del_stu_messsage_height = 180;

Message del_stu_message(WIN_WIDTH, WIN_HEIGHT, del_stu_message_width, del_stu_messsage_height);

// 删除学生输入框
int del_stu_input_width = 150;
int del_stu_input_height = 30;

Input del_stu_sn_input(0, 0, del_stu_input_width, del_stu_input_height); // 删除学生序号输入框
Input* del_stu_sn_input_ptr = &del_stu_sn_input; // 删除学生序号输入框指针


