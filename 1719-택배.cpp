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

int map[202][202];

int D[202];
int check[202];
int parent[202];
vector<pair<int,int>> v[202];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n; i++) {
			D[i] = 300000;
			check[i] = 0;
			parent[i] = i;
		}

		D[h] = 0;
		int Count = n;
		while (Count > 0) {
			int node = 0;
			int Min = 300001;
			for (int i = 1; i <= n; i++) {
				if (check[i] == 0 && Min > D[i]) {
					Min = D[i];
					node = i;
				}
			}
			check[node] = 1;
			
			for (int i = 0; i < v[node].size(); i++) {
				if (D[v[node][i].first] > D[node] + v[node][i].second) {
					D[v[node][i].first] = D[node] + v[node][i].second;
					parent[v[node][i].first] = node;
				}
			}
			Count--;
		}

		for (int i = 1; i <= n; i++) {
			int target =i;
			while (parent[target] != h) {
				target = parent[target];
			}
			map[h][i] = target;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				printf("- ");
			}
			else {
				printf("%d ",map[i][j]);
			}
		}
		printf("\n");
	}
}	else {
			printf("0 ");
		}
	}
}