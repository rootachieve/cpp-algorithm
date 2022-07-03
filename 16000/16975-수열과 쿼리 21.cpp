#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n,q;
int Count;
ll tree[400001];
ll lazy[400001];
ll in[100001];
int C[400001];
void init(int s, int e, int node) {
	if (s == e) {
		tree[node] = in[s];
		C[node] = 1;
		return;
	}

	int m = (s+e)/2;
	init(s,m,node*2);
	init(m+1,e,node*2+1);
	C[node] = C[node*2]+C[node*2+1];
	return;
}

void add(int s, int e, int node, int l, int r,ll value) {
	if (e<l || r<s) {
		return;
	}

	if (l <= s && e <= r) {
		lazy[node] += value;
		return;
	}

	int m = (s+e)/2;

	add(s,m,node*2,l,r,value);
	add(m + 1 ,e, node * 2 + 1, l, r, value);
}

ll Find(int s, int e, int node, int target) {
	if (s == e) {
		if (lazy[node] != 0) {
			tree[node]+=lazy[node];
			lazy[node] = 0;
		}
		return	tree[node];
	}

	int m = (s+e)/2;
	if (lazy[node] != 0) {
		lazy[node*2] +=lazy[node];
		lazy[node*2+1]+=lazy[node];
		lazy[node] = 0;
	}

	if (Count + C[node * 2] < target) {
		Count+=C[node*2];
		return Find(m+1,e,node*2+1,target);
	}
	else {
		return Find(s,m,node*2,target);
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&in[i]);
	}

	init(1,n,1);

	int a,b,c;
	ll d;
	scanf("%d",&q);
	for (int i = 1; i <= q; i++) {
		scanf("%d",&a);
		if (a == 1) {
			scanf("%d%d%lld",&b,&c,&d);
			add(1,n,1,b,c,d);
		}
		else {
			Count = 0;
			scanf("%d",&b);
			printf("%lld\n",Find(1,n,1,b));
		}
	}
}