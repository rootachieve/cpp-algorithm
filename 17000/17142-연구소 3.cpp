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

struct loc {
	int y;
	int x;
	loc(){}

	loc(int a, int b) {
		y = a;
		x = b;
	}
};
int base[52][52];
vector<loc> vir;
loc sel[12];
int visit[52][52];
int n,m;
int Min = 3000;
void back(int now,int check) {
	if (now == m) {
		queue<loc> q;
		for (int i = 0; i < m; i++) {
			q.push(sel[i]);
			visit[sel[i].y][sel[i].x] = 1;
		}

		while (!q.empty()) {
			loc node = q.front();
			q.pop();
			if (base[node.y][node.x + 1] != 0 && visit[node.y][node.x + 1] == 0) {
				visit[node.y][node.x + 1] = visit[node.y][node.x] + 1;
				q.push(loc(node.y,node.x + 1));
			}

			if (base[node.y][node.x - 1] != 0 && visit[node.y][node.x - 1] == 0) {
				visit[node.y][node.x - 1] = visit[node.y][node.x] + 1;
				q.push(loc(node.y, node.x - 1));
			}

			if (base[node.y + 1][node.x] != 0 && visit[node.y + 1][node.x] == 0) {
				visit[node.y + 1][node.x] = visit[node.y][node.x] + 1;
				q.push(loc(node.y + 1, node.x));
			}

			if (base[node.y - 1][node.x] != 0 && visit[node.y - 1][node.x] == 0) {
				visit[node.y - 1][node.x] = visit[node.y][node.x] + 1;
				q.push(loc(node.y - 1, node.x));
			}
		}

		bool err = false;
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (base[i][j] == 1 && visit[i][j] == 0) {
					err = true;
				}
				else if(base[i][j]==1&&visit[i][j]>0){
					Max = max(Max,visit[i][j]-1);
				}
				visit[i][j] = 0;
			}
		}

		if (!err) {
			Min = min(Min,Max);
		}
	}
	else {
		for (int i = check + 1; i < vir.size(); i++) {
			sel[now] = vir[i];
			back(now+1,i);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d",&a);
			if (a == 0) {
				base[i][j] = 1;
			}
			else if (a == 2) {
				vir.push_back(loc(i,j));
				base[i][j] = 2;
			}
		}
	}

	back(0,-1);
	if (Min == 3000) {
		printf("-1");
	}else{
	printf("%d",Min);
	}
}