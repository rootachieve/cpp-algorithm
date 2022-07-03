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

ll arr[100001];

int main() {
	int n;
	scanf("%d",&n);
	ll a;
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a);
		arr[i] = arr[i-1] + a;
	}
	ll m;
	ll b;
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",arr[b] - arr[a-1]);
	}
}