#include "GameManager.h"
int main()
{
    GameManager game;
    game.StartGame();

    std::srand(static_cast<unsigned>(std::time(0))); // 시드 설정
    bool GameEnd = true;
    while (GameEnd)
    {
        GameEnd = game.ShowMenu();
    }
    return 0;
}