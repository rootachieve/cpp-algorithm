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

	string a, b;
	while (cin>>a>>b) {

		int index = 0;

		for (int i = 0; i < b.size(); i++) {
			if (a[index] == b[i]) {
				index++;
				
			}
			if (index == a.size()) {
				break;
			}
		}

		if (index == a.size()) {
			cout<<"Yes\n";
		}
		else {
			cout<<"No\n";
		}
	}
}