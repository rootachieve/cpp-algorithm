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
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

string a,b;

vector<int> v;
vector<int> v2;
int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main() {
	cin>>a>>b;

	for (int i = 0; i < a.size(); i++) {
		v.push_back(arr[a[i]-65]);
		v.push_back(arr[b[i] - 65]);
	}

	while (v.size() > 2) {
		for (int i = 0; i < v.size() - 1; i++) {
			v2.push_back((v[i] + v[i+1])%10);
		}

		v = v2;
		v2.clear();
	}

	cout<<v[0]<<v[1];
}