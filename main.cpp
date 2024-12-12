#include "EUI/EUI.h" // 引入EUI组件库
#include "Student/student.h"


int main()
{
	initgraph(WIN_WIDTH,WIN_HEIGHT);// 创建绘图窗口

	setbkcolor(RGB(255, 255, 255)); // 设置背景为白色
	cleardevice();

	stuMainInterface();


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
