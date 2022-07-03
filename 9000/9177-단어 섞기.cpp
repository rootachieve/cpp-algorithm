#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

string a, b, c;
int nowT;
int dp[201][201][401];
void back(int l, int r, int now) {
	if (now == c.size()) {
		dp[l][r][now] = nowT;
	}
	else {
		if (a[l] == b[r]) {
			if (a[l] == c[now]) {
				if(abs(dp[l+1][r][now+1])<nowT){
					back(l+1,r,now+1);
				}
				if (abs(dp[l][r + 1][now + 1]) < nowT) {
					back(l, r + 1, now + 1);
				}


				if (dp[l+1][r][now+1] == nowT || dp[l][r+1][now+1] == nowT) {
					dp[l][r][now] = nowT;
				}
				else {
					dp[l][r][now] = -nowT;
				}
			}
			else {
				dp[l][r][now] = -nowT;
			}
		}
		else {
			if (a[l] == c[now]) {
				if (abs(dp[l + 1][r][now + 1]) < nowT) {
					back(l + 1, r , now + 1);
				}
				dp[l][r][now] = dp[l + 1][r][now + 1];
			}
			else if (b[r] == c[now]) {
				if (abs(dp[l][r + 1][now + 1]) < nowT) {
					back(l, r + 1, now + 1);
				}
				dp[l][r][now] = dp[l][r+1][now+1];
			}
			else {
				dp[l][r][now] = -nowT;
			}
		}
	}
}

int main() {
	int t;
	cin>>t;

	for (int h = 1; h <= t; h++) {
		cin>>a>>b>>c;
		nowT = h;
		back(0,0,0);
		if (dp[0][0][0] == nowT) {
			printf("Data set %d: yes\n",h);
		}
		else {

			printf("Data set %d: no\n", h);
		}
	}
}