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
string a;
stack<char> s;
int main() {
	cin>>a;
	bool err =false;
	for (int i = 0; i < a.size(); i++) {
		if (s.empty()) {
			s.push(a[i]);
		}
		else {
			if (s.top() == 'A' && a[i] == 'P') {
				s.pop();
				if (!s.empty() && s.top() == 'P') {
					s.pop();
					if (!s.empty() && s.top() == 'P') {
						
					}
					else {
						err= true;
						continue;
					}
				}
				else {
					err = true;
					continue;
				}
			}
			else {
				s.push(a[i]);
			}
		}
	}

	if (err || s.size() > 1) {
		cout<<"NP";
	}
	else {
		if (s.top() == 'P') {

			cout << "PPAP";
		}
		else {
			cout << "NP";

		}
	}
}