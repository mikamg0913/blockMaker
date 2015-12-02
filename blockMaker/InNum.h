#pragma once
#include "siv3D.hpp"

class InNum{
private:
	Vec2 size;
	String text;
	String tx0, tx1;
	Font *font;
	bool err;
public:
	InNum();
	bool In(Font fnt);
	Vec2 rtVec2();
	void del();
};