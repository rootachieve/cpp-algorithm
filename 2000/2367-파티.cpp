#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int map[802][802];
int c[802][802];
int f[802][802];
int n;
int parent[802];
int lim[101];
int flow(int s, int e) {
	int ans = 0;
	while (true) {
		queue<int> q;
		fill(parent+1,parent+1+n, -1);
		int node;
		parent[s] = s;
		q.push(s);
		while (!q.empty() && parent[e] == -1) {
			node = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (c[node][i] - f[node][i] > 0 && parent[i] == -1) {
					parent[i] = node;
					q.push(i);
				}
			}
		}

		if (parent[e] == -1) {
			break;
		}
		else {
			int Min = c[parent[e]][e]- f[parent[e]][e];
			for (int i = e; i != s; i = parent[i]) {
				Min = min(Min,c[parent[i]][i]-f[parent[i]][i]);
			}

			for (int i = e; i != s; i = parent[i]) {
				f[parent[i]][i]+=Min;
				f[i][parent[i]]-=Min;
			}
			ans++;
		}

	}

	return ans;
}
int main() {
	int cntP,plate,food;
	cin>>cntP>>plate>>food;
	n = cntP+food+2;
	int temp;
	for (int i = 1; i <= food; i++) {
		cin>>temp;
		c[cntP+i][cntP+food+2] = temp;
	}
	int a,b;
	for (int i = 1; i <= cntP; i++) {
		cin>>a;
		c[cntP+food+1][i] = plate;
		for (int j = 1; j <= a; j++) {
			cin>>b;
			c[i][cntP+b] = 1;
		}
	}

	cout<<flow(cntP+food+1, cntP + food + 2);
}