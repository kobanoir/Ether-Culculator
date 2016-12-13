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
private:
	State state;
	int copper=0,P_copper=0;
	int silver=0, P_silver=0;
	int gold=0, P_gold=0;
	int legend=0, P_legend=0;
	int total = 0;
};