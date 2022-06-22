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
#include <map>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a;
		int Max = 0;
		int maxloc = 0;
		int sum = 0;
		bool err = false;
		for (int i = 1; i <= n; i++) {
			cin>>a;
			sum+=a;
			if (a > Max) {
				Max = a;
				maxloc = i;
				err = false;
			}
			else if (a == Max) {
				err = true;
			}
		}

		if (err) {
			cout<<"no winner"<<"\n";
		}
		else if ((double)Max/sum > 0.5) {
			printf("majority winner %d\n",maxloc);
		}
		else {
			printf("minority winner %d\n", maxloc);
		}
		
	}
}