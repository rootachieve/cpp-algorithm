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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
queue<int> q;

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		printf("%d ",q.front());
		q.pop();
		if (q.empty()) {
			break;
		}
		q.push(q.front());
		q.pop();
	}
}