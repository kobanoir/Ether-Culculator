#include "game.h"

Game::Game() {
	state = State::MAIN;
}

void Game::draw_key(int x, int y) {
	RoundRect(x, y, 150, 70, 10).draw();
}

void Game::update() {
	switch (state) {
	case State::MAIN:
		break;
	case State::RESULT:
		break;
	}
}

void Game::draw() {
	switch (state) {
	case State::MAIN:
		draw_key(200, 180);
		draw_key(200, 300);
		draw_key(200, 420);
		draw_key(200, 540);
		draw_key(600, 180);
		draw_key(600, 300);
		draw_key(600, 420);
		draw_key(600, 540);
		draw_key(820, 30);
		break;
	case State::RESULT:
		break;
	}
}