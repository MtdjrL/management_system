#include "EUI/EUI.h"
#include "Common/common.h"

// ������
extern int navbar_posx;
extern int navbar_posy;

Navbar user_navbar(navbar_posx, navbar_posy, NAV_WIDTH, WIN_HEIGHT);

// ���İ�ť
int borrow_btn_posx = 1200;
int borrow_btn_posy = 20;
int borrow_btn_width = 120;
int borrow_btn_height = 35;

Button borrow_btn(borrow_btn_posx, borrow_btn_posy, borrow_btn_width, borrow_btn_height);

// ����ͼ�鵯��
int borrow_book_message_width = 520;
int borrow_book_message_height = 180;

Message borrow_book_message(WIN_WIDTH, WIN_HEIGHT, borrow_book_message_width, borrow_book_message_height);

// ����ͼ�������
int borrow_book_input_width = 150;
int borrow_book_input_height = 30;

Input borrow_book_sn_input(0, 0, borrow_book_input_width, borrow_book_input_height);
Input* borrow_book_sn_input_ptr = &borrow_book_sn_input;

// �ɽ���ͼ���б�
int borrow_book_tb_posx = 240;
int borrow_book_tb_posy = 120;
int borrow_book_tb_width = 1082;

int borrow_book_tb_row = 10; // �ɽ���ͼ���б�����
int borrow_book_tb_col = 5; // �ɽ���ͼ���б�����

Table borrow_book_tb(borrow_book_tb_posx, borrow_book_tb_posy, borrow_book_tb_width, borrow_book_tb_row, borrow_book_tb_col); // ͼ���б�
Table* borrow_book_tb_ptr = &borrow_book_tb;
headerList borrow_book_tb_hl[MAX_COL]; // ͼ���б��ͷ

// �黹��ť
int return_btn_posx = 1200;
int return_btn_posy = 20;
int return_btn_width = 120;
int return_btn_height = 35;

Button return_btn(return_btn_posx, return_btn_posy, return_btn_width, return_btn_height);

// �黹ͼ�鵯��
int return_book_message_width = 520;
int return_book_message_height = 180;

Message return_book_message(WIN_WIDTH, WIN_HEIGHT, return_book_message_width, return_book_message_height);

// �黹ͼ�������
int return_book_input_width = 150;
int return_book_input_height = 30;

Input return_book_sn_input(0, 0, return_book_input_width, return_book_input_height);
Input* return_book_sn_input_ptr = &return_book_sn_input;

// ���黹ͼ���б�
int return_book_tb_posx = 240;
int return_book_tb_posy = 120;
int return_book_tb_width = 1082;

int return_book_tb_row = 10; // ���黹ͼ���б�����
int return_book_tb_col = 5; // ���黹ͼ���б�����

Table return_book_tb(return_book_tb_posx, return_book_tb_posy, return_book_tb_width, return_book_tb_row, return_book_tb_col); // ͼ���б�
Table* return_book_tb_ptr = &return_book_tb;
headerList return_book_tb_hl[MAX_COL]; // ͼ���б��ͷ