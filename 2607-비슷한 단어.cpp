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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int base[26];
int check[26];
int ans;
int n;
string a,b;

int main() {
	cin>>n;
	cin>>a;
	for (int i = 0; i < a.length(); i++) {
		base[a[i]-65]++;
	}

	for (int i = 2; i <= n; i++) {
		cin>>b;
		for (int i = 0; i < b.length(); i++) {
			check[b[i] - 65]++;
		}

		int diff = 0;
		for (int i = 0; i < 26; i++) {
			diff += abs(check[i]-base[i]);
			check[i] = 0;
		}

		if (a.length() == b.length()) {
			if (diff <= 2) {
				ans++;
			}
		}
		else {
			if (diff <= 1) {
				ans++;
			}
		}
	}

	printf("%d",ans);
}