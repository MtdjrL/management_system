#include "EUI/EUI.h"
#include "Common/common.h"

// 导航栏
extern int navbar_posx;
extern int navbar_posy;

Navbar user_navbar(navbar_posx, navbar_posy, NAV_WIDTH, WIN_HEIGHT);

// 借阅按钮
int borrow_btn_posx = 1200;
int borrow_btn_posy = 20;
int borrow_btn_width = 120;
int borrow_btn_height = 35;

Button borrow_btn(borrow_btn_posx, borrow_btn_posy, borrow_btn_width, borrow_btn_height);

// 借阅图书弹框
int borrow_book_message_width = 520;
int borrow_book_message_height = 180;

Message borrow_book_message(WIN_WIDTH, WIN_HEIGHT, borrow_book_message_width, borrow_book_message_height);

// 借阅图书输入框
int borrow_book_input_width = 150;
int borrow_book_input_height = 30;

Input borrow_book_sn_input(0, 0, borrow_book_input_width, borrow_book_input_height);
Input* borrow_book_sn_input_ptr = &borrow_book_sn_input;

// 可借阅图书列表
int borrow_book_tb_posx = 240;
int borrow_book_tb_posy = 120;
int borrow_book_tb_width = 1082;

int borrow_book_tb_row = 10; // 可借阅图书列表行数
int borrow_book_tb_col = 5; // 可借阅图书列表列数

Table borrow_book_tb(borrow_book_tb_posx, borrow_book_tb_posy, borrow_book_tb_width, borrow_book_tb_row, borrow_book_tb_col); // 图书列表
Table* borrow_book_tb_ptr = &borrow_book_tb;
headerList borrow_book_tb_hl[MAX_COL]; // 图书列表表头

// 归还按钮
int return_btn_posx = 1200;
int return_btn_posy = 20;
int return_btn_width = 120;
int return_btn_height = 35;

Button return_btn(return_btn_posx, return_btn_posy, return_btn_width, return_btn_height);

// 归还图书弹框
int return_book_message_width = 520;
int return_book_message_height = 180;

Message return_book_message(WIN_WIDTH, WIN_HEIGHT, return_book_message_width, return_book_message_height);

// 归还图书输入框
int return_book_input_width = 150;
int return_book_input_height = 30;

Input return_book_sn_input(0, 0, return_book_input_width, return_book_input_height);
Input* return_book_sn_input_ptr = &return_book_sn_input;

// 待归还图书列表
int return_book_tb_posx = 240;
int return_book_tb_posy = 120;
int return_book_tb_width = 1082;

int return_book_tb_row = 10; // 待归还图书列表行数
int return_book_tb_col = 5; // 待归还图书列表列数

Table return_book_tb(return_book_tb_posx, return_book_tb_posy, return_book_tb_width, return_book_tb_row, return_book_tb_col); // 图书列表
Table* return_book_tb_ptr = &return_book_tb;
headerList return_book_tb_hl[MAX_COL]; // 图书列表表头