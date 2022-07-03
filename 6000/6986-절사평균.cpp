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
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int n,k;
vector<double> v;

int main() {
	cin>>n>>k;
	double a;
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	double sum2 = 0;


	for (int i = 0; i < n; i++) {
		if (i < k) {
			sum2+= v[k];
		}
		else if (i >= n - k) {

			sum2 += v[n - k - 1];
		}else{
			sum2+=v[i];
		}
	}
	for (int i = k; i < n - k; i++) {
		sum += v[i];
	}
	printf("%.2lf\n%.2lf",sum/ (n - 2 * k)+ 0.00000001,sum2/n + 0.00000001);
}