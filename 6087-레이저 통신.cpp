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

int map[5][102][102];
int base[102][102];
int r,c;
char arr[103];
int Sx,Sy;
int Ey,Ex;
int Count = 0;
queue<pair<int,pair<int,int>>> q;
int main() {
	scanf("%d%d",&c,&r);
	for (int i = 1; i <= r; i++) {
		scanf("%s",&arr);
		for (int j = 1; j <= c; j++) {
			map[1][i][j] = 10001;
			map[2][i][j] = 10001;
			map[3][i][j] = 10001;
			map[4][i][j] = 10001;
			if (arr[j - 1] == '.') {
				base[i][j] = 1;
			}
			else if (arr[j-1] == 'C') {
				if(Count==0){
				Sy = i;
				Sx = j;
				Count++;
				}
				else {
					Ey = i;
					Ex = j;
				}
				base[i][j] = 2;
			}
		}
	}
	for(int i = 1;i<=4;i++){
		map[i][Sy][Sx] = 1;
		q.push({i,{Sy,Sx}});
	}
	while (!q.empty()) {
		int y = q.front().second.first;
		int x =  q.front().second.second;
		int ty = q.front().first;
		q.pop();
		if (base[y][x + 1] != 0) {
			if (ty == 2) {
				if (map[2][y][x + 1] > map[ty][y][x]) {
					map[2][y][x + 1] = map[ty][y][x];
					q.push({ 2,{y,x + 1} });
				}
			}
			else if(ty!=4){
				if (map[2][y][x + 1] > map[ty][y][x] + 1) {
					map[2][y][x + 1] = map[ty][y][x] + 1;
					q.push({2,{y,x+1}});
				}
			}
		}

		if (base[y][x - 1] != 0) {
			if (ty == 4) {
				if (map[4][y][x - 1] > map[ty][y][x]) {
					map[4][y][x - 1] = map[ty][y][x];
					q.push({ 4,{y,x - 1} });
				}
			}
			else if(ty!=2){
				if (map[4][y][x - 1] > map[ty][y][x] + 1) {
					map[4][y][x - 1] = map[ty][y][x] + 1;
					q.push({ 4,{y,x - 1} });
				}
			}
		}

		if (base[y - 1][x] != 0) {
			if (ty == 1) {
				if (map[1][y - 1][x] > map[ty][y][x]) {
					map[1][y - 1][x] = map[ty][y][x];
					q.push({ 1,{y - 1,x} });
				}
			}
			else if(ty!=3){
				if (map[1][y - 1][x] > map[ty][y][x] + 1) {
					map[1][y - 1][x] = map[ty][y][x] + 1;
					q.push({ 1,{y - 1,x} });
				}
			}
		}

		if (base[y + 1][x] != 0) {
			if (ty == 3) {
				if (map[3][y + 1][x] > map[ty][y][x]) {
					map[3][y + 1][x] = map[ty][y][x];
					q.push({ 3,{y + 1,x} });
				}
			}
			else if(ty!=1){
				if (map[3][y + 1][x] > map[ty][y][x] + 1) {
					map[3][y + 1][x] = map[ty][y][x] + 1;
					q.push({ 3,{y + 1,x} });
				}
			}
		}
	}

	printf("%d",min(min(map[1][Ey][Ex],map[2][Ey][Ex]),min(map[3][Ey][Ex],map[4][Ey][Ex]))-1);
}