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
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;
int main(){
	int n;
	cin>>n;
	string in;
	cin>>in;
	int B = 0;
	int R = 0;
	char now =' ';
	for (int i = 0; i < n; i++) {
		if (in[i] != now) {
			now = in[i];
			if (in[i] == 'B') {
				B++;
			}
			else {
				R++;
			}
		}
	}

	cout<<min(B,R)+1;
}