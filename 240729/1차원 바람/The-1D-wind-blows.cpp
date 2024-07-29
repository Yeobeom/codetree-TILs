#include<bits/stdc++.h>

constexpr int MAX_N = 101;
int board[MAX_N][MAX_N];

int N, M, Q;

void Lshift(int y)
{
    int right = board[y][M - 1];
    for (int x = M - 1; x >= 1; x--)
        board[y][x] = board[y][x - 1];
    board[y][0] = right;
}

void Rshift(int y)
{
    int left = board[y][0];
    for (int x = 0; x < M; x++)
        board[y][x] = board[y][x + 1];
    board[y][M - 1] = left;
}

void shift(int y, char d)
{
    if (d == 'L') Lshift(y);
    else Rshift(y);
}

bool lowerPropagtion(int y, char d)
{
    if (y >= N) return false;

    int ty = y - 1;
    for (int x = 0; x < M; x++)
    {
        if (board[ty][x] == board[y][x])
        {
            shift(y, d);
            return true;
        }
    }
    return false;
}


bool upperPropagtion(int y, char d)
{
    if (y < 0) return false;

    int ty = y + 1;
    for (int x = 0; x < M; x++)
    {
        if (board[ty][x] == board[y][x])
        {
            shift(y, d);
            return true;
        }
    }
    return false;
}

void toggleD(char& d)
{
    if (d == 'L') d = 'R';
    else d = 'L';
}

void propagtion(int y, char d)
{
    shift(y, d);
    int uy = y - 1;
    char ud = d;
    do toggleD(ud); while (upperPropagtion(uy--, ud));
    int dy = y + 1;
    char dd = d;
    do toggleD(dd); while (lowerPropagtion(dy++, dd));
}

void show()
{

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cout << board[y][x] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> N >> M >> Q;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cin >> board[y][x];
        }
    }

    int r;
    char d;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> r >> d;
        propagtion(r - 1, d);
        
    }
    show();

    return EXIT_SUCCESS;
}