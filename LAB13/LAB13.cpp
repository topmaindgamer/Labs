#include <iostream>
using namespace std;

int tr = 1;
int board[8][8];

void show()
{
    for (int i = 0; i < 8; i++)
    {

        cout << 8 - i << ' ';
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == true) {
                cout << "W ";
            }
            else {
                cout << "* ";
            }
        }
        cout << '\n';

    }
    cout << ("  a b c d e f g h");
}

bool chek(int a, int b)
{
    for (int i = 0; i < a; ++i)
    {
        if (board[i][b])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b - i >= 0; ++i)
    {
        if (board[a - i][b - i])
        {
            return false;
        }
    }

    for (int i = 1; i <= a && b + i < 8; i++)
    {
        if (board[a - i][b + i])
        {
            return false;
        }
    }

    return true;
}


void put(int li)
{
    for (int i = 0; i < 8; ++i)
    {
        if (chek(li, i))
        {
            board[li][i] = 1;
            put(li + 1);
            board[li][i] = 0;
        }
    }

    if (li == 8)
    {
        cout << "Решение №" << tr << endl;
        tr++;
        show();
        cout << endl << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    put(0);
}