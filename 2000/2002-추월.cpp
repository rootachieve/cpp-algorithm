#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
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

unordered_map<string,int> m;
int n;
string temp;
int ans;
vector<string>v;
int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		m.insert({temp,i});
	}

	for (int i = 1; i <= n; i++) {
		cin>>temp;
		v.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (m[v[i]] > m[v[j]]) {
				ans++;
				break;
			}
		}

	}

	printf("%d",ans);
}