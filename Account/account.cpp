#include "account.h"

/*事件监听*/

int teacher_login_listen = 1; // 老师登录页面监听
int stu_login_listen = 1; // 学生登录页面监听
int teacher_verify_listen = 1; // 老师安全验证页面监听
int stu_verify_listen = 1; // 学生安全验证页面监听
int reset_teacher_pwd_listen = 1; // 重置老师密码页面监听
int reset_stu_pwd_listen = 1; // 重置学生密码页面监听
int stu_register_listen = 1; // 学生注册页面监听

/*数据类型*/

extern Teacher teacher; // 老师
extern Student stu[MAX_STU]; // 学生

/*全局变量*/

IMAGE account_icon; // 账号框图标
IMAGE pwd_icon; // 密码框图标
IMAGE back_btn_icon; // 回退按钮图标
IMAGE back_btn_pressed_icon; // 回退按钮按压图标

// 账号框图标
int account_icon_posx = 480;
int account_icon_posy = 310;

// 密码框图标
int pwd_icon_posx = account_icon_posx;
int pwd_icon_posy = account_icon_posy + 80;

extern int stu_num; // 学生总数
extern int cur_stu_id; // 当前学生id
extern int login_stu_id; // 登录的学生id
extern wchar_t teacher_code[TEXT_LEN]; // 老师验证码
extern wchar_t stu_code[TEXT_LEN]; // 学生验证码

extern Toast toast; // 弱提示框

extern IconButton back_btn; // 回退按钮
extern Input teacher_login_account_input; // 老师登录账号框
extern Input teacher_login_pwd_input; // 老师登录密码框
extern Input stu_login_account_input; // 学生登录账号框
extern Input stu_login_pwd_input; // 学生登录密码框
extern Input stu_register_account_input; // 学生注册账号框
extern Input stu_register_pwd_input; // 学生注册密码框
extern Input stu_register_confirm_pwd_input; // 学生注册确认密码框
extern Input teacher_code_input; // 老师验证码框
extern Input stu_code_input; // 学生验证码框
extern Input teacher_reset_account_input; // 老师重置密码账号框
extern Input teacher_reset_pwd_input; // 老师重置密码密码框
extern Input teacher_reset_confirm_pwd_input; // 老师重置密码确认密码框  
extern Input stu_reset_account_input; // 学生重置密码账号框
extern Input stu_reset_pwd_input; // 学生重置密码密码框
extern Input stu_reset_confirm_pwd_input; // 学生重置密码确认密码框
extern Button teacher_login_btn; // 老师登录按钮
extern Button stu_login_btn; // 学生登录按钮
extern Button stu_login_register_btn; // 学生登录页注册账号按钮
extern Button stu_register_btn; // 学生注册账号按钮
extern TextButton teacher_forget_pwd_btn; // 老师忘记密码按钮
extern TextButton teacher_stu_login_btn; // 老师登录页学生登录按钮
extern TextButton stu_forget_pwd_btn; // 学生忘记密码按钮
extern TextButton stu_teacher_login_btn; // 学生登录页老师登录按钮
extern Button teacher_verify_btn; // 老师验证按钮
extern Button stu_verify_btn; // 学生验证按钮
extern Button teacher_reset_btn; // 老师重置密码按钮
extern Button stu_reset_btn; // 学生重置密码按钮

/*函数实现*/

// 界面初始化
void initInterface()
{
	IMAGE logo_icon; // logo图标

	// logo
	int logo_posx = 585;
	int logo_posy = 142;

	// 标题文本
	int title_text_posx = 660;
	int title_text_posy = 150;

	// 副标题文本
	int sub_title_text_posx = 522;
	int sub_title_text_posy = 223;

	// 加载图标
	loadimage(&logo_icon, L"./pic/logo.png");
	loadimage(&account_icon, L"./pic/account.png");
	loadimage(&pwd_icon, L"./pic/password.png");
	loadimage(&back_btn_icon, L"./pic/back.png");
	loadimage(&back_btn_pressed_icon, L"./pic/back_pressed.png");

	// logo
	transparentimage(NULL, logo_posx, logo_posy, &logo_icon);

	// 标题
	setFontStyle(Title);
	outtextxy(title_text_posx, title_text_posy, L"UESTG");

	// 副标题
	setFontStyle(SubTitle);
	outtextxy(sub_title_text_posx, sub_title_text_posy, L"奶龙是一只高效简洁的学生管理系统");

	// 回退按钮
	back_btn.setIcon(back_btn_icon, back_btn_pressed_icon);
}

