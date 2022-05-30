#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

ll n;
bool arr[500001];
vector<ll> v;
int main() {
	cin>>n;
	ll a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
		
	}

	sort(v.begin(),v.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans+=abs(i+1-v[i]);
		
	}

	printf("%lld",ans);
}