#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
vector<int> input1,input2;
vector<int> base;
vector<int> target;
int pi[200001];

void kmp() {
	int i = - 1;
	int j = 0;
	pi[j] = i;
	while (j < target.size()) {
		if (i == -1 || target[i] == target[j]) {
			pi[++j] = ++i;
		}
		else {
			i = pi[i];
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int a;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		input1.push_back(a);
	}

	sort(input1.begin(), input1.end());
	for (int i = 1; i <= n; i++) {
		cin >> a;
		input2.push_back(a);
		input1.push_back(input1[i-1]);
	}

	sort(input2.begin(), input2.end());
	for (int i = 0; i < input1.size()-1; i++) {
		base.push_back(input1[i+1] - input1[i] <0 ? input1[i + 1] - input1[i]  + 360000: input1[i + 1] - input1[i]);
	}

	for (int i = 0; i < input2.size()-1; i++) {
		target.push_back(input2[i + 1] - input2[i] < 0 ? input2[i + 1] - input2[i] + 360000 : input2[i + 1] - input2[i]);
	}

	kmp();


	int i = 0;
	int j = 0;
	bool Find = false;
	while (i < base.size()) {
		if (j == -1 || base[i] == target[j]) {
			i++;
			j++;
		}
		else {
			j = pi[j];
		}

		if (j ==target.size()) {
			Find = true;
			break;
		}
	}

	if (Find) {
		cout<<"possible";
	}
	else {
		cout<<"impossible";
	}
}