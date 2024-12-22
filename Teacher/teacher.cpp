#include "teacher.h"

/*�¼�����*/

int stu_management_listen = 1; // ѧ������ҳ�����
int homepage_listen = 1;

/*��������*/

extern Student stu[MAX_STU]; // ѧ��

/*ȫ�ֱ���*/

int add_stu_message_show = 0; // ���ѧ���������ʾ״̬
int modify_stu_message_show = 0; // �޸�ѧ���������ʾ״̬
int del_stu_message_show = 0; // ɾ��ѧ���������ʾ״̬
int add_stu_pair_flag = 0; // ���ѧ���������ı�-�������Ƿ���ӱ�־������ֹ��ε���ѧ��������ʱ�ظ����
int modify_stu_pair_flag = 0; // �޸�ѧ���������ı�-�������Ƿ���ӱ�־������ֹ��ε���ѧ��������ʱ�ظ����
int del_stu_pair_flag = 0; // ɾ��ѧ���������ı�-�������Ƿ���ӱ�־������ֹ��ε���ѧ��������ʱ�ظ����

extern int cur_stu_id; // ��ǰѧ��id
extern int stu_num; // ѧ������

extern Navbar teacher_navbar; // ������
extern Toast toast; // ����ʾ��

extern Input search_stu_input; // ����ѧ�������
extern int stu_tb_row; // ѧ���б�����
extern int stu_tb_col; // ѧ���б�����
extern Button search_btn; // ������ť
extern Button add_btn; // ��Ӱ�ť
extern Button modify_btn; // �޸İ�ť
extern Button del_btn; // ɾ����ť
extern Table* stu_tb_ptr; // ѧ���б�
extern headerList stu_tb_hl[MAX_COL]; // ѧ���б��ͷ
extern Message add_stu_message; // ���ѧ������
extern Input* add_stu_stu_id_input_ptr; // ���ѧ������ѧ�������
extern Input* add_stu_name_input_ptr; // ���ѧ���������������
extern Input* add_stu_class_input_ptr; // ���ѧ������༶�����
extern Input* add_stu_calculus_input_ptr; // ���ѧ������΢���������
extern Input* add_stu_martix_input_ptr; // ���ѧ���������Դ��������
extern Input* add_stu_c_c_input_ptr; // ���ѧ�����������������
extern Message modify_stu_message; // �޸�ѧ������
extern Input* modify_stu_stu_id_input_ptr; // �޸�ѧ������ѧ�������
extern Input* modify_stu_name_input_ptr; // �޸�ѧ���������������
extern Input* modify_stu_class_input_ptr; // �޸�ѧ������༶�����
extern Input* modify_stu_calculus_input_ptr; // �޸�ѧ������΢���������
extern Input* modify_stu_martix_input_ptr; // �޸�ѧ���������Դ��������
extern Input* modify_stu_c_c_input_ptr; // �޸�ѧ�����������������
extern Message del_stu_message; // ɾ��ѧ������
extern Input* del_stu_stu_id_input_ptr;  // ɾ��ѧ������ѧ�������

/*����ʵ��*/

// ����Ա������
void TeacherMainInterface()
{
	// ��������ť
	NavButton nav_btn1(NAV_WIDTH, NAV_BUTTON_HEIGHT); // ��ҳ
	NavButton nav_btn2(NAV_WIDTH, NAV_BUTTON_HEIGHT); // ѧ������

	// ��������ťָ��
	NavButton* nav_btn1_ptr = &nav_btn1;
	NavButton* nav_btn2_ptr = &nav_btn2;

	teacher_navbar.setTitleFontSize(22);
	teacher_navbar.setTitleText(L"UESTG");

	nav_btn1_ptr->setText(L"��ҳ");
	nav_btn2_ptr->setText(L"ѧ������");

	teacher_navbar.addNavButton(nav_btn1_ptr);
	teacher_navbar.addNavButton(nav_btn2_ptr);

	// Ϊ��������ť�󶨵���¼�
	nav_btn1_ptr->bindOnClick(homepage); // �� ��ҳ
	nav_btn2_ptr->bindOnClick(stuManagementPage); // �� ѧ������

	teacher_navbar.setGap(70); // ���õ�������ť���ּ��
	teacher_navbar.show(); // ��ʾ������

	homepage(); // Ĭ�Ͻ�����ҳ
	//stuManagementPage();
}

