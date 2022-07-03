#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <math.h>
#include <algorithm>

#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
string a,b;
int check(int loc) {
	int Count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (b[i + loc] != a[i]) {
			Count++;
		}
	}
	return Count;
}
int main() {
	cin>>a>>b;
	int Min = 51;
	for (int i = 0; i + a.size() <= b.size(); i++) {
		Min = min(Min,check(i));
	}

	printf("%d",Min);
}