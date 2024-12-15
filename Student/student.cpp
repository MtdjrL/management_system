#include "student.h"

extern int login_stu_id; // 登录的学生id
extern int stu_login_listen;
extern Student stu[MAX_STU];

int message_is_shown = 0;

Message stumess(WIN_WIDTH, WIN_HEIGHT, 520, 300);

Button stubtn(1210, 50, 120, 35);
/*函数实现*/

void ShowStuMessage() {
	stumess.open(INFO);
	message_is_shown = 1;
}
void closestumessMessage() {
	stumess.close();
	stubtn.show();
}

// 用户主界面
void stuMainInterface()
{
	readFile();
	stu_login_listen = 0;
	COLORREF color = 0xffffff;
	setlinecolor(color); // 设置线条颜色，即图形的边框颜色
	setfillcolor(color); // 设置图形的填充颜色
	fillrectangle(0, 0, WIN_WIDTH, WIN_HEIGHT);
	cleardevice();
	// 设置顶栏
	setfillcolor(RGB(183,211,241));
	setlinecolor(RGB(183, 211, 241));
	fillrectangle(0, 0, WIN_WIDTH, 40);
	// 查询按钮

	stubtn.setText(L"查 询");
	stubtn.show();
	stubtn.bindOnClick(ShowStuMessage);// 绑定

	stumess.setTitle(L"成绩");
	
	wchar_t calculus[TEXT_LEN] = L"";
	wcscat_s(calculus, L"    微 积 分：  ");
	wcscat_s(calculus, stu[login_stu_id].calculus);//微积分成绩

	wchar_t martix[TEXT_LEN] = L"";
	wcscat_s(martix, L"      线性代数：  ");
	wcscat_s(martix, stu[login_stu_id].martix);//线性代数

	wchar_t c_c[TEXT_LEN] = L"";
	wcscat_s(c_c, L"      程序设计：  ");
	wcscat_s(c_c, stu[login_stu_id].c_c);//程序设计

	wchar_t altimately[100]=L"";
	wcscat_s(altimately,calculus);
	wcscat_s(altimately,martix);
	wcscat_s(altimately,c_c);

	wchar_t hello[100] = L"欢迎您，";
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
				message_is_shown = stumess.isShow();// 更新监听状态
			}
		}
		else {
			if (stubtn.isOn(esggg.x, esggg.y)) {
				stubtn.eventLoop();
			}
		}
	}
	
}

