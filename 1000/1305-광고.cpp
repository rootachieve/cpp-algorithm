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
string in;
int pi[1000002];
void kmp(const char* a) {
	int l = strlen(a);
	int i = -1;
	int j = 0;
	pi[j] = -1;
	while (j < l) {
		if (i == -1 || a[i] == a[j]) {
			pi[++j] = ++i;
		}
		else {
			i = pi[i];
		}
	}
}
int main() {
	scanf("%d",&n);
	cin>>in;
	kmp(in.c_str());
	printf("%d",n - pi[n]);
}