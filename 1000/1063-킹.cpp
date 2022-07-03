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

int map[10][10];
int arr[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
int Ky,Kx,Sy,Sx;
void check(int num) {
	if (map[Ky + arr[0][num]][Kx + arr[1][num]] != 0) {
		if (Ky + arr[0][num] == Sy && Kx + arr[1][num] == Sx) {
			if (map[Sy + arr[0][num]][Sx + arr[1][num]] != 0) {
				Sy = Sy+arr[0][num];
				Sx = Sx+arr[1][num];
				Ky = Ky+arr[0][num];
				Kx = Kx+arr[1][num];
			}
		}
		else {
			Ky = Ky + arr[0][num];
			Kx = Kx + arr[1][num];
		}
	}
}
int main() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			map[i][j] = 1;
		}
	}
	string temp;
	cin>>temp;
	Kx = temp[0]-64;
	Ky = 9-(temp[1]-48);

	cin >> temp;
	Sx = temp[0] - 64;
	Sy = 9-(temp[1] - 48);
	
	int n;

	cin>>n;

	for (int i = 1; i <= n; i++) {
		cin>>temp;
		if (temp[0] == 'R') {
			if (temp[1] == 'T') {
				check(2);
			}
			else if (temp[1] == 'B') {
				check(4);
			}
			else {
				check(3);
			}
		}
		else if (temp[0] == 'L') {
			if (temp[1] == 'T') {
				check(0);
			}
			else if (temp[1] == 'B') {
				check(6);
			}
			else {
				check(7);
			}
		}
		else if (temp[0] == 'B') {
			check(5);
		}
		else if (temp[0] == 'T') {
			check(1);
		}
	}

	cout<<(char)(Kx+64)<< (9-Ky)<<"\n";

	cout << (char)(Sx + 64) <<(9-Sy);
}