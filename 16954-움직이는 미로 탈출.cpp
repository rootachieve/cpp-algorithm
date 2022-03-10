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
queue<pair<int,pair<int,int>>> q;
int map[10][10][10];
int visit[10][10][10];
char arr[10];

int main() {
	for (int i = 0; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			for (int k = 1; k <= 8; k++) {
				map[i][j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= 8; i++) {
		scanf("%s",&arr);
		int Count = 0;
		for (int j = i; j <= 8; j++) {
			for (int k = 1; k <= 8; k++) {
				if (arr[k - 1] == '#') {
					map[Count][j][k] = 0;
				}
			}
			Count++;
		}
	}
	printf("");
	visit[0][8][1] = 1;
	q.push({0,{8,1}});
	while (!q.empty()) {
		int r = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		int Y,X;

		for(int i = 1;i<=9;i++){
			switch (i) {
				case 1:
					Y = y;
					X = x;
					break;
				case 2:
					Y = y-1;
					X = x;
					break;
				case 3:
					Y = y-1;
					X = x-1;
					break;
				case 4:
					Y = y-1;
					X = x+1;
					break;
				case 5:
					Y = y;
					X = x-1;
					break;
				case 6:
					Y = y;
					X = x+1;
					break;
				case 7:
					Y = y + 1;
					X = x;
					break;
				case 8:
					Y = y+ 1;
					X = x-1;
					break;
				case 9:
					Y = y+1;
					X = x+1;
					break;
			}
			if ((map[min(r + 1, 8)][Y][X] == 1&&map[r][Y][X]==1) && visit[min(r + 1, 8)][Y][X] == 0) {
				visit[min(r + 1, 8)][Y][X] = 1;
				q.push({ min(r + 1, 8) ,{Y,X}});
			}
		}
	}
	printf("%d",visit[8][1][8]);
}