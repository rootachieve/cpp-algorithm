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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

pair<ll,ll> parent[20001];
void merge(ll a, ll b) {
	parent[a] = {b,abs(a-b)%MOD};
}

pair<ll,ll> find(ll a) {
	if (parent[a].first == a) {
		return {a,0};
	}

	pair<ll,ll> y = find(parent[a].first);
	parent[a] = {y.first,y.second + parent[a].second};
	return parent[a];
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string a;
	ll b,c;
	ll n;
	while (t--) {
		cin>>n;
		for (ll i = 1; i <= n; i++) {
			parent[i] ={i,0};
		}

		while (1) {
			cin>>a;
			if (a[0] == 'O') {
				break;
			}
			else if (a[0] == 'E') {
				cin>>b;
				cout<<find(b).second<<"\n";
			}
			else {
				cin>>b>>c;
				merge(b,c);
			}
		}
	}
}
