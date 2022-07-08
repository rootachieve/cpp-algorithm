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

int arr[1025][1025];
int base[1025][1025];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>base[i][j];
			arr[i][j] = arr[i][j-1]+base[i][j];
		}
	}
	int a,b,c,d,e;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		if (a == 0) {
			cin>>b>>c>>d;
			base[b][c] = d;
			for (int j = c; j <= n; j++) {
				arr[b][j] = arr[b][j-1] + base[b][j];
			}
		}
		else {
			cin>>b>>c>>d>>e;
			int sy = min(b,d);
			int ey = max(b,d);
			int sx = min(c,e);
			sx--;
			int ex = max(c,e);
			int sum = 0;
			for (int j = sy; j <= ey; j++) {
				sum += arr[j][ex] - arr[j][sx];
			}
			cout<<sum<<"\n";
		}
	}
}