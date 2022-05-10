#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

ll table[31][100001];
ll in[100001];
ll n,k,m;
int main() {
	scanf("%lld%lld%lld",&n,&k,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&in[i]);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld",&table[0][i]);
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= k; j++) {
			table[i][j] = table[i-1][table[i-1][j]];
		}
	}
	m--;
	ll p = pow((ll)2,(ll)30);
	for (int i = 30; i >= 0; i--) {
		if(m-p>=0){
			for (int j = 1; j <= n;j++) {
				in[j] = table[i][in[j]];
			}

			m -= p;
		}

		p/=2;
	}

	for (int i = 1; i <= n; i++) {
		printf("%lld ",in[i]);
	}
}