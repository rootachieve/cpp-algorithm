#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

string in;
int ans;
stack<char> s;
int main() {
	int t;
	cin>>t;

	bool err;
	while (t--) {
		cin>>in;
		for (int i = 0; i < in.size(); i++) {
			if (s.empty()) {

				s.push(in[i]);
			}
			else {
				if (s.top() == in[i]) {
					s.pop();
				}
				else {
					s.push(in[i]);
				}
			}
		}
		if (s.empty()) {
			ans++;
		}
		else {
			while (!s.empty()) {
				s.pop();
			}
		}
	}
	
	printf("%d",ans);
}