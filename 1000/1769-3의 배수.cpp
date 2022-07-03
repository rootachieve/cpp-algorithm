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
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int main() {
	string a;
	cin>>a;
	int Ans = 0;
	while (a.length() > 1) {
		int sum = 0;
		Ans++;
		for (int i = 0; i < a.length(); i++) {
			sum+=a[i]-48;
		}
		a = to_string(sum);
	}
	printf("%d\n", Ans);
	if ((a[0] - 48) % 3 == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}