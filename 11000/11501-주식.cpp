#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
//#include <stack>
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

ll arr[3000003];

int main() {
	int t;
	scanf("%d",&t);
	int n;
	while (t--) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			scanf("%d",&arr[i]);
		}
		ll sum = 0;

		ll top = 0;
		for (int i = n; i > 0; i--) {
			if (i == n) {
				top = arr[i];
			}
			else {
				if (arr[i] > top) {
					top = arr[i];
				}
				else {
					sum+=top - arr[i];
				}
			}
		}
		printf("%lld\n",sum);
	}
}