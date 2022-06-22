#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
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
int map[102][102];
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin>>map[i][j];
		}
	}
	int ans =0;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j <= m+1; j++) {
			if (map[i][j] > now) {
				ans+=map[i][j] - now;
			}
			else if (map[i][j] < now) {
				ans+=now-map[i][j];
			}

			now = map[i][j];
		}
		
	}

	for (int i = 1; i <= m; i++) {
		int now = 0;
		for (int j = 1; j <= n + 1; j++) {
			if (map[j][i] > now) {
				ans += map[j][i] - now;
			}
			else if (map[j][i] < now) {
				ans += now - map[j][i];
			}
			now = map[j][i];
		}

	}
    
	ans+=2*n*m;
	cout<<ans;
}