#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int map[301][301][301];

int main() {
	int n,m;
	cin>>n>>m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d",&map[0][i][j]);

			if (i != j && map[0][i][j] == 0) {
				map[0][i][j] = 1e9;
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[k-1][i][j] > map[k-1][i][k] + map[k-1][k][j]) {
					map[k][i][j] = map[k-1][i][k] + map[k-1][k][j];
				}
				else {
					map[k][i][j] = map[k-1][i][j];
				}
			}
		}
	}

	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		if (map[a-1][b][c] == 1e9) {
			printf("-1\n");
		}
		else {
			printf("%d\n",map[a-1][b][c]);
		}
	}
}