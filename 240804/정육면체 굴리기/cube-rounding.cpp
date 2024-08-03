#include<iostream>

// dice[0] 바닥, dice[5] 천장
//    2
//  1 0 4 5
//    3
int dice[6];
int* Bottom = &dice[0];
int* Top = &dice[5];

// 위에서 2번이 바닥이 된다.
// 즉 0->2->5->3 에서 2->5->3->0 이 된다.
// 2번 값이 0으로, 5번 값이 2번으로 가는 것과 같다.
void UP()
{
	int tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = tmp;
}

// 위에서 3번이 바닥이 된다.
// 즉 0->2->5->3 에서 3->0->2->5 이 된다.
// 2번 값이 5번으로, 0번 값이 2번으로 가는 것과 같다.
void DOWN()
{
	int tmp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = tmp;
}

// 위에서 1번이 바닥이 된다.
// 즉 0->4->5->1 에서 1->0->4->5 이 된다.
// 1번 값이 0번으로, 5번 값이 1번으로 가는 것과 같다.
void LEFT()
{
	int tmp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = tmp;
}

// 위에서 4번이 바닥이 된다.
// 즉 0->4->5->1 에서 1->0->4->5 이 된다.
// 4번 값이 0번으로, 0번 값이 2번으로 가는 것과 같다.
void RIGHT()
{
	int tmp = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = tmp;
}

int board[20][20];
int n, m, k;

void init()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			std::cin >> board[y][x];
		}
	}
}

// 동(R), 서(L), 북(U), 남(D)
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int y, x;
	std::cin >> n >> m >> y >> x >> k;

	init();
	for (int i = 0; i < k; i++)
	{
		int dir = 0;
		std::cin >> dir;

		int ny = y + dy[dir - 1];
		int nx = x + dx[dir - 1];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;

		y = ny;
		x = nx;

		if (dir == 1) RIGHT();
		else if (dir == 2) LEFT();
		else if (dir == 3) UP();
		else DOWN();

		if (board[y][x] == 0) board[y][x] = *Bottom;
		else
		{
			*Bottom = board[y][x];
			board[y][x] = 0;
		}
		std::cout << *Top << '\n';
	}

	return EXIT_SUCCESS;
}