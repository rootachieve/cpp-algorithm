#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int arr[26][200002];
int main() {
	cin.tie(0);

	string in;
	cin>>in;

	for (int i = 1; i <= in.size(); i++) {
		for (int j = 0; j <= 25; j++) {
			arr[j][i] += arr[j][i-1];
		}

		arr[in[i-1]-97][i]++;
	}

	int n;
	cin>>n;
	string a;
	int b,c;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b>>c;
		b++;
		c++;
		cout<<arr[a[0]-97][c] - arr[a[0]-97][b-1]<<"\n";
	}
}