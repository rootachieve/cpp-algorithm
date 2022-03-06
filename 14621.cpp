#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#define MOD 1000000
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD
#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD
using namespace std;


typedef struct edge {
	int a;
	int b;
	int w;
};
int n,m;
int type[1002];
int parent[1002];
int Rank[1002];
int answer = 0;
vector <edge> v;
bool compare(edge l, edge r) {
	return l.w<r.w;
}

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
		Rank[a] += Rank[b];
		Rank[b] = 0;
	}
	else {
		parent[a] = b;
		Rank[b] += Rank[a];
		Rank[a] =0;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	char temp[5];
	for (int i = 1; i <= n; i++) {
		scanf("%s",&temp);
		if (temp[0] == 'W') {
			type[i] = 1;
		}
		else {
			type[i] = 2;
		}

		Rank[i] = 1;
		parent[i] = i;
	}

	int s,e,w;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&s,&e,&w);
		edge k = {s,e,w};
		v.push_back(k);
	}

	sort(v.begin(),v.end(),compare);

	for (int i = 0; i < v.size(); i++) {
		if(type[v[i].a]!=type[v[i].b]){
			if (find(v[i].a) != find(v[i].b)) {
				merge(v[i].a, v[i].b);
				answer+= v[i].w;
			}
		}
	}
	int Count = 0;
	for (int i = 1; i <= n; i++) {
		if (Rank[i] > 0) {
			Count++;
		}
	}

	if (Count > 1) {
		printf("-1");
	}
	else {
		printf("%d", answer);
	}
}