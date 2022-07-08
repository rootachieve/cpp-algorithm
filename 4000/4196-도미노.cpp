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

int id,d[100001];
bool fin[100001];
bool in[100001];
vector<int> v[100001];
int Cnt;
int g[100001];
stack<int> s;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (d[y] == 0) {
			parent = min(parent,dfs(y));
		}
		else if (!fin[y]) {
			parent = min(parent,d[y]);
		}
	}

	if (parent == d[x]) {
		Cnt++;
		while (1) {
			int t = s.top();
			s.pop();
			fin[t] = true;
			g[t] = Cnt;
			if (t == x) {
				break;
			}
		}
	}

	return parent;
}

int main() {
	int t;
	cin>>t;
	int n,m;
	int a,b;
	while (t--) {
		cin>>n>>m;
		Cnt = 0;
		for (int i = 1; i <= n; i++) {
			d[i] = 0;
			fin[i] = false;
			id = 0;
			g[i] = 0;
			in[i] = false;
			v[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			cin>>a>>b;
			v[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				dfs(i);
			}
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (g[i] != g[v[i][j]]) {
					in[g[v[i][j]]] = true;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= Cnt; i++) {
			if (!in[i]) {
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}