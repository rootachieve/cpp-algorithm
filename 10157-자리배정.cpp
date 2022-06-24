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

int main() {
	int n,m,k;
	cin>>m>>n>>k;
	int y = 1;
	int x = 1;
	int cnt = 0;
	if (k <= n) {
		y = k;
		printf("%d %d",x,y);
	}
	else if (n * m < k) {
		cout<<0;
	}
	else {
		y= n;
		x = 1;
		cnt = n;
		for (int i = 2;; i+=2) {
			
			if (cnt + m - (i - 1) >= k) {
				x+=k-cnt;
				break;
			}
			cnt += m - (i - 1);
			x += m - (i - 1);


			if (cnt + n - (i - 1) >= k) {
				y -= k - cnt;
				break;
			}
			cnt += n - (i - 1);
			y -= n - (i - 1);


			if (cnt + m - i >= k) {
				x -= k - cnt;
				break;
			}
			cnt += m - i;
			x -= m - i;


			if (cnt + n - i >= k) {
				y += k - cnt;
				break;
			}
			cnt += n - i;
			y += n - i;
		}


		printf("%d %d", x, y);
	}
	
}