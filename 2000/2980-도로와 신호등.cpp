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
vector<int> v;
int main(){
	int n,m;
	cin>>n>>m;
	int cnt  = 0;
	int a,b,c;
	int loc = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b>>c;
		cnt += (a - loc);
		loc =a;
		int temp = cnt%(b+c);
		if (temp < b) {
			cnt+=b-temp;
		}
	}

	cnt += (m - loc);
	cout<<cnt;
}