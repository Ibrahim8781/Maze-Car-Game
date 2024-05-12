//Mohammad_Ibraheem_22I-2603, Ibrahim_Ahmed_22I-8781
#include"Header1.h"
void main() {
	Game game;
	int menCh = game.Menu();
	switch (menCh) {
	case 1: {
		game.Manual();
		break;
	}
	case 2: {
		game.Auto();
	}
	case 3: {
		game.showScore();
		break;
	}
	case 0: {
		exit(1);
	}
	}
}