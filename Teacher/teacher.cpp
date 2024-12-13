#include "teacher.h"

/*�¼�����*/

int book_management_listen = 1; // ͼ�����ҳ�����
int homepage_listen = 1;

/*��������*/

extern Student book[MAX_STU]; // ͼ��

/*ȫ�ֱ���*/

int add_book_message_show = 0; // ���ͼ�鵯�����ʾ״̬
int modify_book_message_show = 0; // �޸�ͼ�鵯�����ʾ״̬
int del_book_message_show = 0; // ɾ��ͼ�鵯�����ʾ״̬
int add_book_pair_flag = 0; // ���ͼ�鵯�����ı�-�������Ƿ���ӱ�־������ֹ��ε���ͼ�������ʱ�ظ����
int modify_book_pair_flag = 0; // �޸�ͼ�鵯�����ı�-�������Ƿ���ӱ�־������ֹ��ε���ͼ�������ʱ�ظ����
int del_book_pair_flag = 0; // ɾ��ͼ�鵯�����ı�-�������Ƿ���ӱ�־������ֹ��ε���ͼ�������ʱ�ظ����

extern int cur_book_id; // ��ǰͼ��id
extern int book_num; // ͼ������
extern int user_num; // �û�����
extern int borrow_book_num;  // ����ͼ������
extern int exist_book_num; // �ִ�ͼ������

extern Navbar admin_navbar; // ������
extern Toast toast; // ����ʾ��

extern Input search_book_input; // ����ͼ�������
extern int book_tb_row; // ͼ���б�����
extern int book_tb_col; // ͼ���б�����
extern Button search_btn; // ������ť
extern Button add_btn; // ��Ӱ�ť
extern Button modify_btn; // �޸İ�ť
extern Button del_btn; // ɾ����ť
extern Table* book_tb_ptr; // ͼ���б�
extern headerList book_tb_hl[MAX_COL]; // ͼ���б��ͷ
extern Message add_book_message; // ���ͼ�鵯��
extern Input* add_book_sn_input_ptr; // ���ͼ�鵯���������
extern Input* add_book_name_input_ptr; // ���ͼ�鵯�����������
extern Input* add_book_author_input_ptr; // ���ͼ�鵯�����������
extern Input* add_book_publisher_input_ptr; // ���ͼ�鵯������������
extern Input* add_book_publish_time_input_ptr; // ���ͼ�鵯�����ʱ�������
extern Message modify_book_message; // �޸�ͼ�鵯��
extern Input* modify_book_sn_input_ptr; // �޸�ͼ�鵯���������
extern Input* modify_book_name_input_ptr; // �޸�ͼ�鵯�����������
extern Input* modify_book_author_input_ptr; // �޸�ͼ�鵯�����������
extern Input* modify_book_publisher_input_ptr; // �޸�ͼ�鵯������������
extern Input* modify_book_publish_time_input_ptr; // �޸�ͼ�鵯�����ʱ�������
extern Message del_book_message; // ɾ��ͼ�鵯��
extern Input* del_book_sn_input_ptr;  // ɾ��ͼ�鵯���������

/*����ʵ��*/

// ����Ա������
void adminMainInterface()
{
	// ��������ť
	NavButton nav_btn1(NAV_WIDTH, NAV_BUTTON_HEIGHT); // ��ҳ
	NavButton nav_btn2(NAV_WIDTH, NAV_BUTTON_HEIGHT); // ͼ�����

	// ��������ťָ��
	NavButton* nav_btn1_ptr = &nav_btn1;
	NavButton* nav_btn2_ptr = &nav_btn2;

	admin_navbar.setTitleFontSize(22);
	admin_navbar.setTitleText(L"��  ֪");

	nav_btn1_ptr->setText(L"��ҳ");
	nav_btn2_ptr->setText(L"ͼ�����");

	admin_navbar.addNavButton(nav_btn1_ptr);
	admin_navbar.addNavButton(nav_btn2_ptr);

	// Ϊ��������ť�󶨵���¼�
	nav_btn1_ptr->bindOnClick(homepage); // �� ��ҳ
	nav_btn2_ptr->bindOnClick(bookManagementPage); // �� ͼ�����

	admin_navbar.setGap(70); // ���õ�������ť���ּ��
	admin_navbar.show(); // ��ʾ������

	homepage(); // Ĭ�Ͻ�����ҳ
	//bookManagementPage();
}

