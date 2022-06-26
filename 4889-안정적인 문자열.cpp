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
stack<char>s;
int main(){
	string in;
	int t = 0;
	while (1) {
	++t;
		cin>>in;
		if (in[0] == '-') {
			break;
		}

		for (int i = 0; i < in.size(); i++) {
			if (s.empty()) {
				s.push(in[i]);
			}
			else {
				if (in[i] == '{') {
					s.push(in[i]);
				}
				else {
					if (s.top() == '{') {
						s.pop();
					}
					else {
						s.push(in[i]);
					}
				}
			}
		}

		int cnt = 0;
		int num = 0;
		while (!s.empty()) {
			if (num % 2 == 0) {
				if (s.top() == '{') {
					cnt++;
				}
			}
			else {
				if (s.top() == '}') {
					cnt++;
				}
			}
			s.pop();
			num++;
		}

		printf("%d. %d\n",t,cnt);
	}
}