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
set<int> s;
int ans1;
int ans2;
int main() {
	int n,m;
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		s.insert(a);
	}
	ans1 = n;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		if (s.find(a) == s.end()) {
			ans2++;
		}
		else {
			ans1--;
		}
	}

	cout<<ans1+ans2;
}