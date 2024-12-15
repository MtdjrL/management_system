#pragma once

#include "EUI/EUI.h"
#include "Common/common.h"
#include "Common/font.h"
#include "Common/icon.h"
#include "Teacher/teacher.h"
#include "Student/student.h"

void initInterface(); // �����ʼ��

void login(); // ��¼

void teacherLoginPage(); // ��ʦ��¼ҳ

void stuLoginPage(); // ѧ����¼ҳ

void teacherLogin(); // ��ʦ��¼

void stuLogin(); // ѧ����¼

//void stuRegisterPage(); // ѧ��ע��ҳ

//void stuRegister(); // ѧ��ע��

void teacherVerifyPage(); // ��ʦ��ȫ��֤ҳ

void stuVerifyPage(); // ѧ����ȫ��֤ҳ

void teacherVerify(); // ��ʦ��ȫ��֤

void stuVerify(); // ѧ����ȫ��֤

void resetTeacherPasswordPage(); // ������ʦ����ҳ

void resetStuPasswordPage(); // ����ѧ������ҳ

void resetTeacherPassword(); // ������ʦ����

void resetStuPassword(); // ����ѧ������


