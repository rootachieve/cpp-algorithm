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
#define MAX 5000002
using namespace std;
typedef struct info{
	ll y;
	ll x;
	ll loc;
	info(ll a, ll b, ll c) {
		y = a;
		x = b;
		loc = c;
	}

}Info;

vector<Info> v;
stack<Info> s;
int t, n;
int base;

ll ccw(Info a, Info b,Info c) {
	ll temp = a.x * b.y + b.x * c.y + c.x * a.y -
		(a.x * c.y + b.x * a.y + c.x * b.y);

	if (temp > 0) {
		return 1;
	}
	else if (temp == 0) {
		return 0;
	}
	else {
		return -1;
	}
}
bool comp(Info a, Info b) {
	ll temp = ccw(v[0], a, b);
	if (temp == 1) {//ccw
		return true;
	}
	else if (temp == 0) {
		return ((pow(a.y - v[0].y, 2) + pow(a.x - v[0].x, 2)))
			<
			((pow(b.y - v[0].y, 2) + pow(b.x - v[0].x, 2)));

	}
	else {//cw
		return false;
	}
}
bool comp2(Info a, Info b) {
	if (a.y == b.y) {
		return a.x<b.x;
	}
	else {
		return a.y<b.y;
	}
}
int main() {
	ll a, b;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld", &a, &b);
			v.push_back(Info(b,a,i));
		}
		sort(v.begin(), v.end(),comp2);
		sort(v.begin() + 1, v.end(), comp);

		s.push(v[0]);
		s.push(v[1]);
		int Count = 1;
		while (ccw(v[0], v[n - Count], v[n - Count - 1]) == 0) {
			Count++;
		}
		reverse(v.end()-Count,v.end());
		for (int i = 0; i < n; i++) {
			printf("%d ",v[i].loc);
		}
		printf("\n");
	}

}