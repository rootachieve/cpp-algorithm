#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

ll Count;
long long tree[400002];
long long init(long long s, long long e, long long node) {
	if (s == e) {
		return tree[node] = 1;
	}
	long long m = (s + e) / 2;
	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

long long get(long long s, long long e, long long node, long long num) {
	if (s == e) {
		tree[node] = 0;
		return s;
	}
	long long m = (s + e) / 2;
	tree[node]--;
	if (Count + tree[node * 2] <= num) {
		Count += tree[node*2];
		return get(m+1,e,node*2+1,num);
	}
	else{
		return get(s,m,node*2,num);
	}
}

int n;
int table[100001];
int main() {
	scanf("%d",&n);
	init(1,n,1);

	int num;
	for (int i = 1; i <= n; i++) { 
		scanf("%d",&num);
		Count = 0;
		int node = get(1,n,1,num);
		table[node] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n",table[i]);
	}
}