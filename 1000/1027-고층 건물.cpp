#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b,a%b);
	}
}
long long lcm(long long a, long long b) {
	return a* b/ gcd(a,b);
}

int n;
long long base[52];

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&base[i]);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int Count = 0;
		long long top = MAX;
		long long bot = 1;
		long long l = 0;
		for (long long j = i - 1; j >= 1; j--) {
			l = lcm(i-j,bot);
			if ((l / bot) * top > (l / (i - j) * (base[i]-base[j]))) {
				top = base[i] - base[j];
				bot = i-j;
				Count++;
			}

		}
		top = -MAX;
		bot = 1;
		for (long long j = i + 1; j <= n; j++) {
			l = lcm(j - i, bot);
			if ((l / bot) * top < (l / (j - i) * (base[j] - base[i]))) {
				top = base[j] - base[i];
				bot = j - i;
				Count++;
			}

		}
		answer = max(Count,answer);
	}

	printf("%d",answer);
}
