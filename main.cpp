#include "EUI/EUI.h" // ����EUI�����
#include "Student/student.h"


int main()
{
	initgraph(WIN_WIDTH,WIN_HEIGHT);// ������ͼ����

	setbkcolor(RGB(255, 255, 255)); // ���ñ���Ϊ��ɫ
	cleardevice();

	stuMainInterface();


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}
