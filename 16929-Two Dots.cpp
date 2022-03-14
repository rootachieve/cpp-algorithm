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

char map[53][53];
int parent[2502];
int Rank[2502];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a == b) {
		return;
	}

	if (Rank[a] > Rank[b]) {
		parent[b] = a;
		Rank[a]+=Rank[b];
	}
	else {
		parent[a] = b;
		Rank[b] +=Rank[a];
	}
}
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%s",map[i]);
	}
	for (int i = 1; i <= n * m; i++) {
		parent[i] = i;
		Rank[i] = 1;
	}
	bool cy = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == map[i + 1][j]) {
				if (find((i * m) + j + 1) == find(((i + 1) * m) + j + 1)) {
					cy = true;
					break;
				}
				else {
					merge((i * m) + j + 1, ((i + 1) * m) + j + 1);
				}
			}

			if (map[i][j] == map[i][j + 1]) {
				if (find((i * m) + j + 1) == find((i * m) + j + 2)) {
					cy = true;
					break;
				}
				else {
					merge((i * m) + j + 1, (i * m) + j + 2);
				}
			}
		}
		if (cy) {
			break;
		}
	}

	if (cy) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	
}