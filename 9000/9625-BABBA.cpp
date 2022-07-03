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

ll fibo[49];

int main() {
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= 45; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	int n;
	cin>>n;
	printf("%lld %lld",fibo[n-1],fibo[n]);
}