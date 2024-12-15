#include "account.h"

/*�¼�����*/

int teacher_login_listen = 1; // ��ʦ��¼ҳ�����
int stu_login_listen = 1; // ѧ����¼ҳ�����
int teacher_verify_listen = 1; // ��ʦ��ȫ��֤ҳ�����
int stu_verify_listen = 1; // ѧ����ȫ��֤ҳ�����
int reset_teacher_pwd_listen = 1; // ������ʦ����ҳ�����
int reset_stu_pwd_listen = 1; // ����ѧ������ҳ�����
int stu_register_listen = 1; // ѧ��ע��ҳ�����

/*��������*/

extern Teacher teacher; // ��ʦ
extern Student stu[MAX_STU]; // ѧ��

/*ȫ�ֱ���*/

IMAGE account_icon; // �˺ſ�ͼ��
IMAGE pwd_icon; // �����ͼ��
IMAGE back_btn_icon; // ���˰�ťͼ��
IMAGE back_btn_pressed_icon; // ���˰�ť��ѹͼ��

// �˺ſ�ͼ��
int account_icon_posx = 480;
int account_icon_posy = 310;

// �����ͼ��
int pwd_icon_posx = account_icon_posx;
int pwd_icon_posy = account_icon_posy + 80;

extern int stu_num; // ѧ������
extern int cur_stu_id; // ��ǰѧ��id
extern int login_stu_id; // ��¼��ѧ��id
extern wchar_t teacher_code[TEXT_LEN]; // ��ʦ��֤��
extern wchar_t stu_code[TEXT_LEN]; // ѧ����֤��

extern Toast toast; // ����ʾ��

extern IconButton back_btn; // ���˰�ť
extern Input teacher_login_account_input; // ��ʦ��¼�˺ſ�
extern Input teacher_login_pwd_input; // ��ʦ��¼�����
extern Input stu_login_account_input; // ѧ����¼�˺ſ�
extern Input stu_login_pwd_input; // ѧ����¼�����
extern Input stu_register_account_input; // ѧ��ע���˺ſ�
extern Input stu_register_pwd_input; // ѧ��ע�������
extern Input stu_register_confirm_pwd_input; // ѧ��ע��ȷ�������
extern Input teacher_code_input; // ��ʦ��֤���
extern Input stu_code_input; // ѧ����֤���
extern Input teacher_reset_account_input; // ��ʦ���������˺ſ�
extern Input teacher_reset_pwd_input; // ��ʦ�������������
extern Input teacher_reset_confirm_pwd_input; // ��ʦ��������ȷ�������  
extern Input stu_reset_account_input; // ѧ�����������˺ſ�
extern Input stu_reset_pwd_input; // ѧ���������������
extern Input stu_reset_confirm_pwd_input; // ѧ����������ȷ�������
extern Button teacher_login_btn; // ��ʦ��¼��ť
extern Button stu_login_btn; // ѧ����¼��ť
extern Button stu_login_register_btn; // ѧ����¼ҳע���˺Ű�ť
extern Button stu_register_btn; // ѧ��ע���˺Ű�ť
extern TextButton teacher_forget_pwd_btn; // ��ʦ�������밴ť
extern TextButton teacher_stu_login_btn; // ��ʦ��¼ҳѧ����¼��ť
extern TextButton stu_forget_pwd_btn; // ѧ���������밴ť
extern TextButton stu_teacher_login_btn; // ѧ����¼ҳ��ʦ��¼��ť
extern Button teacher_verify_btn; // ��ʦ��֤��ť
extern Button stu_verify_btn; // ѧ����֤��ť
extern Button teacher_reset_btn; // ��ʦ�������밴ť
extern Button stu_reset_btn; // ѧ���������밴ť

/*����ʵ��*/

// �����ʼ��
void initInterface()
{
	IMAGE logo_icon; // logoͼ��

	// logo
	int logo_posx = 585;
	int logo_posy = 142;

	// �����ı�
	int title_text_posx = 660;
	int title_text_posy = 150;

	// �������ı�
	int sub_title_text_posx = 522;
	int sub_title_text_posy = 223;

	// ����ͼ��
	loadimage(&logo_icon, L"./pic/logo.png");
	loadimage(&account_icon, L"./pic/account.png");
	loadimage(&pwd_icon, L"./pic/password.png");
	loadimage(&back_btn_icon, L"./pic/back.png");
	loadimage(&back_btn_pressed_icon, L"./pic/back_pressed.png");

	// logo
	transparentimage(NULL, logo_posx, logo_posy, &logo_icon);

	// ����
	setFontStyle(Title);
	outtextxy(title_text_posx, title_text_posy, L"UESTG");

	// ������
	setFontStyle(SubTitle);
	outtextxy(sub_title_text_posx, sub_title_text_posy, L"������һֻ��Ч����ѧ������ϵͳ");

	// ���˰�ť
	back_btn.setIcon(back_btn_icon, back_btn_pressed_icon);
}

