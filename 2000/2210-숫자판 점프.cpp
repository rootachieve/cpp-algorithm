#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
bool arr[1000000];
int map[5][5];
struct info {
	int x;
	int y;
	int now;

	info(int a, int b, int c) {
		x = b;
		y = a;
		now = c;

	}
};

int bfs[2][4] = {{1,-1,0,0},{0,0,1,-1}};
void back(info In,int num) {
	if (num == 5) {
		arr[In.now] = true;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (0 <= In.y + bfs[0][i] && In.y + bfs[0][i] <= 4) {
				if (0 <= In.x + bfs[1][i] && In.x + bfs[1][i] <= 4) {
					back(info(In.y + bfs[0][i], In.x + bfs[1][i],In.now*10+map[In.y + bfs[0][i]][In.x + bfs[1][i]]),num+1);
				}
			}
		}
	}
}
ll n;
ll ans;
int main() {
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			cin>>map[i][j];
		}
	}

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			back(info(i,j,map[i][j]),0);
		}
	}

	for (int i = 0; i < 1000000; i++) {
		if(arr[i]){
			ans++;
		}
	}

	printf("%lld",ans);
}