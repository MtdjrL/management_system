#include "EUI/EUI.h"
#include "Common/common.h"

// �˺ſ�
int account_input_posx = 533;
int account_input_posy = 310;
int account_input_width = 300;
int account_input_height = 30;

// �����
int pwd_input_posx = account_input_posx;
int pwd_input_posy = account_input_posy + 80;
int pwd_input_width = account_input_width;
int pwd_input_height = account_input_height;

// ȷ�������
int pwd_confirm_input_posx = pwd_input_posx;
int pwd_confirm_input_posy = pwd_input_posy + 50;

// ��ʦ��¼�˺ſ�
Input teacher_login_account_input(account_input_posx, account_input_posy, account_input_width, account_input_height);

// ��ʦ��¼�����
Input teacher_login_pwd_input(pwd_input_posx, pwd_input_posy, pwd_input_width, pwd_input_height);

// ѧ����¼�˺ſ�
Input stu_login_account_input(account_input_posx, account_input_posy, account_input_width, account_input_height);

// ѧ����¼�����
Input stu_login_pwd_input(pwd_input_posx, pwd_input_posy, pwd_input_width, pwd_input_height);

// ѧ��ע���˺ſ�
Input stu_register_account_input(account_input_posx, account_input_posy, account_input_width, account_input_height);

// ѧ��ע�������
Input stu_register_pwd_input(pwd_input_posx, pwd_input_posy, pwd_input_width, pwd_input_height);

// ѧ��ע��ȷ�������
Input stu_register_confirm_pwd_input(pwd_confirm_input_posx, pwd_confirm_input_posy, pwd_input_width, pwd_input_height);

// ��ʦ���������˺ſ�
Input teacher_reset_account_input(account_input_posx, account_input_posy, account_input_width, account_input_height);

// ��ʦ�������������
Input teacher_reset_pwd_input(pwd_input_posx, pwd_input_posy, pwd_input_width, pwd_input_height);

// ��ʦ��������ȷ�������
Input teacher_reset_confirm_pwd_input(pwd_confirm_input_posx, pwd_confirm_input_posy, pwd_input_width, pwd_input_height);

// ѧ�����������˺ſ�
Input stu_reset_account_input(account_input_posx, account_input_posy, account_input_width, account_input_height);

// ѧ���������������
Input stu_reset_pwd_input(pwd_input_posx, pwd_input_posy, pwd_input_width, pwd_input_height);

// ѧ����������ȷ�������
Input stu_reset_confirm_pwd_input(pwd_confirm_input_posx, pwd_confirm_input_posy, pwd_input_width, pwd_input_height);

// ��֤���
int code_input_posx = account_input_posx;
int code_input_posy = 340;
int code_input_width = account_input_width;
int code_input_height = 30;

// ��ʦ��֤���
Input teacher_code_input(code_input_posx, code_input_posy, code_input_width, code_input_height);

// ѧ����֤���
Input stu_code_input(code_input_posx, code_input_posy, code_input_width, code_input_height);

// ��¼��ť
int login_btn_posx = account_input_posx;
int login_btn_posy = 480;
int login_btn_width = account_input_width;
int login_btn_height = 40;

// ��ʦ��¼��ť
Button teacher_login_btn(login_btn_posx, login_btn_posy, login_btn_width, login_btn_height);

// ѧ����¼��ť
Button stu_login_btn(login_btn_posx, login_btn_posy, login_btn_width, login_btn_height);

// ѧ����¼ҳע���˺Ű�ť
int login_register_btn_posx = login_btn_posx;
int login_register_btn_posy = login_btn_posy + 50;
int login_register_btn_width = login_btn_width;
int login_register_btn_height = login_btn_height;

Button stu_login_register_btn(login_register_btn_posx, login_register_btn_posy, login_register_btn_width, login_register_btn_height);

// ѧ��ע���˺Ű�ť
int register_btn_posx = login_btn_posx;
int register_btn_posy = 500;
int register_btn_width = login_btn_width;
int register_btn_height = login_btn_height;

Button stu_register_btn(register_btn_posx, register_btn_posy, register_btn_width, register_btn_height);

// �������밴ť
int forget_pwd_btn_posx = 527;
int forget_pwd_btn_posy = 435;
int forget_pwd_btn_width = 78;
int forget_pwd_btn_height = 30;

// ��ʦ�������밴ť
TextButton teacher_forget_pwd_btn(forget_pwd_btn_posx, forget_pwd_btn_posy, forget_pwd_btn_width, forget_pwd_btn_height);

// ѧ���������밴ť
TextButton stu_forget_pwd_btn(forget_pwd_btn_posx, forget_pwd_btn_posy, forget_pwd_btn_width, forget_pwd_btn_height);

// ��ʦ��¼ҳѧ����¼��ť
int teacher_stu_login_btn_posx = 768;
int teacher_stu_login_btn_posy = forget_pwd_btn_posy;
int teacher_stu_login_btn_width = forget_pwd_btn_width;
int teacher_stu_login_btn_height = forget_pwd_btn_height;

TextButton teacher_stu_login_btn(teacher_stu_login_btn_posx, teacher_stu_login_btn_posy, teacher_stu_login_btn_width, teacher_stu_login_btn_height);

// ѧ����¼ҳ��ʦ��¼��ť
int stu_teacher_login_btn_posx = 750;
int stu_teacher_login_btn_posy = forget_pwd_btn_posy;
int stu_teacher_login_btn_width = forget_pwd_btn_width + 20;
int stu_teacher_login_btn_height = forget_pwd_btn_height;

TextButton stu_teacher_login_btn(stu_teacher_login_btn_posx, stu_teacher_login_btn_posy, stu_teacher_login_btn_width, stu_teacher_login_btn_height);

// ��֤��ť
int verify_btn_posx = login_btn_posx;
int verify_btn_posy = 430;
int verify_btn_width = login_btn_width;
int verify_btn_height = login_btn_height;

// ��ʦ��֤��ť
Button teacher_verify_btn(verify_btn_posx, verify_btn_posy, verify_btn_width, verify_btn_height);

// ѧ����֤��ť
Button stu_verify_btn(verify_btn_posx, verify_btn_posy, verify_btn_width, verify_btn_height);

// �������밴ť
int reset_pwd_btn_posx = login_btn_posx;
int reset_pwd_btn_posy = 500;
int reset_pwd_btn_width = login_btn_width;
int reset_pwd_btn_height = login_btn_height;

// ��ʦ�������밴ť
Button teacher_reset_btn(reset_pwd_btn_posx, reset_pwd_btn_posy, reset_pwd_btn_width, reset_pwd_btn_height);

// ѧ���������밴ť
Button stu_reset_btn(reset_pwd_btn_posx, reset_pwd_btn_posy, reset_pwd_btn_width, reset_pwd_btn_height);

// ���˰�ť
int back_btn_posx = 10;
int back_btn_posy = 10;
int back_btn_width = 25; // ��ͼƬ����һ��
int back_btn_height = 25; // ��ͼƬ����һ��

IconButton back_btn(back_btn_posx, back_btn_posy, back_btn_width, back_btn_height);

