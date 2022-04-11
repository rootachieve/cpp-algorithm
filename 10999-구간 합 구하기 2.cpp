#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 500002
using namespace std;
ll base[1000000];
ll tree[4000000];
ll lazy[4000000];
ll n,m,k;

ll init(ll s, ll e, ll node) {
	if (s == e) {
		tree[node] = base[s];
		return tree[node];
	}

	ll mid = (s+e)/2;
	tree[node] = init(s,mid,node*2)+init(mid+1,e,node*2+1);
	return tree[node];
}

ll update(ll s, ll e, ll node, ll l, ll r, ll value) {
	if (l > e || r < s) {
		return 0;
	}
	
	if (l <= s && e <= r) {
		lazy[node]+=value;
		return value*(e-s+1);
	}

	ll mid = (s+e)/2;
	ll befo = tree[node];
	tree[node]+=update(s,mid,node*2,l,r,value) + update(mid + 1,e, node * 2+1, l, r, value);
	return tree[node]-befo;
}

ll sum(ll s,ll e,ll node, ll l, ll r) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (e - s + 1);
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if (l > e || r < s) {
		return 0;
	}

	if (l <= s && e <= r) {
		return tree[node];
	}

	ll mid = (s+e)/2;

	return sum(s,mid,node*2,l,r)+sum(mid+1,e,node*2+1,l,r);
}
int main() {
	ll a,b,c,d;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&base[i]);
	}
	init(1,n,1);
	for (int i = 1; i <= m + k; i++) {
		scanf("%lld",&a);
		if (a == 1) {
			scanf("%lld%lld%lld",&b,&c,&d);
			update(1,n,1,b,c,d);
		}
		else {
			scanf("%lld%lld", &b, &c);
			printf("%lld\n",sum(1,n,1,b,c));
		}
	}
}