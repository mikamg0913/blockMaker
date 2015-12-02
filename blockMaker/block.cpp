#include "block.h"


extern int fst;
block::block(){
	pal = new Color[6];
	pal[0] = Palette::White,pal[1] = Palette::Black;
	pal[2] = Palette::Red, pal[3] = Palette::Blue;
	pal[4] = Palette::Yellow, pal[5] = Palette::Green;
	num = 0;
}


block::block(Vec2 sz){
	size = sz;
	tile = new int*[(int)size.x];
	for (auto i : step((int)size.x))tile[i] = new int[(int)size.y];
	rect = new Rect*[(int)size.x];
	for (auto i : step((int)size.x)){
		rect[i] = new Rect[(int)size.y];
		for (auto j : step((int)size.y)){
			tile[i][j] = 0;
			rect[i][j].setSize(s, s);
			rect[i][j].setPos((i+1) * s, (j+1) * s);
		}
	}	
}

void block::ini(Vec2 sz){
	if (sz.y <= 36){
		s = 20;
	}
	else{
		s = 10;
	}
	size = sz;
	tile = new int*[(int)(size.x)];
	for (auto i : step((int)size.x))tile[i] = new int[(int)size.y];
	rect = new Rect*[(int)size.x];
	for (auto i : step((int)size.x)){
		rect[i] = new Rect[(int)size.y];
		for (auto j : step((int)size.y)){
			tile[i][j] = 0;
			rect[i][j].setSize(s, s);
			rect[i][j].setPos(i * s+20, j * s+20);
		}
	}
	sel.setSize(s-2,s-2);
	
}



void block::edit(Font fnt){
	for (auto i : step((int)size.x)){
		for (auto j : step((int)size.y)){
			rect[i][j].draw(pal[tile[i][j]]);
			if (rect[i][j].mouseOver){
				sel.setPos(i * s+1+20, j* s+1+20);
				sel.drawFrame(0, 1, Palette::Gray);
				if (Input::MouseL.pressed)tile[i][j] = num;
				if (Input::MouseR.clicked)num = tile[i][j];
			}

		}
	}

	Rect(size.x*s + 40, 20, 20, 19).draw(pal[num]);
	fnt(L"選").draw(size.x*s + 20, 19);
	for (auto i : step(6)){
		fnt(i).draw(size.x*s + 20, (i+1) * 20 + 20);
		Rect(size.x*s + 40, (i+1)*20+20,20,20).draw(pal[i]);
		if (Rect(size.x*s + 40, (i+1) * 20 + 20, 20, 20).mouseOver){
			Rect(size.x*s + 40 + 1, (i+1) * 20 + 20 + 1, 19, 18).drawFrame(0, 1, Color(255 - pal[i].r, 255 - pal[i].g, 255 - pal[i].b));
			if (Input::MouseL.clicked)num = i;
		}
	}
	
	fnt(L"保存する(sキー)").draw(size.x*s + 30, 180);
	fnt(L"やり直す(rキー)").draw(size.x*s + 30, 200+1);
	//fnt(L"やり直す(rキー)").draw(size.x*s + 30, 200 + 1);

	if (Input::KeyS.clicked)save();
	if (Input::KeyR.clicked)fst = 2;
}

//配列保存する
void block::save(){
	String txt;
	TextWriter writer(L"xy.txt");
	writer.writeln(L"xy[",size.x,L"][",size.y,L"]=");
	for (auto i : step((int)size.y)){
		txt.clear();
		if (i == 0)txt.operator+=(L"{");
		for (auto j : step((int)size.x)){
			txt.operator+=(Format(tile[j][i]));
			if (i == size.y - 1 && j == size.x - 1){
				txt.operator+=(L"}");
			}
			else{
				txt.operator+=(L",");
			}
		}
		if (i != size.y - 1)txt.push_back('\n');
		writer.writeln(txt);
	}	
}

//やり直し
void block::del(){
	delete tile;
	delete rect;
	size.x = 0, size.y = 0, num = 0;
	fst = 0;
	Window::Resize(400, 100);
}
