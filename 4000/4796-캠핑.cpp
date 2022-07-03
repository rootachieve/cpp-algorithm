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

ll p,l,v;

int main() {
	int cnt = 0;
	while (1) {
		scanf("%lld%lld%lld", &p, &l, &v);
		if (l == 0) {
			break;
		}
		cnt++;
		printf("Case %d: %lld\n",cnt,v/l * p + min(v%l,p));
	}
}