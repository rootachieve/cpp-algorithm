#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
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

vector<int> v;
int n;
int a;

bool comp(int a, int b) {
	return a>b;
	}
int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		v.clear();
		for (int j = 1; j <= 10; j++) {
			cin>>a;
			v.push_back(a);
		}

		sort(v.begin(),v.end(),comp);
		printf("%d\n",v[2]);
	}
}