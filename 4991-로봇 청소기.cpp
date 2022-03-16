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

int n,m;
int map[23][23];
int visit[23][23];
int d[14][14];
char arr[24];
pair<int,int> loc[14];
queue<pair<int,pair<int,int>>> q;
int Count;
int sum;
int check[14];
int Min = 250000;
void back(int now, int rest) {
	if (rest == 0) {
		Min = min(Min,sum);
	}
	else {
		for (int i = 2; i <= Count; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				sum+=d[now][i];
				back(i,rest-1);
				sum-=d[now][i];
				check[i] = 0;
			}
		}
	}
}
int main() {
	while(1) {
		scanf("%d%d",&m,&n);
		if (n == 0) {
			break;
		}
		Count = 1;
		Min = 250000;
		for (int i = 0; i <= n+1; i++) {
			for (int j = 0; j <= m+1; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%s",&arr);
			for (int j = 1; j <= m; j++) {
				if (arr[j - 1] == '.') {
					map[i][j] = 1;
				}
				else if (arr[j-1] == 'o') {
					loc[1] = {i,j};
					map[i][j] = 1;
				}
				else if (arr[j - 1] == '*') {
					map[i][j] = ++Count;
					loc[Count] = {i,j};
				}
			}
		}
		for (int i = 1; i <= Count; i++) {
			for (int j = 1; j <= Count; j++) {
				if (i != j) {
					d[i][j] = 500;
				}
			}
		}

		bool err = false;
		for(int i = 1;i<=Count;i++){
			q.push({0,{loc[i].first,loc[i].second}});
			visit[loc[i].first][loc[i].second] = i;
			while (!q.empty()) {
				int y = q.front().second.first;
				int x = q.front().second.second;
				int t = q.front().first;
				q.pop();

				if (map[y - 1][x] != 0 && visit[y - 1][x] != i) {
					visit[y - 1][x] = i;
					if (map[y - 1][x] > 1) {
						d[i][map[y-1][x]] = t+1;
					}
					q.push({t+1,{y-1,x}});
				}

				if (map[y + 1][x] != 0 && visit[y + 1][x] != i) {
					visit[y + 1][x] = i;
					if (map[y + 1][x] > 1) {
						d[i][map[y + 1][x]] = t + 1;
					}
					q.push({ t + 1,{y + 1,x} });
				}

				if (map[y][x+1] != 0 && visit[y][x+1] != i) {
					visit[y ][x+1] = i;
					if (map[y ][x+1] > 1) {
						d[i][map[y ][x+1]] = t + 1;
					}
					q.push({ t + 1,{y ,x+1} });
				}

				if (map[y][x-1] != 0 && visit[y][x-1] != i) {
					visit[y][x-1] = i;
					if (map[y][x-1] > 1) {
						d[i][map[y][x-1]] = t + 1;
					}
					q.push({ t + 1,{y ,x-1} });
				}
			}
			for (int j = 2; j <= Count; j++) {
				if (d[i][j] == 500) {
					err= true;
					break;
				}
			}
			if (err) {
				break;
			}
		}
		if (err) {
			printf("-1\n");
		}
		else {
			back(1,Count-1);
			printf("%d\n",Min);
		}
	}
}