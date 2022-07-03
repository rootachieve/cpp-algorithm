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
ll ans;
int main() {
	cin>>n;
	ll befo = 1;
	ll Count = 10;
	ll num = 1;

	while (n >= Count) {

		ans+=(Count - befo)*num;
		befo = Count;
		Count*=10;
		num++;
	}
	Count/=10;

	ans+=(n -Count + 1)*num;

	printf("%lld",ans);

}