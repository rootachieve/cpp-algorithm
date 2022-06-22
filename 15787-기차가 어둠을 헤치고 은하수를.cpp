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

set<int> s;
int arr[100001];
int main() {
	int n,m;
	cin>>n>>m;

	int a,b,c;
	for (int i = 1; i <= m; i++) {
		cin>>a>>b;
		if (a == 1) {
			cin>>c;

			arr[b] = (arr[b] | (1<<c));
		}
		else if (a == 2) {
			cin>>c;
			arr[b] = (arr[b] & ~(1<<c));
		}
		else if (a == 3) {
			arr[b] = arr[b]<<1;
			arr[b] = arr[b] & ~(1<<21);
		}
		else {
			arr[b] = arr[b]>>1;

			arr[b] = arr[b] & ~(1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {


		if (s.find(arr[i]) == s.end()) {
			s.insert(arr[i]);
			ans++;
		}
	}

	cout<<ans;
}