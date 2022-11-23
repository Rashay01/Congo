#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct board
{
    string sBoard;
    char Player;
    int iNum_Moves;
};

array<string, 3> deleteSpace(string sline)
{
    array<string, 3> arrNoSpaces;
    int count = -1;
    string WordsubString = "";
    for (auto x : sline)
    {
        if (x == ' ')
        {
            count = count + 1;
            arrNoSpaces[count] = WordsubString;
            WordsubString = "";
        }
        else
        {
            WordsubString = WordsubString + x;
        }
    }
    count = count + 1;
    arrNoSpaces[count] = WordsubString;
    return arrNoSpaces;
}

void getTheFullRows(vector<string> &rows)
{
    string sLine;
    for (int i = 0; i < rows.size(); i++)
    {
        sLine = rows[i];
        for (int k = 0; k < sLine.length(); k++)
        {
            switch (sLine[k])
            {
            case '2':
                sLine.replace(k, 1, "11");
                break;
            case '3':
                sLine.replace(k, 1, "111");
                break;
            case '4':
                sLine.replace(k, 1, "1111");
                break;
            case '5':
                sLine.replace(k, 1, "11111");
                break;
            case '6':
                sLine.replace(k, 1, "111111");
                break;
            case '7':
                sLine.replace(k, 1, "1111111");
                break;
            default:
                break;
            }
        }
        rows[i] = sLine;
    }
}

void locatePosPieces(vector<string> rows)
{

    vector<string> arrPieces = {"white pawn:",
                                "black pawn:",
                                "white superpawn:",
                                "black superpawn:",
                                "white giraffe:",
                                "black giraffe:",
                                "white monkey:",
                                "black monkey:",
                                "white elephant:",
                                "black elephant:",
                                "white lion:",
                                "black lion:",
                                "white crocodile:",
                                "black crocodile:",
                                "white zebra:",
                                "black zebra:"};
    char block;
    vector<string> rowAlpha = {"7", "6", "5", "4", "3", "2", "1"};
    vector<string> colPos = {"a", "b", "c", "d", "e", "f", "g"};
    for (int i = 0; i < 7; i++)
    {
        for (int k = rows.size() - 1; k >= 0; k--)
        {
            block = rows[k][i];
            switch (block)
            {
            case 'P':
                arrPieces[0].insert(arrPieces[0].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'p':
                arrPieces[1].insert(arrPieces[1].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'S':
                arrPieces[2].insert(arrPieces[2].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 's':
                arrPieces[3].insert(arrPieces[3].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'G':
                arrPieces[4].insert(arrPieces[4].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'g':
                arrPieces[5].insert(arrPieces[5].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'M':
                arrPieces[6].insert(arrPieces[6].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'm':
                arrPieces[7].insert(arrPieces[7].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'E':
                arrPieces[8].insert(arrPieces[8].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'e':
                arrPieces[9].insert(arrPieces[9].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'L':
                arrPieces[10].insert(arrPieces[10].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'l':
                arrPieces[11].insert(arrPieces[11].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'C':
                arrPieces[12].insert(arrPieces[12].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'c':
                arrPieces[13].insert(arrPieces[13].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'Z':
                arrPieces[14].insert(arrPieces[14].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            case 'z':
                arrPieces[15].insert(arrPieces[15].length(), " " + colPos[i] + rowAlpha[k]);
                break;
            default:
                break;
            }
        }
    }
    for (int i = 0; i < arrPieces.size(); i++)
    {
        cout << arrPieces[i] << endl;
    }
}

void makeBoard(vector<string> row)
{
    char cNew_board[7][7];
    for (int i = 0; i < row.size(); i++)
    {
        for (int k = 0; k < 7; k++)
        {
            cNew_board[i][k] = row[i][k];
        }
    }
}

void displaythePiecesInfo(board bsBoard)
{
    string FEN = bsBoard.sBoard;
    string Delimiter = "/";
    int position = 0;
    string currRow;
    vector<string> rows;

    while ((position = FEN.find(Delimiter)) != FEN.npos)
    {
        currRow = FEN.substr(0, position);
        rows.push_back(currRow);
        FEN.erase(0, position + 1);
    }
    rows.push_back(FEN);
    getTheFullRows(rows);
    locatePosPieces(rows);
    makeBoard(rows);

    string sidetoplay;
    if (bsBoard.Player == 'w')
    {
        sidetoplay = "white";
    }
    else
    {
        sidetoplay = "black";
    }

    cout << "side to play: " + sidetoplay << endl;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<board> boards(N);
    for (int i = 0; i < N; i++)
    {
        string input_FEN;
        getline(cin, input_FEN);
        array<string, 3> FEN;
        FEN = deleteSpace(input_FEN);
        boards[i].sBoard = FEN[0];
        boards[i].Player = FEN[1][0];
        boards[i].iNum_Moves = stoi(FEN[2]);
    }

    for (int j = 0; j < boards.size(); j++)
    {
        displaythePiecesInfo(boards[j]);
        if (j != boards.size() - 1)
        {
            cout << endl;
        }
    }
}