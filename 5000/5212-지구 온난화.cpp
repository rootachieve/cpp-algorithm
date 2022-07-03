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
int map[11][11];
int ans[11][11];
int l = 11;
int r = 0;
int u = 11;
int d = 0;
int main() {
	int n,m;
	cin>>n>>m;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == 'X') {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				int cnt = 0;
				map[i-1][j] == 0? cnt++:NULL;

				map[i + 1][j] == 0 ? cnt++ : NULL;

				map[i][j - 1] == 0 ? cnt++ : NULL;

				map[i][j + 1] == 0 ? cnt++ : NULL;

				if (cnt <= 2) {
					ans[i][j] = 1;
					u = min(u,i);
					d = max(d,i);
					l = min(l,j);
					r = max(r,j);
				}
			}
		}
	}

	for (int i = u; i <= d; i++) {
		for (int j = l; j <= r; j++) {
			if (ans[i][j] == 1) {
				cout<<'X';
			}
			else {
				cout<<'.';
			}
		}
		cout<<"\n";
	}
}