// ��ҳ
void homepage()
{
	stu_management_listen = 0; // �ر�ѧ������ҳҳ�����

	refresh(NavbarMatchArea); // ˢ����Ļ

	IMAGE stu_num_icon; // ѧ������ͼ��

	wchar_t stu_num_text[TEXT_LEN]; // ѧ������
	wsprintfW(stu_num_text, L"%d", stu_num);

	// ���ı���ɫ
	int startx = NAV_WIDTH + 1;
	int starty = 0;
	int endx = WIN_WIDTH;
	int endy = WIN_HEIGHT;

	COLORREF color = RGB(238, 240, 243); // ������ɫ
	setlinecolor(color); // ����������ɫ����ͼ�εı߿���ɫ
	setfillcolor(color); // ����ͼ�ε������ɫ
	fillrectangle(startx, starty, endx, endy);

	// չʾ��
	color = RGB(255, 255, 255); // չʾ����ɫ
	setlinecolor(color);
	setfillcolor(color);
	setFontStyle(RecText);

	int title_posx = 0;
	int title_posy = 0;
	int title_left_margin = 150; // չʾ�������߾�
	int title_top_margin = 35; // չʾ������ϱ߾�
	int text_posx = 0;
	int text_posy = 0;
	int text_left_margin = 190; // չʾ���ı���߾�
	int text_top_margin = 70; // չʾ���ı��ϱ߾�
	int icon_left_margin = 20;
	int icon_top_margin = 20;

	int width = 249; 
	int height = 120;
	int gap = 30; // չʾ����
	int radius = 15; // չʾ��Բ��

	starty = 50;
	endy = starty + height;

	// չʾ��1
	startx = NAV_WIDTH + 40;
	endx = startx + width;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	//loadimage(&stu_num_icon, L"./pic/stu_num.png");
	//transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &stu_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"ѧ������");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, stu_num_text);

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	homepage_listen = 1; // ������ҳҳ�����
	while (homepage_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// ������
		if (teacher_navbar.isOn(msg.x, msg.y))
		{
			teacher_navbar.eventLoop(); // �����¼�ѭ��
		}
	}
}

