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
struct com {
	bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		else {
			return a.first>b.first;
		}
	}
};
vector<long long> v;
unordered_map<long long ,int> m;
int n,t;
long long tree[300002];
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
	scanf("%d",&t);
	long long x,y;
	while (t--) {

		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, com> pq;
		long long ans = 0;
		m.clear();
		v.clear();
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld",&x,&y);
			pq.push({x,y});
			v.push_back(y);
		}
		sort(v.begin(),v.end());
		int Count = 1;
		for (int i = 0; i < v.size(); i++) {
			if (m.find(v[i]) == m.end()) {
				m.insert({v[i],Count++});
			}
		}
		add(1,Count-1,1);
		while(!pq.empty()){			
			ans+= sum(m.find(pq.top().second)->second, Count-1, 1, 1, Count - 1);
			change(1, Count - 1, 1, m.find(pq.top().second)->second);
			pq.pop();
		}

		printf("%lld\n",ans);
	}
}