// 登录
void login()
{
	initInterface(); // 界面初始化
	teacherLoginPage(); // 老师登录
}

// 老师登录页
void teacherLoginPage()
{
	stu_login_listen = 0; // 关闭学生登录页面事件监听

	// 刷新屏幕
	refresh(AccountArea); 
	refresh(LeftTop);

	// 图标
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// 账号框
	teacher_login_account_input.setHolderText(L"老师账号");
	teacher_login_account_input.show();

	// 密码框
	teacher_login_pwd_input.setPassword(1);
	teacher_login_pwd_input.setHolderText(L"老师密码");
	teacher_login_pwd_input.show();

	// 忘记密码按钮
	teacher_forget_pwd_btn.setText(L"忘记密码");
	teacher_forget_pwd_btn.bindOnClick(teacherVerifyPage); // 绑定 老师安全验证 函数
	teacher_forget_pwd_btn.show();

	// 学生登录按钮
	teacher_stu_login_btn.setText(L"学生登录");
	teacher_stu_login_btn.bindOnClick(stuLoginPage); // 绑定 学生登录页 函数
	teacher_stu_login_btn.show();

	// 登录按钮
	teacher_login_btn.setText(L"登 录");
	teacher_login_btn.setBkColor(RGB(72, 151, 146));
	teacher_login_btn.setBorderColor(RGB(72, 151, 146));
	teacher_login_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_login_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_login_btn.bindOnClick(teacherLogin);
	teacher_login_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	teacher_login_listen = 1; // 开启老师登录页面监听
	while (teacher_login_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入		
		// 登录按钮
		if (teacher_login_btn.isOn(msg.x, msg.y))
		{
			teacher_login_btn.eventLoop(); // 进入事件循环
		}
		// 账号框
		if (teacher_login_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_login_account_input.eventLoop(); // 进入事件循环
			}
		}
		// 密码框
		if (teacher_login_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_login_pwd_input.eventLoop(); // 进入事件循环
			}
		}
		// 忘记密码按钮
		if (teacher_forget_pwd_btn.isOn(msg.x, msg.y))
		{
			teacher_forget_pwd_btn.eventLoop(); // 进入事件循环
		}
		// 学生登录按钮
		if (teacher_stu_login_btn.isOn(msg.x, msg.y))
		{
			teacher_stu_login_btn.eventLoop(); // 进入事件循环
		}
	}
}

// 学生登录页
void stuLoginPage()
{
	teacher_login_listen = 0; // 关闭老师登录页面监听

	// 刷新屏幕
	refresh(AccountArea);
	refresh(LeftTop);

	// 图标
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// 账号框
	stu_login_account_input.setHolderText(L"学生账号");
	stu_login_account_input.show();

	// 密码框
	stu_login_pwd_input.setPassword(1);
	stu_login_pwd_input.setHolderText(L"学生密码");
	stu_login_pwd_input.show();

	// 忘记密码按钮
	stu_forget_pwd_btn.setText(L"忘记密码");
	stu_forget_pwd_btn.bindOnClick(stuVerifyPage); // 绑定学生安全验证函数
	stu_forget_pwd_btn.show();

	// 老师登录按钮
	stu_teacher_login_btn.setText(L"老师登录");
	stu_teacher_login_btn.bindOnClick(teacherLoginPage);
	stu_teacher_login_btn.show();

	// 登录按钮
	stu_login_btn.setText(L"登 录");
	stu_login_btn.setBkColor(RGB(72, 151, 146));
	stu_login_btn.setBorderColor(RGB(72, 151, 146));
	stu_login_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_login_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_login_btn.bindOnClick(stuLogin);
	stu_login_btn.show();

	//// 注册账号按钮
	//stu_login_register_btn.setText(L"注册账号");
	//stu_login_register_btn.setBkColor(RGB(72, 151, 146));
	//stu_login_register_btn.setBorderColor(RGB(93, 202, 195));
	//stu_login_register_btn.setHoverBkColor(RGB(44, 135, 129));
	//stu_login_register_btn.setPressedBkColor(RGB(25, 91, 87));
	//stu_login_register_btn.bindOnClick(stuRegisterPage);
	//stu_login_register_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	stu_login_listen = 1; // 开启学生登录页面监听
	while (stu_login_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入		
		// 登录按钮
		if (stu_login_btn.isOn(msg.x, msg.y))
		{
			stu_login_btn.eventLoop(); // 进入事件循环
		}
		// 账号框
		if (stu_login_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_login_account_input.eventLoop(); // 进入事件循环
			}
		}
		// 密码框
		if (stu_login_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_login_pwd_input.eventLoop(); // 进入事件循环
			}
		}
		// 忘记密码按钮
		if (stu_forget_pwd_btn.isOn(msg.x, msg.y))
		{
			stu_forget_pwd_btn.eventLoop(); // 进入事件循环
		}
		// 老师登录按钮
		if (stu_teacher_login_btn.isOn(msg.x, msg.y))
		{
			stu_teacher_login_btn.eventLoop(); // 进入事件循环
		}
		//// 注册按钮
		//if (stu_login_register_btn.isOn(msg.x, msg.y))
		//{
		//	stu_login_register_btn.eventLoop(); // 进入事件循环
		//}
	}
}

