#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
long long num = 1;
long long n, k;
long long nP;
long long kP;
long long nMkP;
long long bP;
long long even;
long long re;
long long back(long long num) {
	if (num == 0) {
		return 1;
	}
	else if (num == 1) {
		return bP;
	}
	else if (num % 2 == 0) {
		even = back(num / 2);
		re = ((even % MOD) * (even % MOD)) % MOD;
		return re;
	}
	else {
		even = back(num - 1);
		re = ((even % MOD) * (bP % MOD)) % MOD;
		return re;
	}
}
int main() {
	int temp;
	scanf("%lld%lld", &n, &k);
	cin>>temp;
	nP = 1;
	for (int i = 2; i <= n; i++) {
		nP = ((nP % MOD) * (i % MOD)) % MOD;
		cin>>temp;
	}
	kP = 1;

	for (int i = 2; i <= k; i++) {
		kP = ((kP % MOD) * (i % MOD)) % MOD;
		num = ((num%MOD)*(2%MOD))%MOD;
	}

	nMkP = 1;
	for (int i = 2; i <= n - k; i++) {
		nMkP = ((nMkP % MOD) * (i % MOD)) % MOD;
	}

	bP = ((kP % MOD) * (nMkP % MOD)) % MOD;

	long long base = back(MOD - 2);

	long long ans = ((nP % MOD) * (base % MOD)) % MOD;

	ans = ((ans%MOD) * (num%MOD) ) % MOD;

	cout << ans % MOD;
}