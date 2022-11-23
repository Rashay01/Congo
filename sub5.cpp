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

// Given FEN string, returns string
string unseperate(array<string, 3> FEN)
{
    string result;
    result.append(FEN[0]);
    result.append(" ");
    result.append(FEN[1]);
    result.append(" ");
    result.append(FEN[2]);

    return result;
}

int getRowCoordinate(string coordsPos)
{
    int row;
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
    return row;
}

int getColCoordinate(string coordsPos)
{
    int col;
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
    return col;
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
        if (cCurrChar == 'p')
        {
            board[row][col] = "p";
            col++;
        }
        else if (cCurrChar == 's')
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

// This function prints the current grid and positions of pieces to the output
void printgrid(array<array<string, 7>, 7> grid)
{
    for (int r = 0; r < 7; r++)
    {
        for (int f = 0; f < 7; f++)
        {
            cout << grid[r][f];
        }
        cout << endl;
    }
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

bool ValidateBoard(array<array<string, 7>, 7> board)
{
    int count = 0;
    for (int row = 0; row < 7; row++)
    {
        for (int col = 0; col < 7; col++)
        {
            if (board[row][col] != "0")
            {
                count++;
            }
        }
    }

    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

array<array<string, 7>, 7> setNewMoves(array<array<string, 7>, 7> board, string move, string Player)
{
    array<array<string, 7>, 7> new_board = board;
    string start, finish;

    start.push_back(move[0]);
    start.push_back(move[1]);
    finish.push_back(move[2]);
    finish.push_back(move[3]);

    new_board[getRowCoordinate(finish)][getColCoordinate(finish)] = getItem_board(board, start);
    if (move[1] == '4' && move[3] == '4')
    {
        new_board[getRowCoordinate(finish)][getColCoordinate(finish)] = "0";
    }
    new_board[getRowCoordinate(start)][getColCoordinate(start)] = "0";

    if (Player == "w")
    {
        for (int i = 0; i < 7; i++)
        {
            if (board[3][i] == "P" || board[3][i] == "S" || board[3][i] == "G" || board[3][i] == "E" || board[3][i] == "L" || board[3][i] == "M" || board[3][i] == "Z")
            {
                new_board[3][i] = "0";
            }
            if (new_board[0][i] == "P")
            {
                new_board[0][i] = "S";
            }
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            if (board[3][i] == "p" || board[3][i] == "s" || board[3][i] == "g" || board[3][i] == "e" || board[3][i] == "l" || board[3][i] == "m" || board[3][i] == "z")
            {
                new_board[3][i] = "0";
            }
            if (new_board[6][i] == "p")
            {
                new_board[6][i] = "s";
            }
        }
    }

    return new_board;
}

string BoardtoString(array<array<string, 7>, 7> board, string Player, int iNumber)
{
    array<string, 3> arrNew;
    string sNewBoard;
    int iCounter;

    for (int row = 0; row < 7; row++)
    {
        iCounter = 0;
        for (int col = 0; col < 7; col++)
        {
            if (board[row][col] != "0" || col == 6)
            {
                if (board[row][col] == "0" && col == 6)
                {
                    iCounter++;
                    sNewBoard.append(to_string(iCounter));
                    continue;
                }
                if (iCounter != 0)
                {
                    sNewBoard.append(to_string(iCounter));
                }
                sNewBoard.append(board[row][col]);
                iCounter = 0;
            }
            else
            {
                iCounter++;
            }
        }
        if (row != 6)
        {
            sNewBoard.append("/");
        }
    }

    arrNew[0] = sNewBoard;

    if (Player == "b")
    {
        arrNew[1] = "w";
        iNumber++;
    }
    else
    {
        arrNew[1] = "b";
    }

    arrNew[2] = to_string(iNumber);

    string sAnswer;
    sAnswer.append(arrNew[0]);
    sAnswer.append(" ");
    sAnswer.append(arrNew[1]);
    sAnswer.append(" ");
    sAnswer.append(arrNew[2]);

    return sAnswer;
}

string getCurrentState(array<array<string, 7>, 7> board)
{
    vector<string> wlion, blion;
    string state;

    wlion = getPossiblePositions(board, "L");
    blion = getPossiblePositions(board, "l");

    if (wlion.size() == 0)
    {
        state = "Black wins";
    }
    else if (blion.size() == 0)
    {
        state = "White wins";
    }
    else if (ValidateBoard(board))
    {
        state = "Draw";
    }
    else
    {
        state = "Continue";
    }

    return state;
}

int BoardEvaluation(array<array<string, 7>, 7> board, string Player)
{
    int i_Player_W_value = 0, i_Player_B_value = 0;
    int iPawn = 100, iSPawn = 350, iZebra = 300, iGiraffe = 400;
    int actScore;
    string sState = getCurrentState(board);

    if (sState == "White wins")
    {
        actScore = 10000;
    }
    else if (sState == "Black wins")
    {
        actScore = -10000;
    }
    else if (sState == "Draw")
    {
        actScore = 0;
    }
    else
    {
        for (int r = 0; r < 7; r++)
        {
            for (int f = 0; f < 7; f++)
            {
                if (board[r][f] == "P")
                {
                    i_Player_W_value += iPawn;
                }
                else if (board[r][f] == "S")
                {
                    i_Player_W_value += iSPawn;
                }
                else if (board[r][f] == "Z")
                {
                    i_Player_W_value += iZebra;
                }
                else if (board[r][f] == "G")
                {
                    i_Player_W_value += iGiraffe;
                }

                if (board[r][f] == "p")
                {
                    i_Player_B_value += iPawn;
                }
                else if (board[r][f] == "s")
                {
                    i_Player_B_value += iSPawn;
                }
                else if (board[r][f] == "z")
                {
                    i_Player_B_value += iZebra;
                }
                else if (board[r][f] == "g")
                {
                    i_Player_B_value += iGiraffe;
                }
            }
        }
        actScore = i_Player_W_value - i_Player_B_value;
    }

    if (Player == "w")
    {
        return actScore;
    }
    else
    {
        return -actScore;
    }
}

vector<string> poss_lion_Moves(array<array<string, 7>, 7> board, string Player)
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

vector<string> poss_zebra_moves(array<array<string, 7>, 7> Board, string Player)
{
    vector<string> poss_moves;
    array<string, 8> arrZebra_moves;
    array<string, 49> valid_moves = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "a6",
                                     "b6", "c6", "d6", "e6", "f6", "g6", "a5", "b5", "c5", "d5", "e5", "f5", "g5",
                                     "a4", "b4", "c4", "d4", "e4", "f4", "g4", "a3", "b3", "c3", "d3", "e3", "f3",
                                     "g3", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "a1", "b1", "c1", "d1", "e1", "f1", "g1"};

    if (Player == "w")
    {
        vector<string> w_zebra_arr = getPossiblePositions(Board, "Z");
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
                    string curPos = getItem_board(Board, arrZebra_moves[i]);
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
        vector<string> b_zebra_arr = getPossiblePositions(Board, "z");
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
                    string curPos = getItem_board(Board, arrZebra_moves[i]);
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

vector<string> poss_giraffe_moves(array<array<string, 7>, 7> Board, string Player)
{
    vector<string> poss_moves;
    array<string, 16> giraffe_moves;
    array<string, 49> valid_moves = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "a6", "b6", "c6", "d6", "e6", "f6", "g6", "a5", "b5", "c5", "d5", "e5", "f5", "g5", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "a3", "b3", "c3", "d3", "e3", "f3", "g3", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "a1", "b1", "c1", "d1", "e1", "f1", "g1"};

    if (Player == "w")
    {
        vector<string> w_giraffe_arr = getPossiblePositions(Board, "G");
        string w_giraffe;
        if (w_giraffe_arr.size() != 0)
        {
            w_giraffe = w_giraffe_arr[0];
        }
        else
        {
            return poss_moves;
        }
        giraffe_moves[0].push_back(char((int)w_giraffe[0] - 2));
        giraffe_moves[0].push_back(char((int)w_giraffe[1] - 2));
        giraffe_moves[1].push_back(char((int)w_giraffe[0] - 2));
        giraffe_moves[1].push_back(char((int)w_giraffe[1]));
        giraffe_moves[2].push_back(char((int)w_giraffe[0] - 2));
        giraffe_moves[2].push_back(char((int)w_giraffe[1] + 2));
        giraffe_moves[3].push_back(char((int)w_giraffe[0] - 1));
        giraffe_moves[3].push_back(char((int)w_giraffe[1] - 1));
        giraffe_moves[4].push_back(char((int)w_giraffe[0] - 1));
        giraffe_moves[4].push_back(char((int)w_giraffe[1]));
        giraffe_moves[5].push_back(char((int)w_giraffe[0] - 1));
        giraffe_moves[5].push_back(char((int)w_giraffe[1] + 1));
        giraffe_moves[6].push_back(char((int)w_giraffe[0]));
        giraffe_moves[6].push_back(char((int)w_giraffe[1] - 2));
        giraffe_moves[7].push_back(char((int)w_giraffe[0]));
        giraffe_moves[7].push_back(char((int)w_giraffe[1] - 1));
        giraffe_moves[8].push_back(char((int)w_giraffe[0]));
        giraffe_moves[8].push_back(char((int)w_giraffe[1] + 1));
        giraffe_moves[9].push_back(char((int)w_giraffe[0]));
        giraffe_moves[9].push_back(char((int)w_giraffe[1] + 2));
        giraffe_moves[10].push_back(char((int)w_giraffe[0] + 1));
        giraffe_moves[10].push_back(char((int)w_giraffe[1] - 1));
        giraffe_moves[11].push_back(char((int)w_giraffe[0] + 1));
        giraffe_moves[11].push_back(char((int)w_giraffe[1]));
        giraffe_moves[12].push_back(char((int)w_giraffe[0] + 1));
        giraffe_moves[12].push_back(char((int)w_giraffe[1] + 1));
        giraffe_moves[13].push_back(char((int)w_giraffe[0] + 2));
        giraffe_moves[13].push_back(char((int)w_giraffe[1] - 2));
        giraffe_moves[14].push_back(char((int)w_giraffe[0] + 2));
        giraffe_moves[14].push_back(char((int)w_giraffe[1]));
        giraffe_moves[15].push_back(char((int)w_giraffe[0] + 2));
        giraffe_moves[15].push_back(char((int)w_giraffe[1] + 2));

        for (int p = 0; p < 16; p++)
        {
            for (int l = 0; l < valid_moves.size(); l++)
            {
                if (giraffe_moves[p] == valid_moves[l])
                {
                    string pos = getItem_board(Board, giraffe_moves[p]);
                    if (pos != "P" && pos != "S" && pos != "M" && pos != "E" && pos != "L" && pos != "C" && pos != "Z")
                    {
                        if ((pos == "0") || ((pos == "p" || pos == "s" || pos == "l" || pos == "e" || pos == "z" || pos == "m" || pos == "c" || pos == "g") && (p == 0 || p == 1 || p == 2 || p == 6 || p == 9 || p == 13 || p == 14 || p == 15)))
                        {
                            poss_moves.push_back(w_giraffe + giraffe_moves[p]);
                        }
                    }
                    break;
                }
            }
        }

        return poss_moves;
    }
    else
    {
        vector<string> b_giraffe_arr = getPossiblePositions(Board, "g");
        string b_giraffe;
        if (b_giraffe_arr.size() != 0)
        {
            b_giraffe = b_giraffe_arr[0];
        }
        else
        {
            return poss_moves;
        }
        giraffe_moves[0].push_back(char((int)b_giraffe[0] - 2));
        giraffe_moves[0].push_back(char((int)b_giraffe[1] - 2));
        giraffe_moves[1].push_back(char((int)b_giraffe[0] - 2));
        giraffe_moves[1].push_back(char((int)b_giraffe[1]));
        giraffe_moves[2].push_back(char((int)b_giraffe[0] - 2));
        giraffe_moves[2].push_back(char((int)b_giraffe[1] + 2));
        giraffe_moves[3].push_back(char((int)b_giraffe[0] - 1));
        giraffe_moves[3].push_back(char((int)b_giraffe[1] - 1));
        giraffe_moves[4].push_back(char((int)b_giraffe[0] - 1));
        giraffe_moves[4].push_back(char((int)b_giraffe[1]));
        giraffe_moves[5].push_back(char((int)b_giraffe[0] - 1));
        giraffe_moves[5].push_back(char((int)b_giraffe[1] + 1));
        giraffe_moves[6].push_back(char((int)b_giraffe[0]));
        giraffe_moves[6].push_back(char((int)b_giraffe[1] - 2));
        giraffe_moves[7].push_back(char((int)b_giraffe[0]));
        giraffe_moves[7].push_back(char((int)b_giraffe[1] - 1));
        giraffe_moves[8].push_back(char((int)b_giraffe[0]));
        giraffe_moves[8].push_back(char((int)b_giraffe[1] + 1));
        giraffe_moves[9].push_back(char((int)b_giraffe[0]));
        giraffe_moves[9].push_back(char((int)b_giraffe[1] + 2));
        giraffe_moves[10].push_back(char((int)b_giraffe[0] + 1));
        giraffe_moves[10].push_back(char((int)b_giraffe[1] - 1));
        giraffe_moves[11].push_back(char((int)b_giraffe[0] + 1));
        giraffe_moves[11].push_back(char((int)b_giraffe[1]));
        giraffe_moves[12].push_back(char((int)b_giraffe[0] + 1));
        giraffe_moves[12].push_back(char((int)b_giraffe[1] + 1));
        giraffe_moves[13].push_back(char((int)b_giraffe[0] + 2));
        giraffe_moves[13].push_back(char((int)b_giraffe[1] - 2));
        giraffe_moves[14].push_back(char((int)b_giraffe[0] + 2));
        giraffe_moves[14].push_back(char((int)b_giraffe[1]));
        giraffe_moves[15].push_back(char((int)b_giraffe[0] + 2));
        giraffe_moves[15].push_back(char((int)b_giraffe[1] + 2));

        for (int p = 0; p < 16; p++)
        {
            for (int l = 0; l < valid_moves.size(); l++)
            {
                if (giraffe_moves[p] == valid_moves[l])
                {
                    string pos = getItem_board(Board, giraffe_moves[p]);
                    if (pos != "p" &&
                        pos != "s" &&
                        pos != "m" &&
                        pos != "e" &&
                        pos != "l" &&
                        pos != "c" &&
                        pos != "z")
                    {
                        if ((pos == "0") || ((pos == "P" || pos == "S" || pos == "L" || pos == "E" || pos == "Z" || pos == "M" || pos == "C" || pos == "G") && (p == 0 || p == 1 || p == 2 || p == 6 || p == 9 || p == 13 || p == 14 || p == 15)))
                        {
                            poss_moves.push_back(b_giraffe + giraffe_moves[p]);
                        }
                    }
                    break;
                }
            }
        }

        return poss_moves;
    }
}

vector<string> poss_pawn_moves(array<array<string, 7>, 7> board, string Player)
{
    vector<string> poss_moves;
    array<string, 49> valid_moves = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "a6", "b6", "c6", "d6", "e6", "f6", "g6",
                                     "a5", "b5", "c5", "d5", "e5", "f5", "g5", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "a3", "b3",
                                     "c3", "d3", "e3", "f3", "g3", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "a1", "b1", "c1", "d1", "e1", "f1", "g1"};

    if (Player == "w")
    {
        vector<string> w_pawn_arr = getPossiblePositions(board, "P");
        string w_pawn;
        int move_size;
        if (w_pawn_arr.size() == 0)
        {
            return poss_moves;
        }
        for (int w = 0; w < w_pawn_arr.size(); w++)
        {
            w_pawn = w_pawn_arr[w];
            if (w_pawn[1] == '7')
            {
                continue;
            }
            if (w_pawn[1] == '6' || w_pawn[1] == '5')
            {
                array<string, 5> pawn_moves;
                bool bOddMove = false;
                pawn_moves[0].push_back(char((int)w_pawn[0] - 1));
                pawn_moves[0].push_back(char((int)w_pawn[1] + 1));
                pawn_moves[1].push_back(char((int)w_pawn[0]));
                pawn_moves[1].push_back(char((int)w_pawn[1] + 1));
                pawn_moves[2].push_back(char((int)w_pawn[0] + 1));
                pawn_moves[2].push_back(char((int)w_pawn[1] + 1));
                pawn_moves[3].push_back(char((int)w_pawn[0]));
                pawn_moves[3].push_back(char((int)w_pawn[1] - 1));
                pawn_moves[4].push_back(char((int)w_pawn[0]));
                pawn_moves[4].push_back(char((int)w_pawn[1] - 2));

                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < valid_moves.size(); j++)
                    {
                        if (pawn_moves[i] == valid_moves[j])
                        {
                            string pos = getItem_board(board, pawn_moves[i]);
                            if (pos != "P" && pos != "S" && pos != "L" && pos != "E" && pos != "G" && pos != "M" && pos != "C" && pos != "Z")
                            {
                                if (!((i == 3 || i == 4) && (pos == "p" || pos == "s" || pos == "l" || pos == "e" || pos == "g" || pos == "m" || pos == "c" || pos == "z")) && !bOddMove)
                                {
                                    poss_moves.push_back(w_pawn + pawn_moves[i]);
                                }
                                if (i == 3 && (pos == "p" || pos == "s" || pos == "l" || pos == "e" || pos == "g" || pos == "m" || pos == "c" || pos == "z"))
                                {
                                    bOddMove = true;
                                }
                            }
                            else if (i == 3)
                            {
                                bOddMove = true;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                array<string, 3> pawn_moves;
                pawn_moves[0].push_back(char((int)w_pawn[0] - 1));
                pawn_moves[0].push_back(char((int)w_pawn[1] + 1));
                pawn_moves[1].push_back(char((int)w_pawn[0]));
                pawn_moves[1].push_back(char((int)w_pawn[1] + 1));
                pawn_moves[2].push_back(char((int)w_pawn[0] + 1));
                pawn_moves[2].push_back(char((int)w_pawn[1] + 1));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < valid_moves.size(); j++)
                    {
                        if (pawn_moves[i] == valid_moves[j])
                        {
                            string posCurr = getItem_board(board, pawn_moves[i]);
                            if (posCurr != "P" && posCurr != "S" && posCurr != "L" && posCurr != "E" && posCurr != "G" && posCurr != "M" && posCurr != "C" && posCurr != "Z")
                            {
                                poss_moves.push_back(w_pawn + pawn_moves[i]);
                            }
                            break;
                        }
                    }
                }
            }
        }

        return poss_moves;
    }
    else
    {
        vector<string> b_pawn_arr = getPossiblePositions(board, "p");
        string b_pawn;
        if (b_pawn_arr.size() == 0)
        {

            return poss_moves;
        }
        for (int w = 0; w < b_pawn_arr.size(); w++)
        {
            b_pawn = b_pawn_arr[w];
            if (b_pawn[1] == '1')
            {
                continue;
            }
            if (b_pawn[1] == '2' || b_pawn[1] == '3')
            {
                array<string, 5> pawn_moves;
                bool bOddMove = false;
                pawn_moves[0].push_back(char((int)b_pawn[0] - 1));
                pawn_moves[0].push_back(char((int)b_pawn[1] - 1));
                pawn_moves[1].push_back(char((int)b_pawn[0]));
                pawn_moves[1].push_back(char((int)b_pawn[1] - 1));
                pawn_moves[2].push_back(char((int)b_pawn[0] + 1));
                pawn_moves[2].push_back(char((int)b_pawn[1] - 1));
                pawn_moves[3].push_back(char((int)b_pawn[0]));
                pawn_moves[3].push_back(char((int)b_pawn[1] + 1));
                pawn_moves[4].push_back(char((int)b_pawn[0]));
                pawn_moves[4].push_back(char((int)b_pawn[1] + 2));
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < valid_moves.size(); j++)
                    {
                        if (pawn_moves[i] == valid_moves[j])
                        {
                            string posCurr = getItem_board(board, pawn_moves[i]);
                            if (posCurr != "p" && posCurr != "s" && posCurr != "l" && posCurr != "e" && posCurr != "g" && posCurr != "m" && posCurr != "c" && posCurr != "z")
                            {
                                if (!((i == 3 || i == 4) && (posCurr == "P" || posCurr == "S" || posCurr == "L" || posCurr == "E" || posCurr == "G" || posCurr == "M" || posCurr == "C" || posCurr == "Z")) && !bOddMove)
                                {
                                    poss_moves.push_back(b_pawn + pawn_moves[i]);
                                }
                                if (i == 3 && (posCurr == "P" || posCurr == "S" || posCurr == "L" || posCurr == "E" || posCurr == "G" || posCurr == "M" || posCurr == "C" || posCurr == "Z"))
                                {
                                    bOddMove = true;
                                }
                            }
                            else if (i == 3)
                            {
                                bOddMove = true;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                array<string, 3> pawn_moves;
                pawn_moves[0].push_back(char((int)b_pawn[0] - 1));
                pawn_moves[0].push_back(char((int)b_pawn[1] - 1));
                pawn_moves[1].push_back(char((int)b_pawn[0]));
                pawn_moves[1].push_back(char((int)b_pawn[1] - 1));
                pawn_moves[2].push_back(char((int)b_pawn[0] + 1));
                pawn_moves[2].push_back(char((int)b_pawn[1] - 1));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < valid_moves.size(); j++)
                    {
                        if (pawn_moves[i] == valid_moves[j])
                        {
                            string posCurr = getItem_board(board, pawn_moves[i]);
                            if (posCurr != "p" && posCurr != "s" && posCurr != "l" && posCurr != "e" && posCurr != "g" && posCurr != "m" && posCurr != "c" && posCurr != "z")
                            {
                                poss_moves.push_back(b_pawn + pawn_moves[i]);
                            }
                            break;
                        }
                    }
                }
            }
        }
        return poss_moves;
    }
}

vector<string> poss_superpawn_moves(array<array<string, 7>, 7> Board, string Player)
{
    vector<string> poss_moves;
    array<string, 49> valid_moves = {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "a6", "b6", "c6", "d6", "e6", "f6", "g6",
                                     "a5", "b5", "c5", "d5", "e5", "f5", "g5", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "a3", "b3", "c3", "d3", "e3",
                                     "f3", "g3", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "a1", "b1", "c1", "d1", "e1", "f1", "g1"};

    if (Player == "w")
    {
        vector<string> possSPMoves = getPossiblePositions(Board, "S");
        string sSuperPawn;
        int move_size;
        if (possSPMoves.size() == 0)
        {
            return poss_moves;
        }
        for (int w = 0; w < possSPMoves.size(); w++)
        {
            sSuperPawn = possSPMoves[w];
            array<string, 11> arrSPawn;
            bool black_piece, bAlready;
            bool bOddMove1 = false, bOddMove2 = false, bOddMove3 = false;
            arrSPawn[0].push_back(char((int)sSuperPawn[0] - 1));
            arrSPawn[0].push_back(char((int)sSuperPawn[1] - 1));
            arrSPawn[1].push_back(char((int)sSuperPawn[0] - 2));
            arrSPawn[1].push_back(char((int)sSuperPawn[1] - 2));
            arrSPawn[2].push_back(char((int)sSuperPawn[0] - 1));
            arrSPawn[2].push_back(char((int)sSuperPawn[1]));
            arrSPawn[3].push_back(char((int)sSuperPawn[0] - 1));
            arrSPawn[3].push_back(char((int)sSuperPawn[1] + 1));
            arrSPawn[4].push_back(char((int)sSuperPawn[0]));
            arrSPawn[4].push_back(char((int)sSuperPawn[1] - 1));
            arrSPawn[5].push_back(char((int)sSuperPawn[0]));
            arrSPawn[5].push_back(char((int)sSuperPawn[1] - 2));
            arrSPawn[6].push_back(char((int)sSuperPawn[0]));
            arrSPawn[6].push_back(char((int)sSuperPawn[1] + 1));
            arrSPawn[7].push_back(char((int)sSuperPawn[0] + 1));
            arrSPawn[7].push_back(char((int)sSuperPawn[1] - 1));
            arrSPawn[8].push_back(char((int)sSuperPawn[0] + 2));
            arrSPawn[8].push_back(char((int)sSuperPawn[1] - 2));
            arrSPawn[9].push_back(char((int)sSuperPawn[0] + 1));
            arrSPawn[9].push_back(char((int)sSuperPawn[1]));
            arrSPawn[10].push_back(char((int)sSuperPawn[0] + 1));
            arrSPawn[10].push_back(char((int)sSuperPawn[1] + 1));

            for (int i = 0; i < 11; i++)
            {
                bAlready = false;
                for (int j = 0; j < valid_moves.size(); j++)
                {
                    if (arrSPawn[i] == valid_moves[j])
                    {
                        bAlready = true;
                        string pos = getItem_board(Board, arrSPawn[i]);
                        if (pos != "P" && pos != "S" && pos != "L" && pos != "E" && pos != "G" && pos != "M" && pos != "C" && pos != "Z")
                        {
                            black_piece = pos == "p" || pos == "s" || pos == "l" || pos == "e" || pos == "g" || pos == "m" || pos == "c" || pos == "z";

                            if ((i == 0 || i == 4 || i == 7) && black_piece)
                            {
                                bOddMove1 = true;
                                break;
                            }

                            if ((i == 1 || i == 5 || i == 8) && (bOddMove1 || black_piece))
                            {
                                bOddMove1 = false;
                                break;
                            }

                            if (bOddMove1 == false)
                            {
                                poss_moves.push_back(sSuperPawn + arrSPawn[i]);
                            }
                            else
                            {
                                bOddMove1 = false;
                            }
                        }
                        else if (i == 0 || i == 4 || i == 7)
                        {
                            bOddMove1 = true;
                        }
                        else if (i == 1 || i == 5 || i == 8)
                        {
                            bOddMove1 = false;
                        }
                        break;
                    }
                }
                if (bAlready == false)
                {
                    bOddMove1 = false;
                }
            }
        }

        return poss_moves;
    }
    else
    {
        vector<string> possSPMoves1 = getPossiblePositions(Board, "s");
        string sSPMoves1;
        if (possSPMoves1.size() == 0)
        {
            return poss_moves;
        }
        for (int w = 0; w < possSPMoves1.size(); w++)
        {
            sSPMoves1 = possSPMoves1[w];
            array<string, 11> arrSPawn;
            bool bWPiece, bAlready;
            bool bOddMove1 = false, bOddMove2 = false, bOddMove3 = false;
            arrSPawn[0].push_back(char((int)sSPMoves1[0] - 1));
            arrSPawn[0].push_back(char((int)sSPMoves1[1] + 1));
            arrSPawn[1].push_back(char((int)sSPMoves1[0] - 2));
            arrSPawn[1].push_back(char((int)sSPMoves1[1] + 2));
            arrSPawn[2].push_back(char((int)sSPMoves1[0] - 1));
            arrSPawn[2].push_back(char((int)sSPMoves1[1]));
            arrSPawn[3].push_back(char((int)sSPMoves1[0] - 1));
            arrSPawn[3].push_back(char((int)sSPMoves1[1] - 1));
            arrSPawn[4].push_back(char((int)sSPMoves1[0]));
            arrSPawn[4].push_back(char((int)sSPMoves1[1] + 1));
            arrSPawn[5].push_back(char((int)sSPMoves1[0]));
            arrSPawn[5].push_back(char((int)sSPMoves1[1] + 2));
            arrSPawn[6].push_back(char((int)sSPMoves1[0]));
            arrSPawn[6].push_back(char((int)sSPMoves1[1] - 1));
            arrSPawn[7].push_back(char((int)sSPMoves1[0] + 1));
            arrSPawn[7].push_back(char((int)sSPMoves1[1] + 1));
            arrSPawn[8].push_back(char((int)sSPMoves1[0] + 2));
            arrSPawn[8].push_back(char((int)sSPMoves1[1] + 2));
            arrSPawn[9].push_back(char((int)sSPMoves1[0] + 1));
            arrSPawn[9].push_back(char((int)sSPMoves1[1]));
            arrSPawn[10].push_back(char((int)sSPMoves1[0] + 1));
            arrSPawn[10].push_back(char((int)sSPMoves1[1] - 1));

            for (int i = 0; i < 11; i++)
            {
                bAlready = false;
                for (int l = 0; l < valid_moves.size(); l++)
                {
                    if (arrSPawn[i] == valid_moves[l])
                    {
                        bAlready = true;
                        string pos = getItem_board(Board, arrSPawn[i]);
                        if (pos != "p" && pos != "s" && pos != "l" && pos != "e" && pos != "g" && pos != "m" && pos != "c" && pos != "z")
                        {
                            bWPiece = pos == "P" || pos == "S" || pos == "L" || pos == "E" || pos == "G" || pos == "M" || pos == "C" || pos == "Z";

                            if ((i == 0 || i == 4 || i == 7) && bWPiece)
                            {
                                bOddMove1 = true;
                                break;
                            }

                            if ((i == 1 || i == 5 || i == 8) && (bOddMove1 || bWPiece))
                            {
                                bOddMove1 = false;
                                break;
                            }

                            if (bOddMove1 == false)
                            {
                                poss_moves.push_back(sSPMoves1 + arrSPawn[i]);
                            }
                            else
                            {
                                bOddMove1 = false;
                            }
                        }
                        else if (i == 0 || i == 4 || i == 7)
                        {
                            bOddMove1 = true;
                        }
                        else if (i == 1 || i == 5 || i == 8)
                        {
                            bOddMove1 = false;
                        }
                        break;
                    }
                }
                if (bAlready == false)
                {
                    bOddMove1 = false;
                }
            }
        }
        return poss_moves;
    }
}

vector<string> getBestMove(array<array<string, 7>, 7> board, string Player)
{
    vector<string> poss_moves, arr_possLion, arr_possZebra, arr_possGiraffe, arr_possPawn, arr_possSPawns;
    arr_possLion = poss_lion_Moves(board, Player);
    arr_possZebra = poss_zebra_moves(board, Player);
    arr_possGiraffe = poss_giraffe_moves(board, Player);
    arr_possPawn = poss_pawn_moves(board, Player);
    arr_possSPawns = poss_superpawn_moves(board, Player);

    poss_moves.insert(poss_moves.end(), arr_possLion.begin(), arr_possLion.end());
    poss_moves.insert(poss_moves.end(), arr_possZebra.begin(), arr_possZebra.end());
    poss_moves.insert(poss_moves.end(), arr_possGiraffe.begin(), arr_possGiraffe.end());
    poss_moves.insert(poss_moves.end(), arr_possPawn.begin(), arr_possPawn.end());
    poss_moves.insert(poss_moves.end(), arr_possSPawns.begin(), arr_possSPawns.end());

    return poss_moves;
}

int getBoardMaterialScore(array<array<string, 7>, 7> board, string Player)
{
    int player_w_value = 0, player_b_value = 0;
    int iPawn = 100, iSPawn = 350, iZebra = 300, iGiraffe = 400;

    for (int r = 0; r < 7; r++)
    {
        for (int f = 0; f < 7; f++)
        {
            if (board[r][f] == "P")
            {
                player_w_value += iPawn;
            }
            else if (board[r][f] == "S")
            {
                player_w_value += iSPawn;
            }
            else if (board[r][f] == "Z")
            {
                player_w_value += iZebra;
            }
            else if (board[r][f] == "G")
            {
                player_w_value += iGiraffe;
            }

            if (board[r][f] == "p")
            {
                player_b_value += iPawn;
            }
            else if (board[r][f] == "s")
            {
                player_b_value += iSPawn;
            }
            else if (board[r][f] == "z")
            {
                player_b_value += iZebra;
            }
            else if (board[r][f] == "g")
            {
                player_b_value += iGiraffe;
            }
        }
    }
    return player_w_value - player_b_value;
}

int getBoardMobilityScore(array<array<string, 7>, 7> board, string Player, vector<string> arrChanges, vector<string> arrBestMoves)
{
    return arrChanges.size() - arrBestMoves.size();
}

int getBoardAttackScore(array<array<string, 7>, 7> board, string Player, vector<string> arrChanges, vector<string> arrBestMoves)
{
    int Player_w_attack = 0, Player_b_attack = 0;

    for (int w = 0; w < arrChanges.size(); w++)
    {
        string sCurrPos, sCurrPiece;
        sCurrPos.push_back(arrChanges[w][2]);
        sCurrPos.push_back(arrChanges[w][3]);
        sCurrPiece = getItem_board(board, sCurrPos);
        if (sCurrPiece == "p" || sCurrPiece == "s" || sCurrPiece == "g" || sCurrPiece == "z" || sCurrPiece == "l")
        {
            Player_w_attack++;
            if (sCurrPiece == "l")
            {
                Player_w_attack += 10;
            }
        }
    }

    for (int b = 0; b < arrBestMoves.size(); b++)
    {
        string sCurrPos, sCurrPiece;
        sCurrPos.push_back(arrBestMoves[b][2]);
        sCurrPos.push_back(arrBestMoves[b][3]);
        sCurrPiece = getItem_board(board, sCurrPos);
        if (sCurrPiece == "P" || sCurrPiece == "S" || sCurrPiece == "G" || sCurrPiece == "Z" || sCurrPiece == "L")
        {
            Player_b_attack++;
            if (sCurrPiece == "L")
            {
                Player_b_attack += 10;
            }
        }
    }

    return Player_w_attack - Player_b_attack;
}

int EvaluateTheBoard(array<array<string, 7>, 7> grid, string Player, vector<string> turns, vector<string> bmoves)
{
    int iActScore, iMaterialScore, iMobilityScore, iAttackScore;
    string state = getCurrentState(grid);
    iMaterialScore = getBoardMaterialScore(grid, Player);
    iMobilityScore = getBoardMobilityScore(grid, Player, turns, bmoves);
    iAttackScore = getBoardAttackScore(grid, Player, turns, bmoves);

    if (state == "White wins")
    {
        iActScore = 10000;
    }
    else if (state == "Black wins")
    {
        iActScore = -10000;
    }
    else if (state == "Draw")
    {
        iActScore = 0;
    }
    else
    {
        iActScore = iMaterialScore + iMobilityScore + iAttackScore;
    }

    if (Player == "w")
    {
        return iActScore;
    }
    else
    {
        return -iActScore;
    }
}

int findMinMax(array<array<string, 7>, 7> Board, int depth, string Player)
{
    array<array<string, 7>, 7> newBoard;
    vector<string> moves;
    string state = getCurrentState(Board);
    int Eval;

    if (state != "Continue" || depth == 0)
    {
        return BoardEvaluation(Board, Player);
    }

    int value = -100000;
    moves = getBestMove(Board, Player);
    for (int m = 0; m < moves.size(); m++)
    {
        newBoard = setNewMoves(Board, moves[m], Player);
        string sNewPlayer;
        if (Player == "w")
        {
            sNewPlayer = "b";
        }
        else
        {
            sNewPlayer = "w";
        }
        Eval = -findMinMax(newBoard, depth - 1, sNewPlayer);
        value = max(value, Eval);
    }
    return value;
}

int main()
{
    vector<string> sLine;
    int N, iNumber;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string input_FEN, move;
        getline(cin, input_FEN);
        sLine.push_back(input_FEN);
    }

    for (int i = 0; i < N; i++)
    {

        array<string, 3> FEN, new_FEN;
        array<array<string, 7>, 7> board;

        FEN = deleteSpace(sLine[i]);
        board = initiliaseBoard(FEN);
        vector<string> arrChanges = getBestMove(board, "w");
        vector<string> arrBestMovies = getBestMove(board, "b");
        int boardEvaluation = EvaluateTheBoard(board, FEN[1], arrChanges, arrBestMovies);

        cout << boardEvaluation << endl;
    }

    return 0;
}