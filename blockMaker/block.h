#pragma once
#include "siv3D.hpp"

class block{
private:
	Vec2 size;
	int **tile;
	Rect **rect;
	Rect sel;
	//ƒ^ƒCƒ‹‚ÌŽí—Þ
	int num;
public:
	double s;
	Color *pal;
	block();
	block(Vec2 sz);
	void ini(Vec2 sz);
	void edit(Font fnt);
	void save();
	void del();
};

