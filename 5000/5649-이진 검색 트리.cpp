#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
vector<int> v[1000001];
int Count;
int num;
stack<int> s;
int value[1000001];
int root = 0;
int nowroot = 0;

void back(int node) {
	if (v[node].size() == 2) {
		back(min(v[node][0],v[node][1]));
		back(max(v[node][0], v[node][1]));
		printf("%d\n", node);
	}
	else if (v[node].size() == 1) {
		back(v[node][0]);
		printf("%d\n", node);
	}
	else {
		printf("%d\n",node);
	}
}
int main() {
	while (scanf("%d",&num) != EOF) {
		if (root == 0) {
			root = num;
		}
		if (s.empty()) {
			v[nowroot].push_back(num);
			s.push(num);
			nowroot = num;
		}
		else {
			if (s.top() > num) {
				v[s.top()].push_back(num);
				s.push(num);
			}
			else {
				int temp = 0;
				while (!s.empty() && s.top() < num) {
					temp = s.top();
					s.pop();
				}

				if (s.empty()) {
					v[nowroot].push_back(num);
					s.push(num);
					nowroot = num;
				}
				else {
					v[temp].push_back(num);
					s.push(num);
				}
			}
		}
	}

	printf("");

	back(root);
}