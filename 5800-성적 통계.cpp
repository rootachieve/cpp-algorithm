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
	int t;
	cin>>t;
	int now = 1;
	int a;
	while (now <= t) {
		int n;
		cin>>n;
		v.clear();
		for(int i = 1; i <= n; i++) {
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		int Max= 0;
		for (int i = 0; i < n - 1; i++) {
			Max = max(Max,v[i+1] - v[i]);
		}

		printf("Class %d\n",now);
		printf("Max %d, Min %d, Largest gap %d\n",v[n-1],v[0],Max);
		now++;
	}
}