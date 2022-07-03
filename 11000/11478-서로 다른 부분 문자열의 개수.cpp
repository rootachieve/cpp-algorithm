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

string in;
set<string> s;

int main() {
	cin>>in;
	int ans = 0;
	for (int i = 0; i < in.size(); i++) {
		string temp;
		for (int j = i; j < in.size(); j++) {
			temp.push_back(in[j]);
			if (s.find(temp) == s.end()) {
				s.insert(temp);
				ans++;
			}
		}
	}

	cout<<ans;
}