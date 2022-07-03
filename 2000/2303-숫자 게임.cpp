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
vector<int> v;
int main() {
	int t;
	cin>>t;
	int num = 0;
	int ans = 0;
	int ansnum = 0;
	while (t--) {
		v.clear();
		num++;
		int a;
		for(int i = 1;i<=5;i++){
			cin>>a;
			v.push_back(a);
		}
		int Max = 0;
		int M;
		for (int i = 0; i <= 2; i++) {
			for (int j = i + 1; j <= 3; j++) {
				M = 0;
				for (int k = j + 1; k <= 4; k++) {
					M = (v[i] + v[j] + v[k])%10;
				}
				if (Max <= M) {
					Max = M;
				}
			}
		}
		if (ansnum <= Max) {
			ansnum = Max;
			ans = num;
		}
	}
	cout<<ans;
}
