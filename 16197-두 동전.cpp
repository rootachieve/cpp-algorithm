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

int n,m;
int base[22][22];
char arr[22];
int Min = 11;
void back(int Count ,int ay, int ax, int by, int bx) {
	if (Count >= Min) {
		return;
	}
	if (ay == 0 || ay == n + 1 || ax == 0 || ax == m + 1) {
		if (by != 0 && by != n + 1 && bx != 0 && bx != m + 1) {
			Min = min(Min,Count);
		}
		else {
			return;
		}
	}else if (by == 0 || by == n + 1 || bx == 0 || bx == m + 1) {
		if (ay != 0 && ay != n + 1 && ax != 0 && ax != m + 1) {
			Min = min(Min, Count);
		}
		else {
			return;
		}
	}
	else {
		int nay,nax,nbx,nby;
		for (int i = 1; i <= 4; i++) {
			nay = ay;
			nax = ax;
			nby = by;
			nbx = bx;
			if (i == 1) {
				if (base[ay - 1][ax] == 0) {
					nay--;
				}

				if (base[by - 1][bx] == 0) {
					nby--;
				}
			}
			else if (i == 2) {
				if (base[ay][ax+1] == 0) {
					nax++;
				}

				if (base[by][bx+1] == 0) {
					nbx++;
				}
			}
			else if (i == 3) {
				if (base[ay + 1][ax] == 0) {
					nay++;
				}

				if (base[by + 1][bx] == 0) {
					nby++;
				}
			}
			else {
				if (base[ay][ax - 1] == 0) {
					nax--;
				}

				if (base[by][bx - 1] == 0) {
					nbx--;
				}
			}

			back(Count+1,nay,nax,nby,nbx);
		}
	}
}
int main() {
	int Count = 0;
	int ax,ay,bx,by;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%s",&arr);
		for (int j = 1; j <= m; j++) {
			if (arr[j - 1] == 'o') {
				if (Count == 0) {
					ax = j;
					ay = i;
					Count++;
				}
				else {
					by = i;
					bx = j;
				}
			}
			else if (arr[j - 1] == '#') {
				base[i][j] = 1;
			}
		}
	}

	back(0, ay,ax,by,bx);
	if (Min == 11) {
		printf("-1");
	}
	else {
		printf("%d",Min);
	}
}