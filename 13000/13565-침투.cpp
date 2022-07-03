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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int arr[2][4] {{0,0,-1,1},{-1,1,0,0}};

struct Info{
	int y,x;

	Info(int a, int b) {
		y = a;
		x = b;
	}
};
int map[1002][1002];
int n,m;
queue<Info> q;
string temp;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		for (int j = 0; j < m; j++) {
			if (temp[j] == '0') {
				map[i][j+1] = 1;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		map[0][i] = 1;
		map[n+1][i] = 1;
	}

	q.push(Info(0,1));
	map[0][1] = 2;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (y + arr[0][i] <= n+1 && y + arr[0][i] >= 0 && x + arr[1][i] <= m && x + arr[1][i] >= 1) {
				if (map[y+arr[0][i]][x+arr[1][i]]==1) {
					map[y + arr[0][i]][x + arr[1][i]] = 2;
					q.push(Info(y + arr[0][i],x + arr[1][i]));
				}
			}
		}
	}

	if (map[n + 1][1]==2) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}