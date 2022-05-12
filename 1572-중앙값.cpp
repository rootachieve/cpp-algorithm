#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n,l;
int Count;
int Middle;
int tree[280000];
int in[250001];
void SetT(int s, int e, int node, int target) {
	if (s == e) {
		tree[node]++;
		return;
	}

	int mid = (s + e) / 2;
	tree[node]++;

	if (target <= mid) {
		SetT(s, mid, node * 2, target);
	}
	else {
		SetT(mid + 1, e, node * 2 + 1, target);
	}

}

void SetF(int s, int e, int node, int target) {
	if (s == e) {
		tree[node]--;
		return;
	}

	int mid = (s + e) / 2;
	tree[node]--;
	if (target <= mid) {
		SetF(s, mid, node * 2, target);
	}
	else {
		SetF(mid + 1, e, node * 2 + 1, target);
	}

}

int Find(int s, int e, int node) {
	if (s == e) {
		return s;
	}

	int mid = (s+e)/2;

	if (Count + tree[node * 2] < Middle) {
		Count+=tree[node*2];
		return Find(mid+1,e ,node*2 + 1);
	}else{
		return Find(s,mid,node*2);
	}
}

int main() {
	scanf("%d%d",&n,&l);
	Middle = (l+1)/2;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&in[i]);
	}
	int Max = *max_element(in+1,in+n+1);
	for (int i = 1; i < l; i++) {
		SetT(0,Max,1,in[i]);
	}
	ll ans = 0;
	for (int i = l; i <= n; i++) {
		SetT(0, Max,1,in[i]);
		Count = 0;
		ll temp =(ll)Find(0, Max,1);
		ans+=temp;
		SetF(0, Max,1,in[i-(l-1)]);
	}
	printf("%lld",ans);
}