// ��¼
void login()
{
	initInterface(); // �����ʼ��
	teacherLoginPage(); // ��ʦ��¼
}

// ��ʦ��¼ҳ
void teacherLoginPage()
{
	stu_login_listen = 0; // �ر�ѧ����¼ҳ���¼�����

	// ˢ����Ļ
	refresh(AccountArea); 
	refresh(LeftTop);

	// ͼ��
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// �˺ſ�
	teacher_login_account_input.setHolderText(L"��ʦ�˺�");
	teacher_login_account_input.show();

	// �����
	teacher_login_pwd_input.setPassword(1);
	teacher_login_pwd_input.setHolderText(L"��ʦ����");
	teacher_login_pwd_input.show();

	// �������밴ť
	teacher_forget_pwd_btn.setText(L"��������");
	teacher_forget_pwd_btn.bindOnClick(teacherVerifyPage); // �� ��ʦ��ȫ��֤ ����
	teacher_forget_pwd_btn.show();

	// ѧ����¼��ť
	teacher_stu_login_btn.setText(L"ѧ����¼");
	teacher_stu_login_btn.bindOnClick(stuLoginPage); // �� ѧ����¼ҳ ����
	teacher_stu_login_btn.show();

	// ��¼��ť
	teacher_login_btn.setText(L"�� ¼");
	teacher_login_btn.setBkColor(RGB(72, 151, 146));
	teacher_login_btn.setBorderColor(RGB(72, 151, 146));
	teacher_login_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_login_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_login_btn.bindOnClick(teacherLogin);
	teacher_login_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	teacher_login_listen = 1; // ������ʦ��¼ҳ�����
	while (teacher_login_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����		
		// ��¼��ť
		if (teacher_login_btn.isOn(msg.x, msg.y))
		{
			teacher_login_btn.eventLoop(); // �����¼�ѭ��
		}
		// �˺ſ�
		if (teacher_login_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_login_account_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �����
		if (teacher_login_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_login_pwd_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �������밴ť
		if (teacher_forget_pwd_btn.isOn(msg.x, msg.y))
		{
			teacher_forget_pwd_btn.eventLoop(); // �����¼�ѭ��
		}
		// ѧ����¼��ť
		if (teacher_stu_login_btn.isOn(msg.x, msg.y))
		{
			teacher_stu_login_btn.eventLoop(); // �����¼�ѭ��
		}
	}
}

// ѧ����¼ҳ
void stuLoginPage()
{
	teacher_login_listen = 0; // �ر���ʦ��¼ҳ�����

	// ˢ����Ļ
	refresh(AccountArea);
	refresh(LeftTop);

	// ͼ��
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// �˺ſ�
	stu_login_account_input.setHolderText(L"ѧ���˺�");
	stu_login_account_input.show();

	// �����
	stu_login_pwd_input.setPassword(1);
	stu_login_pwd_input.setHolderText(L"ѧ������");
	stu_login_pwd_input.show();

	// �������밴ť
	stu_forget_pwd_btn.setText(L"��������");
	stu_forget_pwd_btn.bindOnClick(stuVerifyPage); // ��ѧ����ȫ��֤����
	stu_forget_pwd_btn.show();

	// ��ʦ��¼��ť
	stu_teacher_login_btn.setText(L"��ʦ��¼");
	stu_teacher_login_btn.bindOnClick(teacherLoginPage);
	stu_teacher_login_btn.show();

	// ��¼��ť
	stu_login_btn.setText(L"�� ¼");
	stu_login_btn.setBkColor(RGB(72, 151, 146));
	stu_login_btn.setBorderColor(RGB(72, 151, 146));
	stu_login_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_login_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_login_btn.bindOnClick(stuLogin);
	stu_login_btn.show();

	//// ע���˺Ű�ť
	//stu_login_register_btn.setText(L"ע���˺�");
	//stu_login_register_btn.setBkColor(RGB(72, 151, 146));
	//stu_login_register_btn.setBorderColor(RGB(93, 202, 195));
	//stu_login_register_btn.setHoverBkColor(RGB(44, 135, 129));
	//stu_login_register_btn.setPressedBkColor(RGB(25, 91, 87));
	//stu_login_register_btn.bindOnClick(stuRegisterPage);
	//stu_login_register_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	stu_login_listen = 1; // ����ѧ����¼ҳ�����
	while (stu_login_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����		
		// ��¼��ť
		if (stu_login_btn.isOn(msg.x, msg.y))
		{
			stu_login_btn.eventLoop(); // �����¼�ѭ��
		}
		// �˺ſ�
		if (stu_login_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_login_account_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �����
		if (stu_login_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_login_pwd_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �������밴ť
		if (stu_forget_pwd_btn.isOn(msg.x, msg.y))
		{
			stu_forget_pwd_btn.eventLoop(); // �����¼�ѭ��
		}
		// ��ʦ��¼��ť
		if (stu_teacher_login_btn.isOn(msg.x, msg.y))
		{
			stu_teacher_login_btn.eventLoop(); // �����¼�ѭ��
		}
		//// ע�ᰴť
		//if (stu_login_register_btn.isOn(msg.x, msg.y))
		//{
		//	stu_login_register_btn.eventLoop(); // �����¼�ѭ��
		//}
	}
}

// ��ʦ��¼
void teacherLogin()
{
	int not_empty = 0; // �ǿձ�ʶ

	wchar_t* account = teacher_login_account_input.text(); // ��ȡ�˺�
	wchar_t* password = teacher_login_pwd_input.text(); // ��ȡ����

	// �ǿ�
	if (wcslen(account) != 0 && wcslen(password) != 0)
	{
		not_empty = 1;
	}

	// ��
	if (not_empty == 0)
	{
		// ��ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// У��ͨ��
		if (wcscmp(account, teacher.account) == 0 && wcscmp(password, teacher.password) == 0)
		{
			TeacherMainInterface(); // ��ת����ʦ������
		}
		// У��δͨ��
		else
		{
			// ѧ����ʾ
			toast.setText(L"�˺Ż������������������");
			toast.show(WARNING);
		}
	}
}

// ѧ����¼
void stuLogin()
{
	int not_empty = 0; // �ǿձ�ʶ

	wchar_t* account = stu_login_account_input.text(); // ��ȡ�˺�
	wchar_t* password = stu_login_pwd_input.text(); // ��ȡ����

	int id = 0; // ��¼��ѧ��id

	// �ǿ�
	if (wcslen(account) != 0 && wcslen(password) != 0)
	{
		not_empty = 1;
	}

	// ��
	if (not_empty == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// �����˺�
		for (int i = 0; i < stu_num; i++)
		{
			// ��ѯ����
			if (wcscmp(stu[i].account, account) == 0)
			{
				// У��ͨ��
				if (wcscmp(stu[i].password, password) == 0)
				{
					login_stu_id = stu[i].id; // ��¼��¼ѧ����id
					stuMainInterface(); // ��ת��ѧ��������
				}
				// У��δͨ��
				else
				{
					// ѧ����ʾ
					toast.setText(L"�˺Ż������������������");
					toast.show(WARNING);
				}
				break;
			}
		}
	}
}

// ѧ��ע��ҳ
/*void stuRegisterPage()
{
	stu_login_listen = 0; // �ر�ѧ����¼ҳ�����

	refresh(AccountArea); // ˢ����Ļ

	// ���˰�ť
	back_btn.bindOnClick(stuLoginPage); // �� ѧ����¼ҳ ����
	back_btn.show();

	// ͼ��
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// �˺ſ�
	stu_register_account_input.setHolderText(L"�˺�");
	stu_register_account_input.show();

	// �����
	stu_register_pwd_input.setPassword(1);
	stu_register_pwd_input.setHolderText(L"����");
	stu_register_pwd_input.show();

	// ȷ�������
	stu_register_confirm_pwd_input.setPassword(1);
	stu_register_confirm_pwd_input.setHolderText(L"ȷ������");
	stu_register_confirm_pwd_input.show();

	// ע�ᰴť
	stu_register_btn.setText(L"ע ��");
	stu_register_btn.setBkColor(RGB(72, 151, 146));
	stu_register_btn.setBorderColor(RGB(72, 151, 146));
	stu_register_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_register_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_register_btn.bindOnClick(stuRegister); // �� ѧ��ע�� ����
	stu_register_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	stu_register_listen = 1; // ����ѧ��ע��ҳ�����
	while (stu_register_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����		
		// ���˰�ť
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // �¼�ѭ��

		}
		// ע�ᰴť
		if (stu_register_btn.isOn(msg.x, msg.y))
		{
			stu_register_btn.eventLoop(); // �����¼�ѭ��
		}
		// �˺ſ�
		if (stu_register_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_account_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �����
		if (stu_register_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_pwd_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// ȷ�������
		if (stu_register_confirm_pwd_input.isOn(msg.x,msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_confirm_pwd_input.eventLoop();
			}
		}
	}
}*/
/*
// ѧ��ע��
void stuRegister()
{
	int valid = 0; // ����Ϸ���ʶ
	int not_empty = 0; // �ǿձ�ʶ
	int equal = 0; // ��������������ȱ�ʶ

	wchar_t* account = stu_register_account_input.text(); // ��ȡ�˺�
	wchar_t* password = stu_register_pwd_input.text(); // ��ȡ����
	wchar_t* confirm_password = stu_register_confirm_pwd_input.text(); // ��ȡȷ������

	// �ǿ�
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// ���������������
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// ��
	if (not_empty == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// �����������벻���
		if (equal == 0)
		{
			// ѧ����ʾ
			toast.setText(L"�����������벻��ȣ�����������");
			toast.show(WARNING);
		}
		// �ǿ������������������
		else
		{
			valid = 1; // ����Ϸ�
		}
	}

	// ����Ϸ���ע���˺�
	if (valid)
	{
		stu[stu_num].id = cur_stu_id++;
		wcscpy_s(stu[stu_num].account, account);
		wcscpy_s(stu[stu_num].password, password);
		stu_num++;
		writeFile(); // ������д���ļ�

		// ѧ����ʾ
		toast.setText(L"ע��ɹ�");
		toast.show(SUCCESS);

		stuLoginPage(); // ��ת��ѧ����¼ҳ
	}
}*/

// ��ʦ��ȫ��֤ҳ
void teacherVerifyPage()
{
	teacher_login_listen = 0; // �ر���ʦ��¼ҳ�����

	refresh(AccountArea); // ˢ����Ļ

	// ���˰�ť
	back_btn.bindOnClick(teacherLoginPage); // �� ��ʦ��¼ҳ ����
	back_btn.show();

	// ��֤���
	teacher_code_input.setHolderText(L"��֤��");
	teacher_code_input.show();

	// ��֤��ť
	teacher_verify_btn.setText(L"�� ֤");
	teacher_verify_btn.setBkColor(RGB(72, 151, 146));
	teacher_verify_btn.setBorderColor(RGB(72, 151, 146));
	teacher_verify_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_verify_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_verify_btn.bindOnClick(teacherVerify); // �� ��ʦ��ȫ��֤ ����
	teacher_verify_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	teacher_verify_listen = 1; // ������ʦ��¼ҳ�����
	while (teacher_verify_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// ���˰�ť
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // �¼�ѭ��
			
		}
		// ��֤��ť
		if (teacher_verify_btn.isOn(msg.x, msg.y))
		{
			teacher_verify_btn.eventLoop(); // �����¼�ѭ��
		}
		// ��֤���
		if (teacher_code_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_code_input.eventLoop(); // �����¼�ѭ��
			}
		}
	}
}

// ѧ����ȫ��֤ҳ
void stuVerifyPage()
{
	stu_login_listen = 0; // �ر�ѧ����¼ҳ�����

	refresh(AccountArea); // ˢ����Ļ

	// ���˰�ť
	back_btn.bindOnClick(stuLoginPage); // �� ѧ����¼ҳ ����
	back_btn.show();

	// ��֤���
	stu_code_input.setHolderText(L"��֤��");
	stu_code_input.show();

	// ��֤��ť
	stu_verify_btn.setText(L"�� ֤");
	stu_verify_btn.setBkColor(RGB(72, 151, 146));
	stu_verify_btn.setBorderColor(RGB(72, 151, 146));
	stu_verify_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_verify_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_verify_btn.bindOnClick(stuVerify); // �� ѧ����ȫ��֤ ����
	stu_verify_btn.show();

		
	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	stu_verify_listen = 1; // ������ʦ��¼ҳ�����
	while (stu_verify_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����
		// ���˰�ť
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // �¼�ѭ��

		}
		// ��֤��ť
		if (stu_verify_btn.isOn(msg.x, msg.y))
		{
			stu_verify_btn.eventLoop(); // �����¼�ѭ��
		}
		// ��֤���
		if (stu_code_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_code_input.eventLoop(); // �����¼�ѭ��
			}
		}
	}
}

