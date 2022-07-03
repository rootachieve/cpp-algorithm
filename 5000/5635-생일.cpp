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
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
struct Info {
	string name;
	int d, m, y;
	Info(string a, int b, int c, int e) {
		name = a;
		d = b;
		m = c;
		y = e;
	}
};
bool comp(Info a, Info b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			return a.d<b.d;
		}
		else {
			return a.m<b.m;
		}
	}
	else {
		return a.y<b.y;
	}
}

vector<Info> v;
int main() {
	int n;
	 cin>> n;
	 int t = n;
	 int a,b,c;
	 string temp;
	 while (t--) {
		 cin>>temp>>a>>b>>c;
		 v.push_back(Info(temp,a,b,c));
	 }

	 sort(v.begin(),v.end(),comp);

	 cout<<v[n-1].name<<endl;
	 cout<<v[0].name;
}