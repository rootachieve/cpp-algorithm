#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
int dp[101][101][101];

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		if (dp[20][20][20] == RESET) {
			dp[20][20][20] = W(20,20,20);
		}
		return dp[20][20][20];
	}

	if (a < b && b < c) {
		int sum = 0;
		if (dp[a][b][c-1] == RESET) {
			dp[a][b][c-1] = W(a, b, c-1);
		}
		sum += dp[a][b][c - 1];

		if (dp[a][b-1][c-1] == RESET) {
			dp[a][b-1][c-1] = W(a, b-1, c-1);
		}
		sum += dp[a][b - 1][c - 1];

		if (dp[a][b-1][c] == RESET) {
			dp[a][b-1][c] = W(a, b-1, c);
		}
		sum -= dp[a][b - 1][c];

		return sum;
	}

	int sum = 0;
	if (dp[a-1][b][c] == RESET) {
		dp[a-1][b][c] = W(a-1, b, c);
	}
	sum += dp[a-1][b][c];

	if (dp[a-1][b - 1][c] == RESET) {
		dp[a-1][b - 1][c] = W(a-1, b - 1, c);
	}
	sum += dp[a-1][b - 1][c];


	if (dp[a-1][b][c-1] == RESET) {
		dp[a-1][b][c-1] = W(a-1, b, c-1);

	}
	sum += dp[a-1][b][c-1];


	if (dp[a - 1][b-1][c - 1] == RESET) {
		dp[a - 1][b-1][c - 1] = W(a - 1, b-1, c - 1);

	}
	sum -= dp[a - 1][b-1][c - 1];
	return sum;
}

int main() {
	int a, b, c;
	while (1) {
		scanf("%d%d%d",&a,&b,&c);
		if (a == b && b == c && a == -1) {
			break;
		}
		int ans =  W(a,b,c);
		
		printf("w(%d, %d, %d) = %d\n",a,b,c, ans);
	}
}