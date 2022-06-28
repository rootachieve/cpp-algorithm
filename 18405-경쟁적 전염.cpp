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
int map[201][201];
pair<int,int> ans[201][201];

int base[2][4] = {{0,0,1,-1},{-1,1,0,0}};


struct Info {
	int y = 0;
	int x = 0;
	int t;

	Info( int b, int c, int d) {
		y = b;
		x = c;
		t = d;
	}
};
queue<Info> q[1001];
int main() {
int ansT,ansY,ansX;
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j];
			if (map[i][j] != 0) {
				q[map[i][j]].push(Info(i,j,0));
				ans[i][j] = {map[i][j],0};
			}
		}
	}
	cin>>ansT>>ansY>>ansX;
	for (int h = 1; h <= m; h++) {
		while (!q[h].empty()) {
			int y = q[h].front().y;
			int x = q[h].front().x;
			int t = q[h].front().t;
			q[h].pop();
			for (int i = 0; i < 4; i++) {
				if (y + base[0][i] <= n && y + base[0][i] >= 1 && x + base[1][i] <= n && x + base[1][i] >= 1) {
					if (ans[y + base[0][i]][x + base[1][i]].first == 0 || ans[y + base[0][i]][x + base[1][i]].second > t + 1) {
						ans[y + base[0][i]][x + base[1][i]].second = t + 1;
						ans[y + base[0][i]][x + base[1][i]].first = ans[y][x].first;
						q[h].push(Info(y + base[0][i], x + base[1][i],t+1));
					}
				}
			}
		}
	}

	if (ans[ansY][ansX].first == 0) {
		printf("0");
	}
	else {
		if (ans[ansY][ansX].second <= ansT) {
			printf("%d",ans[ansY][ansX].first);
		}
		else {
			printf("0");
		}
	}
}