// ��ʦ��ȫ��֤
void teacherVerify()
{
	wchar_t* code = teacher_code_input.text(); // ��ȡ��֤��

	// ��
	if (wcslen(code) == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// У��ͨ��
		if (wcscmp(code, teacher_code) == 0)
		{
			resetTeacherPasswordPage(); // ��ת��������ʦ����ҳ
		}
		// У��δͨ��
		else
		{
			// ѧ����ʾ
			toast.setText(L"��֤���������������");
			toast.show(WARNING);
		}
	}
}

// ѧ����ȫ��֤
void stuVerify()
{
	wchar_t* code = stu_code_input.text(); // ��ȡ��֤��

// ��
	if (wcslen(code) == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// У��ͨ��
		if (wcscmp(code, stu_code) == 0)
		{
			resetStuPasswordPage(); // ��ת��������ʦ����ҳ
		}
		// У��δͨ��
		else
		{
			// ѧ����ʾ
			toast.setText(L"��֤���������������");
			toast.show(WARNING);
		}
	}
}

// ������ʦ����ҳ
void resetTeacherPasswordPage()
{
	teacher_verify_listen = 0; // �ر���ʦ��ȫ��֤ҳ�����

	// ˢ����Ļ
	refresh(AccountArea);

	// ���˰�ť
	back_btn.bindOnClick(teacherVerifyPage); // �� ��ʦ��ȫ��֤ҳ ����
	back_btn.show();

	// ͼ��
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// �˺ſ�
	teacher_reset_account_input.setHolderText(L"�˺�");
	teacher_reset_account_input.show();

	// �����
	teacher_reset_pwd_input.setPassword(1);
	teacher_reset_pwd_input.setHolderText(L"����");
	teacher_reset_pwd_input.show();

	// ȷ�������
	teacher_reset_confirm_pwd_input.setPassword(1);
	teacher_reset_confirm_pwd_input.setHolderText(L"ȷ������");
	teacher_reset_confirm_pwd_input.show();

	// �������밴ť
	teacher_reset_btn.setText(L"�� ��");
	teacher_reset_btn.setBkColor(RGB(72, 151, 146));
	teacher_reset_btn.setBorderColor(RGB(72, 151, 146));
	teacher_reset_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_reset_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_reset_btn.bindOnClick(resetTeacherPassword); // �� ������ʦ���� ����
	teacher_reset_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	reset_teacher_pwd_listen = 1; // ����������ʦ����ҳ�����
	while (reset_teacher_pwd_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// ���˰�ť
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // �¼�ѭ��
		}
		// ���ð�ť
		if (teacher_reset_btn.isOn(msg.x, msg.y))
		{
			teacher_reset_btn.eventLoop(); // �����¼�ѭ��
		}
		// �˺ſ�
		if (teacher_reset_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_account_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �����
		if (teacher_reset_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_pwd_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// ȷ�������
		if (teacher_reset_confirm_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_confirm_pwd_input.eventLoop();
			}
		}
	}
}

