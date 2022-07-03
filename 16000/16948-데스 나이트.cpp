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
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
struct Info {
	int y,x;
	Info(int a, int b) {
		y = a;
		x = b;
	}
};
int v[2][6] = {{-2,-2,0,0,2,2},{-1,1,-2,2,-1,1}};
int n;
int map[202][202];
int sy,sx, ey,ex;
queue <Info> q;
int main() {
	scanf("%d",&n);
	scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
	sy++;
	sx++;
	ey++;
	ex++;
	map[sy][sx] = 1;
	q.push(Info(sy,sx));
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		if (ey == y && ex == x) {
			break;
		}

		for (int i = 0; i < 6; i++) {
			if (1 <= y + v[0][i] && y + v[0][i] <= n && 1 <= x + v[1][i] && x + v[1][i] <= n) {
				if (map[y + v[0][i]][x + v[1][i]] == 0) {
					map[y + v[0][i]][x + v[1][i]] = map[y][x] + 1;
					q.push(Info(y+v[0][i],x+v[1][i]));
				}
			}
		}
	}

	if (map[ey][ex] == 0) {
		cout<<-1;
	}
	else {
		cout<<map[ey][ex]-1;
	}
}