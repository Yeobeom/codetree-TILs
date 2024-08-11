#include<iostream>
#include<cstring>

int N, M, K;
int nodes[4];
int path[1001];

int ans = 0;

void dfs(int lv)
{
    if (lv == N)
    {
        int cnt = 0;
        for (int i = 0; i < K; i++)
        {
            if(nodes[i] >= M)cnt++;
        }
        if (ans < cnt) ans = cnt;
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            int dist = nodes[i];
            nodes[i] = nodes[i] + path[lv];
            dfs(lv + 1);
            nodes[i] = dist;
        }
    }
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
	{
		std::cin >> path[i];
	}
    for(int i = 0; i < K; i++) nodes[i] = 1;
    dfs(0);

    std::cout << ans;

    return EXIT_SUCCESS;
}