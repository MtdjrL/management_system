#pragma once

#include "EUI/EUI.h"

enum Font {
	Title, // ����
	SubTitle, // ������
	RecText, // չʾ���ı�
	Normal // ����
};

void setFontStyle(enum Font font); // ���ñ����ı���ʽ