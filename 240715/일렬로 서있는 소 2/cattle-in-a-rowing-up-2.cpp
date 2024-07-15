#include <iostream>

int main() {
    int N, A[101], cnt = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i) std::cin >> A[i];
    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                if (A[i] <= A[j] && A[j] <= A[k]) cnt++;
            }
        }
    }

    std::cout << cnt;
    return 0;
}