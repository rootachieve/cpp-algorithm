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


int main() {
	int num;
	cin>>num;

	int ans = 0;
	if (num % 2 == 1) {
		ans+=1;
		num-=5;
	}

	if (num < 0) {
		printf("-1");
	}
	else {
		ans += num / 10 * 2;
		num %= 10;
		ans += num / 2;
		num %= 2;

		if (num == 0) {
			printf("%d", ans);
		}
		else {
			printf("-1");
		}
	}
	
}