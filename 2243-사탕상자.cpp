#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <unordered_map>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
using namespace std;
long long Count;
int n,t;
long long tree[4000002];
long long add(long long s, long long e, long long node) {
	if (s == e) {
		return tree[node] = 0;
	}
	long long m = (s + e) / 2;
	return tree[node] = add(s, m, node * 2) + add(m + 1, e, node * 2 + 1);
}

long long get(long long s, long long e, long long node, long long num) {
	if (s == e) {
		tree[node]--;
		return s;
	}
	long long m = (s+e)/2;
	if (tree[node*2]+Count>=num) {
		tree[node]--;
		return get(s, m, node * 2, num);
	}
	else {
		Count+=tree[node*2];
		tree[node]-- ;
		return get(m + 1, e, node * 2 + 1, num);
	}
}


long long change(long long s, long long e, long long node, long long data, long long num) {
	if (s == e && s == data) {
		long long befnode = tree[node];
		tree[node]+=num;
		return num;
	}
	long long m = (s + e) / 2;
	if (m >= data) {

		long long befnode2 = tree[node];
		tree[node] += change(s, m, node * 2, data,num);
		return tree[node] - befnode2;
	}
	else {
		long long  befnode3 = tree[node];
		tree[node] += change(m + 1, e, node * 2 + 1, data,num);
		return tree[node] - befnode3;
	}
}
int main() {
	scanf("%d",&n);
	int type,a,b;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&type);

		if (type == 1) {
			scanf("%d",&a);
			Count = 0;
			printf("%lld\n", get(1, 1000000, 1,a));
		}
		else {
			scanf("%d%d",&a,&b);
			change(1, 1000000,1, a,b);
		}
	}
}