// 老师登录
void teacherLogin()
{
	int not_empty = 0; // 非空标识

	wchar_t* account = teacher_login_account_input.text(); // 获取账号
	wchar_t* password = teacher_login_pwd_input.text(); // 获取密码

	// 非空
	if (wcslen(account) != 0 && wcslen(password) != 0)
	{
		not_empty = 1;
	}

	// 空
	if (not_empty == 0)
	{
		// 提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 校验通过
		if (wcscmp(account, teacher.account) == 0 && wcscmp(password, teacher.password) == 0)
		{
			TeacherMainInterface(); // 跳转至老师主界面
		}
		// 校验未通过
		else
		{
			// 学生提示
			toast.setText(L"账号或密码错误，请重新输入");
			toast.show(WARNING);
		}
	}
}

// 学生登录
void stuLogin()
{
	int not_empty = 0; // 非空标识

	wchar_t* account = stu_login_account_input.text(); // 获取账号
	wchar_t* password = stu_login_pwd_input.text(); // 获取密码

	int id = 0; // 登录的学生id

	// 非空
	if (wcslen(account) != 0 && wcslen(password) != 0)
	{
		not_empty = 1;
	}

	// 空
	if (not_empty == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 查找账号
		for (int i = 0; i < stu_num; i++)
		{
			// 查询命中
			if (wcscmp(stu[i].account, account) == 0)
			{
				// 校验通过
				if (wcscmp(stu[i].password, password) == 0)
				{
					login_stu_id = stu[i].id; // 记录登录学生的id
					stuMainInterface(); // 跳转至学生主界面
				}
				// 校验未通过
				else
				{
					// 学生提示
					toast.setText(L"账号或密码错误，请重新输入");
					toast.show(WARNING);
				}
				break;
			}
		}
	}
}

