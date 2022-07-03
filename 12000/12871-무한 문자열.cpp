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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b,a%b);
	}
}
int main(){
	string a,b,c,d;
	cin>>a;
	cin>>b;
	int lcm = a.size()*b.size()/gcd(a.size(),b.size());
	int ta = lcm/a.size();
	int tb = lcm/b.size();
	for (int i = 1; i <= ta; i++) {
		c+=a;
	}
	for (int i = 1; i <= tb; i++) {
		d += b;
	}

	bool err =false;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] != d[i]) {
			err = true;
			break;
		}
	}

	if (err) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	
	
}