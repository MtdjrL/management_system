#include "student.h"

extern Message stu_message(WIN_WIDTH, WIN_HEIGHT, STU_MESSAGE_WIDTH, STU_MESSAGE_HEIGHT);
/*函数实现*/

void ShowStuMessage() {

}

// 用户主界面
void stuMainInterface()
{
	cleardevice();
	// 设置顶栏
	setfillcolor(RGB(183,211,241));
	setlinecolor(RGB(183, 211, 241));
	fillrectangle(0, 0, WIN_WIDTH, 40);
	
	
	
	stu_message.setTitle(L"");



}
