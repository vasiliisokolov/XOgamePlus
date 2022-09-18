#include <iostream>

int main()
{
    int iInput, jInput;
    char move;
    char battleField[3][3] =
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    for(int count = 0; count < 10; count++)
    {
        if (count % 2 == 0)
        {
            move = 'X';
        }
        else
        {
            move = 'O';
        }
        std::cout << "Player " << move << ", make a move: \n";
        std::cin >> iInput >> jInput;
        battleField[iInput][jInput] = move;
    }
    
}

