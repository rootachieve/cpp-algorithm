#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int n,m;

int main() {
	int Min = 10000000;
	scanf("%d%d",&n,&m);
	int a = 10000000;
	int b = 10000000;
	int c,d;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&c,&d);
		a = min(a,c);
		b = min(b,d);
	}

	if (6 * b > a) {
		if (n % 6 == 0) {
			Min = n/6 * a;
		}
		else {
			Min = min((n / 6) * a + (n % 6) * b, (n/6+1)*a);
		}
	}
	else {
		Min = min(Min, n * b);
	}
	printf("%d",Min);
}