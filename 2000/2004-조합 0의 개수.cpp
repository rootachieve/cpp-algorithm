#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
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
ll n,m;

ll fun(ll te, ll re) {
	ll num = re;
	ll temp = 0;
	ll cn = 0;
	while (num <= te) {
		cn += te/num;
		num*=re;
	}

	return cn;
}

int main() {
	cin>>n>>m;
	
	ll A = fun(n,2) - fun(m,2) - fun(n-m,2);
	ll B = fun(n, 5) - fun(m, 5) - fun(n - m, 5);
	printf("%lld",min(A, B));
}