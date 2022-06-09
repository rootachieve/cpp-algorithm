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

int n;
int arr[1500002];

int main() {
	scanf("%d",&n);
	int a,b;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d",&a,&b);
		ans = max(ans,arr[i]);
		if (i + a <= n+1) {
			arr[i+a] = max(arr[i+a],ans + b);
		}
	}

	printf("%d",max(ans,arr[n+1]));
}