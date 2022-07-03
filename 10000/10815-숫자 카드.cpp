#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>
#include <algorithm>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
vector<ll> v;
int n,m;

int main() {
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) {
		scanf("%d",&a);
		vector<ll>::iterator iter = lower_bound(v.begin(), v.end(), a);
		if (iter != v.end()) {
			if (*iter == a) {
				printf("1 ");
				continue;
			}
		}
		printf("0 ");
	}
}