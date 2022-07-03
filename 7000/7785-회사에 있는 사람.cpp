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


set<string> s;

int main() {
	int n;
	cin >> n;
	string a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (b[0] == 'e') {
			s.insert(a);
		}
		else {
			s.erase(a);
		}
	}
	set<string>::iterator iter = s.end();
	for (iter--; iter != s.begin(); iter--) {
		cout << *iter << "\n";
	}
	cout << *iter << "\n";
}