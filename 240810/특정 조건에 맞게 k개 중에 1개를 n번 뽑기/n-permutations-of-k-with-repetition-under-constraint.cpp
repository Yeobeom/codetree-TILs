#include <iostream>

int path[21];
int N, K;


void dfs(int lv)
{
	if (lv > 2) if (path[lv - 1] == path[lv - 2] && path[lv - 1] == path[lv - 3]) return;

	if (lv == N)
	{
		int ret = 0;
		for (int i = 0; i < N; i++)
			std::cout << path[i] << ' ';
		std::cout << '\n';
	}
	else
	{
		for (int i = 1; i <= K; i++)
		{
			path[lv] = i;
			dfs(lv + 1);
		}
	}
}

int main(int argc , char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> K >> N;

	dfs(0);

	return EXIT_SUCCESS;
}