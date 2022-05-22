#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int a,b;

int main() {
	cin>>a>>b;
	int c = 1;
	int d = 1;
	int Count = 1;
	int ans = 0;
	while (Count <= b) {
		if (a <= Count && Count <= b) {
			ans+=c;
		}

		d--;
		if (d == 0) {
			c++;
			d = c;
		}

		Count++;
	}

	printf("%d",ans);
}