// ����ѧ������ҳ
void resetStuPasswordPage()
{
	stu_verify_listen = 0; // �ر�ѧ����ȫ��֤ҳ�����

	refresh(AccountArea); // ˢ����Ļ

	// ���˰�ť
	back_btn.bindOnClick(stuVerifyPage); // �� ѧ����ȫ��֤ҳ ����
	back_btn.show();

	// ͼ��
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// �˺ſ�
	stu_reset_account_input.setHolderText(L"�˺�");
	stu_reset_account_input.show();

	// �����
	stu_reset_pwd_input.setPassword(1);
	stu_reset_pwd_input.setHolderText(L"����");
	stu_reset_pwd_input.show();

	// ȷ�������
	stu_reset_confirm_pwd_input.setPassword(1);
	stu_reset_confirm_pwd_input.setHolderText(L"ȷ������");
	stu_reset_confirm_pwd_input.show();

	// �������밴ť
	stu_reset_btn.setText(L"�� ��");
	stu_reset_btn.setBkColor(RGB(72, 151, 146));
	stu_reset_btn.setBorderColor(RGB(72, 151, 146));
	stu_reset_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_reset_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_reset_btn.bindOnClick(resetStuPassword);
	stu_reset_btn.show();

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	reset_stu_pwd_listen = 1; // ����������ʦ����ҳ�����
	while (reset_stu_pwd_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// ���˰�ť
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // �¼�ѭ��
		}
		// ���ð�ť
		if (stu_reset_btn.isOn(msg.x, msg.y))
		{
			stu_reset_btn.eventLoop(); // �����¼�ѭ��
		}
		// �˺ſ�
		if (stu_reset_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_account_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// �����
		if (stu_reset_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_pwd_input.eventLoop(); // �����¼�ѭ��
			}
		}
		// ȷ�������
		if (stu_reset_confirm_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_confirm_pwd_input.eventLoop();
			}
		}
	}
}

