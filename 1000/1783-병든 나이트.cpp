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

ll n,m;

int main() {
	cin>>n>>m;
	

	if (n >= 3 && m >= 7) {
		ll ans = 5;
		m-=7;
		printf("%lld",ans+m);
	}
	else {
		if (n >= 3) {
			printf("%lld",min(m,4ll));
		}
		else {
			if (n == 1) {
				printf("1");
			}
			else {
				printf("%lld",min(4ll,(m+1)/2));
			}
		}
	}
}