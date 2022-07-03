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

int dp[10001];
pair<int,int> item[5001];
int n, m;
double tem;
int a;
double b;
int main() {
	while(1){
		cin>>n;
		cin>>tem;
		if (n == 0) {
			break;
		}
		m= tem* 100;
		for (int i = 1; i <= n; i++) {
			cin>>a;
			cin>>b;
			item[i] = {a,b*100+0.5};
		}

		for (int i = 1; i <= m; i++) {
			dp[i] = dp[i-1];
			for (int j = 1; j <= n; j++) {
				if (item[j].second <= i) {
					dp[i] = max(dp[i],dp[i - item[j].second] + item[j].first);
				}
			}
		}

		printf("%d\n",dp[m]);
	}
}