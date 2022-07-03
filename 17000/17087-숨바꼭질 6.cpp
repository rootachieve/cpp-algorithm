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

int n,m;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b,a%b);
	}
}

int main() {
	int ans;
	scanf("%d%d",&n,&m);
	scanf("%d",&ans);
	ans = abs(m-ans);
	int temp;
	for (int i = 2; i <= n; i++) {
		scanf("%d",&temp);
		ans = gcd(ans,abs(m-temp));
	}

	printf("%d",ans);
}