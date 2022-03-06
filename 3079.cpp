#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MOD 1000000007
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD
#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD
using namespace std;
int n;
long long m;
long long base[100002];
int main() {
	scanf("%d%lld",&n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%lld",&base[i]);
	}

	long long s = 0;
	long long e = m*(*max_element(base,base+n));
	long long ans = m * (*max_element(base, base + n));
	while (s <= e) {
		long long mid = (s+e)/2;
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			temp+=mid/base[i];
		}

		if (temp >= m) {
			ans = min(ans,mid);
			e = mid-1;
		}
		else {
			s = mid+1;
		}
	}

	printf("%lld",ans);
}