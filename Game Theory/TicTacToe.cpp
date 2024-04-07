#include <bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col;
};

char player = 'x', opponent = 'o';
bool isMovesLeft(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int evaluate(vector<vector<char>> &b)
{

    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    return 0;
}

pair<int, int> minimax(vector<vector<char>> &board, int depth, bool isMax)
{
    int score = evaluate(board);

    if (score == 10)
        return make_pair(score - depth, depth);

    if (score == -10)
        return make_pair(score + depth, depth);

    if (isMovesLeft(board) == false)
        return make_pair(0, depth);

    if (isMax)
    {
        pair<int, int> best = make_pair(-1000, 0);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = player;

                    best = max(best,
                               minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }

    else
    {
        pair<int, int> best = make_pair(1000, 0);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (board[i][j] == '_')
                {

                    board[i][j] = opponent;

                    best = min(best,
                               minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

Move findBestMoveForX(vector<vector<char>> &board)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    int moves;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (board[i][j] == '_')
            {

                board[i][j] = player;

                pair<int, int> moveVal = minimax(board, 1, false);

                board[i][j] = '_';

                if (moveVal.first > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal.first;
                    moves = moveVal.second;
                }
            }
        }
    }

    string status = "";
    if (bestVal > 0)
    {
        status = "x Wins";
    }
    else if (bestVal < 0)
    {
        status = "o Wins";
    }
    else
    {
        status = "Draw";
    }
    cout << status << endl;
    printf("%d", moves);

    return bestMove;
}

Move findBestMoveForO(vector<vector<char>> &board)
{
    int bestVal = 1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    int moves;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '_')
            {
                board[i][j] = opponent;

                pair<int, int> moveVal = minimax(board, 1, true);

                board[i][j] = '_';
                if (moveVal.first < bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal.first;
                    moves = moveVal.second;
                }
            }
        }
    }

    string status = "";
    if (bestVal > 0)
    {
        status = "x Wins";
    }
    else if (bestVal < 0)
    {
        status = "o Wins";
    }
    else
    {
        status = "Draw";
    }
    cout << status << endl;
    printf("%d", moves);

    return bestMove;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> board(3, vector<char>(3, '_'));
    char p;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y >> p;
        board[x][y] = p;
    }
    Move bestMove;
    if (p == 'x')
        bestMove = findBestMoveForO(board);
    else if (p == 'o')
        bestMove = findBestMoveForX(board);

    cout << " row: " << bestMove.row << " col: " << bestMove.col;
    return 0;
}

