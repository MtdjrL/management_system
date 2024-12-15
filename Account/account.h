#pragma once

#include "EUI/EUI.h"
#include "Common/common.h"
#include "Common/font.h"
#include "Common/icon.h"
#include "Teacher/teacher.h"
#include "Student/student.h"

void initInterface(); // 界面初始化

void login(); // 登录

void teacherLoginPage(); // 老师登录页

void stuLoginPage(); // 学生登录页

void teacherLogin(); // 老师登录

void stuLogin(); // 学生登录

//void stuRegisterPage(); // 学生注册页

//void stuRegister(); // 学生注册

void teacherVerifyPage(); // 老师安全验证页

void stuVerifyPage(); // 学生安全验证页

void teacherVerify(); // 老师安全验证

void stuVerify(); // 学生安全验证

void resetTeacherPasswordPage(); // 重置老师密码页

void resetStuPasswordPage(); // 重置学生密码页

void resetTeacherPassword(); // 重置老师密码

void resetStuPassword(); // 重置学生密码


