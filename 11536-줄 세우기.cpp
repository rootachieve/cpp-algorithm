#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
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
int main(){
	int n;
	cin>>n;
	string befo,now;
	int type = 0;
	bool err = false;
	for (int i = 1; i <= n; i++) {
		cin>>now;
		if (i == 1) {
			befo=now;
		}
		else if(i==2){
			if (befo < now) {
				type=1;
			}
			else {
				type=2;
			}
			befo = now;
		}
		else {
			if (type == 1 && befo > now) {
				err = true;
			}
			else if (type == 2 && befo < now) {
				err = true;
			}
			befo = now;
		}
	}

	if (err) {
		cout<<"NEITHER";
	}
	else {
		if (type == 1) {
			cout<<"INCREASING";
		}
		else {
			cout<<"DECREASING";
		}
	}
}