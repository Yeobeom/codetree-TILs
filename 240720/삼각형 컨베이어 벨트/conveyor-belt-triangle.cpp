#include<bits/stdc++.h>

constexpr int MAX = 200;
constexpr int MAX_LENGTH = 3 * MAX;

int belt[MAX_LENGTH];
int afterBelt[MAX_LENGTH];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, t;
	std::cin >> n >> t;

	for (int i = 0; i < 3 * n; i++)
	{
		std::cin >> belt[i];
	}

	for (int i = 0; i < 3 * n; i++)
	{
		afterBelt[(i + t) % (3 * n)] = belt[i];
	}

	for (int i = 0; i < n; i++)
		std::cout << afterBelt[i] << ' ';
	std::cout << '\n';
	for (int i = n; i < 2*n; i++)
		std::cout << afterBelt[i] << ' ';
	std::cout << '\n';
	for (int i = 2*n; i < 3 * n; i++)
		std::cout << afterBelt[i] << ' ';

	return EXIT_SUCCESS;
}