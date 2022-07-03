#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int n,m;
int map[1025][1025];

int main() {
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d",&a);
			map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + a;
		}
	}

	int x1,x2,y1,y2;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		int ans = map[y2][x2] + map[y1-1][x1-1] - map[y1-1][x2] - map[y2][x1-1];
		printf("%d\n",ans);
	}
}