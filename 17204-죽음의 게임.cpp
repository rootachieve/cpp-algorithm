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
vector<int> v[150];
int n,m;
bool visit[150];
bool err =false;
int ans = 0;
void back(int num,int d) {
	if (visit[num]) {
		err = true;
		return;
	}
	if (num == m) {
		ans = d;
		return;
	}
	visit[num] = true;
	back(v[num][0],d+1);
}

int main() {
	cin>>n>>m;
	int a;
	for (int i = 0; i < n; i++) {
		cin>>a;
		v[i].push_back(a);
	}

	back(0,0);

	if (err) {
		cout<<"-1";
	}
	else {
		cout<<ans;
	}
}