// ������ʦ����
void resetTeacherPassword()
{
	int valid = 0; // ����Ϸ���ʶ
	int not_empty = 0; // �ǿձ�ʶ
	int equal = 0; // ��������������ȱ�ʶ

	wchar_t* account = teacher_reset_account_input.text(); // ��ȡ�˺�
	wchar_t* password = teacher_reset_pwd_input.text(); // ��ȡ����
	wchar_t* confirm_password = teacher_reset_confirm_pwd_input.text(); // ��ȡ������������

	// �ǿ�
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// ���������������
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// ��
	if (not_empty == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// �����������벻���
		if (equal == 0)
		{
			// ѧ����ʾ
			toast.setText(L"�����������벻��ȣ�����������");
			toast.show(WARNING);
		}
		// �ǿ������������������
		else
		{
			valid = 1; // ����Ϸ�
		}
	}

	// ����Ϸ�
	if (valid)
	{
		// �˺�ƥ��
		if (wcscmp(account, teacher.account) == 0)
		{
			wcscpy_s(teacher.password, password); // �޸�����
			writeFile(); // ������д���ļ�

			// ѧ����ʾ
			toast.setText(L"�����޸ĳɹ�");
			toast.show(SUCCESS);

			teacherLoginPage(); // ��ת����ʦ��¼ҳ
		}
		// �˺Ų�ƥ��
		else
		{
			// ѧ����ʾ
			toast.setText(L"�˺Ŵ�������������");
			toast.show(WARNING);
		}
	}
}

