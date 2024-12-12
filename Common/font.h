#pragma once

#include "EUI/EUI.h"

enum Font {
	Title, // 标题
	SubTitle, // 副标题
	RecText, // 展示框文本
	Normal // 常规
};

void setFontStyle(enum Font font); // 设置标题文本样式