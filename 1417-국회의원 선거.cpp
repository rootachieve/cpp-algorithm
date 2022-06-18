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

int n;
priority_queue<int> q;
int main() {
int num;
	cin>>n;
	cin>>num;
	int a;

	for (int i = 2; i <= n; i++) {
		cin>>a;
		q.push(a);
	}
	int ans = 0;
	while (!q.empty()&&q.top()>=num) {
		q.push(q.top()-1);
		q.pop();
		num++;
		ans++;
	}

	cout<<ans;
}