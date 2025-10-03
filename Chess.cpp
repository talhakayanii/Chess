#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<time.h>

char box = 219;
using namespace std;
void start();
void king(int, int);
void queen(int, int);
void rock(int, int);
void bishop(int, int);
void knight(int, int);
void saveyourking();
void queen_attack();
void queen_location(int&, int&, int&, int&, int(&array)[8][8]);
void rock_attack();
void rock_location(int&, int&, int&, int&, int(&array)[8][8]);
void bishop_attack();
void bishop_location(int&, int&, int&, int&, int(&array)[8][8]);
void knight_attack();
void knight_location(int&, int&, int&, int&, int(&array)[8][8]);
void king_attack(int&, int&, int&, int&, int(&array)[8][8]);
int main()
{
    start();
}
//FUNCTION DEFINITIONS
void start()
{
    //YOUR NEXT MOVE PREDICTION

    int choice, row, column;
    int rungame;
    int repeat = 1;
    while (repeat == 1)
    {
        cout << "PLEASE SELECT ANY OF THE FOLLOWING CHOICES\n";
        cout << "[1] KING\n";
        cout << "[2] QUEEN\n";
        cout << "[3] ROCK\n";
        cout << "[4] BISHOP\n";
        cout << "[5] KNIGHT\n";
        cout << "[6] FINISH\n";
        cin >> choice;
        if (choice == 6)
        {
            repeat = 0;
        }
        while (choice < 1 || choice>6)
        {
            cout << "KINDLY MAKE THE RIGHT CHOICE\n";
            cin >> choice;
        }
        if (choice != 6)
        {
            cout << "PLEASE SELECT THE INITIAL POSITION OF THE SELECTED PIECE\n";
            cout << "ENTER ROW\n";
            cin >> row;
            while (row < 1 || row>8)
            {
                cout << "KINDLY MAKE THE RIGHT CHOICE\n";
                cin >> row;
            }


            cout << "ENTER COLUMN\n";
            cin >> column;
            while (column < 1 || column>8)
            {
                cout << "KINDLY MAKE THE RIGHT CHOICE\n";
                cin >> column;
            }
        }


        switch (choice)
        {
        case 1:
        {
            king(row, column);
            break;
        }
        case 2:
        {
            queen(row, column);
            break;
        }
        case 3:
        {
            rock(row, column);
            break;
        }
        case 4:
        {
            bishop(row, column);
            break;
        }
        case 5:
        {
            knight(row, column);
            break;
        }
        case 6:
        {
            repeat = 0;
            break;
        }


        }

    }
    system("cls");
    cout << "DO YOU WANT TO PLAY GAME?\n";
    cout << "PRESS 0 FOR NO AND PRESS 1 FOR YES\n";
    cin >> rungame;
    while (rungame != 0 && rungame != 1)
    {
        cin >> rungame;
    }
    if (rungame == 0)
    {
        exit(1);
    }
    else if (rungame == 1)
    {
        saveyourking();
    }
}

