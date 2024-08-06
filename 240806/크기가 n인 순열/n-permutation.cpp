#include <iostream>
using namespace std;

int N;
int path[10];
int DAT[10];

void dfs(int lv)
{
    if(lv == N)
    {
        for(int i = 0; i < N; i++) std::cout << path[i] << ' ';
        std::cout << '\n';
    }
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(DAT[i] > 0) continue;
            path[lv] = i;
            DAT[i] = 1;
            dfs(lv+1);
            DAT[i] = 0;
        }
    }
}

int main() {
    std::cin >> N;
    dfs(0);
    return 0;
}