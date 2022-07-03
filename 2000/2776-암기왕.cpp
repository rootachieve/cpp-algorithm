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

set<int> s;

int main() {
	int t;
	cin>>t;
	int a,b;
	while (t--) {
		s.clear();
		scanf("%d",&a);
		for (int i = 1; i <= a; i++) {
			scanf("%d", &b);
			s.insert(b);
		}
		scanf("%d", &a);
		for (int i = 1; i <= a; i++) {
			scanf("%d", &b);
			if (s.find(b) == s.end()) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}
	}
}