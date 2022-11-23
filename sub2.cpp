#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

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

array<array<string, 7>, 7> initiliaseBoard(array<string, 3> FEN)
{
    int rank = 0, file = 0;
    array<array<string, 7>, 7> board = {{{"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"}}};
    for (int i = 0; i < (int)FEN[0].size(); i++)
    {
        char positions = FEN[0][i];
        if (positions == '/')
        {
            file = 0;
            rank++;
        }
        else if (positions == '1' || positions == '2' || positions == '3' || positions == '4' || positions == '5' || positions == '6' || positions == '7')
        {
            int num = positions - 48;
            file += num;
        }
        else if (positions == 'p')
        {
            board[rank][file] = "p";
            file++;
        }
        else if (positions == 'g')
        {
            board[rank][file] = "g";
            file++;
        }
        else if (positions == 'm')
        {
            board[rank][file] = "m";
            file++;
        }
        else if (positions == 'e')
        {
            board[rank][file] = "e";
            file++;
        }
        else if (positions == 'l')
        {
            board[rank][file] = "l";
            file++;
        }
        else if (positions == 'c')
        {
            board[rank][file] = "c";
            file++;
        }
        else if (positions == 'z')
        {
            board[rank][file] = "z";
            file++;
        }
        else if (positions == 'P')
        {
            board[rank][file] = "P";
            file++;
        }
        else if (positions == 's')
        {
            board[rank][file] = "s";
            file++;
        }
        else if (positions == 'S')
        {
            board[rank][file] = "S";
            file++;
        }
        else if (positions == 'G')
        {
            board[rank][file] = "G";
            file++;
        }
        else if (positions == 'E')
        {
            board[rank][file] = "E";
            file++;
        }
        else if (positions == 'L')
        {
            board[rank][file] = "L";
            file++;
        }
        else if (positions == 'C')
        {
            board[rank][file] = "C";
            file++;
        }
        else if (positions == 'Z')
        {
            board[rank][file] = "Z";
            file++;
        }
        else if (positions == 'M')
        {
            board[rank][file] = "M";
            file++;
        }
    }
    return board;
}

vector<string> getPossiblePositions(array<array<string, 7>, 7> board, string piece)
{
    vector<string> curr_positions;
    string colPos[7] = {"a", "b", "c", "d", "e", "f", "g"};

    for (int col = 0; col < 7; col++)
    {
        for (int row = 6; row >= 0; row--)
        {
            if (board[row][col] == piece)
            {
                string coords = colPos[col] + to_string(7 - row);
                curr_positions.push_back(coords);
            }
        }
    }
    return curr_positions;
}

string getItem_board(array<array<string, 7>, 7> board, string coordsPos)
{
    int row, col;
    switch (coordsPos[0])
    {
    case 'a':
        col = 0;
        break;
    case 'b':
        col = 1;
        break;
    case 'c':
        col = 2;
        break;
    case 'd':
        col = 3;
        break;
    case 'e':
        col = 4;
        break;
    case 'f':
        col = 5;
        break;
    case 'g':
        col = 6;
        break;
    }

    switch (coordsPos[1])
    {
    case '1':
        row = 6;
        break;
    case '2':
        row = 5;
        break;
    case '3':
        row = 4;
        break;
    case '4':
        row = 3;
        break;
    case '5':
        row = 2;
        break;
    case '6':
        row = 1;
        break;
    case '7':
        row = 0;
        break;
    }
    return board[row][col];
}

