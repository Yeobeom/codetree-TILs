#include <iostream>
using namespace std;

int blocks[10000];
int tmp[10000];

int main() {
    int n;
    cin >>n;
    for(int i = 0; i < n; i++) cin >> blocks[i];

    int s,e;
    cin >> s >> e;
    s = n - s - 1;
    e = n - e - 1;
    for(int i = e; i <= s; i++) blocks[i] = -1;
    int tmp_idx = 0;
    for(int i = 0; i < n; i++) 
    {
        if(blocks[i] != -1) tmp[tmp_idx++] = blocks[i];
    }
    for(int i = 0; i < tmp_idx; i++) blocks[i] = tmp[i];
    n = tmp_idx;

    cin >> s >> e;
    s = n - s;
    e = n - e;
    for(int i = e; i <= s; i++) blocks[i] = -1;
    tmp_idx = 0;
    for(int i = 0; i < n; i++) 
    {
        if(blocks[i] != -1) tmp[tmp_idx++] = blocks[i];
    }
    for(int i = 0; i < tmp_idx; i++) blocks[i] = tmp[i];
    n = tmp_idx;

    std::cout << n << '\n';
    for(int i = 0; i < n; i++) cout << blocks[i] << '\n';


    return 0;
}