// 学生注册页
/*void stuRegisterPage()
{
	stu_login_listen = 0; // 关闭学生登录页面监听

	refresh(AccountArea); // 刷新屏幕

	// 回退按钮
	back_btn.bindOnClick(stuLoginPage); // 绑定 学生登录页 函数
	back_btn.show();

	// 图标
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// 账号框
	stu_register_account_input.setHolderText(L"账号");
	stu_register_account_input.show();

	// 密码框
	stu_register_pwd_input.setPassword(1);
	stu_register_pwd_input.setHolderText(L"密码");
	stu_register_pwd_input.show();

	// 确认密码框
	stu_register_confirm_pwd_input.setPassword(1);
	stu_register_confirm_pwd_input.setHolderText(L"确认密码");
	stu_register_confirm_pwd_input.show();

	// 注册按钮
	stu_register_btn.setText(L"注 册");
	stu_register_btn.setBkColor(RGB(72, 151, 146));
	stu_register_btn.setBorderColor(RGB(72, 151, 146));
	stu_register_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_register_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_register_btn.bindOnClick(stuRegister); // 绑定 学生注册 函数
	stu_register_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	stu_register_listen = 1; // 开启学生注册页面监听
	while (stu_register_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入		
		// 回退按钮
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // 事件循环

		}
		// 注册按钮
		if (stu_register_btn.isOn(msg.x, msg.y))
		{
			stu_register_btn.eventLoop(); // 进入事件循环
		}
		// 账号框
		if (stu_register_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_account_input.eventLoop(); // 进入事件循环
			}
		}
		// 密码框
		if (stu_register_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_pwd_input.eventLoop(); // 进入事件循环
			}
		}
		// 确认密码框
		if (stu_register_confirm_pwd_input.isOn(msg.x,msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_register_confirm_pwd_input.eventLoop();
			}
		}
	}
}*/
/*
// 学生注册
void stuRegister()
{
	int valid = 0; // 输入合法标识
	int not_empty = 0; // 非空标识
	int equal = 0; // 两次密码输入相等标识

	wchar_t* account = stu_register_account_input.text(); // 获取账号
	wchar_t* password = stu_register_pwd_input.text(); // 获取密码
	wchar_t* confirm_password = stu_register_confirm_pwd_input.text(); // 获取确认密码

	// 非空
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// 两次密码输入相等
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// 空
	if (not_empty == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 两次密码输入不相等
		if (equal == 0)
		{
			// 学生提示
			toast.setText(L"两次密码输入不相等，请重新输入");
			toast.show(WARNING);
		}
		// 非空且两次密码输入相等
		else
		{
			valid = 1; // 输入合法
		}
	}

	// 输入合法，注册账号
	if (valid)
	{
		stu[stu_num].id = cur_stu_id++;
		wcscpy_s(stu[stu_num].account, account);
		wcscpy_s(stu[stu_num].password, password);
		stu_num++;
		writeFile(); // 将数据写入文件

		// 学生提示
		toast.setText(L"注册成功");
		toast.show(SUCCESS);

		stuLoginPage(); // 跳转至学生登录页
	}
}*/

// 老师安全验证页
void teacherVerifyPage()
{
	teacher_login_listen = 0; // 关闭老师登录页面监听

	refresh(AccountArea); // 刷新屏幕

	// 回退按钮
	back_btn.bindOnClick(teacherLoginPage); // 绑定 老师登录页 函数
	back_btn.show();

	// 验证码框
	teacher_code_input.setHolderText(L"验证码");
	teacher_code_input.show();

	// 验证按钮
	teacher_verify_btn.setText(L"验 证");
	teacher_verify_btn.setBkColor(RGB(72, 151, 146));
	teacher_verify_btn.setBorderColor(RGB(72, 151, 146));
	teacher_verify_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_verify_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_verify_btn.bindOnClick(teacherVerify); // 绑定 老师安全验证 函数
	teacher_verify_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	teacher_verify_listen = 1; // 开启老师登录页面监听
	while (teacher_verify_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 回退按钮
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // 事件循环
			
		}
		// 验证按钮
		if (teacher_verify_btn.isOn(msg.x, msg.y))
		{
			teacher_verify_btn.eventLoop(); // 进入事件循环
		}
		// 验证码框
		if (teacher_code_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_code_input.eventLoop(); // 进入事件循环
			}
		}
	}
}

// 学生安全验证页
void stuVerifyPage()
{
	stu_login_listen = 0; // 关闭学生登录页面监听

	refresh(AccountArea); // 刷新屏幕

	// 回退按钮
	back_btn.bindOnClick(stuLoginPage); // 绑定 学生登录页 函数
	back_btn.show();

	// 验证码框
	stu_code_input.setHolderText(L"验证码");
	stu_code_input.show();

	// 验证按钮
	stu_verify_btn.setText(L"验 证");
	stu_verify_btn.setBkColor(RGB(72, 151, 146));
	stu_verify_btn.setBorderColor(RGB(72, 151, 146));
	stu_verify_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_verify_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_verify_btn.bindOnClick(stuVerify); // 绑定 学生安全验证 函数
	stu_verify_btn.show();

		
	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	stu_verify_listen = 1; // 开启老师登录页面监听
	while (stu_verify_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入
		// 回退按钮
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // 事件循环

		}
		// 验证按钮
		if (stu_verify_btn.isOn(msg.x, msg.y))
		{
			stu_verify_btn.eventLoop(); // 进入事件循环
		}
		// 验证码框
		if (stu_code_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_code_input.eventLoop(); // 进入事件循环
			}
		}
	}
}

// 老师安全验证
void teacherVerify()
{
	wchar_t* code = teacher_code_input.text(); // 获取验证码

	// 空
	if (wcslen(code) == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 校验通过
		if (wcscmp(code, teacher_code) == 0)
		{
			resetTeacherPasswordPage(); // 跳转至重置老师密码页
		}
		// 校验未通过
		else
		{
			// 学生提示
			toast.setText(L"验证码错误，请重新输入");
			toast.show(WARNING);
		}
	}
}

