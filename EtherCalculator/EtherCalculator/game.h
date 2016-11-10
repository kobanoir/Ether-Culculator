#pragma once
#include "common.h"

class Game {
public:
	//コンストラクタ
	Game();

	enum State {
		MAIN,
		RESULT,
	};

	void update();
	void draw();
	//キーを書きたいとき呼び出す
	void draw_key(int x, int y);
private:
	State state;
};