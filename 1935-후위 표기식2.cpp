#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
double ans;
int n;
string in;
double change[26];
bool Set = false;
int main() {
	cin>>n;
	cin>>in;
	for (int i = 0; i < n; i++) {
		cin>>change[i];
	}
	stack<double> s;
	for (int i = 0; i < in.size(); i++) {
		if (65 <= in[i] && in[i] <= 90) {
			s.push(change[in[i]-65]);
		}
		else {
			if (in[i] == '*') {

				double f = s.top();
				s.pop();
				f *= s.top();
				s.pop();
				s.push(f);
			}
			else if (in[i] == '/') {
				double f = s.top();
				s.pop();
				double sec = s.top();
				sec/=f;
				s.pop();
				s.push(sec);
			}
			else if (in[i] == '-') {
				double f = s.top();
				s.pop();
				double sec = s.top();
				sec -= f;
				s.pop();
				s.push(sec);
			}
			else {
				double f = s.top();
				s.pop();
				f+=s.top();
				s.pop();
				s.push(f);
			}
		}
	}
	printf("%.2lf",s.top());
}