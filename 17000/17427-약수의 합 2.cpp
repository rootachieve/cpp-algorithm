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

ll sum[1000001];

int main() {
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX / i; j++) {
			sum[i*j]+=j;
		}
	}
	int n;
	scanf("%d",&n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans+=sum[i];
	}
	printf("%lld",ans);
}