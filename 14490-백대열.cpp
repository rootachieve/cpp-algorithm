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

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b,a%b);
	}
}

int main() {
	string a;
	cin>>a;
	int i;
	int num1=0;
	int num2=0;
	for (i = 0; a[i] != ':'; i++) {
		num1*=10;
		num1+=a[i]-48;
	}
	for (i++;a[i] != NULL; i++) {
		num2*=10;
		num2+=a[i]-48;
	}
	int g = gcd(num1,num2);
	printf("%d:%d",num1/g,num2/g);
}