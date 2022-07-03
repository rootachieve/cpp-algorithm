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
int arr[21][1001];
int main() {
	int n,m;
	cin>>n>>m;

	int dir = 0;
	int locY = 0;
	int locX = 0;
	bool err = false;

	string temp;
	int temp2;

	for (int i = 1; i <= m; i++) {
		cin>>temp>>temp2;
		if (temp[0] == 'T') {
			if (temp2 == 0) {
				dir == 0 ? dir = 3 : dir--;
			}
			else {
				dir == 3 ? dir = 0 : dir++;
			}
		}
		else {
			if (dir == 0) {
				locX+=temp2;
			}
			else if (dir == 1) {

				locY -= temp2;
			}else if(dir == 2) {

				locX -= temp2;
			}
			else {

				locY += temp2;
			}

			if (locY<0 || locY>n || locX<0 || locX>n) {
				err = true;
			}
		}
	}

	if (err) {
		cout<<-1;
	}
	else {
		printf("%d %d",locX,locY);
	}
}