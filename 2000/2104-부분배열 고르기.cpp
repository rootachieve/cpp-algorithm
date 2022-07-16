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
#define MOD 1000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

pair<int,int> minT[400001];
ll sumT[400001];
ll value[100001];

int n;
void init(int s, int e, int node) {
	if (s == e) {
		minT[node] = {value[s],s};
		sumT[node] = value[s];
	}
	else {
		int m =(s+e)/2;
		init(s,m,node*2);
		init(m+1,e,node*2+1);

		sumT[node] = sumT[node*2]+sumT[node*2+1];
		minT[node] = minT[node*2].first < minT[node*2+1].first ? minT[node*2] : minT[node*2+1];
	}
}

ll Sum(int s, int e, int l, int r, int node) {
	if (e < l || r < s) {
		return 0;
	}
	else if (l <= s && e <= r) {
		return sumT[node];
	}
	else {
		int m = (s+e)/2;
		return Sum(s,m,l,r,node*2) + Sum(m+1,e,l,r,node*2+1);
	}
}


pair<int, int> Min(int s, int e, int l, int r, int node) {
	if (e < l || r < s) {
		return {2000000,0};
	}
	else if (l <= s && e <= r) {
		return minT[node];
	}
	else {
		int m = (s + e) / 2;
		pair<int,int> a,b;
		a = Min(s,m,l,r,node*2);
		b = Min(m+1,e,l,r,node*2+1);
		if (a.first < b.first) {
			return a;
		}
		else {
			return b;
		}
	}
}



ll back(int s, int e) {
	if (s == e) {
		return value[s]*value[s];
	}
	else {
		pair<int,int> M = Min(1,n,s,e,1);
		ll Max = Sum(1,n,s,e,1) * M.first;
		if (s <= M.second - 1) {
			Max = max(Max,back(s,M.second-1));
		}

		if (M.second + 1 <= e) {
			Max = max(Max, back(M.second + 1, e));
		}

		return Max;
	}
}

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>value[i];
	}

	init(1,n,1);

	cout<<back(1,n);
}