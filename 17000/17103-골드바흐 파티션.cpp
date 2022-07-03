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

bool isPrime[MAX+1];
int main() {
	int t;
	for (int i = 2; i * 2 <= MAX; i++) {
		if (!isPrime[i]) {
			for (int j = i + i; j <= MAX; j+=i) {
				isPrime[j] = true;
			}
		}
	}
	int a;
	int cnt;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&a);
		cnt = 0;
		for (int i = 2; i <= a / 2; i++) {
			if (!isPrime[i]) {
				if (!isPrime[a - i]) {
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}