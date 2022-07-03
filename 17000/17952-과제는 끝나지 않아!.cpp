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
stack<pair<int,int>> s;
int main() {
	int n;
	cin>>n;
	int a,b,c;
	int ans = 0;
	int nowT = 0;
	int nowV = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		if(a==1) {
			cin>>b>>c;
			if (nowT > 0) {
				s.push({nowT,nowV});
			}
			nowT = c;
			nowV = b;
		}

		if (nowT > 0) {
			nowT--;
			if (nowT == 0) {
				ans += nowV;
				if (!s.empty()) {
					nowT = s.top().first;
					nowV = s.top().second;
					s.pop();
				}
			}
		}
	}

	cout<<ans;
}