#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
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

vector<int> tree[400001];
int base[100001];
void init(int s,int e,int node){
	if (s == e) {
		tree[node].push_back(base[s]);
	}
	else {
		int m = (s+e)/2;
		init(s,m,node*2);
		init(m+1,e,node*2+1);
		tree[node].resize(tree[node*2].size()+tree[node*2+1].size());
		merge(tree[node*2].begin(),tree[node*2].end(),tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),tree[node].begin());
	}
}

int sum(int s, int e, int l, int r, int k, int node) {
	if (l <= s && e <= r) {
		return tree[node].size() - (upper_bound(tree[node].begin(),tree[node].end(),k) - tree[node].begin());
	}
	else if (e < l || r < s) {
		return 0;
	}
	else {
		int m = (s+e)/2;
		return sum(s,m,l,r,k,node*2) + sum(m+1,e,l,r,k,node*2+1);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>base[i];
	}
	init(1,n,1);
	int m;
	cin>>m;

	int a,b,c;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b>>c;
		cout<<sum(1,n,a,b,c,1)<<"\n";
	}
}