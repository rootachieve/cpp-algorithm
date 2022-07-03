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
set<string> s;
int main() {
	string temp;
	while (1) {
		cin>>temp;
		if (temp == "*") {
			break;
		}
		bool err = false;
		for (int i = 1; i < temp.size(); i++) {

			s.clear();
			for (int j = 0; j + i < temp.size(); j++) {
				string t;
				t+=temp[j];
				t+=temp[i+j];
				if (s.find(t) == s.end()) {
					s.insert(t);
				}
				else {
					err = true;
					break;
				}
				
			}
		}

		if (err) {
			cout<<temp <<" is NOT surprising.\n";
		}
		else {

			cout << temp << " is surprising.\n";
		}
	}
}