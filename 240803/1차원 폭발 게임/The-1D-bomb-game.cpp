#include<iostream>
#include<list>

int N, M;
int bombs[201];
int tmp[201];

bool Boom()
{
	if (N == 0) return false;
	bool isBoom = false;
	int prev = bombs[0];
	int cnt = 1;
	int tmpN = N;
	for (int i = 1; i < N; i++)
	{
		if (prev == bombs[i]) cnt++;
		else
		{
			if (cnt >= M)
			{
				tmpN -= cnt;
				isBoom = true;
				for (int j = 1; j <= cnt; j++) bombs[i - j] = 0;
				
			}
			cnt = 1;
		}
		prev = bombs[i];
	}
	if (cnt >= M)
	{
		isBoom = true;
		for (int j = 1; j <= cnt; j++) bombs[N - j] = 0;
		tmpN -= cnt;
	}
	int tmpIdx = 0;
	for (int i = 0; i < N; i++)
	{
		if (bombs[i] == 0) continue;
		tmp[tmpIdx++] = bombs[i];
	}
	
	for (int i = 0; i < N; i++) bombs[i] = 0;
	for (int i = 0; i < tmpIdx; i++) bombs[i] = tmp[i];
	N = tmpN;
	return isBoom;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++) std::cin >> bombs[i];
	while (Boom());

	std::cout << N << '\n';
	for (int i = 0; i < N; i++) std::cout << bombs[i] << '\n';

	return EXIT_SUCCESS;
}