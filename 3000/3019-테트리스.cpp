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
vector<int> v;
int main() {
	int n,m;
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}
	int ans = 0;

	if (m == 1) {
		for (int i = 0; i < n - 3; i++) {
			if (v[i] == v[i + 1] && v[i + 2] == v[i + 3] && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		ans+=n;
	}
	else if (m == 2) {
		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1]) {
				ans++;
			}
		}
	}
	else if (m == 3) {
		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] && v[i + 1] + 1 == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1] + 1) {
				ans++;
			}
		}
	}
	else if (m == 4) {
		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] + 1 && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] + 1 == v[i + 1]) {
				ans++;
			}
		}
	}
	else if (m == 5) {
		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] + 1== v[i + 1]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1] + 1) {
				ans++;
			}
		}

		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] + 1 && v[i + 1] + 1 == v[i + 2]) {
				ans++;
			}
		}
	}
	else if (m == 6) {
		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 2; i++) {
			if (v[i] + 1 == v[i + 1] && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1] + 2) {
				ans++;
			}
		}
	}
	else {
		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i] == v[i + 1]) {
				ans++;
			}
		}

		for (int i = 0; i < n - 2; i++) {
			if (v[i] == v[i + 1] && v[i + 1] == v[i + 2] + 1) {
				ans++;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			if (v[i]+2 == v[i + 1]) {
				ans++;
			}
		}
	}

	cout<<ans;
}