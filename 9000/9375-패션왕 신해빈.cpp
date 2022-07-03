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
#define MAX 2000000001;
#define RESET 0
using namespace std;
map<string,int> m;
int base[32];
int check[32];
int n;
string a,b;
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int Count = 0;
		m.clear();
		for (int i = 1; i <= n; i++) {
			cin>>a;
			cin>>b;
			if (m.find(b) == m.end()) {
				m.insert({b,++Count});
				base[m.find(b)->second]++;
			}
			else {
				base[m.find(b)->second]++;
			}
		}
		check[0] = 1;
		for (int i = 1; i <= Count; i++) {
			check[i] = check[i-1]*(base[i]+1);
		}
		printf("%d\n",check[Count]-1);

		for (int i = 1; i <= Count; i++) {
			check[i] = 0;
			base[i] = 0;
		}
	}
}