#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
vector<pair<ll,pair<ll,ll>>> input;
vector<int> v[52];
bool complete[52];
int base[52];
bool dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		if (!complete[v[node][i]]) {
			complete[v[node][i]] = true;

			if (base[v[node][i]] == 0 || dfs(base[v[node][i]])) {
				base[v[node][i]]=node;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	ll a,b,c;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b>>c;
		input.push_back({a,{b,c}});
	}

	for (int i = 0; i < n-1; i++) {
		for(int j = i+1;j<n;j++){
			if (input[i].first == input[j].first && input[i].second.first == input[j].second.first && input[i].second.second == input[j].second.second) {
				v[i+1].push_back(j+1);
			}
			else if (input[i].first <= input[j].first &&input[i].second.first <= input[j].second.first &&input[i].second.second <= input[j].second.second) {
				v[j+1].push_back(i+1);
			}else if (input[i].first >= input[j].first &&input[i].second.first >= input[j].second.first &&input[i].second.second >= input[j].second.second) {
				v[i+1].push_back(j+1);
			}
		}
	}
	int ans = n;
	for (int i = 1; i <= n; i++) {
		fill(complete,complete+n+1,false);
		if (dfs(i)) {
			ans--;
		}
		fill(complete, complete + n+1, false);
		if (dfs(i)) {
			ans--;
		}
	}

	cout<<ans;
}