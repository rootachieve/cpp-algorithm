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
struct edge{
	int s,e;
	long long cost;
	edge(int A,int B,int C) : s(A),e(B),cost(C){}
};
int n;
int parent[1001];
int Rank[1001];
vector<edge> v;
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
		Rank[b]+=Rank[a];
	}
}

bool comp(edge a, edge b) {
	return a.cost<b.cost;
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		Rank[i] = 1;
		parent[i] = i;
	}
	long long temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld",&temp);
			if (i <= j) {
				v.push_back(edge(i,j,temp));
			}
		}
	}
	long long answer = 0;
	sort(v.begin(),v.end(),comp);
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].s) != find(v[i].e)) {
			merge(v[i].s,v[i].e);
			answer+=v[i].cost;
		}
	}
	printf("%lld",answer);
}