// ѧ������
void stuManagementPage()
{
	refresh(NavbarMatchArea); // ˢ����Ļ

	// ����ѧ�������
	search_stu_input.setHolderText(L"����");
	search_stu_input.show();

	// ������ť
	search_btn.setText(L"�� ��");
	search_btn.bindOnClick(searchStu);
	search_btn.show();

	// ������ť
	add_btn.setText(L"�� ��");
	add_btn.bindOnClick(openAddStuMessage);
	add_btn.show();

	// �޸İ�ť
	modify_btn.setText(L"�� ��");
	modify_btn.bindOnClick(openModifyStuMessage);
	modify_btn.show();

	// ɾ����ť
	del_btn.setText(L"ɾ ��");
	del_btn.setBkColor(RGB(199, 74, 61));
	del_btn.setBorderColor(RGB(213, 67, 52));
	del_btn.setHoverBkColor(RGB(178,58,45));
	del_btn.setPressedBkColor(RGB(162, 46, 34));
	del_btn.bindOnClick(openDelStuMessage);
	del_btn.show();

	// ѧ���б�
	int tb_width[] = { 20,10,20,20,20,20 }; // �п��������λΪ%����Ϊ100
	stu_tb_ptr->setGridWidth(tb_width); // �趨�п�
	setTableHeader(StuTable, stu_tb_hl); // �����б��ͷ
	searchStu(); // Ĭ������ѧ����Ĭ��������ֵΪ�գ����Ϊ��ѯ��������

	// ���ѧ������
	add_stu_message.setTitle(L"���ѧ��"); // ���ñ���
	// δ������ѧ��������ı�-������
	if (add_stu_pair_flag == 0)
	{
		// ����ı��������
		add_stu_message.addLabel(L"ѧ��"); 
		add_stu_message.addInput(add_stu_stu_id_input_ptr); 
		add_stu_message.addLabel(L"����"); 
		add_stu_message.addInput(add_stu_name_input_ptr); 
		add_stu_message.addLabel(L"�༶"); 
		add_stu_message.addInput(add_stu_class_input_ptr); 
		add_stu_message.addLabel(L"΢����");
		add_stu_message.addInput(add_stu_calculus_input_ptr);
		add_stu_message.addLabel(L"���Դ���");
		add_stu_message.addInput(add_stu_martix_input_ptr);
		add_stu_message.addLabel(L"�������");
		add_stu_message.addInput(add_stu_c_c_input_ptr);
		
		add_stu_pair_flag = 1; // ��ʾ������ı�-������
	}
	add_stu_message.cancelBtn()->bindOnClick(closeAddStuMessage); // ȡ����ť�󶨹رյ�����
	add_stu_message.enterBtn()->bindOnClick(addStu);

	// �޸�ѧ������
	modify_stu_message.setTitle(L"�޸�ѧ��"); // ���ñ���
	// δ����޸�ѧ��������ı�-������
	if (modify_stu_pair_flag == 0)
	{
		// ����ı��������
		modify_stu_message.addLabel(L"ѧ��");
		modify_stu_message.addInput(modify_stu_stu_id_input_ptr);
		modify_stu_message.addLabel(L"����");
		modify_stu_message.addInput(modify_stu_name_input_ptr);
		modify_stu_message.addLabel(L"�༶");
		modify_stu_message.addInput(modify_stu_class_input_ptr);
		modify_stu_message.addLabel(L"΢����");
		modify_stu_message.addInput(modify_stu_calculus_input_ptr);
		modify_stu_message.addLabel(L"���Դ���");
		modify_stu_message.addInput(modify_stu_martix_input_ptr);
		modify_stu_message.addLabel(L"�������");
		modify_stu_message.addInput(modify_stu_c_c_input_ptr);

		modify_stu_pair_flag = 1; // ��ʾ������ı�-������
	}
	modify_stu_message.cancelBtn()->bindOnClick(closeModifyStuMessage); // ȡ����ť�󶨹رյ�����
	modify_stu_message.enterBtn()->bindOnClick(modifyStu);

	// ɾ��ѧ������
	del_stu_message.setTitle(L"ɾ��ѧ��"); // ���ñ���
	// δ���ɾ��ѧ��������ı�-������
	if (del_stu_pair_flag == 0)
	{
		// ����ı��������
		del_stu_message.addLabel(L"ѧ�����");
		del_stu_message.addInput(del_stu_stu_id_input_ptr);

		del_stu_pair_flag = 1; // ��ʾ������ı�-������
	}
	del_stu_message.cancelBtn()->bindOnClick(closeDelStuMessage); // ȡ����ť�󶨹رյ�����
	del_stu_message.enterBtn()->bindOnClick(delStu); // ȷ�ϰ�ť�󶨴򿪵�����

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	stu_management_listen = 1; // ����ѧ������ҳ���¼�����
	while (stu_management_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// �е����
		if (del_stu_message_show || add_stu_message_show || modify_stu_message_show)
		{
			// ɾ��ѧ������
			if (del_stu_message_show)
			{
				if (del_stu_message.isOn(msg.x, msg.y))
				{
					del_stu_message.eventLoop(); // �����¼�ѭ��
					del_stu_message_show = del_stu_message.isShow(); // ���µ������ʾ״̬
				}
			}
			// ���ѧ������
			if (add_stu_message_show)
			{
				if (add_stu_message.isOn(msg.x, msg.y))
				{
					add_stu_message.eventLoop(); // �����¼�ѭ��
					add_stu_message_show = add_stu_message.isShow(); // ���µ������ʾ״̬
				}
			}
			// �޸�ѧ������
			if (modify_stu_message_show)
			{
				if (modify_stu_message.isOn(msg.x, msg.y))
				{
					modify_stu_message.eventLoop(); // �����¼�ѭ��
					modify_stu_message_show = modify_stu_message.isShow(); // ���µ������ʾ״̬
				}
			}
		}
		// �޵����
		else
		{
			// ������
			if (teacher_navbar.isOn(msg.x, msg.y))
			{
				teacher_navbar.eventLoop(); // �����¼�ѭ��
			}
			// ������
			if (search_stu_input.isOn(msg.x, msg.y))
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					search_stu_input.eventLoop(); // �����¼�ѭ��
				}
			}
			// ������ť
			if (search_btn.isOn(msg.x, msg.y))
			{
				search_btn.eventLoop(); // �����¼�ѭ��
			}
			// ��Ӱ�ť
			if (add_btn.isOn(msg.x, msg.y))
			{
				add_btn.eventLoop(); // �����¼�ѭ��
			}
			// �޸İ�ť
			if (modify_btn.isOn(msg.x, msg.y))
			{
				modify_btn.eventLoop(); // �����¼�ѭ��
			}
			// ɾ����ť
			if (del_btn.isOn(msg.x, msg.y))
			{
				del_btn.eventLoop(); // �����¼�ѭ��
			}
		}
	}
}

