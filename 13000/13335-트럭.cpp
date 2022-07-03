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

queue<pair<int,int>> q;
vector<int> v;
int main() {
	int n,m,w;
	int a;
	int WL = 0;
	int T = 0;
	scanf("%d%d%d",&n,&m,&w);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		v.push_back(a);
	}
	int index = 0;
	while (index != n) {

		T++;
		if (!q.empty() && q.front().second + m == T) {
			WL-=q.front().first;
			q.pop();
		}
		if (WL + v[index] <= w) {
			q.push({v[index],T});
			WL+=v[index];
			index++;
		}
		else {
			T = q.front().second + m -1;
		}
	}

	while (!q.empty()) {
		T = q.front().second+m;
		q.pop();
	}

	printf("%d",T);
}