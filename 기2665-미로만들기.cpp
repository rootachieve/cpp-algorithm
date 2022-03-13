#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
char map[52][52];
int visit[52][52];
int n;

queue<pair<int,int>> q;
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%s",&map[i]);
		for (int j = 0; j < n; j++) {
			visit[i][j] = 3000;
		}
	}
	visit[0][0] = 1;
	q.push({0,0});
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x + 1 < n) {
			if (map[y][x + 1] == '0') {
				if (visit[y][x + 1] > visit[y][x] + 1) {
					visit[y][x + 1] = visit[y][x] + 1;
					q.push({ y,x + 1 });
				}
			}
			else {
				if (visit[y][x + 1] > visit[y][x]) {
					visit[y][x + 1] = visit[y][x];
					q.push({ y,x + 1 });
				}
			}
		}

		if (x - 1 >= 0) {
			if (map[y][x - 1] == '0') {
				if (visit[y][x - 1] > visit[y][x] + 1) {
					visit[y][x - 1] = visit[y][x] + 1;
					q.push({ y,x - 1 });
				}
			}
			else {
				if (visit[y][x - 1] > visit[y][x]) {
					visit[y][x - 1] = visit[y][x];
					q.push({ y,x - 1 });
				}
			}
		}

		if (y + 1 < n) {
			if (map[y + 1][x] == '0') {
				if (visit[y + 1][x] > visit[y][x] + 1) {
					visit[y + 1][x] = visit[y][x] + 1;
					q.push({ y + 1,x });
				}
			}
			else {
				if (visit[y + 1][x] > visit[y][x]) {
					visit[y + 1][x] = visit[y][x];
					q.push({ y + 1,x });
				}
			}
		}

		if (y - 1 >= 0) {
			if (map[y - 1][x] == '0') {
				if (visit[y - 1][x] > visit[y][x] + 1) {
					visit[y - 1][x] = visit[y][x] + 1;
					q.push({ y - 1,x });
				}
			}
			else {
				if (visit[y - 1][x] > visit[y][x]) {
					visit[y - 1][x] = visit[y][x];
					q.push({ y - 1,x });
				}
			}
		}

	}

	printf("%d",visit[n-1][n-1]-1);
}