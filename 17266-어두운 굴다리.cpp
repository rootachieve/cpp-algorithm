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
	int n;
	int m;
	cin>>n>>m;
	int a;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());
	int Max = 0;
	for (int i = 1; i < m-1; i++) {
		int l,r;
		(v[i] - v[i-1]) % 2 == 0? l = (v[i] - v[i-1])/2 : l = (v[i] - v[i - 1]) / 2 + 1;
		(v[i + 1] - v[i]) % 2 == 0 ? r = (v[i + 1] - v[i]) / 2 : r = (v[i + 1] - v[i]) / 2 + 1;
		Max = max(Max,max(l,r));
	}

	Max = max(max(v[0],n-v[m-1]),Max);
	cout<<Max;

}