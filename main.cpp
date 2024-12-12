#include "EUI/EUI.h" // 引入EUI组件库

#define WIN_WIDTH 1800 // 窗口宽度
#define WIN_HEIGHT 900 // 窗口高度

// 显示文本
void showText()
{
	settextcolor(BLACK); // 设置文本颜色为黑色
	outtextxy(810, 460, L"用户点击了按钮"); // 在坐标（810,460）下显示文本
	


}

int main()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT); // 创建绘图窗口

	// 设置背景色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();

	Button btn(820, 320, 120, 40); // 创建一个宽120，高40的按钮，坐标为（820,320）
	btn.setText(L"点击");
	btn.bindOnClick(showText); // 为按钮绑定showText函数作为点击事件
	btn.show(); // 显示按钮

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	while (1)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	

		// 如果鼠标位于按钮区域
		if (btn.isOn(msg.x, msg.y))
		{
			btn.eventLoop();
		}
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
