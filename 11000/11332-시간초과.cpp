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

ll limit[5] = { 1000000001,31623,1001,30,13};

ll check(ll num, ll type) {
	if (type == 1) {
		return num;
	}
	else if (type == 2) {
		return pow(num, 2LL);
	}
	else if (type == 3) {
		return pow(num, 3LL);
	}
	else if (type == 4) {
		return pow(2LL, num);
	}
	else {
		ll temp = 1;
		for (int i = 1; i <= num; i++) {
			temp *= i;
		}

		return temp;
	}
}


int main() {
	int n;
	cin >> n;
	string temp;
	ll a, b, c;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		cin >> a >> b >> c;
		ll TL = 1e8 * c;
		int type = 0;
		if (temp == "O(N)") type = 1;
		else if (temp == "O(N^2)") type = 2;
		else if (temp == "O(N^3)") type = 3;
		else if (temp == "O(2^N)") type = 4;
		else if (temp == "O(N!)") type = 5;

		if (a < limit[type - 1]) {

			ll Cnt = check(a, type) * b;

			if (Cnt <= TL) {
				cout << "May Pass.\n";
			}
			else {
				cout << "TLE!\n";
			}
		}
		else {
			cout << "TLE!\n";
		}
	}
}