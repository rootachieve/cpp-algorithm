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
int map[1025][1025];

int back(int Sy, int Sx, int Ey, int Ex) {
	if (Sy == Ey) {
		return map[Sy][Sx];
	}
	else {
		int arr[4];
		int midX = (Sx+Ex)/2;
		int midY = (Sy+Ey)/2;
		arr[0] = back(Sy,Sx,midY,midX);
		arr[1] = back(midY+1,Sx,Ey,midX);
		arr[2] = back(Sy,midX+1,midY,Ex);
		arr[3] = back(midY+1,midX+1,Ey,Ex);

		sort(arr,arr+4);
		return arr[2];
	}
}

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			cin>>map[i][j];
		}
	}


	cout<<back(1,1,n,n);
}