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
int Count[2][1001];
int main() {
	int a,b;
	for(int i = 1;i<=3;i++){
		scanf("%d%d", &a, &b);
		Count[0][a]++;
		Count[1][b]++;
	}
	for(int j = 0;j<=1;j++){
		for (int i = 0; i <= 1000; i++) {
			if (Count[j][i] == 1) {
				printf("%d ",i);
				break;
			}
		}
	}
}