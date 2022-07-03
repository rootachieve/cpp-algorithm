#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n;
pair<int,int> arr[1001];
int a,b;
int main() {
	cin>>n;
	int Max = 0;
	int MaxLoc = 0;
	for (int i = 1; i <= n; i++) {
		cin>>a>>b;
		arr[i] = {a,b};
		if (Max < b) {
			Max = b;
			MaxLoc = a;
		}
	}
	ll sum = 0;
	sort(arr + 1, arr + n + 1);
	int now = 0;
	int loc = 0;

	for (int i = 1; arr[i].first <= MaxLoc; i++) {
		if (arr[i].first == MaxLoc) {
			sum += (arr[i].first - loc) * now;
		}
		else if (arr[i].second > now) {
			sum+=(arr[i].first-loc)*now;
			now = arr[i].second;
			loc = arr[i].first;
		}
	}
	now = 0;
	loc = n+1;
	for (int i = n; arr[i].first >= MaxLoc; i--) {
		if (arr[i].first == MaxLoc) {
			sum += (loc - arr[i].first) * now;
		}
		else if (arr[i].second > now) {
			sum += (loc -arr[i].first) * now;
			now = arr[i].second;
			loc = arr[i].first;
		}
	}
	printf("%lld",sum+Max);
}