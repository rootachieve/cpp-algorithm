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
set<string> s;
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		if (s.find(temp) == s.end()) {
			s.insert(temp);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		cin>>temp;
		if (s.find(temp) != s.end()) {
			ans++;
		}
	}
	printf("%d",ans);
}