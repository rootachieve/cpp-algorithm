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
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
vector<pair<int,int>> v;
int main() {
	int n;
	cin>>n;
	int Ymax = 0;
	int Xmax = 0;
	int a,b;
	for (int i = 1; i <= 6; i++) {
		cin>>a>>b;
		if ((a - 1) / 2 == 0) {
			Ymax = max(Ymax,b);
		}
		else {
			Xmax = max(Xmax,b);
		}
		v.push_back({a,b});
	}
	v.insert(v.end(),v.begin(),v.end());
	int Find = 0;
	for (int i = 0;; i++) {
		if ((v[i].second == Ymax && v[i + 1].second == Xmax)|| (v[i].second == Xmax && v[i + 1].second == Ymax)) {
			Find = v[i+3].second*v[i+4].second;
			break;
		}
	}
	cout<<(Ymax*Xmax - Find)*n;
}