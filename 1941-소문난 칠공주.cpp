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
int Cy;
int Cs;
int check[7][7];
int visit[7][7];
int map[27];
int answer = 0;
void back(int now, int C) {
	if (Cy >= 4) {
		return;
	}
	if (C == 7) {

		
		bool Find = false;
		bool err = false;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				if (check[i][j] == 1&&visit[i][j]==0) {
					if(!Find){
						Find = true;	
						queue<pair<int, int>> q;
						q.push({i,j});
						visit[i][j] = 1;
						while (!q.empty()) {
							int y = q.front().first;
							int x = q.front().second;
							q.pop();
							if (check[y+1][x] == 1 && visit[y+1][x] == 0) {
								visit[y+1][x] = 1;
								q.push({y+1,x});
							}

							if (check[y-1][x] == 1 && visit[y-1][x] == 0) {
								visit[y-1][x] = 1;
								q.push({ y-1,x });
							}

							if (check[y][x+1] == 1 && visit[y][x+1] == 0) {
								visit[y][x+1] = 1;
								q.push({ y,x+1 });
							}

							if (check[y][x-1] == 1 && visit[y][x-1] == 0) {
								visit[y][x-1] = 1;
								q.push({ y,x-1 });
							}
						}
					}
					else {
						err = true;
						break;
					}
				}

			}
			if (err) {
				break;
			}
		}

		if (!err) {
			answer++;
		}
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				visit[i][j] = 0;
			}
		}
	}
	else {
		for (int i = now + 1; i <= 25; i++) {
			if (map[i] == 2) {
				Cs++;
				check[(i-1)/5+1][(i-1)%5+1] = 1;
				back(i,C+1);
				Cs--;
				check[(i - 1) / 5+1][(i - 1) % 5 + 1] = 0;
			}
			else {
				Cy++;
				check[(i - 1) / 5+1][(i - 1) % 5 + 1] = 1;
				back(i, C + 1);
				Cy--;
				check[(i - 1) / 5+1][(i - 1) % 5 + 1] = 0;
			}
		}
	}
}

int main() {
	char temp[7];
	for (int i = 0; i < 5; i++) {
		scanf("%s",&temp);
		for (int j = 1; j <= 5; j++) {
			if (temp[j - 1] == 'Y') {
				map[i*5+j] = 1;
			}
			else {
				map[i*5+j] = 2;
			}
		}
	}

	back(0,0);
	printf("%d",answer);
}