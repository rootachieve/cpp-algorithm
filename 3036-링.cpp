#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
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

ll befoU = 1;
ll befoB = 1;
int arr[101];
int n;
ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b,a%b);
	}
}

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}
	ll temp;
	ll g;
	for (int i = 2; i <= n; i++) {
		befoU = befoU*arr[i-1];
		befoB = befoB*arr[i];

		
		g = gcd(befoU,befoB);
		befoU/=g;
		befoB/=g;

		printf("%lld/%lld\n",befoU,befoB);
	}
}