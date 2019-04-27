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

void Render::draw(Player* player, Enemy* enemy, GameObject* key1, GameObject* key2, GameObject* key3, GameObject* environment, GameObject* tree, int tree_size)
{
	environment->Draw();

	std::sort(tree, tree + tree_size,
		[](GameObject const & a, GameObject const & b) -> bool
	{ return a.zIndex < b.zIndex; });
	
	bool player_drawn = false;

	for (int i = 0; i < tree_size; i++) {
		if (tree[i].zIndex > player->zIndex && !player_drawn) {
			player->Animate();
			player_drawn = true;
		}
		tree[i].Draw();

	}
	if (player_drawn == false)
	{
		player->Animate();
	}
	
	//enemy->Draw();
	key1->Draw();
	key2->Draw();
	key3->Draw();
}
