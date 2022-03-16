#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

queue<pair<int,pair<int,int>>> is;
queue<pair<int, pair<int, int>>> sea;
int answer = 10001;
int n;
int map[102][102];
int visit[102][102];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	int Count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1&&visit[i][j]==0) {
				visit[i][j] = ++Count;
				is.push({0,{i,j}});
				while (!is.empty()) {
					int y = is.front().second.first;
					int x = is.front().second.second;
					int t = is.front().first;
					is.pop();
					if (y + 1 <= n) {
						if (map[y + 1][x] == 1 && visit[y+1][x] != Count) {
							visit[y+1][x] = Count;
							is.push({t+1,{y+1,x}});
						}
						else if (map[y + 1][x] == 0 && visit[y+1][x] != Count) {
							visit[y+1][x] = Count;
							sea.push({1,{y + 1,x} });
						}
					}

					if (y - 1 >= 1) {
						if (map[y - 1][x] == 1 && visit[y-1][x] != Count) {
							visit[y-1][x] = Count;
							is.push({ t + 1,{y - 1,x} });
						}
						else if (map[y - 1][x] == 0 && visit[y-1][x] != Count) {
							visit[y-1][x] = Count;
							sea.push({ 1,{y - 1,x} });
						}
					}

					if (x - 1 >= 1) {
						if (map[y][x - 1] == 1 && visit[y][x - 1] != Count) {
							visit[y][x - 1] = Count;
							is.push({ t + 1,{y,x - 1} });
						}
						else if (map[y][x - 1] == 0 && visit[y][x - 1] != Count) {
							visit[y][x - 1] = Count;
							sea.push({ 1,{y,x - 1} });
						}
					}

					if (x + 1 <= n) {
						if (map[y][x + 1] == 1 && visit[y][x + 1] != Count) {
							visit[y][x + 1] = Count;
							is.push({ t + 1,{y,x + 1} });
						}
						else if (map[y][x + 1] == 0 && visit[y][x + 1] != Count) {
							visit[y][x + 1] = Count;
							sea.push({ 1,{y,x + 1} });
						}
					}
				}

				while (!sea.empty()) {
					int y = sea.front().second.first;
					int x = sea.front().second.second;
					int t = sea.front().first;
					sea.pop();
					if (y + 1 <= n) {
						if (map[y + 1][x] == 1 && visit[y + 1][x] != Count) {
							answer = min(answer,t);
						}
						else if (map[y + 1][x] == 0 && visit[y + 1][x] != Count) {
							visit[y + 1][x] = Count;
							sea.push({ t+1,{y + 1,x} });
						}
					}

					if (y - 1 >= 1) {
						if (map[y - 1][x] == 1 && visit[y - 1][x] != Count) {
							answer = min(answer, t);
						}
						else if (map[y - 1][x] == 0 && visit[y - 1][x] != Count) {
							visit[y - 1][x] = Count;
							sea.push({ t+1,{y - 1,x} });
						}
					}

					if (x - 1 >= 1) {
						if (map[y][x - 1] == 1 && visit[y][x - 1] != Count) {
							answer = min(answer, t);
						}
						else if (map[y][x - 1] == 0 && visit[y][x - 1] != Count) {
							visit[y][x - 1] = Count;
							sea.push({ t+1,{y,x - 1} });
						}
					}

					if (x + 1 <= n) {
						if (map[y][x + 1] == 1 && visit[y][x + 1] != Count) {
							answer = min(answer, t);
						}
						else if (map[y][x + 1] == 0 && visit[y][x + 1] != Count) {
							visit[y][x + 1] = Count;
							sea.push({ t+1,{y,x + 1} });
						}
					}
				}
			}
		}
	}
	printf("%d",answer);
}