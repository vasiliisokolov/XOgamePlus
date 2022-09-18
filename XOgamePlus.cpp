#include <iostream>

bool check_move(int, int);
std::pair<bool, char> check_won(char battleField[][3], int, int);

int main()
{
    int iInput, jInput;
    char move, won;
    bool fin = false;
    char battleField[3][3] =
    {
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'}
    };

    for(int count = 0; count < 10 && !fin; count++)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << battleField[i][j] << " ";
            }
            std::cout << std::endl;
        }
        if (count % 2 == 0)
        {
            move = 'X';
        }
        else
        {
            move = 'O';
        }
        do
        {
            std::cout << "Player " << move << ", make a move: \n";
            std::cin >> iInput >> jInput;
        } while (!check_move(iInput, jInput));
        battleField[iInput][jInput] = move;
        std::pair < bool, char > iswon = check_won(battleField, iInput, jInput);
        fin = iswon.first;
        won = iswon.second;
      
    } 
    if (fin)
        std::cout << won << " is won!" << std::endl;
    else
        std::cout << "Drawn!" << std::endl;
}

bool check_move(int i, int j)
{
    if (i < 0 || i> 2 && j < 0 || j > 2)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

std::pair<bool, char> check_won(char battleField[][3], int iInput, int jInput)
{
    std::string line = "", column = "";
    bool haveWinner = false;
    char result;
    for (int i = 0; i < 3; i++)
    {
        line += battleField[iInput][i];
        column += battleField[i][jInput];
    }
    if (column == "XXX" || line == "XXX")
    {
        haveWinner = true;
        result = 'X';
    }
    else if (column == "OOO" || line == "OOO")
    {
        haveWinner = true;
        result = 'O';
    }
    return std::make_pair(haveWinner, result);
}
