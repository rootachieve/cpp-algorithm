#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
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

stack<int> s[6];

int n,m;
int ans;
int a,b;
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b;
		if (s[a - 1].empty()) {
			ans++;
			s[a-1].push(b);
		}
		else {
			while (!s[a - 1].empty() && s[a - 1].top() > b) {
				s[a-1].pop();
				ans++;
			}

			if (s[a-1].empty()|| s[a - 1].top() != b) {
				s[a-1].push(b);
				ans++;
			}
		}
	}

	printf("%d",ans);
}