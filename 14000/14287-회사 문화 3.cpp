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

vector<int> v[100001];
int line[2][100001];
int id;
int tree[400001];
int dfs(int node) {
	line[0][node] = ++id;
	int Max = id;
	for (int i = 0; i < v[node].size(); i++) {
		Max = dfs(v[node][i]);
	}
	line[1][node] = Max;
	return Max;
}

void update(int s, int e, int target, int value, int node) {
	if (s == e) {
		tree[node]+=value;
	}
	else {
		int m = (s+e)/2;
		if (m < target) {
			update(m+1,e,target,value,node*2+1);
		}
		else {
			update(s,m,target,value,node*2);
		}
		tree[node]+=value;
	}
}

int sum(int s, int e, int l, int r, int node) {
	if (l <= s && e <= r) {
		return tree[node];
	}
	else if(e<l||r<s){
		return 0;
	}
	else {
		int m = (s+e)/2;
		return sum(s,m,l,r,node*2) + sum(m+1,e,l,r,node*2+1);
	}
}
int main() {
cin.tie(0);
cout.tie(0);
ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		if (a != -1) {
			v[a].push_back(i);
		}
	}

	dfs(1);
	int b,c;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		if (a == 1) {
			cin>>b>>c;
			update(1,n,line[0][b],c,1);
		}
		else {
			cin>>b;
			cout<<sum(1,n,line[0][b],line[1][b],1)<<"\n";
		}
	}
}