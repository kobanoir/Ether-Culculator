#pragma once
#include "common.h"

class Game {
public:
	//�R���X�g���N�^
	Game();

	enum State {
		MAIN,
		RESULT,
	};

	void update();
	void draw();
	//�L�[�����������Ƃ��Ăяo��
	void draw_key(int x, int y);
private:
	State state;
};