void king(int row, int column)
{
    //KING CASE
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 10;
        }
    }
    if (row == 1 && column == 8)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 1] = 2;

    }
    else if (column == 8)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 1] = 2;
    }
    else if (column == 1)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1 - 1][column + 1 - 1] = 2;
        array[row - 1][column + 1 - 1] = 2;
        array[row + 1 - 1][column - 1] = 2;
        array[row + 1 - 1][column + 1 - 1] = 2;
    }
    else if (row == 1)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1][column - 1 - 1] = 2;
        array[row - 1][column + 1 - 1] = 2;
        array[row + 1 - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column + 1 - 1] = 2;
    }
    else if (row == 8)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1 - 1][column + 1 - 1] = 2;
        array[row - 1][column - 1 - 1] = 2;
        array[row - 1][column + 1 - 1] = 2;
    }
    else if (row == 8 && column == 8)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1][column - 1 - 1] = 2;

    }
    else if (row == 1 && column == 1)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1][column + 1 - 1] = 2;
        array[row + 1 - 1][column - 1] = 2;
        array[row + 1 - 1][column + 1 - 1] = 2;
    }
    else if (row == 8 && column == 1)
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1 - 1][column + 1 - 1] = 2;
        array[row - 1][column + 1 - 1] = 2;
    }
    else
    {
        cout << "EXISTING POSITION OF YOUR KING PIECE IS " << "[" << row << "," << column << "]" << endl;
        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 1] = 2;
        array[row - 1 - 1][column + 1 - 1] = 2;
        array[row - 1][column - 1 - 1] = 2;
        array[row - 1][column - 1 + 1] = 2;
        array[row][column - 2] = 2;
        array[row + 1 - 1][column - 1] = 2;
        array[row + 1 - 1][column + 1 - 1] = 2;
    }
    array[row - 1][column - 1] = 1;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 10)
            {
                cout << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 10)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void queen(int row, int column)
{
    //QUEEN CASE
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 10;
        }
    }

    cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";

    //Horizontal and vertical moves
    for (int i = 1; i <= 8; i++)
    {
        if (i != column) {
            array[row - 1][i - 1] = 1;
        }
        if (i != row) {
            array[i - 1][column - 1] = 1;
        }
    }

    //Diagonal moves
    int r = row, c = column;
    while (r > 1 && c > 1) {
        r--;
        c--;
        array[r - 1][c - 1] = 1;
    }
    r = row;
    c = column;
    while (r < 8 && c > 1) {
        r++;
        c--;
        array[r - 1][c - 1] = 1;
    }
    r = row;
    c = column;
    while (r > 1 && c < 8) {
        r--;
        c++;
        array[r - 1][c - 1] = 1;
    }
    r = row;
    c = column;
    while (r < 8 && c < 8)
    {
        r++;
        c++;
        array[r - 1][c - 1] = 1;
    }
    array[row - 1][column - 1] = 2;

    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 10)
            {
                cout << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 10)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void rock(int row, int column)
{
    //Rock CASE
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 10;
        }
    }

    cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";

    //Horizontal and vertical moves
    for (int i = 1; i <= 8; i++)
    {
        if (i != column) {
            array[row - 1][i - 1] = 2;
        }
        if (i != row) {
            array[i - 1][column - 1] = 2;
        }
    }
    array[row - 1][column - 1] = 1;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 10)
            {
                cout << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 10)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void bishop(int row, int column)
{
    //Bishop CASE
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 10;
        }
    }
    cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
    //Diagonal moves
    int r = row, c = column;
    while (r > 1 && c > 1) {
        r--;
        c--;
        array[r - 1][c - 1] = 2;
    }
    r = row;
    c = column;
    while (r < 8 && c > 1) {
        r++;
        c--;
        array[r - 1][c - 1] = 2;
    }
    r = row;
    c = column;
    while (r > 1 && c < 8) {
        r--;
        c++;
        array[r - 1][c - 1] = 2;
    }
    r = row;
    c = column;
    while (r < 8 && c < 8)
    {
        r++;
        c++;
        array[r - 1][c - 1] = 2;
    }
    array[row - 1][column - 1] = 1;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 10)
            {
                cout << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 10)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void knight(int row, int column)
{
    //Knights case
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 10;
        }
    }
    if (row == 1 && column == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 1 - 1][column - 2 - 1] = 2;

    }
    else if (row == 2 && column == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
    }
    else if (row == 7 && column == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;
    }
    else if (column == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
    }
    else if (row == 8 && column == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;

    }


    else if (row == 1 && column == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;

    }
    else if (row == 2 && column == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
    }
    else if (row == 7 && column == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 2 - 1][column + 1 - 1] = 2;
    }
    else if (column == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row - 2 - 1][column + 1 - 1] = 2;
    }
    else if (row == 8 && column == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row - 2 - 1][column + 1 - 1] = 2;

    }


    else if (row == 1 && column == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;

    }
    else if (row == 2 && column == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
    }
    else if (row == 7 && column == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
    }
    else if (column == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
    }
    else if (row == 8 && column == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;

    }


    else if (row == 1 && column == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;

    }
    else if (row == 2 && column == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
    }
    else if (row == 7 && column == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;
    }
    else if (column == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
    }
    else if (row == 8 && column == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row - 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;

    }
    else if (row == 1)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;

    }
    else if (row == 2)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;

    }
    else if (row == 7)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;

    }
    else if (row == 8)
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;

    }
    else
    {

        cout << "ALL POSSIBLE NEXT POSITIONS OF THE SELECTED PIECE ARE \n";
        array[row + 1 - 1][column - 2 - 1] = 2;
        array[row + 1 - 1][column + 2 - 1] = 2;
        array[row + 2 - 1][column - 1 - 1] = 2;
        array[row + 2 - 1][column + 1 - 1] = 2;
        array[row - 1 - 1][column + 2 - 1] = 2;
        array[row - 1 - 1][column - 2 - 1] = 2;
        array[row - 2 - 1][column - 1 - 1] = 2;
        array[row - 2 - 1][column + 1 - 1] = 2;

    }
    array[row - 1][column - 1] = 1;

    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 10)
            {
                cout << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 10)
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}
void saveyourking()
{
    //SAVE THE KING
    srand(time(0));
    int choice2, current_1, current_2;
    int enemy;

    cout << "YOU WANT TO ATTACK WITH?\n";
    cout << "[1] QUEEN\n";
    cout << "[2] ROCK\n";
    cout << "[3] BISHOP\n";
    cout << "[4] KNIGHT\n";
    cin >> enemy;
    while (enemy < 1 && enemy>4)
    {
        cin >> enemy;
    }
    system("cls");
    switch (enemy)
    {
    case 1:
    {
        queen_attack();

    }
    case 2:
    {
        rock_attack();
    }
    case 3:
    {
        bishop_attack();
    }
    case 4:
    {
        knight_attack();
    }
    }

}
void queen_attack()
{
    int row, column;
    int row1, column1;
    int desirerow1 = (rand() % 8) + 1, desirecolumn1 = (rand() % 8) + 1, desirerow = (rand() % 8) + 1, desirecolumn = (rand() % 8) + 1;
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 0;
        }
    }
    //10 FOR KING AND RED COLOUR
    array[desirerow1 - 1][desirecolumn1 - 1] = 10;
    //20 FOR QUEEN AND BLUE COLOUR
    array[desirerow - 1][desirecolumn - 1] = 20;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "Q" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 0)
            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 0)
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

    while (1)
    {
        for (int i = 0;i < 10;i++)
        {
            if ((i % 2) == 0) {

                cout << "ENTER CURRENT POSITION OF YOUR QUEEN (rows and columns respectively)\n";
            noun:
                cin >> row >> column;
                if (array[row - 1][column - 1] != 20)
                {
                    cout << "ENTERED POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun;
                }
                queen_location(row, column, desirerow, desirecolumn, array);
            }


            if ((i % 2) != 0)

            {

                cout << "ENTER CURRENT POSITION OF YOUR KING (rows and columns respectively)\n";
            noun1:
                cin >> row1 >> column1;
                if (array[row1 - 1][column1 - 1] != 10)
                {
                    cout << "ENTERED KING POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun1;
                }
                king_attack(row1, column1, desirerow1, desirecolumn1, array);
            }
        }
        if (array[desirerow - 1][desirecolumn - 1] == 10)
        {
            cout << "YOU WON\n";
        }

    }
}
void queen_location(int& row, int& column, int& desirerow, int& desirecolumn, int(&array)[8][8])
{
    array[row - 1][column - 1] = 0;
    //array[row1 - 1][column1 - 1] = 0;
first:
    cout << "ENTER DESIRED POSITION OF YOUR QUEEN (rows and columns respectively)\n";
start:
    cin >> desirerow >> desirecolumn;
    if (array[desirerow - 1][desirecolumn - 1] == 10) {
        cout << "YOU WON\n\n";
        exit(1);




    }
    //Horizontal and vertical moves

    for (int i = 1; i <= 8; i++)
    {
        if (i != column && (array[row - 1][column - 1] != 10)) {
            array[row - 1][i - 1] = 1;
        }
        if (i != row && (array[row - 1][column - 1] != 10))
        {
            array[i - 1][column - 1] = 1;
        }
    }

    //Diagonal moves
    int r = row, c = column;
    while (r > 1 && c > 1) {
        r--;
        c--;
        if (array[r - 1][c - 1] != 10)
        {
            array[r - 1][c - 1] = 1;
        }
    }
    r = row;
    c = column;
    while (r < 8 && c > 1) {
        r++;
        c--;
        if (array[r - 1][c - 1] != 10)
        {
            array[r - 1][c - 1] = 1;
        }
    }
    r = row;
    c = column;
    while (r > 1 && c < 8) {
        r--;
        c++;
        if (array[r - 1][c - 1] != 10) {
            array[r - 1][c - 1] = 1;
        }
    }
    r = row;
    c = column;
    while (r < 8 && c < 8)
    {
        r++;
        c++;
        if (array[r - 1][c - 1] != 10)
        {
            array[r - 1][c - 1] = 1;
        }
    }

    if (array[desirerow - 1][desirecolumn - 1] != 1) {
        cout << "Not a possible move\n";
        goto start;

    }


    array[desirerow - 1][desirecolumn - 1] = 20;


    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "Q" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && (array[i][j] == 0 || array[i][j] == 1))

            {
                cout << box << box << box << box;
            }

            else if ((i + j) % 2 != 0 && (array[i][j] == 0 || array[i][j] == 1))
            {
                cout << "    ";
            }
        }
        cout << endl;
    }
}
void king_attack(int& row1, int& column1, int& desirerow1, int& desirecolumn1, int(&array)[8][8])
{
    array[row1 - 1][column1 - 1] = 0;
    cout << "ENTER DESIRED POSITION OF YOUR KING (rows and columns respectively)\n";
start:
    cin >> desirerow1 >> desirecolumn1;

    if (row1 == 1 && column1 == 8)
    {
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1] = 2;
        }

    }
    else if (column1 == 8)
    {
        if (array[row1 - 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1] = 2;
        }
    }
    else if (column1 == 1)
    {
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 + 1 - 1] = 2)
        {
            array[row1 + 1 - 1][column1 + 1 - 1] = 2;
        }
    }
    else if (row1 == 1)
    {
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1 - 1] = 20;
        }
        if (array[row1 + 1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 + 1 - 1] = 2;
        }
    }
    else if (row1 == 8)
    {
        if (array[row1 - 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1][column1 + 1 - 1] = 2;
        }
    }
    //
    else if (row1 == 8 && column1 == 8)
    {
        if (array[row1 - 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }

    }
    else if (row1 == 1 && column1 == 1)
    {
        if (array[row1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 + 1 - 1] = 2;
        }
    }
    else if (row1 == 8 && column1 == 1)
    {
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 + 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 - 1][column1 + 1 - 1] = 2;
        }
    }
    else
    {

        if (array[row1 - 1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1 - 1][column1 - 1] != 20)
        {
            array[row1 - 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 - 1][column1 - 1 - 1] != 20)
        {
            array[row1 - 1][column1 - 1 - 1] = 2;
        }
        if (array[row1 - 1][column1 - 1 + 1] != 20)
        {
            array[row1 - 1][column1 - 1 + 1] = 2;
        }
        if (array[row1][column1 - 2] != 20)
        {
            array[row1][column1 - 2] = 2;
        }
        if (array[row1 + 1 - 1][column1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 - 1] = 2;
        }
        if (array[row1 + 1 - 1][column1 + 1 - 1] != 20)
        {
            array[row1 + 1 - 1][column1 + 1 - 1] = 2;
        }
    }
    if (array[desirerow1 - 1][desirecolumn1 - 1] != 2) {
        cout << "Not a possible move\n";
        goto start;

    }
    array[desirerow1 - 1][desirecolumn1 - 1] = 10;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "%" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && (array[i][j] == 0 || array[i][j] == 2 || array[i][j] == 1))

            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && (array[i][j] == 0 || array[i][j] == 2 || array[i][j] == 1))
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

}
void rock_attack()
{
    int row, column, secondr, secondc;
    //king variables
    int row1, column1;
    //for king
    int desirerow1 = (rand() % 8) + 1, desirecolumn1 = (rand() % 8) + 1;
    //for rock
    int desirerow = (rand() % 8) + 1, desirecolumn = (rand() % 8) + 1;
    int desirer = (rand() % 8) + 1, desirec = (rand() % 8) + 1;
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 0;
        }
    }
    //10 FOR KING AND RED COLOUR
    array[desirerow1 - 1][desirecolumn1 - 1] = 10;
    //20 FOR ROCK
    array[desirerow - 1][desirecolumn - 1] = 20;
    array[desirer - 1][desirec - 1] = 20;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "R" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 0)
            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 0)
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

    while (1)
    {
        for (int i = 0;i < 10;i++)
        {
            if ((i % 2) == 0) {


                cout << "ENTER CURRENT POSITION OF YOUR ROCK (rows and columns respectively)\n";
            noun:
                cin >> row >> column;
                if (array[row - 1][column - 1] != 20)
                {
                    cout << "ENTERED POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun;
                }
                rock_location(row, column, desirerow, desirecolumn, array);

            }


            if ((i % 2) != 0)

            {

                cout << "ENTER CURRENT POSITION OF YOUR KING (rows and columns respectively)\n";
            noun1:
                cin >> row1 >> column1;
                if (array[row1 - 1][column1 - 1] != 10)
                {
                    cout << "ENTERED KING POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun1;
                }
                king_attack(row1, column1, desirerow1, desirecolumn1, array);
            }
        }
        if (array[desirerow - 1][desirecolumn - 1] == 10)
        {
            cout << "YOU WON\n";
        }

    }
}
void rock_location(int& row, int& column, int& desirerow, int& desirecolumn, int(&array)[8][8])
{
    array[row - 1][column - 1] = 0;
first:

    cout << "ENTER DESIRED POSITION OF YOUR ROCK (rows and columns respectively)\n";
start:
    cin >> desirerow >> desirecolumn;
    if (array[desirerow - 1][desirecolumn - 1] == 10) {
        cout << "YOU WON\n\n";
        exit(1);

    }
    //POSSIBLE MOVEMENTS FOR ROCK
    for (int i = 1; i <= 8; i++)
    {
        if (i != column)
        {
            if (array[row - 1][i - 1] != 10 && array[row - 1][i - 1] != 20)
                array[row - 1][i - 1] = 2;
        }
        if (i != row)
        {
            if (array[i - 1][column - 1] != 10 && array[i - 1][column - 1] != 20)
                array[i - 1][column - 1] = 2;
        }
    }



    if (array[desirerow - 1][desirecolumn - 1] != 2) {
        cout << "Not a possible move\n";
        goto start;

    }


    array[desirerow - 1][desirecolumn - 1] = 20;


    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "R" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && (array[i][j] == 0 || array[i][j] == 2))

            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && (array[i][j] == 0 || array[i][j] == 2))
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

}
void bishop_attack()
{
    int row, column, secondr, secondc;
    //king variables
    int row1, column1;
    //for bishop
    int desirerow1 = (rand() % 8) + 1, desirecolumn1 = (rand() % 8) + 1;
    //for rock
    int desirerow = (rand() % 8) + 1, desirecolumn = (rand() % 8) + 1;
    int desirer = (rand() % 8) + 1, desirec = (rand() % 8) + 1;
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 0;
        }
    }
    //10 FOR KING AND RED COLOUR
    array[desirerow1 - 1][desirecolumn1 - 1] = 10;
    //20 FOR BISHOP
    array[desirerow - 1][desirecolumn - 1] = 20;
    array[desirer - 1][desirec - 1] = 20;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "B" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 0)
            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 0)
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

    while (1)
    {
        for (int i = 0;i < 10;i++)
        {
            if ((i % 2) == 0) {


                cout << "ENTER CURRENT POSITION OF YOUR BISHOP (rows and columns respectively)\n";
            noun:
                cin >> row >> column;
                if (array[row - 1][column - 1] != 20)
                {
                    cout << "ENTERED POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun;
                }
                bishop_location(row, column, desirerow, desirecolumn, array);

            }


            if ((i % 2) != 0)

            {

                cout << "ENTER CURRENT POSITION OF YOUR KING (rows and columns respectively)\n";
            noun1:
                cin >> row1 >> column1;
                if (array[row1 - 1][column1 - 1] != 10)
                {
                    cout << "ENTERED KING POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun1;
                }
                king_attack(row1, column1, desirerow1, desirecolumn1, array);
            }
        }
        if (array[desirerow - 1][desirecolumn - 1] == 10)
        {
            cout << "YOU WON\n";
        }

    }


}
void bishop_location(int& row, int& column, int& desirerow, int& desirecolumn, int(&array)[8][8])
{
    array[row - 1][column - 1] = 0;
first:

    cout << "ENTER DESIRED POSITION OF YOUR BISHOP (rows and columns respectively)\n";
start:
    cin >> desirerow >> desirecolumn;
    if (array[desirerow - 1][desirecolumn - 1] == 10) {
        cout << "YOU WON\n\n";
        exit(1);

    }
    //POSSIBLE MOVES FOR BISHOP          
    //Diagonal moves
    int r = row, c = column;
    while (r > 1 && c > 1) {
        r--;
        c--;
        if (array[r - 1][c - 1] != 10 && array[r - 1][c - 1] != 20)
        {
            array[r - 1][c - 1] = 2;
        }
    }
    r = row;
    c = column;
    while (r < 8 && c > 1) {
        r++;
        c--;
        if (array[r - 1][c - 1] != 10 && array[r - 1][c - 1] != 20)
        {
            array[r - 1][c - 1] = 2;
        }
    }
    r = row;
    c = column;
    while (r > 1 && c < 8) {
        r--;
        c++;
        if (array[r - 1][c - 1] != 10 && array[r - 1][c - 1] != 20)
        {
            array[r - 1][c - 1] = 2;
        }
    }
    r = row;
    c = column;
    while (r < 8 && c < 8)
    {
        r++;
        c++;
        if (array[r - 1][c - 1] != 10 && array[r - 1][c - 1] != 20)
        {
            array[r - 1][c - 1] = 2;
        }
    }

    if (array[desirerow - 1][desirecolumn - 1] != 2) {
        cout << "Not a possible move\n";
        goto start;

    }


    array[desirerow - 1][desirecolumn - 1] = 20;


    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "B" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && (array[i][j] == 0 || array[i][j] == 2))

            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && (array[i][j] == 0 || array[i][j] == 2))
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

}
void knight_attack()
{
    int row, column, secondr, secondc;
    //king variables
    int row1, column1;
    //for king
    int desirerow1 = (rand() % 8) + 1, desirecolumn1 = (rand() % 8) + 1;
    //for knight
    int desirerow = (rand() % 8) + 1, desirecolumn = (rand() % 8) + 1;
    int desirer = (rand() % 8) + 1, desirec = (rand() % 8) + 1;
    int array[8][8];
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            array[i][j] = 0;
        }
    }
    //10 FOR KING AND RED COLOUR
    array[desirerow1 - 1][desirecolumn1 - 1] = 10;
    //20 FOR KNIGHT
    array[desirerow - 1][desirecolumn - 1] = 20;
    array[desirer - 1][desirec - 1] = 20;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "$" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && array[i][j] == 0)
            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && array[i][j] == 0)
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

    while (1)
    {
        for (int i = 0;i < 10;i++)
        {
            if ((i % 2) == 0) {


                cout << "ENTER CURRENT POSITION OF YOUR KNIGHT (rows and columns respectively)\n";
            noun:
                cin >> row >> column;
                if (array[row - 1][column - 1] != 20)
                {
                    cout << "ENTERED POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun;
                }
                knight_location(row, column, desirerow, desirecolumn, array);

            }


            if ((i % 2) != 0)

            {

                cout << "ENTER CURRENT POSITION OF YOUR KING (rows and columns respectively)\n";
            noun1:
                cin >> row1 >> column1;
                if (array[row1 - 1][column1 - 1] != 10)
                {
                    cout << "ENTERED KING POSITION IS WRONG\n";
                    cout << "ENTER AGAIN\n";
                    goto noun1;
                }
                king_attack(row1, column1, desirerow1, desirecolumn1, array);
            }
        }
        if (array[desirerow - 1][desirecolumn - 1] == 10)
        {
            cout << "YOU WON\n";
        }

    }


}
void knight_location(int& row, int& column, int& desirerow, int& desirecolumn, int(&array)[8][8])
{
    array[row - 1][column - 1] = 0;
first:

    cout << "ENTER DESIRED POSITION OF YOUR KNIGHT (rows and columns respectively)\n";
start:
    cin >> desirerow >> desirecolumn;
    if (array[desirerow - 1][desirecolumn - 1] == 10) {
        cout << "YOU WON\n\n";
        exit(1);

    }
    //POSSIBLE MOVES FOR KNIGHT
    if (row == 1 && column == 8)
    {
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }

    }
    else if (row == 2 && column == 8)
    {
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (row == 7 && column == 8)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (column == 8)
    {
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (row == 8 && column == 8)
    {
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }

    }


    else if (row == 1 && column == 7)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }

    }
    else if (row == 2 && column == 7)
    {
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
    }
    else if (row == 7 && column == 7)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 20 && array[row + 1 - 1][column - 2 - 1] != 10)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
    }
    else if (column == 7)
    {
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
    }
    else if (row == 8 && column == 7)
    {
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }

    }


    else if (row == 1 && column == 1)
    {
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }

    }
    else if (row == 2 && column == 1)
    {
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
    }
    else if (row == 7 && column == 1)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
    }
    else if (column == 1)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
    }
    else if (row == 8 && column == 1)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }

    }


    else if (row == 1 && column == 2)
    {
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }

    }
    else if (row == 2 && column == 2)
    {
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (row == 7 && column == 2)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (column == 2)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
    }
    else if (row == 8 && column == 2)
    {
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)

        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }

    }
    else if (row == 1)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }

    }
    else if (row == 2)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }

    }
    else if (row == 7)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }

    }
    else if (row == 8)
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }


    }
    else
    {
        if (array[row + 1 - 1][column - 2 - 1] != 10 && array[row + 1 - 1][column - 2 - 1] != 20)
        {
            array[row + 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row + 1 - 1][column + 2 - 1] != 10 && array[row + 1 - 1][column + 2 - 1] != 20)
        {
            array[row + 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row + 2 - 1][column - 1 - 1] != 10 && array[row + 2 - 1][column - 1 - 1] != 20)
        {
            array[row + 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row + 2 - 1][column + 1 - 1] != 10 && array[row + 2 - 1][column + 1 - 1] != 20)
        {
            array[row + 2 - 1][column + 1 - 1] = 2;
        }
        if (array[row - 1 - 1][column + 2 - 1] != 10 && array[row - 1 - 1][column + 2 - 1] != 20)
        {
            array[row - 1 - 1][column + 2 - 1] = 2;
        }
        if (array[row - 1 - 1][column - 2 - 1] != 10 && array[row - 1 - 1][column - 2 - 1] != 20)
        {
            array[row - 1 - 1][column - 2 - 1] = 2;
        }
        if (array[row - 2 - 1][column - 1 - 1] != 10 && array[row - 2 - 1][column - 1 - 1] != 20)
        {
            array[row - 2 - 1][column - 1 - 1] = 2;
        }
        if (array[row - 2 - 1][column + 1 - 1] != 10 && array[row - 2 - 1][column + 1 - 1] != 20)
        {
            array[row - 2 - 1][column + 1 - 1] = 2;
        }

    }


    if (array[desirerow - 1][desirecolumn - 1] != 2) {
        cout << "Not a possible move\n";
        goto start;

    }


    array[desirerow - 1][desirecolumn - 1] = 20;


    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (array[i][j] == 10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << box << "K" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (array[i][j] == 20)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << box << "$" << box << box;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if ((i + j) % 2 == 0 && (array[i][j] == 0 || array[i][j] == 2))

            {
                cout << box << box << box << box;
            }
            else if ((i + j) % 2 != 0 && (array[i][j] == 0 || array[i][j] == 2))
            {
                cout << "    ";
            }
        }
        cout << endl;
    }

}
