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

int n,m;
vector<int> v;
int main() {
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	int sp = -1001;
	int Count = 0;
	for (int i = 0; i < n; i++) {
		if (sp + m - 1 < v[i]) {
			sp = v[i];
			Count++;
		}
	}

	printf("%d",Count);
}