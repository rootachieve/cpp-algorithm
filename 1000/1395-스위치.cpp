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
int tree[400001];
bool lazy[400001];
void init(int s, int e, int node) {
	if (s == e) {
		tree[node] = 0;
	}
	else {
		int m = (s+e)/2;
		init(s,m,node*2);
		init(m+1,e,node*2+1);

		tree[node] = tree[node*2] + tree[node*2+1];
	}
}

void update(int s, int e, int l, int r, int node) {
	if (lazy[node]) {
		tree[node] = e - s + 1 - tree[node];
		if (s != e) {
			lazy[node * 2] == true ? lazy[node * 2] = false : lazy[node * 2] = true;
			lazy[node * 2 + 1] == true ? lazy[node * 2 + 1] = false : lazy[node * 2 + 1] = true;
		}
		lazy[node] = false;
	}

	if (e < l || r < s) {
		return;
	}
	
	if (l <= s && e <= r) {
		tree[node] = e - s + 1 - tree[node];
		if (s != e) {
			lazy[node * 2] == true ? lazy[node * 2] = false : lazy[node * 2] = true;
			lazy[node * 2 + 1] == true ? lazy[node * 2 + 1] = false : lazy[node * 2 + 1] = true;
		}
		return;
	}

	int m = (s+e)/2;
	update(s,m,l,r,node*2);
	update(m+1,e,l,r,node*2+1);
	tree[node] =tree[node * 2] + tree[node * 2 + 1];
}

int sum(int s, int e, int l, int r, int node) {
	if (lazy[node]) {
		tree[node] = e - s + 1 - tree[node];
		if (s != e) {
			lazy[node * 2] == true ? lazy[node * 2] = false : lazy[node * 2] = true;
			lazy[node * 2 + 1] == true ? lazy[node * 2 + 1] = false : lazy[node * 2 + 1] = true;
		}
		lazy[node] = false;
	}

	
	if (e < l || r < s) {
		return 0;
	}

	if (l <= s && e <= r) {
		return tree[node];
	}

	int m = (s + e) / 2;
	return sum(s, m, l, r, node * 2) + sum(m + 1, e, l, r, node * 2 + 1);
}
int main() {
	int n,m;
	cin>>n>>m;

	init(1,n,1);
	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		if (a == 1) {
			int d = sum(1,n,b,c,1);
			printf("%d\n",d);
		}
		else {
			update(1,n,b,c,1);
		}
	}
}