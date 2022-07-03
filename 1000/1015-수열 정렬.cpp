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

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

vector<pair<int,int>> v;
int ans[52];
int main() {
int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d",&a);

		v.push_back({a,i});
	}

	stable_sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		ans[v[i].second]=i;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ",ans[i]);
	}
}