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
long long in[500020];

long long temp[500020];
unordered_map<long long,int> m;

int n;
long long tree[2000002];
long long add(long long s, long long e, long long node) {
	if (s == e) {
		return tree[node] = 0;
	}
	long long m = (s + e) / 2;
	return tree[node] = add(s, m, node * 2) + add(m + 1, e, node * 2 + 1);
}

long long sum(long long s, long long e, long long node, long long nodel, long long noder) {
	if (e<nodel || s>noder) {
		return 0;
	}
	if (s <= nodel && noder <= e) {
		return tree[node];
	}
	long long m = (noder + nodel) / 2;
	long long a = sum(s, e, node * 2, nodel, m) + sum(s, e, node * 2 + 1, m + 1, noder);
	return a;
}

long long change(long long s, long long e, long long node, long long data) {
	if (s == e && s == data) {
		long long befnode = tree[node];
		tree[node]++;
		return 1;
	}
	long long m = (s + e) / 2;
	if (m >= data) {

		long long befnode2 = tree[node];
		tree[node] += change(s, m, node * 2, data);
		return tree[node] - befnode2;
	}
	else {
		long long  befnode3 = tree[node];
		tree[node] += change(m + 1, e, node * 2 + 1, data);
		return tree[node] - befnode3;
	}
}
int main() {
	scanf("%d",&n);
	for (int h = 0; h < n; h++) {
		scanf("%lld",&in[h]);
		temp[h] = in[h];
	}

	sort(temp,temp+n);

	for (int i = 1; i <= n; i++) {
		m.insert({temp[i-1],i});
	}

	add(1,n,1);
	for (int i = 0; i < n; i++) {
		int Count = sum(1,m.find(in[i])->second,1,1,n);
		printf("%d\n",i+1-Count);
		change(1,n,1, m.find(in[i])->second);
	}

}