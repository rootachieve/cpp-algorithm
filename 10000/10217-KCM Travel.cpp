#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
struct com {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		return a.first>b.first;
	}
};
priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>> , com> pq;
int D[10001][101];
vector<pair<int,pair<int,int>>> v[101];
int t,n,m,k;
int main() {
	scanf("%d",&t);
	for (int h = 1; h <= t; h++) {
		
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				D[j][i] = 100000001;
			}
			v[i].clear();
		}
		D[0][1] = 0;
		int a,b,c,d;
		for (int i = 1; i <= k; i++) {
			scanf("%d%d%d%d",&a,&b,&c,&d);
			v[a].push_back({b,{c,d}});
		}
		pq.push({0,{1,0}});
		while (!pq.empty()) {
			int node = pq.top().second.first;
			int cost = pq.top().first;
			int time = pq.top().second.second;
			pq.pop();
			if (D[cost][node] < time) {
				continue;
			}
			for (int i = 0; i < v[node].size(); i++) {
				if (cost + v[node][i].second.first <=m &&D[cost + v[node][i].second.first][v[node][i].first] >time + v[node][i].second.second) {
					D[cost + v[node][i].second.first][v[node][i].first] = time + v[node][i].second.second;
					pq.push({ cost + v[node][i].second.first,{v[node][i].first, time + v[node][i].second.second}});
				}
			}
			
		}
		int Min = 1000001;
		for (int i = 0; i <= m; i++) {
			if (Min > D[i][n]) {
				Min = D[i][n];
			}
		}

		if(Min < 1000001){
			printf("%d\n",Min);
		}
		else {
			printf("Poor KCM\n");
		}

	}
}
