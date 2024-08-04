#include<iostream>
#include<string>

std::string path;
std::string num[] = { "1","22","333","4444" };
int cnt;
int n;

void dfs()
{
	if (path.length() > n) return;
	else if (path.length() == n)
	{
		++cnt;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			path += num[i];
			dfs();
			for (int j = 0; j < num[i].length(); j++) path.pop_back();
		}
	}

}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);


	std::cin >> n;
	dfs();
	std::cout << cnt;

	return EXIT_SUCCESS;
}