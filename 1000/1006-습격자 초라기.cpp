#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int dp[5][10001][5];
int map[2][10001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	dp[0][1][0] = 1;
	dp[1][1][1] = 1;
	dp[2][1][2] = 2;
	dp[3][1][3] = 1;
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		int ans = 2*n;
		for (int i = 1; i >= 0; i--) {
			for (int j = 1; j <= n; j++) {
				cin>>map[i][j];
			}
		}
		for (int i = 0; i <= 4; i++) {
			int temp;
			bool able = false;
			switch (i) {
				case 0: {
					if (map[0][1] + map[0][n] <= m) {
						able = true;
					}
					break;
				}

				case 1: {
					if (map[1][1] + map[1][n] <= m) {
						able = true;
					}
					break;
				}

				case 2: {
					if (map[1][1] + map[1][n] <= m && map[0][1] + map[0][n] <= m) {
						able = true;
					}
					break;
				}

				case 3: {
					if (map[0][1] + map[1][1] <= m) {
						able = true;
					}
					break;
				}

				default: {
					able = true;
					break;
				}
			}

			if (able) {
				for (int j = 2; j <= n; j++) {
					if (map[0][j] + map[0][j - 1] <= m) {
						dp[i][j][0] = max({dp[i][j-1][1],dp[i][j-1][4]})+1;
					}
					else {
						dp[i][j][0] = 0;
					}

					if (map[1][j] + map[1][j - 1] <= m) {
						dp[i][j][1] = max({ dp[i][j - 1][0],dp[i][j - 1][4] }) + 1;
					}
					else {
						dp[i][j][1] = 0;
					}

					if (map[1][j] + map[1][j - 1] <= m && map[0][j] + map[0][j - 1] <= m) {
						dp[i][j][2] = dp[i][j-1][4] + 2;
					}
					else {
						dp[i][j][2] = 0;
					}

					if (map[0][j] + map[1][j] <= m) {
						dp[i][j][3] = max({dp[i][j-1][0],dp[i][j - 1][1] ,dp[i][j - 1][2] ,
							dp[i][j - 1][3] ,dp[i][j - 1][4] }) + 1;
					}
					else {
						dp[i][j][3] = 0;
					}

					dp[i][j][4] = max({ dp[i][j - 1][0],dp[i][j - 1][1] ,dp[i][j - 1][2] ,
							dp[i][j - 1][3] ,dp[i][j - 1][4] });
				}


				switch (i) {
					case 0: {
						temp = max(dp[i][n][1],dp[i][n][4]);
						break;
					}

					case 1: {
						temp = max(dp[i][n][0], dp[i][n][4]);
						break;
					}

					case 2: {
						temp = dp[i][n][4];
						break;
					}

					case 3: {
						temp = max({ dp[i][n][0],dp[i][n][1] ,dp[i][n][2] ,
								dp[i][n][3] ,dp[i][n][4] });

						break;
					}

					default: {
						temp = max({ dp[i][n][0],dp[i][n][1] ,dp[i][n][2] ,
								dp[i][n][3] ,dp[i][n][4] });
						break;
					}
				}

				ans = min(ans,2*n-temp);
			}
		}

		cout<<ans<<"\n";
	}
}