#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
#define MAX 1000002;
using namespace std;

long long D[1002][1002];//node count value
priority_queue<pair<long long,pair<int,int>>,vector<pair<long long, pair<int, int>>>,greater< pair<long long, pair<int, int>>>> pq;
vector<pair<int,long long>> v[1002];
long long tree[2004];
int n,m,k;
int s,e;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] = MAX;
		}
	}

	scanf("%d%d", &s, &e);
	D[0][s] = 0;

	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	pq.push({0,{0,s}});
	while (!pq.empty()) {
		int node = pq.top().second.second;
		long long value = pq.top().first;
		int Count = pq.top().second.first;
		pq.pop();

		if (D[Count][node] < value) {
			continue;
		}

		for (int i = 0; i < v[node].size(); i++) {
			if (D[Count + 1][v[node][i].first] > value + v[node][i].second) {
				D[Count + 1][v[node][i].first] = value + v[node][i].second;
				pq.push({ D[Count + 1][v[node][i].first],{Count+1,v[node][i].first}});
			}
		}
	}
	long long Min = MAX;
	for (int j = 1; j <= n; j++) {
		Min = min(Min, D[j][e]);
	}
	printf("%lld\n", Min);
	for (int i = 1; i <= k; i++) {
		scanf("%d",&a);
		Min = MAX;
		for (int j = 1; j <= n; j++) {
			D[j][e] += (j*a);
			Min = min(Min, D[j][e]);
		}
		printf("%lld\n", Min);
	}
}