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
#define MAX 1000001
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int main() {
	ll a,b;
	cin>>b>>a;
	ll D = a*100/b;
	ll R = D*b +b - 100* a;
	ll L = 99 - D;
	if (L <= 0) {
		printf("-1");
	}
	else {
		ll ans = R/L;
		if ((ans - 1) * L >= R) {
			printf("%lld",ans - 1);
		}
		else if(ans*L>=R){
			printf("%lld",ans);
		}
		else{
			printf("%lld",ans+1);
		}
	}
}