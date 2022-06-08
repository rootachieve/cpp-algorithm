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
unordered_set<int> s;
vector<int> v,ans;
int n,m;
int main() {
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}

	for (int i = 1; i <= m; i++) {
		cin>>a;
		s.insert(a);
	}

	for (int i = 0; i < n; i++) {
		if (s.find(v[i]) == s.end()) {
			ans.push_back(v[i]);
		}
	}

	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ",ans[i]);
	}
}