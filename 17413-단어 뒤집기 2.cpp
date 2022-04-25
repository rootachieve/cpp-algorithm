#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
string ans;
char in[100001];
stack<char> s;
bool open = false;
int main() {
	cin.getline(in,100001);
	for (int i = 0; in[i]!=NULL; i++) {
		if (open) {
			ans.push_back(in[i]);
			if (in[i] == '>') {
				open = false;
			}
		}
		else if (in[i] == '<'){
			while (!s.empty()) {
				ans.push_back(s.top());
				s.pop();
			}
			open = true;
			ans.push_back(in[i]);
		}
		else if(in[i] == ' ') {
			while (!s.empty()) {
				ans.push_back(s.top());
				s.pop();
			}

			ans.push_back(in[i]);
		}
		else {
			s.push(in[i]);
		}
	}

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	cout<<ans;
}