vector<string> lion_Moves(array<array<string, 7>, 7> board, string Player)
{
    vector<string> poss_moves, arrWLion, arrBLion;
    string wlion, blion;
    bool bvalid = false;
    arrWLion = getPossiblePositions(board, "L");
    arrBLion = getPossiblePositions(board, "l");
    if (arrWLion.size() != 0 && arrBLion.size() != 0)
    {
        wlion = arrWLion[0];
        blion = arrBLion[0];
    }
    else
    {
        return poss_moves;
    }
    if (Player == "w")
    {
        array<string, 9> valid_options = {"c1", "c2", "c3", "d1", "d2", "d3", "e1", "e2", "e3"};
        for (int d = 0; d < valid_options.size(); d++)
        {
            if (wlion == valid_options[d])
            {
                bvalid = true;
            }
        }
        if (bvalid == false)
        {
            return poss_moves;
        }
        if ((wlion[0] == blion[0]))
        {
            bool bEmpty = true;
            for (int row = ((int)wlion[1] + 1) - 48; row < (int)blion[1] - 48; row++)
            {
                if (getItem_board(board, wlion[0] + to_string(row)) != "0")
                {
                    bEmpty = false;
                }
            }
            if (bEmpty)
            {
                poss_moves.push_back(wlion + blion);
            }
        }
        else if ((wlion == "c3" && blion == "e5" && getItem_board(board, "d4") == "0") || (wlion == "e3" && blion == "c5" && getItem_board(board, "d4") == "0"))
        {
            poss_moves.push_back(wlion + blion);
        }
        for (int i = 0; i < 9; i++)
        {
            string cord = valid_options[i];
            string pos = getItem_board(board, cord);
            if ((pos != "L" && pos != "P" && pos != "Z" && pos != "G" && pos != "S" && pos != "M" && pos != "E") && !(wlion[1] == '1' && cord[1] == '3') && !(wlion[1] == '3' && cord[1] == '1') && !(wlion[0] == 'c' && cord[0] == 'e') && !(wlion[0] == 'e' && cord[0] == 'c'))
            {
                poss_moves.push_back(wlion + cord);
            }
        }
    }
    else
    {
        array<string, 9> valid_options = {"c5", "c6", "c7", "d5", "d6", "d7", "e5", "e6", "e7"};
        for (int d = 0; d < valid_options.size(); d++)
        {
            if (blion == valid_options[d])
            {
                bvalid = true;
            }
        }
        if (bvalid == false)
        {
            return poss_moves;
        }
        if ((wlion[0] == blion[0]))
        {
            bool bEmpty = true;
            for (int row = ((int)wlion[1] + 1) - 48; row < (int)blion[1] - 48; row++)
            {
                if (getItem_board(board, blion[0] + to_string(row)) != "0")
                {
                    bEmpty = false;
                }
            }
            if (bEmpty)
            {
                poss_moves.push_back(blion + wlion);
            }
        }
        else if ((getItem_board(board, "d4") == "0") && ((wlion == "c3" && blion == "e5") || (wlion == "e3" && blion == "c5")))
        {
            poss_moves.push_back(blion + wlion);
        }
        for (int i = 0; i < 9; i++)
        {
            string cord = valid_options[i];
            string pos = getItem_board(board, cord);
            if ((pos != "l" && pos != "p" && pos != "z" && pos != "g" && pos != "s" && pos != "m" && pos != "e") && !(blion[1] == '5' && cord[1] == '7') && !(blion[1] == '7' && cord[1] == '5') && !(blion[0] == 'c' && cord[0] == 'e') && !(blion[0] == 'e' && cord[0] == 'c'))
            {
                poss_moves.push_back(blion + cord);
            }
        }
    }

    return poss_moves;
}

int main()
{
    int N;
    bool turn;
    vector<string> sLine, poss_Lion;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string input_FEN;
        getline(cin, input_FEN);
        sLine.push_back(input_FEN);
    }

    for (int i = 0; i < N; i++)
    {
        array<string, 3> FEN;
        array<array<string, 7>, 7> board;

        FEN = deleteSpace(sLine[i]);
        if (FEN[1] == "w")
        {
            turn = true;
        }
        else
        {
            turn = false;
        }
        board = initiliaseBoard(FEN);
        poss_Lion = lion_Moves(board, FEN[1]);

        if (poss_Lion.size() == 0)
        {
            cout << endl;
            return 0;
        }
        sort(poss_Lion.begin(), poss_Lion.end());
        for (int j = 0; j < poss_Lion.size(); j++)
        {
            cout << poss_Lion[j];
            if (j != poss_Lion.size() - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}