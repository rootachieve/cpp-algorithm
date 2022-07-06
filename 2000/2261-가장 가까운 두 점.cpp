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
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
pair<ll,ll> base[100001];

vector<pair<ll, ll>> v;
int n;
ll Pow(ll num) {
	return num*num;
}

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second<b.second;
}
ll back(int s, int e) {
	int r = e-s+1;
	if (r == 2) {
		return Pow(base[s].first - base[e].first) + Pow(base[s].second -base[e].second);
	}
	else if(r==3){
		return min({Pow(base[s].first - base[s+1].first) + Pow(base[s].second - base[s+1].second),Pow(base[s+1].first - base[e].first) + Pow(base[s+1].second - base[e].second),Pow(base[e].first - base[s].first) + Pow(base[e].second - base[s].second)});
	}
	else {
		int m = (s+e)/2;
		ll a = min(back(s,m), back(m+1,e));
		v.clear();
		ll line = (base[m].first+base[m+1].first)/2;
		for (int i = s; i <= e; i++) {
			if (Pow(line - base[i].first) < a) {
				v.push_back(base[i]);
			}
		}
		int len = v.size();

		sort(v.begin(),v.end(),comp);
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (Pow(v[i].second - v[j].second) >= a) {
					break;
				}
				a = min(a, Pow(v[i].first - v[j].first) + Pow(v[i].second - v[j].second));
			}
		}
		return a;
	}
}
int main(){
	scanf("%d",&n);
	ll a,b;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld",&a,&b);
		base[i] = {a,b};
	}

	sort(base+1,base+1+n);



	ll ans = back(1,n);

	printf("%lld", ans);
	
}