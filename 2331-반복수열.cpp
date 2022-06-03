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
int num,p;
int arr[1000001];
int ans;
int Pow(int n, int c) {
	int num = 1;
	for (int i = 1; i <= c; i++) {
		num*=n;
	}
	return num;
}

void dfs(int n) {
	int value = 0;
	int temp = n;
	while(temp>0){
		value += Pow(temp%10,p);
		temp/=10;
	}

	if (arr[value] > 0) {
		ans = arr[value] - 1;
	}
	else {
		arr[value] = arr[n] + 1;
		dfs(value);
	}
}

int main() {
	cin>>num>>p;
	arr[num] = 1;
	dfs(num);
	printf("%d",ans);
}