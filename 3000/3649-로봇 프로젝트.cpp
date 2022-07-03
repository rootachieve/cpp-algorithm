#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n,m;
vector<int> v;

int main() {
	while (scanf("%d", &n) != EOF) {
		scanf("%d",&m);
		v.clear();
		n = n * 10000000;
		int a = 0;
		bool Find = false;
		for (int i = 1; i <= m; i++) {
			scanf("%d",&a);
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		a = 0;
		int b = v.size()-1;
		while (a < b) {
			if (v[a] + v[b] < n) {
				a++;
			}
			else if (v[a] + v[b] > n) {
				b--;
			}
			else {
				printf("yes %d %d\n",v[a],v[b]);
				Find = true;
				break;
			}
		}

		if (!Find) {
			printf("danger\n");
		}
	}
}