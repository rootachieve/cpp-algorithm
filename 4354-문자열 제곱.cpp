#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;


int pi[2000006];
string in;
void kmp(string a) {
	int l = a.size();
	int i = -1;
	int j = 0;
	pi[j] = i;
	while (j<l) {
		if (i == -1 || a[i] == a[j]) {
			pi[++j] = ++i;
		}
		else {
			i = pi[i];
		}
	}
}


int main() {
	while(1){
		cin>>in;
		if (in == ".") {
			break;
		}
		in = in+in;
		int n = in.size();
		kmp(in);
		printf("%d\n",(n/2)/(n-pi[n]));
		fill(pi,pi+n+1,0);
	}

}