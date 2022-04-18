#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 5000002
using namespace std;
vector<pair<int,ll>> v[100002];
int Rank[100002];
bool visit[100002];
pair<int,pair<ll,ll>>table[18][100002];
int n,m;
void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i].first] == false) {
			Rank[v[node][i].first] = Rank[node]+1;
			table[0][v[node][i].first] = {node,{v[node][i].second,v[node][i].second}};
			dfs(v[node][i].first);
		}
	}
}


void make_table() {
	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j] = {table[i-1][table[i-1][j].first].first,
				{ 
				  max(table[i-1][j].second.first,table[i-1][table[i-1][j].first].second.first),
				  min(table[i - 1][j].second.second,table[i - 1][table[i - 1][j].first].second.second)
				}
			};
		}
	}
}
int main() {
	int a,b;
	ll c;
	scanf("%d",&n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%lld",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}

	dfs(1);
	make_table();

	scanf("%d",&m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		ll MaxA = 0;
		ll MinA = MAX;
		ll MaxB = 0;
		ll MinB = MAX;
		if (Rank[a] > Rank[b]) {
			int c = Rank[a] - Rank[b];
			int Count = 0;
			while (c > 0) {
				if ((c & 1) == 1) {
					MaxA = max(MaxA,table[Count][a].second.first);
					MinA = min(MinA,table[Count][a].second.second);
					a = table[Count][a].first;
				}
				c = c >> 1;
				Count++;
			}
		}

		if (Rank[b] > Rank[a]) {
			int c = Rank[b] - Rank[a];
			int Count = 0;
			while (c > 0) {
				if ((c & 1) == 1) {
					MaxB = max(MaxB, table[Count][b].second.first);
					MinB = min(MinB, table[Count][b].second.second);
					b = table[Count][b].first;
				}
				c = c >> 1;
				Count++;
			}
		}


		if (a != b) {
			for (int i = 17; i >= 0; i--) {
				if (table[i][a].first != table[i][b].first) {
					MaxA = max(MaxA, table[i][a].second.first);
					MinA = min(MinA, table[i][a].second.second);
					MaxB = max(MaxB, table[i][b].second.first);
					MinB = min(MinB, table[i][b].second.second);
					a = table[i][a].first;
					b = table[i][b].first;
				}
			}

			while (a != b) {
				MaxA = max(MaxA, table[0][a].second.first);
				MinA = min(MinA, table[0][a].second.second);
				MaxB = max(MaxB, table[0][b].second.first);
				MinB = min(MinB, table[0][b].second.second);
				a = table[0][a].first;
				b = table[0][b].first;
			}
		}

		printf("%lld %lld\n",min(MinA,MinB),max(MaxA,MaxB));
	}
}