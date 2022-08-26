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
int flow(int s, int e) {
	int ans = 0;
	while (true) {
		queue<int> q;
		fill(parent+1,parent+1+n+n, -1);
		int node;
		parent[s] = s;
		q.push(s);
		while (!q.empty() && parent[e] == -1) {
			node = q.front();
			q.pop();
			for (int i = 1; i <= 2*n; i++) {
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
			for (int i = e; i != s; i = parent[i]) {
				f[parent[i]][i]++;
				f[i][parent[i]]--;
			}
			ans++;
		}

	}

	return ans;
}
int main() {
	int m;
	cin>>n>>m;
	for (int i = 3; i <= n; i++) {
		c[i+n][i] = 1;
	}
	int a,b;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		if (a == 1 || b == 1) {
			c[1][max(a,b)+n] = 1;
		}
		else if (a == 2 || b == 2) {
			c[max(a,b)][2] = 1;
		}
		else {
			c[a][b+n] = 1;
			c[b][a+n] = 1;
		}
	}

	cout<<flow(1,2);
}