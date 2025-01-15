#include "GameManager.h"
int main()
{
    GameManager game;
    game.StartGame();

    bool GameEnd = true;
    while (GameEnd)
    {
        GameEnd = game.ShowMenu();
    }
    return 0;
}