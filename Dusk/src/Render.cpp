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

void Render::draw(Player* player, Enemy* enemy, GameObject* key1, GameObject* key2, GameObject* key3, GameObject* environment)
{
	environment->Draw();
	player->Animate();
	//enemy->Draw();
	key1->Draw();
	key2->Draw();
	key3->Draw();
}
