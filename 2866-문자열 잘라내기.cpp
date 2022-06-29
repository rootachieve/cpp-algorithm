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

string arr[1001];
vector<string> v;
set<string> s;
int n,m;
int main() {
	cin>>n>>m;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		v.push_back(temp);
	}

	reverse(v.begin(),v.end());

	for (int i = 0; i < n; i++) {
		bool err = false;
		s.clear();
		for (int j = 0; j < m; j++) {
			arr[j]+=v[i][j];
			if (s.find(arr[j]) == s.end()) {
				s.insert(arr[j]);
			}
			else {
				err = true;
			}
		}

		if (!err) {
			cout<<n-(i+1);
			break;
		}
	}

}