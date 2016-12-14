#include "game.h"

void Main()
{
	Window::Resize(1000, 800);

	const Font font(30);

	auto game = make_shared<Game>();

	if (!FontManager::Register(L"uzura.ttf"))
	{
		return;
	}


	while (System::Update())
	{
		game->update();
		game->draw();
	}
}