// ����ѧ������
void resetStuPassword()
{
	int valid = 0; // ����Ϸ���ʶ
	int not_empty = 0; // �ǿձ�ʶ
	int equal = 0; // ��������������ȱ�ʶ

	wchar_t* account = stu_reset_account_input.text(); // ��ȡ�˺�
	wchar_t* password = stu_reset_pwd_input.text(); // ��ȡ����
	wchar_t* confirm_password = stu_reset_confirm_pwd_input.text(); // ��ȡ������������

	// �ǿ�
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// ���������������
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// ��
	if (not_empty == 0)
	{
		// ѧ����ʾ
		toast.setText(L"�������ݲ���Ϊ�գ�����������");
		toast.show(WARNING);
	}
	// �ǿ�
	else
	{
		// �����������벻���
		if (equal == 0)
		{
			// ѧ����ʾ
			toast.setText(L"�����������벻��ȣ�����������");
			toast.show(WARNING);
		}
		// �ǿ������������������
		else
		{
			valid = 1; // ����Ϸ�
		}
	}

	int index = -1; // ѧ������

	// ����Ϸ�
	if (valid)
	{
		// �����˺�
		for (int i = 0; i < stu_num; i++)
		{
			// ��ѯ����
			if (wcscmp(stu[i].account, account) == 0)
			{
				index = i; // ��¼ѧ������
				break;
			}
		}

		// ��ѯ����
		if (index >= 0 && index < stu_num)
		{
			wcscpy_s(stu[index].password, password); // �޸�����
			writeFile(); // ������д���ļ�

			// ѧ����ʾ
			toast.setText(L"�����޸ĳɹ�");
			toast.show(SUCCESS);

			stuLoginPage(); // ��ת��ѧ����¼ҳ
		}
		// ��ѯδ����
		else
		{
			// ѧ����ʾ
			toast.setText(L"�˺Ŵ�������������");
			toast.show(WARNING);
		}
	}
}


