#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
vector<int> v;
int main() {
	int Min = 10e9;

	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin>>a;
		Min = min(a,Min);
		v.push_back(Min);
	}
	int index = 0;
	bool err = false;
	int loc;
	reverse(v.begin(),v.end());
	for (int i = 1; i <= m; i++) {
		int a;
		cin>>a;
		int find = lower_bound(v.begin()+index,v.end(),a) - v.begin();

		if (find == n) {
			err = true;
			break;
		}
		else {
			index = find+1;
			loc = find;
		}
	}

	if (err) {
		cout<<0;
	}
	else {
		cout<<n-loc;
	}



}