// ��ҳ
void homepage()
{
	book_management_listen = 0; // �ر�ͼ�����ҳҳ�����

	refresh(NavbarMatchArea); // ˢ����Ļ

	IMAGE book_num_icon; // ͼ������ͼ��
	IMAGE user_num_icon; // �û�����ͼ��
	IMAGE exist_book_num_icon; // �ִ�ͼ��ͼ��
	IMAGE borrow_book_num_icon; // ����ͼ��ͼ��

	wchar_t book_num_text[TEXT_LEN]; // ͼ������
	wchar_t user_num_text[TEXT_LEN]; // �û�����
	wchar_t exist_book_num_text[TEXT_LEN]; // �ִ�ͼ��
	wchar_t borrow_book_num_text[TEXT_LEN]; // ����ͼ��
	wsprintfW(book_num_text, L"%d", book_num);
	wsprintfW(user_num_text, L"%d", user_num);
	wsprintfW(exist_book_num_text, L"%d", exist_book_num);
	wsprintfW(borrow_book_num_text, L"%d", borrow_book_num);

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

	loadimage(&book_num_icon, L"../pic/book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"ͼ������");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, book_num_text);

	// չʾ��2
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&user_num_icon, L"../pic/user_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &user_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"�û�����");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, user_num_text);

	// չʾ��3
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&exist_book_num_icon, L"../pic/exist_book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &exist_book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"�ִ�ͼ��");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, exist_book_num_text);

	// չʾ��4
	startx = startx + width + gap;
	endx = endx + width + gap;
	fillroundrect(startx, starty, endx, endy, radius, radius);

	loadimage(&borrow_book_num_icon, L"../pic/borrow_book_num.png");
	transparentimage(NULL, startx + icon_left_margin, starty + icon_top_margin, &borrow_book_num_icon);

	title_posx = startx + title_left_margin;
	title_posy = starty + title_top_margin;
	outtextxy(title_posx, title_posy, L"����ͼ��");
	text_posx = startx + text_left_margin;
	text_posy = starty + text_top_margin;
	outtextxy(text_posx, text_posy, borrow_book_num_text);

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	homepage_listen = 1; // ������ҳҳ�����
	while (homepage_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// ������
		if (admin_navbar.isOn(msg.x, msg.y))
		{
			admin_navbar.eventLoop(); // �����¼�ѭ��
		}
	}
}

// ͼ�����
void bookManagementPage()
{
	refresh(NavbarMatchArea); // ˢ����Ļ

	// ����ͼ�������
	search_book_input.setHolderText(L"����");
	search_book_input.show();

	// ������ť
	search_btn.setText(L"�� ��");
	search_btn.bindOnClick(searchBook);
	search_btn.show();

	// ������ť
	add_btn.setText(L"�� ��");
	add_btn.bindOnClick(openAddBookMessage);
	add_btn.show();

	// �޸İ�ť
	modify_btn.setText(L"�� ��");
	modify_btn.bindOnClick(openModifyBookMessage);
	modify_btn.show();

	// ɾ����ť
	del_btn.setText(L"ɾ ��");
	del_btn.setBkColor(RGB(199, 74, 61));
	del_btn.setBorderColor(RGB(213, 67, 52));
	del_btn.setHoverBkColor(RGB(178,58,45));
	del_btn.setPressedBkColor(RGB(162, 46, 34));
	del_btn.bindOnClick(openDelBookMessage);
	del_btn.show();

	// ͼ���б�
	int tb_width[] = { 10,20,10,20,20,20 }; // �п��������λΪ%����Ϊ100
	book_tb_ptr->setGridWidth(tb_width); // �趨�п�
	setTableHeader(BookTable, book_tb_hl); // �����б��ͷ
	searchBook(); // Ĭ������ͼ�飬Ĭ��������ֵΪ�գ����Ϊ��ѯ��������

	// ���ͼ�鵯��
	add_book_message.setTitle(L"���ͼ��"); // ���ñ���
	// δ������ͼ�鵯����ı�-������
	if (add_book_pair_flag == 0)
	{
		// ����ı��������
		add_book_message.addLabel(L"ͼ����"); 
		add_book_message.addInput(add_book_sn_input_ptr); 
		add_book_message.addLabel(L"����"); 
		add_book_message.addInput(add_book_name_input_ptr); 
		add_book_message.addLabel(L"����"); 
		add_book_message.addInput(add_book_author_input_ptr); 
		add_book_message.addLabel(L"������");
		add_book_message.addInput(add_book_publisher_input_ptr);
		add_book_message.addLabel(L"����ʱ��");
		add_book_message.addInput(add_book_publish_time_input_ptr);
		
		add_book_pair_flag = 1; // ��ʾ������ı�-������
	}
	add_book_message.cancelBtn()->bindOnClick(closeAddBookMessage); // ȡ����ť�󶨹رյ�����
	add_book_message.enterBtn()->bindOnClick(addBook);

	// �޸�ͼ�鵯��
	modify_book_message.setTitle(L"�޸�ͼ��"); // ���ñ���
	// δ����޸�ͼ�鵯����ı�-������
	if (modify_book_pair_flag == 0)
	{
		// ����ı��������
		modify_book_message.addLabel(L"ͼ����");
		modify_book_message.addInput(modify_book_sn_input_ptr);
		modify_book_message.addLabel(L"����");
		modify_book_message.addInput(modify_book_name_input_ptr);
		modify_book_message.addLabel(L"����");
		modify_book_message.addInput(modify_book_author_input_ptr);
		modify_book_message.addLabel(L"������");
		modify_book_message.addInput(modify_book_publisher_input_ptr);
		modify_book_message.addLabel(L"����ʱ��");
		modify_book_message.addInput(modify_book_publish_time_input_ptr);

		modify_book_pair_flag = 1; // ��ʾ������ı�-������
	}
	modify_book_message.cancelBtn()->bindOnClick(closeModifyBookMessage); // ȡ����ť�󶨹رյ�����
	modify_book_message.enterBtn()->bindOnClick(modifyBook);

	// ɾ��ͼ�鵯��
	del_book_message.setTitle(L"ɾ��ͼ��"); // ���ñ���
	// δ���ɾ��ͼ�鵯����ı�-������
	if (del_book_pair_flag == 0)
	{
		// ����ı��������
		del_book_message.addLabel(L"ͼ����");
		del_book_message.addInput(del_book_sn_input_ptr);

		del_book_pair_flag = 1; // ��ʾ������ı�-������
	}
	del_book_message.cancelBtn()->bindOnClick(closeDelBookMessage); // ȡ����ť�󶨹رյ�����
	del_book_message.enterBtn()->bindOnClick(delBook); // ȷ�ϰ�ť�󶨴򿪵�����

	// ����������¼�ѭ������
	ExMessage msg; // �����Ϣ
	book_management_listen = 1; // ����ͼ�����ҳ���¼�����
	while (book_management_listen)
	{
		msg = getmessage(EX_MOUSE); // ��ȡ��Ϣ����	
		// �е����
		if (del_book_message_show || add_book_message_show || modify_book_message_show)
		{
			// ɾ��ͼ�鵯��
			if (del_book_message_show)
			{
				if (del_book_message.isOn(msg.x, msg.y))
				{
					del_book_message.eventLoop(); // �����¼�ѭ��
					del_book_message_show = del_book_message.isShow(); // ���µ������ʾ״̬
				}
			}
			// ���ͼ�鵯��
			if (add_book_message_show)
			{
				if (add_book_message.isOn(msg.x, msg.y))
				{
					add_book_message.eventLoop(); // �����¼�ѭ��
					add_book_message_show = add_book_message.isShow(); // ���µ������ʾ״̬
				}
			}
			// �޸�ͼ�鵯��
			if (modify_book_message_show)
			{
				if (modify_book_message.isOn(msg.x, msg.y))
				{
					modify_book_message.eventLoop(); // �����¼�ѭ��
					modify_book_message_show = modify_book_message.isShow(); // ���µ������ʾ״̬
				}
			}
		}
		// �޵����
		else
		{
			// ������
			if (admin_navbar.isOn(msg.x, msg.y))
			{
				admin_navbar.eventLoop(); // �����¼�ѭ��
			}
			// ������
			if (search_book_input.isOn(msg.x, msg.y))
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					search_book_input.eventLoop(); // �����¼�ѭ��
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

// ����ͼ��
void searchBook()
{
	refresh(TableArea);// ��ѯǰ��ˢ����Ļ

	wchar_t* search_str = search_book_input.text(); // ��ȡ������ı�,��Ϊ�����ı�

	int mapping[MAX_BOOK] = { 0 }; // ӳ�����飬0��ʾ��ӳ�䣬1��ʾӳ��

	// �ؼ���Ϊ��; 
	if (wcscmp(search_str, L"") == 0)
	{
		for (int i = 0; i < book_num; i++)
		{
			mapping[i] = 1;
		}
	}
	// �ؼ��ʷǿ�
	else
	{
		for (int i = 0; i < book_num; i++)
		{
			if (wcscmp(search_str, book[i].name) == 0)
			{
				mapping[i] = 1;
			}
		}
	}
	mappingTableData(mapping, book_tb_col, book_tb_ptr, book_tb_hl); // ӳ��ͼ���б�����
}

// ���ͼ��
void addBook()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* add_book_sn = add_book_sn_input_ptr->text(); // ���
	wchar_t* add_book_name = add_book_name_input_ptr->text(); // ����
	wchar_t* add_book_author = add_book_author_input_ptr->text(); // ����
	wchar_t* add_book_publisher = add_book_publisher_input_ptr->text(); // ������
	wchar_t* add_book_publish_time = add_book_publish_time_input_ptr->text(); // ����ʱ��
	wchar_t add_book_state[TEXT_LEN];
	wcscpy_s(add_book_state, L"δ���"); // ��ӵ�ͼ���Ĭ�Ͻ���״̬

	// �п�
	if (wcslen(add_book_sn) == 0)
	{
		// �û���ʾ
		toast.setText(L"ͼ����Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	// ��Ų���
	for (int i = 0; i < book_num; i++)
	{
		if (wcscmp(add_book_sn, book[i].sn) == 0)
		{
			// �û���ʾ
			toast.setText(L"ͼ�����ظ�������������");
			toast.show(WARNING);
			search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
			return;
		}
	}

	int index = book_num; // ��ӵ�ͼ�������

	book[index].id = ++cur_book_id;
	wcscpy_s(book[index].sn, add_book_sn);
	wcscpy_s(book[index].name, add_book_name);
	wcscpy_s(book[index].author, add_book_author);
	wcscpy_s(book[index].publisher, add_book_publisher);
	wcscpy_s(book[index].publish_time, add_book_publish_time);
	wcscpy_s(book[index].state, add_book_state);

	book_num++;
	exist_book_num++;
	writeFile(); // ������д���ļ�
	flag = 1; // �����ɹ�
	
	closeAddBookMessage(); // �ر����ͼ�鵯��

	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"��ӳɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// �޸�ͼ��
void modifyBook()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* modify_book_sn = modify_book_sn_input_ptr->text(); // ���
	wchar_t* modify_book_name = modify_book_name_input_ptr->text(); // ����
	wchar_t* modify_book_author = modify_book_author_input_ptr->text(); // ����
	wchar_t* modify_book_publisher = modify_book_publisher_input_ptr->text(); // ������
	wchar_t* modify_book_publish_time = modify_book_publish_time_input_ptr->text(); // ����ʱ��

	// �п�
	if (wcslen(modify_book_sn) == 0)
	{
		// �û���ʾ
		toast.setText(L"ͼ����Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	int index = -1; // ��Ҫ�޸ĵ�ͼ������

	// ��ѯ
	for (int i = 0; i < book_num; i++)
	{
		// ��ѯ����
		if (wcscmp(modify_book_sn, book[i].sn) == 0)
		{
			index = i; // ��¼����
			break;
		}
	}

	// ˵����ѯ����
	if (index >= 0 && index < book_num)
	{
		// �ǿղ�д��
		if (wcslen(modify_book_name) != 0)
		{
			wcscpy_s(book[index].name, modify_book_name);
		}
		if (wcslen(modify_book_author) != 0)
		{
			wcscpy_s(book[index].author, modify_book_author);
		}
		if (wcslen(modify_book_publisher) != 0)
		{
			wcscpy_s(book[index].publisher, modify_book_publisher);
		}
		if (wcslen(modify_book_publish_time) != 0)
		{
			wcscpy_s(book[index].publish_time, modify_book_publish_time);
		}
		writeFile(); // ������д���ļ�
		flag = 1; // �����ɹ�
	}
	// ˵����ѯδ����
	else
	{
		// �û���ʾ
		toast.setText(L"ͼ���������޸�ͼ��");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	closeModifyBookMessage(); // �ر��޸�ͼ�鵯��
	
	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"�޸ĳɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// ɾ��ͼ��
void delBook()
{
	int flag = 0; // �����ɹ���ʶ

	wchar_t* del_book_sn = del_book_sn_input_ptr->text(); // ���

	// �п�
	if (wcslen(del_book_sn) == 0)
	{
		// �û���ʾ
		toast.setText(L"ͼ����Ϊ�գ�����������");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ

		return;
	}

	int index = -1; // ��Ҫɾ����ͼ������

	// ��ѯ
	for (int i = 0; i < book_num; i++)
	{
		// ��ѯ����
		if (wcscmp(del_book_sn, book[i].sn) == 0)
		{
			index = i; // ��¼����
			break;
		}
	}

	// ˵����ѯ����
	if (index >= 0 && index < book_num)
	{
		// ͼ��δ���
		if (wcscmp(book[index].state, L"δ���") == 0)
		{
			// ɾ����Ӧͼ��
			for (int i = index; i < book_num; i++)
			{
				book[i].id = book[i + 1].id;
				wcscpy_s(book[i].sn, book[i + 1].sn);
				wcscpy_s(book[i].name, book[i + 1].name);
				wcscpy_s(book[i].author, book[i + 1].author);
				wcscpy_s(book[i].publisher, book[i + 1].publisher);
				wcscpy_s(book[i].publish_time, book[i + 1].publish_time);
				wcscpy_s(book[i].state, book[i + 1].state);
			}
			book_num--;
			exist_book_num--;
			writeFile(); // ������д���ļ�
			flag = 1; // �����ɹ�
		}
		// ͼ���ѽ��
		else
		{
			// �û���ʾ
			toast.setText(L"��ͼ���ѱ����ģ��޷�ɾ��");
			toast.show(WARNING);
			search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
			return;
		}
	}
	else
	{
		// �û���ʾ
		toast.setText(L"ͼ���������޸�ͼ��");
		toast.show(WARNING);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
		return;
	}

	closeDelBookMessage(); // �ر�ɾ��ͼ�鵯��

	// �����ɹ�
	if (flag == 1)
	{
		// �û���ʾ
		toast.setText(L"ɾ���ɹ�");
		toast.show(SUCCESS);
		search_btn.show(); // ����ʾ�����������ǵ�������ť�������Ҫ������ʾ
	}
}

// �����ͼ�鵯��
void openAddBookMessage()
{
	add_book_message.open(CONTENT); // �򿪵���
	add_book_message_show = 1; // ���µ������ʾ״̬
}

// �ر����ͼ�鵯��
void closeAddBookMessage()
{
	add_book_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ�������ͼ���������ô��Ҫ���²�ѯ
	searchBook(); // ���²�ѯ
}

// ���޸�ͼ�鵯��
void openModifyBookMessage()
{
	modify_book_message.open(CONTENT); // �򿪵���
	modify_book_message_show = 1; // ���µ������ʾ״̬
}

// �ر��޸�ͼ�鵯��
void closeModifyBookMessage()
{
	modify_book_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ�������ͼ���������ô��Ҫ���²�ѯ
	searchBook(); // ���²�ѯ
}

// ��ɾ��ͼ�鵯��
void openDelBookMessage()
{
	del_book_message.open(CONTENT); // �򿪵���
	del_book_message_show = 1; // ���µ������ʾ״̬
}

// �ر�ɾ��ͼ�鵯��
void closeDelBookMessage()
{
	del_book_message.close(); // �رյ���
	//һ�����ǹرյ���ʱ��Բ��ֱ����в�������Ҫ���²�ѯ����һ����������û�ȷ����ɾ��ͼ���������ô��Ҫ���²�ѯ
	searchBook(); // ���²�ѯ
}



