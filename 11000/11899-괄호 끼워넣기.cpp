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
stack<char> s;
int main(){
	string in;
	cin>>in;
	for (int i = 0; i < in.size(); i++) {
		if (s.empty()) {
			s.push(in[i]);
		}
		else {
			if (in[i] == '(') {
				s.push('(');
			}
			else {
				if (s.top() == '(') {
					s.pop();
				}
				else {
					s.push(')');
				}
			}
		}
	}

	cout<<s.size();
}