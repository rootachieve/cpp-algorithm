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
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

vector<int> v;
int arr[9];

int n, m;
void back(int num) {
	if (num == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			arr[num] = v[i];
			back(num+1);
		}
	}
}
int main() {
	cin>>n>>m;
	int a;
	for (int i = 1; i <= n; i++)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());

	back(0);
}