#include "InNum.h"


InNum::InNum(){
	text.clear(), tx0.clear(), tx1.clear();
	err = false;
}


bool InNum::In(Font fnt){
	Input::GetCharsHelper(text);
	fnt(L"ƒTƒCƒY‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(—á:10,20)").draw(0, 0);
	fnt(L"”ÍˆÍ‚Í2‚©‚ç72‚Ü‚Å‚Å‚·").draw(0,20);
	fnt(text).draw(0,40);
	if (Input::KeyEnter.clicked){
		bool sw=false;
		for (int i = 0; text[i] != (char)NULL; i++){
			if ((text[i] >= '0' && text[i] <= '9') || text[i] == ','){
				if (text[i] == ','){
					sw = true;
					i++;
				}
				if (sw == false){
					tx0.push_back(text[i]);
				}
				else{ tx1.push_back(text[i]); }
			}
		}
		if ((FromString<int>(tx0) >= 2 && FromString<int>(tx0) <= 72) &&
			(FromString<int>(tx1) >= 2 && FromString<int>(tx1) <= 72)){
			size = Vec2(FromString<int>(tx0), FromString<int>(tx1));
			return true;
			text.clear(), tx0.clear(), tx1.clear();
			err = false;
		}
		else{
			text.clear(),tx0.clear(),tx1.clear();
			err = true;
		}
	}
	if (err == true)fnt(L"error").draw(0,60);
	return false;
	
}

void InNum::del(){
	text.clear(),tx0.clear(),tx1.clear();
}

Vec2 InNum::rtVec2(){ return size; }