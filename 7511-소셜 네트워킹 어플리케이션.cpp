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

int parent[1000001];
int Rank[1000001];
int find(int a) {
	if (parent[a] == a) {
		return a;
	}

	int y = find(parent[a]);
	parent[a] = y;
	return y;
}


void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) {
		return;
	}

	if (Rank[x] > Rank[y]) {
		parent[y] = x;
		Rank[x] += Rank[y];
		Rank[y] = 0;
	}
	else {
		parent[x] = y;
		Rank[y] += Rank[x];
		Rank[x] = 0;
	}
}


int main() {
	int t;
	scanf("%d",&t);
	int n,k,m;
	int a,b;
	int Count =0;
	while (t--) {
		Count++;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			Rank[i] = 1;
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d%d", &a,&b);
			merge(a,b);
		}
		printf("Scenario %d:\n",Count);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			if (find(a) == find(b)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		printf("\n");
	}
}