// 学生安全验证
void stuVerify()
{
	wchar_t* code = stu_code_input.text(); // 获取验证码

// 空
	if (wcslen(code) == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 校验通过
		if (wcscmp(code, stu_code) == 0)
		{
			resetStuPasswordPage(); // 跳转至重置老师密码页
		}
		// 校验未通过
		else
		{
			// 学生提示
			toast.setText(L"验证码错误，请重新输入");
			toast.show(WARNING);
		}
	}
}

// 重置老师密码页
void resetTeacherPasswordPage()
{
	teacher_verify_listen = 0; // 关闭老师安全验证页面监听

	// 刷新屏幕
	refresh(AccountArea);

	// 回退按钮
	back_btn.bindOnClick(teacherVerifyPage); // 绑定 老师安全验证页 函数
	back_btn.show();

	// 图标
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// 账号框
	teacher_reset_account_input.setHolderText(L"账号");
	teacher_reset_account_input.show();

	// 密码框
	teacher_reset_pwd_input.setPassword(1);
	teacher_reset_pwd_input.setHolderText(L"密码");
	teacher_reset_pwd_input.show();

	// 确认密码框
	teacher_reset_confirm_pwd_input.setPassword(1);
	teacher_reset_confirm_pwd_input.setHolderText(L"确认密码");
	teacher_reset_confirm_pwd_input.show();

	// 重置密码按钮
	teacher_reset_btn.setText(L"重 置");
	teacher_reset_btn.setBkColor(RGB(72, 151, 146));
	teacher_reset_btn.setBorderColor(RGB(72, 151, 146));
	teacher_reset_btn.setHoverBkColor(RGB(44, 135, 129));
	teacher_reset_btn.setPressedBkColor(RGB(25, 91, 87));
	teacher_reset_btn.bindOnClick(resetTeacherPassword); // 绑定 重置老师密码 函数
	teacher_reset_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	reset_teacher_pwd_listen = 1; // 开启重置老师密码页面监听
	while (reset_teacher_pwd_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 回退按钮
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // 事件循环
		}
		// 重置按钮
		if (teacher_reset_btn.isOn(msg.x, msg.y))
		{
			teacher_reset_btn.eventLoop(); // 进入事件循环
		}
		// 账号框
		if (teacher_reset_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_account_input.eventLoop(); // 进入事件循环
			}
		}
		// 密码框
		if (teacher_reset_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_pwd_input.eventLoop(); // 进入事件循环
			}
		}
		// 确认密码框
		if (teacher_reset_confirm_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				teacher_reset_confirm_pwd_input.eventLoop();
			}
		}
	}
}

// 重置学生密码页
void resetStuPasswordPage()
{
	stu_verify_listen = 0; // 关闭学生安全验证页面监听

	refresh(AccountArea); // 刷新屏幕

	// 回退按钮
	back_btn.bindOnClick(stuVerifyPage); // 绑定 学生安全验证页 函数
	back_btn.show();

	// 图标
	transparentimage(NULL, account_icon_posx, account_icon_posy, &account_icon);
	transparentimage(NULL, pwd_icon_posx, pwd_icon_posy, &pwd_icon);

	// 账号框
	stu_reset_account_input.setHolderText(L"账号");
	stu_reset_account_input.show();

	// 密码框
	stu_reset_pwd_input.setPassword(1);
	stu_reset_pwd_input.setHolderText(L"密码");
	stu_reset_pwd_input.show();

	// 确认密码框
	stu_reset_confirm_pwd_input.setPassword(1);
	stu_reset_confirm_pwd_input.setHolderText(L"确认密码");
	stu_reset_confirm_pwd_input.show();

	// 重置密码按钮
	stu_reset_btn.setText(L"重 置");
	stu_reset_btn.setBkColor(RGB(72, 151, 146));
	stu_reset_btn.setBorderColor(RGB(72, 151, 146));
	stu_reset_btn.setHoverBkColor(RGB(44, 135, 129));
	stu_reset_btn.setPressedBkColor(RGB(25, 91, 87));
	stu_reset_btn.bindOnClick(resetStuPassword);
	stu_reset_btn.show();

	// 整个界面的事件循环监听
	ExMessage msg; // 鼠标消息
	reset_stu_pwd_listen = 1; // 开启重置老师密码页面监听
	while (reset_stu_pwd_listen)
	{
		msg = getmessage(EX_MOUSE); // 获取消息输入	
		// 回退按钮
		if (back_btn.isOn(msg.x, msg.y))
		{
			back_btn.eventLoop(); // 事件循环
		}
		// 重置按钮
		if (stu_reset_btn.isOn(msg.x, msg.y))
		{
			stu_reset_btn.eventLoop(); // 进入事件循环
		}
		// 账号框
		if (stu_reset_account_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_account_input.eventLoop(); // 进入事件循环
			}
		}
		// 密码框
		if (stu_reset_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_pwd_input.eventLoop(); // 进入事件循环
			}
		}
		// 确认密码框
		if (stu_reset_confirm_pwd_input.isOn(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				stu_reset_confirm_pwd_input.eventLoop();
			}
		}
	}
}

