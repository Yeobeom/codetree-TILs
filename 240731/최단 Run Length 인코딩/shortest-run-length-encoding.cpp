#include<iostream>
#include<string>

std::string encoding(std::string& A)
{
	std::string ret;
	int cnt = 1;
	int chCnt = 1;
	int ch = A[0];
	ret += ch;
	for (int i = 1; i < A.length(); i++)
	{
		
		if (ch != A[i])
		{
			ret += std::to_string(chCnt);
			chCnt = 0;
			++cnt;
			ch = A[i];
			ret += ch;
		}
		++chCnt;
	}
	ret += std::to_string(chCnt);
	return ret;
}

void shift(std::string& A)
{
	char right = A[A.length() - 1];
	for (int i = A.length() - 1; i > 0; --i) A[i] = A[i - 1];
	A[0] = right;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string A;
	std::cin >> A;
	int ret = A.length() + 1;
	for (int i = 0; i < A.length() + 1; i++)
	{
		std::string en = encoding(A);
		shift(A);
		if (ret > en.length()) ret = en.length();
	}
	std::cout << ret;
	return EXIT_SUCCESS;
}