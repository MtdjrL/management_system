#include "EUI/EUI.h" // ����EUI�����
#include "Account/account.h"
#include "Student/student.h"


int main()
{
	initgraph(WIN_WIDTH,WIN_HEIGHT);// ������ͼ����

	setbkcolor(RGB(255, 255, 255)); // ���ñ���Ϊ��ɫ
	cleardevice();

	initData(); // ��ʼ������
	readFile(); // ��������

	//stuMainInterface();
	login(); // ��¼

	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}
