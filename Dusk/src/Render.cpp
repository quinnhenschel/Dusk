#include "ofMain.h"
#include "Render.h"


Render::Render()
{
}

Render::~Render()
{
}

void Render::determineGameObjectZ()
{
	cout << "move";
}

void Render::moveCamera()
{
	cout << "pew";
}

void Render::draw(Player* player, Enemy* enemy)
{
	player->Draw();
	enemy->Draw();
}
