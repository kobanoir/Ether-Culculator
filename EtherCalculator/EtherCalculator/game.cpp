#include "game.h"

static RoundRect copper_up(50, 180, 150, 30, 10);
static RoundRect copper_down(50, 220, 150, 30, 10);
static RoundRect silver_up(50, 330, 150, 30, 10);
static RoundRect silver_down(50, 370, 150, 30, 10);
static RoundRect gold_up(50, 480, 150, 30, 10);
static RoundRect gold_down(50, 520, 150, 30, 10);
static RoundRect legend_up(50, 630, 150, 30, 10);
static RoundRect legend_down(50, 670, 150, 30, 10);
static RoundRect P_copper_up(300, 180, 150, 30, 10);
static RoundRect P_copper_down(300, 220, 150, 30, 10);
static RoundRect P_silver_up(300, 330, 150, 30, 10);
static RoundRect P_silver_down(300, 370, 150, 30, 10);
static RoundRect P_gold_up(300, 480, 150, 30, 10);
static RoundRect P_gold_down(300, 520, 150, 30, 10);
static RoundRect P_legend_up(300, 630, 150, 30, 10);
static RoundRect P_legend_down(300, 670, 150, 30, 10);
static RoundRect reset(800, 50, 150, 60, 10);

Game::Game() {
	state = State::MAIN;
}

void Game::update() {

	static Point pos = Mouse::Pos();

	switch (state) {
	case State::MAIN:
		if (copper_up.mouseOver && Input::MouseL.clicked) {
			copper++;
		}
		if (silver_up.mouseOver && Input::MouseL.clicked) {
			silver++;
		}
		if (gold_up.mouseOver && Input::MouseL.clicked) {
			gold++;
		}
		if (legend_up.mouseOver && Input::MouseL.clicked) {
			legend++;
		}
		if (copper_down.mouseOver && Input::MouseL.clicked && copper > 0) {
			copper--;
		}
		if (silver_down.mouseOver && Input::MouseL.clicked && silver > 0) {
			silver--;
		}
		if (gold_down.mouseOver && Input::MouseL.clicked && gold > 0) {
			gold--;
		}
		if (legend_down.mouseOver && Input::MouseL.clicked && legend > 0) {
			legend--;
		}
		if (P_copper_up.mouseOver && Input::MouseL.clicked) {
			P_copper++;
		}
		if (P_silver_up.mouseOver && Input::MouseL.clicked) {
			P_silver++;
		}
		if (P_gold_up.mouseOver && Input::MouseL.clicked) {
			P_gold++;
		}
		if (P_legend_up.mouseOver && Input::MouseL.clicked) {
			P_legend++;
		}
		if (P_copper_down.mouseOver && Input::MouseL.clicked && P_copper > 0) {
			P_copper--;
		}
		if (P_silver_down.mouseOver && Input::MouseL.clicked && P_silver > 0) {
			P_silver--;
		}
		if (P_gold_down.mouseOver && Input::MouseL.clicked && P_gold > 0) {
			P_gold--;
		}
		if (P_legend_down.mouseOver && Input::MouseL.clicked && P_legend > 0) {
			P_legend--;
		}
		if (reset.mouseOver && Input::MouseL.clicked) {
			copper = 0;
			P_copper = 0;
			silver = 0;
			P_silver = 0;
			gold = 0;
			P_gold = 0;
			legend = 0;
			P_legend = 0;
		}
		total = copper * 10 + silver * 50 + gold * 250 + legend * 1000 + P_copper * 30 + P_silver * 120 + P_gold * 600 + P_legend * 2500;
		break;
	case State::RESULT:
		break;
	}
}

void Game::draw() {
	static Font font(20, L"うずらフォント");
	static Font title(30, L"うずらフォント");
	static Font small(10, L"うずらフォント");
	static Font count(15, L"うずらフォント");

	switch (state) {
	case State::MAIN:
		copper_up.draw();
		silver_up.draw();
		gold_up.draw();
		legend_up.draw();
		copper_down.draw();
		silver_down.draw();
		gold_down.draw();
		legend_down.draw();
		P_copper_up.draw();
		P_silver_up.draw();
		P_gold_up.draw();
		P_legend_up.draw();
		P_copper_down.draw();
		P_silver_down.draw();
		P_gold_down.draw();
		P_legend_down.draw();
		reset.draw();
		title(L"エーテル計算機").draw(20,20);
		font(L"ブロンズ").draw(50, 110);
		font(L"シルバー").draw(50, 270);
		font(L"ゴールド").draw(50, 420);
		font(L"レジェンド").draw(15, 570);
		font(L"プレミアム").draw(280, 110);
		font(L"プレミアム").draw(280, 270);
		font(L"プレミアム").draw(280, 420);
		font(L"プレミアム").draw(280, 570);
		font(L"リセット").draw(805, 60, Palette::Black);
		small(L"+1").draw(115, 185, Palette::Black);
		small(L"+1").draw(115, 335, Palette::Black);
		small(L"+1").draw(115, 485, Palette::Black);
		small(L"+1").draw(115, 635, Palette::Black);
		small(L"+1").draw(365, 185, Palette::Black);
		small(L"+1").draw(365, 335, Palette::Black);
		small(L"+1").draw(365, 485, Palette::Black);
		small(L"+1").draw(365, 635, Palette::Black);
		small(L"-1").draw(115, 225, Palette::Black);
		small(L"-1").draw(115, 375, Palette::Black);
		small(L"-1").draw(115, 525, Palette::Black);
		small(L"-1").draw(115, 675, Palette::Black);
		small(L"-1").draw(365, 225, Palette::Black);
		small(L"-1").draw(365, 375, Palette::Black);
		small(L"-1").draw(365, 525, Palette::Black);
		small(L"-1").draw(365, 675, Palette::Black);
		count(L"ブロンズ:").draw(550, 300);
		count(L"シルバー:").draw(550, 400);
		count(L"ゴールド:").draw(550, 500);
		count(L"レジェンド:").draw(525, 600);
		count(L"プレミアム:").draw(770, 300);
		count(L"プレミアム:").draw(770, 400);
		count(L"プレミアム:").draw(770, 500);
		count(L"プレミアム:").draw(770, 600);
		title(L"合計").draw(500, 700);
		title(total).draw(700, 700);
		count(copper).draw(700,300);
		count(silver).draw(700, 400);
		count(gold).draw(700, 500);
		count(legend).draw(700, 600);
		count(P_copper).draw(940, 300);
		count(P_silver).draw(940, 400);
		count(P_gold).draw(940, 500);
		count(P_legend).draw(940, 600);
		break;
	case State::RESULT:
		break;
	}
}