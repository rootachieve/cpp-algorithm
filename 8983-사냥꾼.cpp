#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n,m;
long long l;
long long base[100002];
int main() {
	scanf("%d%d%lld",&n,&m,&l);
	for (int i = 0; i < n; i++) {
		scanf("%lld",&base[i]);
	}

	sort(base,base+n);
	long long a,b;
	int answer= 0;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld",&a,&b);
		if (b <= l) {
			int index = lower_bound(base,base+n,a) - base;
			
				if (index != 0&&abs(base[index - 1]-a) + b <= l) {
					answer++;
				}
				else {
					if (index != n&&abs(base[index]-a) + b <= l) {
							answer++;
						
					}
				}
			
		}
	}
	printf("%d",answer);
}