// 重置老师密码
void resetTeacherPassword()
{
	int valid = 0; // 输入合法标识
	int not_empty = 0; // 非空标识
	int equal = 0; // 两次密码输入相等标识

	wchar_t* account = teacher_reset_account_input.text(); // 获取账号
	wchar_t* password = teacher_reset_pwd_input.text(); // 获取密码
	wchar_t* confirm_password = teacher_reset_confirm_pwd_input.text(); // 获取二次输入密码

	// 非空
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// 两次密码输入相等
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// 空
	if (not_empty == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 两次密码输入不相等
		if (equal == 0)
		{
			// 学生提示
			toast.setText(L"两次密码输入不相等，请重新输入");
			toast.show(WARNING);
		}
		// 非空且两次密码输入相等
		else
		{
			valid = 1; // 输入合法
		}
	}

	// 输入合法
	if (valid)
	{
		// 账号匹配
		if (wcscmp(account, teacher.account) == 0)
		{
			wcscpy_s(teacher.password, password); // 修改密码
			writeFile(); // 将数据写入文件

			// 学生提示
			toast.setText(L"密码修改成功");
			toast.show(SUCCESS);

			teacherLoginPage(); // 跳转至老师登录页
		}
		// 账号不匹配
		else
		{
			// 学生提示
			toast.setText(L"账号错误，请重新输入");
			toast.show(WARNING);
		}
	}
}

// 重置学生密码
void resetStuPassword()
{
	int valid = 0; // 输入合法标识
	int not_empty = 0; // 非空标识
	int equal = 0; // 两次密码输入相等标识

	wchar_t* account = stu_reset_account_input.text(); // 获取账号
	wchar_t* password = stu_reset_pwd_input.text(); // 获取密码
	wchar_t* confirm_password = stu_reset_confirm_pwd_input.text(); // 获取二次输入密码

	// 非空
	if (wcslen(account) != 0 && wcslen(password) != 0 && wcslen(confirm_password) != 0)
	{
		not_empty = 1;
	}

	// 两次密码输入相等
	if (wcscmp(password, confirm_password) == 0)
	{
		equal = 1;
	}

	// 空
	if (not_empty == 0)
	{
		// 学生提示
		toast.setText(L"输入内容不可为空，请重新输入");
		toast.show(WARNING);
	}
	// 非空
	else
	{
		// 两次密码输入不相等
		if (equal == 0)
		{
			// 学生提示
			toast.setText(L"两次密码输入不相等，请重新输入");
			toast.show(WARNING);
		}
		// 非空且两次密码输入相等
		else
		{
			valid = 1; // 输入合法
		}
	}

	int index = -1; // 学生索引

	// 输入合法
	if (valid)
	{
		// 查找账号
		for (int i = 0; i < stu_num; i++)
		{
			// 查询命中
			if (wcscmp(stu[i].account, account) == 0)
			{
				index = i; // 记录学生索引
				break;
			}
		}

		// 查询命中
		if (index >= 0 && index < stu_num)
		{
			wcscpy_s(stu[index].password, password); // 修改密码
			writeFile(); // 将数据写入文件

			// 学生提示
			toast.setText(L"密码修改成功");
			toast.show(SUCCESS);

			stuLoginPage(); // 跳转至学生登录页
		}
		// 查询未命中
		else
		{
			// 学生提示
			toast.setText(L"账号错误，请重新输入");
			toast.show(WARNING);
		}
	}
}


