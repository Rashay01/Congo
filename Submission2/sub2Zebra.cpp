#include <iostream>
#include <string>
#include <array>
#include <vector>

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
    int row = 0, col = 0;
    array<array<string, 7>, 7> board = {{{"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"},
                                         {"0", "0", "0", "0", "0", "0", "0"}}};
    for (int i = 0; i < (int)FEN[0].size(); i++)
    {
        char cCurrChar = FEN[0][i];
        if (cCurrChar == 's')
        {
            board[row][col] = "s";
            col++;
        }
        else if (cCurrChar == 'g')
        {
            board[row][col] = "g";
            col++;
        }
        else if (cCurrChar == 'm')
        {
            board[row][col] = "m";
            col++;
        }
        else if (cCurrChar == 'e')
        {
            board[row][col] = "e";
            col++;
        }
        else if (cCurrChar == 'l')
        {
            board[row][col] = "l";
            col++;
        }
        else if (cCurrChar == 'c')
        {
            board[row][col] = "c";
            col++;
        }
        else if (cCurrChar == 'z')
        {
            board[row][col] = "z";
            col++;
        }
        else if (cCurrChar == 'P')
        {
            board[row][col] = "P";
            col++;
        }
        else if (cCurrChar == 'S')
        {
            board[row][col] = "S";
            col++;
        }
        else if (cCurrChar == 'G')
        {
            board[row][col] = "G";
            col++;
        }
        else if (cCurrChar == 'M')
        {
            board[row][col] = "M";
            col++;
        }
        else if (cCurrChar == 'E')
        {
            board[row][col] = "E";
            col++;
        }
        else if (cCurrChar == 'L')
        {
            board[row][col] = "L";
            col++;
        }
        else if (cCurrChar == 'C')
        {
            board[row][col] = "C";
            col++;
        }
        else if (cCurrChar == 'Z')
        {
            board[row][col] = "Z";
            col++;
        }
        else if (cCurrChar == '/')
        {
            col = 0;
            row++;
        }
        else if (cCurrChar == '1' || cCurrChar == '2' || cCurrChar == '3' || cCurrChar == '4' || cCurrChar == '5' || cCurrChar == '6' || cCurrChar == '7')
        {
            int num = cCurrChar - 48;
            col += num;
        }
        else if (cCurrChar == 'p')
        {
            board[row][col] = "p";
            col++;
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

vector<string> poss_zebra_moves(array<array<string, 7>, 7> grid, string Player)
{
    vector<string> poss_moves;
    array<string, 8> arrZebra_moves;
    array<string, 49> valid_moves = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "a6",
                                     "b6", "c6", "d6", "e6", "f6", "g6", "a5", "b5", "c5", "d5", "e5", "f5", "g5",
                                     "a4", "b4", "c4", "d4", "e4", "f4", "g4", "a3", "b3", "c3", "d3", "e3", "f3",
                                     "g3", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "a1", "b1", "c1", "d1", "e1", "f1", "g1"};

    if (Player == "w")
    {
        vector<string> w_zebra_arr = getPossiblePositions(grid, "Z");
        string w_zebra;
        if (w_zebra_arr.size() != 0)
        {
            w_zebra = w_zebra_arr[0];
        }
        else
        {
            return poss_moves;
        }
        arrZebra_moves[0].push_back(char((int)w_zebra[0] - 2));
        arrZebra_moves[0].push_back(char((int)w_zebra[1] - 1));
        arrZebra_moves[1].push_back(char((int)w_zebra[0] - 2));
        arrZebra_moves[1].push_back(char((int)w_zebra[1] + 1));
        arrZebra_moves[2].push_back(char((int)w_zebra[0] - 1));
        arrZebra_moves[2].push_back(char((int)w_zebra[1] - 2));
        arrZebra_moves[3].push_back(char((int)w_zebra[0] - 1));
        arrZebra_moves[3].push_back(char((int)w_zebra[1] + 2));
        arrZebra_moves[4].push_back(char((int)w_zebra[0] + 1));
        arrZebra_moves[4].push_back(char((int)w_zebra[1] - 2));
        arrZebra_moves[5].push_back(char((int)w_zebra[0] + 1));
        arrZebra_moves[5].push_back(char((int)w_zebra[1] + 2));
        arrZebra_moves[6].push_back(char((int)w_zebra[0] + 2));
        arrZebra_moves[6].push_back(char((int)w_zebra[1] - 1));
        arrZebra_moves[7].push_back(char((int)w_zebra[0] + 2));
        arrZebra_moves[7].push_back(char((int)w_zebra[1] + 1));

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < valid_moves.size(); j++)
            {
                if (arrZebra_moves[i] == valid_moves[j])
                {
                    string curPos = getItem_board(grid, arrZebra_moves[i]);
                    if (curPos != "P" && curPos != "S" && curPos != "G" && curPos != "M" && curPos != "E" && curPos != "L" && curPos != "C")
                    {
                        poss_moves.push_back(w_zebra + arrZebra_moves[i]);
                    }
                    break;
                }
            }
        }

        return poss_moves;
    }
    else
    {
        vector<string> b_zebra_arr = getPossiblePositions(grid, "z");
        string b_zebra;
        if (b_zebra_arr.size() != 0)
        {
            b_zebra = b_zebra_arr[0];
        }
        else
        {
            return poss_moves;
        }
        arrZebra_moves[0].push_back(char((int)b_zebra[0] - 2));
        arrZebra_moves[0].push_back(char((int)b_zebra[1] - 1));
        arrZebra_moves[1].push_back(char((int)b_zebra[0] - 2));
        arrZebra_moves[1].push_back(char((int)b_zebra[1] + 1));
        arrZebra_moves[2].push_back(char((int)b_zebra[0] - 1));
        arrZebra_moves[2].push_back(char((int)b_zebra[1] - 2));
        arrZebra_moves[3].push_back(char((int)b_zebra[0] - 1));
        arrZebra_moves[3].push_back(char((int)b_zebra[1] + 2));
        arrZebra_moves[4].push_back(char((int)b_zebra[0] + 1));
        arrZebra_moves[4].push_back(char((int)b_zebra[1] - 2));
        arrZebra_moves[5].push_back(char((int)b_zebra[0] + 1));
        arrZebra_moves[5].push_back(char((int)b_zebra[1] + 2));
        arrZebra_moves[6].push_back(char((int)b_zebra[0] + 2));
        arrZebra_moves[6].push_back(char((int)b_zebra[1] - 1));
        arrZebra_moves[7].push_back(char((int)b_zebra[0] + 2));
        arrZebra_moves[7].push_back(char((int)b_zebra[1] + 1));

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < valid_moves.size(); j++)
            {
                if (arrZebra_moves[i] == valid_moves[j])
                {
                    string curPos = getItem_board(grid, arrZebra_moves[i]);
                    if (curPos != "p" && curPos != "s" && curPos != "g" && curPos != "m" && curPos != "e" && curPos != "l" && curPos != "c")
                    {
                        poss_moves.push_back(b_zebra + arrZebra_moves[i]);
                    }
                    break;
                }
            }
        }

        return poss_moves;
    }
}

int main()
{
    vector<string> sLine, poss_Zebra;
    int N;
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

        board = initiliaseBoard(FEN);
        poss_Zebra = poss_zebra_moves(board, FEN[1]);

        if (poss_Zebra.size() == 0)
        {
            cout << endl;
            continue;
        }
        for (int j = 0; j < poss_Zebra.size(); j++)
        {

            if (j != poss_Zebra.size() - 1)
            {
                cout << poss_Zebra[j] << " ";
            }
            else
            {
                cout << poss_Zebra[j];
            }
        }
        cout << endl;
    }

    return 0;
}