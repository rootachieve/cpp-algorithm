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

int parent[100002];
ll value[100002];
int n,m;

pair<int, ll> find(int x,ll v) {
	if (parent[x] == x) {
		return {x,0};
	}

	pair<int,ll> y = find(parent[x],0);
	value[x] += value[parent[x]];
	parent[x] = y.first;
	return {y.first,value[x]};
}

void merge(int x, int y,ll z) {
	pair<int,ll> a = find(x,0);
	pair<int,ll> b = find(y,0);
	ll temp = a.second + z - b.second;
	if (temp>=0) {//a의 부모가 더 가벼움
		parent[b.first] = a.first;
		value[b.first] = temp;
	}
	else {
		parent[a.first] = b.first;
		value[a.first] = abs(temp);
	}
}
int main() {
	char a[3];
	
	while (1) {
		scanf("%d%d",&n,&m);
		if (n == 0) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			value[i] = 0;
			parent[i] = i;
		}

		for (int i = 1; i <= m; i++) {
			ll b = 0;
			ll c = 0;
			ll d = 0;
			scanf("%s",&a);
			if (a[0] == '!') {
				scanf("%lld%lld%lld",&b,&c,&d);

				if (find(b,0).first != find(c,0).first) {
					merge(b,c,d);
				}
			}
			else {
				scanf("%lld%lld", &b, &c);

				if (find(b, 0).first != find(c, 0).first) {
					printf("UNKNOWN\n");
				}
				else {
					printf("%lld\n",value[c]-value[b]);
				}

			}
		}
	}
}