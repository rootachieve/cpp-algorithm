#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
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

int arr[100001];
int n,k,a;
int q[1000000];
int z = -1,front;
int sum;
int p;
void push(int x) {
	z++;
	q[front+z] = x;
}

void pop() {
	if(z!=-1){
		p = q[front];
		front++;
		z--;
	}
	else {
		p=-1;
	}
}

int main() {
	cin>>n>>k;

	int i;
	for (i = 1; i <= k; i++) {
		cin >> a;
		push(a);
		sum+=a;
	}

	int Max = sum;

	for (; i <= n; i++) {
		cin >> a;
		push(a);
		sum+=a;
		pop();
		sum-=p;
		Max = max(Max,sum);
	}


	printf("%d",Max);
}