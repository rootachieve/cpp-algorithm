#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

ll n,m;

ll gcd(ll a,ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b,a%b);
	}
}

int main() {
	ll t;
	cin>>t;
	while (t--) {
		cin>>n>>m;
		printf("%lld\n",n*m/gcd(n,m));
	}
}