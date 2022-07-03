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

int arr[1001];
int vi[1001];
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
		vi[i] = 10000;
	}
	vi[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (vi[i] != 10000) {
			for (int j = 1; j <= arr[i]&&i+j<=n; j++) {
				vi[i+j] = min(vi[i+j],vi[i] + 1);
			}
		}
	}
	if (vi[n] == 10000) {
		printf("-1");
	}
	else {
		printf("%d",vi[n]);
	}
}