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

int arr[101];
struct Info{
	int na,per,v;

	Info(int a, int b, int c) {
		na = a;
		per = b;
		v = c;
	}
};

vector<Info> v;
int n;

bool sor(Info a, Info b) {
	return a.v>b.v;
}
int main() {
	cin>>n;
	int a,b,c;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b>>c;
		v.push_back(Info(a,b,c));
	}

	sort(v.begin(),v.end(),sor);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[v[i].na] <= 1) {
			arr[v[i].na]++;
			printf("%d %d\n",v[i].na,v[i].per);
			cnt++;
			if (cnt == 3) {
				break;
			}
		}
	}
}