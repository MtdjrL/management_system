#include "EUI/EUI.h" // ����EUI�����

#define WIN_WIDTH 1800 // ���ڿ��
#define WIN_HEIGHT 900 // ���ڸ߶�

// ��ʾ�ı�
void showText()
{
	settextcolor(BLACK); // �����ı���ɫΪ��ɫ
	outtextxy(810, 460, L"�û�����˰�ť"); // �����꣨810,460������ʾ�ı�
	


}

int main()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT); // ������ͼ����

	// ���ñ���ɫ
	setbkcolor(RGB(255, 255, 255));
	cleardevice();

	Button btn(820, 320, 120, 40); // ����һ����120����40�İ�ť������Ϊ��820,320��
	btn.setText(L"���");
	btn.bindOnClick(showText); // Ϊ��ť��showText������Ϊ����¼�
	btn.show(); // ��ʾ��ť

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	while (1)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	

		// ������λ�ڰ�ť����
		if (btn.isOn(msg.x, msg.y))
		{
			btn.eventLoop();
		}
	}
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}
