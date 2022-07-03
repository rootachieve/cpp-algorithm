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

deque<int> a,b;

int n,m;

int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
		b.push_back(i);
	}
	int num;
	int ans = 0;
	int l,r;
	for (int i = 1; i <= m; i++) {
		cin>>num;
		l = 0;
		r = 0;
		while (a.front() != num) {
			l++;
			a.push_back(a.front());
			a.pop_front();
		}

		while (b.front() != num) {
			r++;
			b.push_front(b.back());
			b.pop_back();
		}

		a.pop_front();
		b.pop_front();
		ans+=min(l,r);
	}

	cout<<ans;
}