
# include <Siv3D.hpp>
#include "InNum.h"
#include "block.h"

int fst = 0;
void Main()
{
	Window::SetTitle(L"blockMaker");
	const Font font(10);
	const Font fnt(5);
	InNum innum;
	Window::Resize(300, 100);
	String text;
	bool swnum;
	Vec2 size;
	block bl;
	Graphics::SetBackground(Color(100,100,100));

	while (System::Update())
	{
		if (fst == 0){
			swnum = innum.In(font);
			if (swnum == true){//サイズが入力された
				size = innum.rtVec2();//サイズ代入
				fst = true;
				bl.ini(size);
				if (size.y < 10){
					Window::Resize(bl.s*size.x + 150, 240);
				}
				else{
					Window::Resize(bl.s*size.x + 150, bl.s*size.y + 40);
				}
			}
		}
		else if(fst==1){
			//サイズ表示
			if (size.y <= 100){
				font(L"サイズ", size).draw(0, 0);
				bl.edit(font);
			}
			else{
				fnt(L"サイズ", size).draw(0, 0);
				bl.edit(fnt);
			}
		}
		else if (fst == 2){
			innum.del();
			bl.del();
		}
	}
}