// ����ѧ��
void searchStu()
{
	refresh(TableArea);// ��ѯǰ��ˢ����Ļ

	wchar_t* search_str = search_stu_input.text(); // ��ȡ������ı�,��Ϊ�����ı�

	int mapping[MAX_STU] = { 0 }; // ӳ�����飬0��ʾ��ӳ�䣬1��ʾӳ��

	// �ؼ���Ϊ��; 
	if (wcscmp(search_str, L"") == 0)
	{
		for (int i = 0; i < stu_num; i++)
		{
			mapping[i] = 1;
		}
	}
	// �ؼ��ʷǿ�
	else
	{
		for (int i = 0; i < stu_num; i++)
		{
			if (wcscmp(search_str, stu[i].name) == 0)
			{
				mapping[i] = 1;
			}
		}
	}
	mappingTableData(mapping, stu_tb_col, stu_tb_ptr, stu_tb_hl); // ӳ��ѧ���б�����
}

// ���ѧ��
void addStu()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* add_stu_stu_id = add_stu_stu_id_input_ptr->text(); // ѧ��
	wchar_t* add_stu_name = add_stu_name_input_ptr->text(); // ����
	wchar_t* add_stu_class = add_stu_class_input_ptr->text(); // �༶
	wchar_t* add_stu_calculus = add_stu_calculus_input_ptr->text(); // ΢����
	wchar_t* add_stu_martix = add_stu_martix_input_ptr->text(); // ���Դ���
	wchar_t* add_stu_c_c = add_stu_c_c_input_ptr->text(); // �������

	// �п�
	if (wcslen(add_stu_stu_id) == 0)
	{
		// �û���ʾ
		toast.setText(L"ѧ��Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	// ѧ��λ��
	if (!(wcslen(add_stu_stu_id) == 13)) {
		// �û���ʾ
		toast.setText(L"ѧ�Ų���13λ������������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	// ѧ�źͰ༶ƥ��
	wchar_t tttmp[100] = L"";
	wcsncpy_s(tttmp, add_stu_stu_id, 10);
	tttmp[10] = L'\0';
	if (wcscmp(tttmp, add_stu_class)) {
		// �û���ʾ
		toast.setText(L"ѧ����༶��ƥ�䣬����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	// ѧ�Ų���
	for (int i = 0; i < stu_num; i++)
	{
		if (wcscmp(add_stu_stu_id, stu[i].stu_id) == 0)
		{
			// �û���ʾ
			toast.setText(L"ѧ������ظ�������������");
			toast.show(WARNING);
			search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
			return;
		}
	}

	int index = stu_num; // ��ӵ�ѧ��������
	
	stu[index].id = cur_stu_id++;
	wcscpy_s(stu[index].stu_id, add_stu_stu_id);
	wcscpy_s(stu[index].name, add_stu_name);
	wcscpy_s(stu[index].classs , add_stu_class);
	wcscpy_s(stu[index].calculus, add_stu_calculus);
	wcscpy_s(stu[index].martix, add_stu_martix);
	wcscpy_s(stu[index].c_c, add_stu_c_c);
	wchar_t add_stu_account[100] = L"";
	wcscat_s(add_stu_account, add_stu_stu_id);
	wcscat_s(add_stu_account, L"@UESTG");
	wcscpy_s(stu[index].account, add_stu_account);
	wchar_t add_stu_password[100] = L"";
	wcsncpy_s(add_stu_password, add_stu_stu_id + 7, 6);
	add_stu_password[6] = L'\0';
	wcscpy_s(stu[index].password, add_stu_password);
	stu_num++;
	writeFile(); // ������д���ļ�
	flag = 1; // �����ɹ�
	
	closeAddStuMessage(); // �ر����ѧ������

	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"��ӳɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// �޸�ѧ��
void modifyStu()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* modify_stu_stu_id = modify_stu_stu_id_input_ptr->text(); // ѧ��
	wchar_t* modify_stu_name = modify_stu_name_input_ptr->text();  // ����
	wchar_t* modify_stu_class = modify_stu_class_input_ptr->text();// �༶
	wchar_t* modify_stu_calculus = modify_stu_calculus_input_ptr->text(); // ΢����
	wchar_t* modify_stu_martix = modify_stu_martix_input_ptr->text();  // ���Դ���
	wchar_t* modify_stu_c_c = modify_stu_c_c_input_ptr->text(); // �������

	// �п�
	if (wcslen(modify_stu_stu_id) == 0)
	{
		// �û���ʾ
		toast.setText(L"ѧ�����Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	// ѧ��λ��
	if (!(wcslen(modify_stu_stu_id) == 13)) {
		// �û���ʾ
		toast.setText(L"ѧ�Ų���13λ������������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	// ѧ�źͰ༶ƥ��
	wchar_t tttmp[100] = L"";
	wcsncpy_s(tttmp, modify_stu_stu_id, 10);
	tttmp[10] = L'\0';
	if (wcscmp(tttmp, modify_stu_class)) {
		// �û���ʾ
		toast.setText(L"ѧ����༶��ƥ�䣬����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	int index = -1; // ��Ҫ�޸ĵ�ѧ������

	// ��ѯ
	for (int i = 0; i < stu_num; i++)
	{
		// ��ѯ����
		if (wcscmp(modify_stu_stu_id, stu[i].stu_id) == 0)
		{
			index = i; // ��¼����
			break;
		}
	}

	// ˵����ѯ����
	if (index >= 0 && index < stu_num)
	{
		// �ǿղ�д��
		if (wcslen(modify_stu_name) != 0)
		{
			wcscpy_s(stu[index].name, modify_stu_name);
		}
		if (wcslen(modify_stu_class) != 0)
		{
			wcscpy_s(stu[index].classs, modify_stu_class);
		}
		if (wcslen(modify_stu_calculus) != 0)
		{
			wcscpy_s(stu[index].calculus, modify_stu_calculus);
		}
		if (wcslen(modify_stu_martix) != 0)
		{
			wcscpy_s(stu[index].martix, modify_stu_martix);
		}
		if (wcslen(modify_stu_c_c) != 0)
		{
			wcscpy_s(stu[index].c_c, modify_stu_c_c);
		}
		writeFile(); // ������д���ļ�
		flag = 1; // �����ɹ�
	}
	// ˵����ѯδ����
	else
	{
		// �û���ʾ
		toast.setText(L"ѧ�������޸�ѧ��");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	closeModifyStuMessage(); // �ر��޸�ѧ������
	
	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"�޸ĳɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// ɾ��ѧ��
void delStu()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* del_stu_stu_id = del_stu_stu_id_input_ptr->text(); // ѧ��

	// �п�
	if (wcslen(del_stu_stu_id) == 0)
	{
		// �û���ʾ
		toast.setText(L"ѧ��Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	int index = -1; // ��Ҫɾ����ѧ������

	// ��ѯ
	for (int i = 0; i < stu_num; i++)
	{
		// ��ѯ����
		if (wcscmp(del_stu_stu_id, stu[i].stu_id) == 0)
		{
			index = i; // ��¼����
			break;
		}
	}

	// ˵����ѯ����
	if (index >= 0 && index < stu_num)
	{

			// ɾ����Ӧѧ��
			for (int i = index; i < stu_num; i++)
			{
				stu[i].id = stu[i + 1].id;
				wcscpy_s(stu[i].stu_id, stu[i + 1].stu_id);
				wcscpy_s(stu[i].name, stu[i + 1].name);
				wcscpy_s(stu[i].classs, stu[i + 1].classs);
				wcscpy_s(stu[i].calculus, stu[i + 1].calculus);
				wcscpy_s(stu[i].martix, stu[i + 1].martix);
				wcscpy_s(stu[i].c_c, stu[i + 1].c_c);
			}
			stu_num--;
			writeFile(); // ������д���ļ�
			flag = 1; // �����ɹ�


	}
	else
	{
		// �û���ʾ
		toast.setText(L"ѧ�������޸�ѧ��");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	closeDelStuMessage(); // �ر�ɾ��ѧ������

	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"ɾ���ɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// �����ѧ������
void openAddStuMessage()
{
	add_stu_message.open(CONTENT); // �򿪵���
	add_stu_message_show = 1; // ���µ������ʾ״̬
}

// �ر����ѧ������
void closeAddStuMessage()
{
	add_stu_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ�������ѧ����������ô��Ҫ���²�ѯ
	searchStu(); // ���²�ѯ
}

// ���޸�ѧ������
void openModifyStuMessage()
{
	modify_stu_message.open(CONTENT); // �򿪵���
	modify_stu_message_show = 1; // ���µ������ʾ״̬
}

// �ر��޸�ѧ������
void closeModifyStuMessage()
{
	modify_stu_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ�������ѧ����������ô��Ҫ���²�ѯ
	searchStu(); // ���²�ѯ
}

// ��ɾ��ѧ������
void openDelStuMessage()
{
	del_stu_message.open(CONTENT); // �򿪵���
	del_stu_message_show = 1; // ���µ������ʾ״̬
}

// �ر�ɾ��ѧ������
void closeDelStuMessage()
{
	del_stu_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ����ɾ��ѧ����������ô��Ҫ���²�ѯ
	searchStu(); // ���²�ѯ
}



