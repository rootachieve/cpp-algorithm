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
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n;
vector<int> v;

bool comp(int a, int b) {
	return a>b;
}
int main() {
	cin>>n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),comp);
	int Max  =0;
	for (int i = 0; i < n; i++) {
		Max = max(Max, i + 1 + v[i]);
	}

	printf("%d",Max + 1);
}