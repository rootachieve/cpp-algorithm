#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
vector<pair<int,int>> v[2501];

priority_queue<pair<ll,pair<ll,ll>>> pq;
ll base[2501];
ll map[2501][2501];
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>base[i];
	}

	ll a,b,c;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}

	map[1][1] = 1;
	pq.push({-1,{1,1}});
	ll cost,node,use,target,dist;
	while (!pq.empty()) {
		cost = -pq.top().first;
		node = pq.top().second.first;
		use = pq.top().second.second;
		pq.pop();
		if (map[node][use] < cost) {
			continue;
		}
		if (node == n) {
			break;
		}

		for (int i = 0; i < v[node].size(); i++) {
			target = v[node][i].first;
			dist = v[node][i].second;
			if (map[target][use] == 0 || map[target][use] > cost + dist * base[use]) {
				map[target][use] = cost + dist*base[use];
				pq.push({-map[target][use],{target,use}});
			}

			if (node != use&&base[node]<base[use]) {
				if (map[target][node] == 0 || map[target][node] > cost + dist * base[node]) {
					map[target][node] = cost + dist * base[node];
					pq.push({ -map[target][node],{target,node} });
				}
			}
		}
	}

	ll Min = 1e17;
	for (int i = 1; i <= n; i++) {
		if (map[n][i] != 0) {
			Min = min(Min,map[n][i]);
		}
	}

	cout<<Min - 1;
}