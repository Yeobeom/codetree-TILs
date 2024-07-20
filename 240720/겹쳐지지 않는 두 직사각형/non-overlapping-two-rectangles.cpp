#include<bits/stdc++.h>

constexpr int MAX = 5;
constexpr int MIN_VALUE = -0x7f7f7f;
constexpr int MAX_SQUARE = 0x7f7f7f;
int board[MAX][MAX];

using Point = std::pair<int, int>;
using Pair = std::pair<Point, Point>;
using Square = std::pair<Pair, int>;

Square squares[MAX_SQUARE];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			std::cin >> board[y][x];
		}
	}

	int squaresSize = 0;
	for (int sy = 0; sy < n; sy++)
	{
		for (int sx = 0; sx < m; sx++)
		{
			for (int ey = sy; ey < n; ey++)
			{
				for (int ex = sx; ex < m; ex++)
				{
					int area = 0;
					for (int ty = sy; ty <= ey; ty++)
					{
						for (int tx = sx; tx <= ex; tx++)
						{
							area += board[ty][tx];
						}
					}
					squares[squaresSize++] = { {{sy,sx},{ey,ex}},area };
				}
			}
		}
	}

	int maxArea = MIN_VALUE;

	for (int i = 0; i < squaresSize; i++)
	{
		int& sy = squares[i].first.first.first;
		int& sx = squares[i].first.first.second;
		int& ey = squares[i].first.second.first;
		int& ex = squares[i].first.second.second;
		int& area = squares[i].second;

		for (int j = 0; j < squaresSize; j++)
		{
			if (i == j) continue;


			int& tsy = squares[j].first.first.first;
			int& tsx = squares[j].first.first.second;
			int& tey = squares[j].first.second.first;
			int& tex = squares[j].first.second.second;
			int& tarea = squares[j].second;

			bool continueFlag = false;
			for (int y = tsy; y <= tey; y++)
			{
				for (int x = tsx; x <= tex; x++)
				{
					if (y >= sy && y <= ey && x >= sx && x <= ex)
					{
						continueFlag = true;
						break;
					}
				}
				if (continueFlag) break;
			}
			if (continueFlag) continue;

			int target = area + tarea;
			if (maxArea < target)
			{
				maxArea = target;
			}
		}
	}

	std::cout << maxArea;


	return EXIT_SUCCESS;
}