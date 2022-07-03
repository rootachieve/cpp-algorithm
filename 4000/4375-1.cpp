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

int arr[10001];
bool arr2[10001];
ll num;
int main() {
	ll Cnt;
	ll n;
	while (scanf("%lld", &n) != EOF) {
		num = 1;
		Cnt = 1;
		while (num % n != 0) {
			num = (num*10 % n + 1) %n;
			Cnt++;
		}

		printf("%lld\n",Cnt);
	}
}