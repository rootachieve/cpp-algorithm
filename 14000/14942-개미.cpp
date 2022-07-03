#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define MOD(x,y,z) (((x)%z)+((y)%z))%z
#define MODF(x,y,z) (((x)%z)*((y)%z))%z
using namespace std;
pair<long long,long long> table[18][100001];
int n;
long long remain[100001];
bool check[100001];
vector<pair<long long, long long>> v[100001];


void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++){
		if (!check[v[node][i].first]) {
			table[0][v[node][i].first] = { node,v[node][i].second };
			dfs(v[node][i].first);
		}
	}
}
int main() {
	long long s,e,d;
	long long a,b;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&remain[i]);
	}

	for (int i = 1; i <= n - 1; i++) {
		scanf("%lld%lld%lld",&s,&e,&d);
		v[s].push_back({e,d});
		v[e].push_back({s,d});
	}

	dfs(1);

	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j].first = table[i-1][table[i-1][j].first].first;
			table[i][j].second = table[i - 1][table[i - 1][j].first].second + table[i - 1][j].second;
		}
	}
	int target;
	for (int i = 1; i <= n; i++) {
		target = i;
		for (int j = 17; j >= 0; j--) {
			if (table[j][target].first != 0 && remain[i] >= table[j][target].second) {
				remain[i] -= table[j][target].second;
				target = table[j][target].first;
			}
		}

		printf("%d\n",target);
	}

}