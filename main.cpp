#include <iostream>
#include <conio.h>

using namespace std;

void update(char t[][3])
{
    system("CLS");
    cout << "    0   1   2\n";
    cout << "  -------------\n";
    for (int i=0; i<3; i++)
    {
        cout << i << " ";
        for (int j=0; j<3; j++)
        {
            cout << "| " << t[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "  -------------\n";
}
void input(char t[][3], char turn)
{
    // choose column
    int i, j;
    cout << turn << " turn\n";
    while (1)
    {
        cout << "Enter 2d array index to play: ";
        cin >> i;
        cin >> j;

        if ((i > 2) || (j > 2))
        {
            cout << "Error! Index out of range\n";
            continue;
        }
        if (t[i][j] != '?')
        {
            cout << "Error! This channel is already taken\n\n";
            continue;
        }
        else
        {
            t[i][j] = turn;
            break;
        }
    }
}
char check(char t[][3], char turn)
{
    // all pattern to win
    if ((t[0][0] == turn) && (t[0][1] == turn) && (t[0][2] == turn))
        return turn;
    else if ((t[1][0] == turn) && (t[1][1] == turn) && (t[1][2] == turn))
        return turn;
    else if ((t[2][0] == turn) && (t[2][1] == turn) && (t[2][2] == turn))
        return turn;
    else if ((t[0][0] == turn) && (t[1][0] == turn) && (t[2][0] == turn))
        return turn;
    else if ((t[0][1] == turn) && (t[1][1] == turn) && (t[2][1] == turn))
        return turn;
    else if ((t[0][2] == turn) && (t[1][2] == turn) && (t[2][2] == turn))
        return turn;
    else if ((t[0][0] == turn) && (t[1][1] == turn) && (t[2][2] == turn))
        return turn;
    else if ((t[0][2] == turn) && (t[1][1] == turn) && (t[2][0] == turn))
        return turn;
    else
        return '?';
}
int main()
{
    // set all column to '?'
    char ttt[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
            ttt[i][j] = '?';
    }
    // gameplay
    char turn, win = '?';
    for (int round=1; round<=9; round++)
    {
        if ((round % 2) == 0)
            turn = 'o';
        else
            turn = 'x';

        update(ttt);
        if (win != '?')
            break;
        input(ttt, turn);
        win = check(ttt, turn);
    }
    // winner check
    if (win == 'x')
        cout << "\nx is winner !!!\n";
    else if (win == 'o')
        cout << "\no is winner !!!\n";
    else
        cout << "\ndraw :(\n";
    getch();

    return 0;
}