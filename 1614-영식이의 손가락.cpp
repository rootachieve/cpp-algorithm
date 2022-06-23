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
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

ll n,m;

int main() {
	cin>>n>>m;
	if (m == 0) {
		cout<<n-1;
	}
	else {
		m--;
		ll ans = 5;
		if (n == 1 || n == 5) {
			ans+=m*8;
			n==5? ans+=7 : ans+=3;
			cout<<ans;
		}
		else {
			ans+=m*4;

			if (m % 2 == 0) {
				ans+=4-n;
			}
			else {
				ans+=n-2;
			}

			cout<<ans;
		}
	}
}