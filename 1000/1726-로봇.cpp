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
int map[5][102][102];
int base[102][102];
int n,m;
queue <pair<int,pair<int,int>>> q;
int main() {
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d",&a);
			if (a == 0) {
				base[i][j] = 1;
			}
		}
	}

	scanf("%d%d%d",&a,&b,&c);
	
	switch (c) {
	case 1:
		c = 1;
		break;
	case 2:
		c = 3;
		break;
	case 3:
		c = 2;
		break;
	case 4:
		c = 0;
		break;
	}
	q.push({ c,{a,b} });
	map[c][a][b] = 1;
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int di = q.front().first;
		q.pop();

		if (map[(di + 1) % 4][y][x] == 0) {
			map[(di + 1) % 4][y][x] = map[di][y][x] + 1;
			q.push({ (di + 1) % 4 ,{y,x}});
		}

		if (map[(di + 3) % 4][y][x] == 0) {
			map[(di+3)%4][y][x] = map[di][y][x]+1;
			q.push({ (di + 3) % 4 ,{y,x}});
		}
		
		if(di==0){
			for (int i = 1; i <= 3; i++) {
				if (base[y - i][x] == 0) {
					break;
				}
				if (map[di][y - i][x] == 0) {
					map[di][y - i][x] = map[di][y][x] + 1;
					q.push({di,{y-i,x}});
				}
			}
		}
		else if(di==1){
			for (int i = 1; i <= 3; i++) {
				if (base[y][x+i] == 0) {
					break;
				}
				if (map[di][y][x+i] == 0) {
					map[di][y][x+i] = map[di][y][x] + 1;
					q.push({ di,{y ,x + i} });
				}
			}
		}
		else if (di == 2) {
			for (int i = 1; i <= 3; i++) {
				if (base[y + i][x] == 0) {
					break;
				}
				if (map[di][y + i][x] == 0) {
					map[di][y + i][x] = map[di][y][x] + 1;
					q.push({ di,{y + i,x} });
				}
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {
				if (base[y][x - i] == 0) {
					break;
				}
				if (map[di][y][x - i] == 0) {
					map[di][y][x - i] = map[di][y][x] + 1;
					q.push({ di,{y,x-i} });
				}
			}
		}
	}

	scanf("%d%d%d", &a, &b, &c);
	switch (c) {
	case 1:
		c = 1;
		break;
	case 2:
		c = 3;
		break;
	case 3:
		c = 2;
		break;
	case 4:
		c = 0;
		break;
	}

	printf("%d",map[c][a][b] - 1);

}