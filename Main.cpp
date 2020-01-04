#include "Game.h"
#include <time.h>

using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));
	Game game;
	game.run();
	return 0;
}