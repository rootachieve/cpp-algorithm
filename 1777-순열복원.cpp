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

int tree[400001];
int n;
int in[100001];
int ans[100001];
int Count;

int Find(int s, int e, int node, int target) {
	if (s == e) {
		tree[node] = 0;
		return s;
	}
	int m = (s+e)/2;
	tree[node]--;
	if (Count + tree[node * 2 + 1] <= target) {
		Count+=tree[node*2+1];
		return Find(s,m,node*2,target);
	}
	else {
		return Find(m+1,e,node*2+1,target);
	}
}

int init(int s, int e, int node) {
	if (s == e) {
		tree[node] = 1;
		return 1;
	}

	int m = (s+e)/2;

	return tree[node] = init(s,m,node*2) + init(m+1,e,node*2+1);
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&in[i]);
	}

	init(1,n,1);
	
	for (int i = n; i >= 1; i--) {
		Count = 0;
		int temp = Find(1,n,1,in[i]);
		ans[temp] = i;
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ",ans[i]);
	}
}
