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

vector<int> v;
int main() {
	int n,m;
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	a = 0 ;
	int b =n-1;
	int ans = 0;
	while (a < b) {
		if (v[a] + v[b] == m) {
			a++;
			b--;
			ans++;
		}
		else if (v[a] + v[b] < m) {
			a++;
		}
		else {
			b--;
		}
	}

	cout<<ans;
}