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
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int n;
vector<int> v;
int main() {
	cin>>n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	int Min = 4;
	a = 0;
	int b = 0;

	for (int i = 1; i < n; i++) {
		if (v[i] - v[a] <= 4) {
			b++;
			Min = min(max(0,5 - (b - a + 1)),Min);
		}
		else {
			while (v[a] + 4 < v[i]) {
				a++;
			}
			b = i;
			Min = min(max(0, 5 - (b - a + 1)), Min);
		}
	}
	cout<<Min;
}
