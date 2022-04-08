#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 500002
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> pq;
int n,m;
int s,e;
long long D[502];

long long AlmostD[502];
queue<int> check[502];

bool comp(const pair<long long, long long> &a,const  pair<long long, long long> &b) {
	return a.first<b.first;
}
vector<pair<long long,long long>> v[502];

void del(int node) {
	int top;
	while (!check[node].empty()) {
		 top = check[node].front();
		 check[node].pop();
		 v[top].erase(lower_bound(v[top].begin(),v[top].end(),pair<long long, long long>(node,0),comp));
		 del(top);
	}
}
int main() {

	int a, b, c;
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0) {
			break;
		}
		scanf("%d%d",&s,&e);
		s++;
		e++;
		for (int i = 1; i <= n; i++) {
			D[i] = MAX;
			AlmostD[i] = MAX;
			v[i].clear();
			while (!check[i].empty()) {
				check[i].pop();
			}
		}
		D[s] = 0;
		AlmostD[s] = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d",&a,&b,&c);
			v[a+1].push_back({b+1,c});
		}

		for (int i = 1; i <= n; i++) {
			sort(v[i].begin(),v[i].end());
		}
		pq.push({0LL,s});
		while (!pq.empty()) {
			long long value = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			if (value > D[node]) {
				continue;
			}
			for (int i = 0; i < v[node].size(); i++) {
				if (D[v[node][i].first] > value + v[node][i].second) {
					D[v[node][i].first] = value + v[node][i].second;
					while (!check[v[node][i].first].empty()) {
						check[v[node][i].first].pop();
					}
					check[v[node][i].first].push(node);
					pq.push({ D[v[node][i].first] ,v[node][i].first });
				}
				else if (D[v[node][i].first] == value + v[node][i].second) {
					check[v[node][i].first].push(node);
				}
			}
		}

		if (D[e] == MAX) {
			printf("-1\n");
		}
		else {
			del(e);

			pq.push({ 0LL,s });
			while (!pq.empty()) {
				long long value = pq.top().first;
				int node = pq.top().second;
				pq.pop();

				if (value > AlmostD[node]) {
					continue;
				}
				for (int i = 0; i < v[node].size(); i++) {
					if (AlmostD[v[node][i].first] > value + v[node][i].second) {
						AlmostD[v[node][i].first] = value + v[node][i].second;
						pq.push({ AlmostD[v[node][i].first] ,v[node][i].first });
					}
				}
			}

			if (AlmostD[e] == MAX) {
				printf("-1\n");
			}
			else {
				printf("%lld\n", AlmostD[e]);
			}
		}

	}

}