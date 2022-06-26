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
int n,m,k;
int map[101][101];
vector<pair<int,int>> v;
int main() {
	cin>>n>>m>>k;
	int a,b;
	for (int i = 1; i <= k; i++) {
		cin>>a>>b;
		v.push_back({a,b});
		if (a != b) {
			v.push_back({b,a});
		}
		else {
			v.push_back({101,101});
		}
	}
	int Max = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first <= n && v[i].second <= m) {
			int now = v[i].first*v[i].second;
			for (int g = 1; g <= v[i].first; g++) {
				for (int h = 1; h <= v[i].second; h++) {
					map[g][h] = 1;
				}
			}

			for (int j = (i / 2 + 1) * 2; j < v.size(); j++) {
				if (v[j].first <= n && v[j].second <= m) {
					bool err =false;
					for (int g = n; g >= n - v[j].first + 1; g--) {
						for (int h = m; h >= m - v[j].second + 1; h--) {
							if(map[g][h]==1){
								err= true;
							}
						}
					}
					if (!err) {
						Max = max(Max,now+v[j].first*v[j].second);
					}
				}
			}
			for (int g = 1; g <= v[i].first; g++) {
				for (int h = 1; h <= v[i].second; h++) {
					map[g][h] = 0;
				}
			}
		}
	}

	cout<<Max;

}