#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
vector<int> v;
bool comp(int a, int b) {
	return a>b;
}
int main() {
int a;
	cin>>n>>m;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),comp);

	int Max = 0;
	int Min = 1000001;
	int len = 0;
	for (int i = 0; i <m;i++) {
		if (i < n) {
			if ((i + 1) * v[i] >= Max) {
				Max = (i + 1) * v[i];
				Min = v[i];
			}
		}
		else {
			if (n * v[i] >= Max) {
				Max = n*v[i];
				Min = v[i];
			}
		}
	}
	printf("%d %d",Min,Max);
}