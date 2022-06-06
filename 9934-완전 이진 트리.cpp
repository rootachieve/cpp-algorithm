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
int tree[2048];
vector<int> v[10];
int n;
int Count;
void back(int level,int node) {
	if (level == n - 1) {
		v[level].push_back(tree[++Count]);
	}
	else {
		back(level + 1,node*2);
		v[level].push_back(tree[++Count]);
		back(level+1,node*2+1);
	}
}
int main() {
	cin>>n;
	int a;
	int Max = pow(2,n);
	Max--;
	for (int i = 1; i <= Max; i++) {
		cin>>tree[i];
	}
	back(0, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<v[i].size(); j++) {
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
}