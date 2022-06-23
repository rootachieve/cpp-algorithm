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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
set<string> s;

string in;
void check(int index1, int index2) {
	string temp ="";
	for (int i = index1 - 1; i >= 0; i--) {
		temp+=in[i];
	}
	for (int i = index2 - 1; i >= index1; i--) {
		temp += in[i];
	}
	for (int i = in.size() - 1; i >= index2; i--) {
		temp+=in[i];
	}

	if (s.find(temp) == s.end()) {
		s.insert(temp);
	}
}

int main() {
	cin>>in;
	for (int i = 1, l = in.size() - 1; i < l; i++) {
		for (int j = i + 1; j <= l; j++) {
			check(i,j);
		}
	}

	cout<<*s.begin();
}