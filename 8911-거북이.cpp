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

int l,r,u,d;
int y,x;
int dir = 1;
int main() {
	int n;
	cin>>n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		x = 0;
		y = 0;
		d = 0;
		l = 0;
		u = 0;
		r = 0;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 'F') {
				if (dir == 1) {
					y++;
					if(y>=0){
						u = max(u,y);
					}
				}
				else if (dir == 2) {
					x++;
					if (x >= 0) {
						r = max(r, x);
					}
				}
				else if (dir == 3) {
					y--; 
					if (y <= 0) {
						d = max(d, abs(y));
					}
				}
				else {
					x--; 
					if (x <= 0) {
						l = max(l, abs(x));
					}
				}
			}
			else if (temp[j] == 'B') {
				if (dir == 3) {
					y++;
					if (y >= 0) {
						u = max(u, y);
					}
				}
				else if (dir == 4) {
					x++;
					if (x >= 0) {
						r = max(r, x);
					}
				}
				else if (dir == 1) {
					y--;
					if (y <= 0) {
						d = max(d, abs(y));
					}
				}
				else {
					x--;
					if (x <= 0) {
						l = max(l, abs(x));
					}
				}
			}
			else {
				if (temp[j] == 'L') {
					dir == 1 ? dir = 4 : dir--;
				}
				else {
					dir == 4 ? dir = 1 : dir++;
				}
			}
		}
		cout<<(r + l)*(u+ d)<<"\n";
	}
}