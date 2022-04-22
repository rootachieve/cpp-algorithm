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
#define MAX 2000000001;
using namespace std;

priority_queue<pair<ll,int>,vector< pair<ll, int>>,greater< pair<ll, int>>> pq;
ll n,m,k;
priority_queue<ll> D[1001];
vector<pair<ll,int>> v[1001];
int main() {
	ll a, b, c;
	scanf("%lld%lld%lld",&n,&m,&k);
	D[1].push(0);
	pq.push({0,1});
	for(int i = 1;i<=m;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		v[a].push_back({c,b});
	}

	while (!pq.empty()) {
		int node = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int t = v[node][i].second;
			ll u = v[node][i].first;

			if (D[t].size() >= k) {
				if (D[t].top() > cost + u) {
					D[t].pop();
					D[t].push(cost+u);
					pq.push({cost+u,t});
				}
			}
			else {
				D[t].push(cost + u);
				pq.push({ cost + u,t });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (D[i].size() < k) {
			printf("-1\n");
		}
		else {
			printf("%lld\n",D[i].top());
		}
	}
}