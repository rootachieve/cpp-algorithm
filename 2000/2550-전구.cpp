#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include<cmath>
#include<cstring>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
int n;
int D[10001];
int R[10001];
int A[10001];

int dp[2][10001];
int main() {
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		D[a] = i;
		R[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		A[D[a]] = i;
	}

	printf("");

	int Maxnum = 0;
	int Maxloc = 0;
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		int num = 0;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				if (dp[1][j] > Max) {
					Max = dp[1][j];
					num = j;
				}
			}
		}
		dp[1][i] = Max + 1;
		dp[0][i] = num;
		if (Max + 1 > Maxnum) {
			Maxnum = Max + 1;
			Maxloc = i;
		}
	}
	vector<int>v;
	while (Maxloc != 0) {
		v.push_back(R[Maxloc]);
		Maxloc = dp[0][Maxloc];
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ",v[i]);
	}
	printf("");
}