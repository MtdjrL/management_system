#include "student.h"

extern int login_stu_id; // ��¼��ѧ��id
extern int stu_login_listen;
extern Student stu[MAX_STU];

int message_is_shown = 0;

Message stumess(WIN_WIDTH, WIN_HEIGHT, 520, 300);

Button stubtn(1210, 50, 120, 35);
/*����ʵ��*/

void ShowStuMessage() {
	stumess.open(INFO);
	message_is_shown = 1;
}
void closestumessMessage() {
	stumess.close();
	stubtn.show();
}

// �û�������
void stuMainInterface()
{
	readFile();
	stu_login_listen = 0;
	COLORREF color = 0xffffff;
	setlinecolor(color); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(color); // ����ͼ�ε������ɫ
	fillrectangle(0, 0, WIN_WIDTH, WIN_HEIGHT);
	cleardevice();
	// ���ö���
	setfillcolor(RGB(183,211,241));
	setlinecolor(RGB(183, 211, 241));
	fillrectangle(0, 0, WIN_WIDTH, 40);
	// ��ѯ��ť

	stubtn.setText(L"�� ѯ");
	stubtn.show();
	stubtn.bindOnClick(ShowStuMessage);// ��

	stumess.setTitle(L"�ɼ�");
	
	wchar_t calculus[TEXT_LEN] = L"";
	wcscat_s(calculus, L"    ΢ �� �֣�  ");
	wcscat_s(calculus, stu[login_stu_id].calculus);//΢���ֳɼ�

	wchar_t martix[TEXT_LEN] = L"";
	wcscat_s(martix, L"      ���Դ�����  ");
	wcscat_s(martix, stu[login_stu_id].martix);//���Դ���

	wchar_t c_c[TEXT_LEN] = L"";
	wcscat_s(c_c, L"      ������ƣ�  ");
	wcscat_s(c_c, stu[login_stu_id].c_c);//�������

	wchar_t altimately[100]=L"";
	wcscat_s(altimately,calculus);
	wcscat_s(altimately,martix);
	wcscat_s(altimately,c_c);

	wchar_t hello[100] = L"��ӭ����";
	wcscat_s(hello, stu[login_stu_id].stu_id);
	
	outtextxy(1150, 10, hello);
	outtextxy(10, 10, stu[login_stu_id].name);

	stumess.setText(altimately);

	stumess.enterBtn()->bindOnClick(closestumessMessage);
	stumess.cancelBtn()->bindOnClick(closestumessMessage);


	ExMessage esggg;

	while (1) {
		esggg = getmessage(EX_MOUSE);

		
		if (message_is_shown) {
			if (stumess.isOn(esggg.x, esggg.y)) {
				stumess.eventLoop();
				message_is_shown = stumess.isShow();// ���¼���״̬
			}
		}
		else {
			if (stubtn.isOn(esggg.x, esggg.y)) {
				stubtn.eventLoop();
			}
		}
	}
	
}

