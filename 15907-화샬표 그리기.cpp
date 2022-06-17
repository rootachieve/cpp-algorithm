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

vector<int> v[5001];
int main() {
	int a,b,n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b;
		v[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(v[i].begin(),v[i].end());
	}
	int ans = 0;
	for(int j = 1;j<=n;j++){
		for (int i = 0; i < v[j].size(); i++) {
			if (v[j].size() == 1) {
				break;
			}
			if (i == 0) {
				ans+=v[j][1]-v[j][0];
			}
			else if(i==v[j].size()-1){
				ans+=v[j][i] - v[j][i-1];
			}else{
				ans+=min(abs(v[j][i-1]-v[j][i]),abs(v[j][i]-v[j][i+1]));
			}
		}
	}

	cout<<ans;
}