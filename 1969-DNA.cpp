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
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

vector<string> v;

int main() {
	int n,m;
	cin>>n>>m;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		v.push_back(temp);
	}
	string ans="";
	int Ans = 0;
	for (int i = 0; i < m; i++) {
		int A = 0,T=0,G=0,C=0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 'A') {
				A++;
			}
			else if(v[j][i] =='T'){
				T++;
			}
			else if (v[j][i] == 'G') {
				G++;
			}
			else {
				C++;
			}
		}

		if (A >= G && A >= C && A >= T) {
			ans+='A';
			Ans+=G+C+T;
		}
		else if (C >= A && C >= T && C >= G) {
			ans+='C';
			Ans+=A+G+T;
		}
		else if (G >= T && G >= A && G >= C) {
			ans+='G';
			Ans+=C+A+T;
		}
		else {
			ans+='T';
			Ans+=A+C+G;
		}
	}
	cout<<ans;
	printf("\n%d",Ans);
}