#include <iostream>
using namespace std;

int dp[1000000 + 1];

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{

	int N;
	cin >> N;
	dp[0] = 1; // 2^0
	for (int i = 1; i <= N; ++i)
	{
		if ((i & 0x1) == 0)
		{
			dp[i] = dp[ i / 2];
		}
		dp[i] += dp[i - 1];
		dp[i] %= 1000000000;
	}
	cout << dp[N] << endl;


    return 0;
}
