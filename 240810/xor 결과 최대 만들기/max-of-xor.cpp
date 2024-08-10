#include <iostream>

int arr[21];
int path[21];
int n, m;

int ans = 0;

void dfs(int lv, int prev)
{
	if (lv == m)
	{
		int ret = 0;
		for(int i = 0; i < m; i++)
			ret ^= path[i];
		if(ans < ret) ans = ret;
	}
	else
	{
		for (int i = prev; i < n; i++)
		{
			path[lv] = arr[i];
			dfs(lv + 1, prev + 1);
		}
	}
}

int main(int argc , char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++) std::cin >> arr[i];

	dfs(0,0);

	std::cout << ans;

	return EXIT_SUCCESS;
}