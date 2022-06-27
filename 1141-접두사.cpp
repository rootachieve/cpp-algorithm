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
vector<string> v;

bool cop(string a, string b) {
	return a.size()<b.size();
}
int main(){
	int n;
	cin>>n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cop);
	bool err =false;
	int ans = 0;
	for (int i = 0; i < n; i++) {

		bool err = false;
		
		for (int j = i+1; j < n; j++) {
			if (v[i].size() <= v[j].size()) {
				for (int k = 0; k <= v[i].size(); k++) {
					if (k == v[i].size()) {
						err = true;
						break;
					}

					if (v[i][k] != v[j][k]) {
						break;
					}
				}
			}

			if (err) {
				break;
			}
		}

		if (!err) {
			ans++;
		}
	}

	cout<<ans;
}