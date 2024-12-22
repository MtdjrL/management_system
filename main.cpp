#include "EUI/EUI.h" // 引入EUI组件库
#include "Account/account.h"
#include "Student/student.h"


int main()
{
	initgraph(WIN_WIDTH,WIN_HEIGHT);// 创建绘图窗口

	setbkcolor(RGB(255, 255, 255)); // 设置背景为白色
	cleardevice();

	initData(); // 初始化数据
	readFile(); // 读入数据

	//stuMainInterface();
	login(); // 登录

	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
