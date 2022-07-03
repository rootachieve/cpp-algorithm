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
stack<pair<ll,ll>> s;
pair<ll,ll> base;
ll t,n;
vector<pair<ll,ll>> v;
ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll t = a.second*b.first + b.second*c.first + c.second*a.first 
		- (a.second*c.first+b.second*a.first+c.second*b.first);
	if (t > 0) {
		return 1;
	}
	else if (t == 0) {
		return 0;
	}
	else {
		return -1;
	}
}
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	ll temp = ccw(v[0], a, b);
	if(temp==0){
		return sqrt(pow(a.first-base.first,2)+pow(a.second-base.second,2))
			<
			sqrt(pow(b.first - base.first, 2) + pow(b.second - base.second, 2));
	}
	return temp>0;
}

int main() {
	ll a,b;
	scanf("%d",&n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld%lld",&a,&b);
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	sort(v.begin()+1,v.end(),comp);
	s.push(v[0]);
	s.push(v[1]);
	pair<ll, ll> se;
	for (ll i = 2; i < v.size(); i++) {
		while(s.size()>=2){
			se = s.top();
			s.pop();
			ll temp = ccw(s.top(), se, v[i]);
			if (temp > 0) {
				s.push(se);
				break;
			}
		}
		s.push(v[i]);
	}


	printf("%d",s.size());
}