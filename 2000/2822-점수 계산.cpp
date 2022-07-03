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

int a;
vector<pair<int,int>> v;
vector<int> ans;
int sum;
bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first>b.first;
}
int main() {
	for (int i = 1; i <= 8; i++) {
		cin>>a;
		v.push_back({a,i});
	}
	stable_sort(v.begin(),v.end(),comp);

	for (int i = 0; i < 5; i++) {
		ans.push_back(v[i].second);
		sum+=v[i].first;
	}
	cout<<sum<<endl;
	sort(ans.begin(),ans.end());
	for (int i = 0; i < 5; i++) {
		cout<<ans[i];
		cout<< " ";
	}

	
}