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
ll arr[100001];
ll Sarr[100001];
void Sort(int s, int e) {
	if (s + 1 == e) {
		if (arr[e] > arr[s]) {
			int temp = arr[e];
			arr[e] = arr[s];
			arr[s] = temp;
		}
	}
	else if (s + 1 < e) {
		Sort(s,(s+e)/2);
		Sort((s+e)/2+1,e);

		int a = s;
		int b = (s+e)/2 + 1;
		int c=  s;

		while (a <= (s + e) / 2 && b <= e) {
			if (arr[a] >= arr[b]) {
				Sarr[c] = arr[a];
				c++;
				a++;
			}
			else {
				Sarr[c] = arr[b];
				c++;
				b++;
			}
		}

		if (a > (s + e) / 2) {
			while (b <= e) {
				Sarr[c] = arr[b];
				c++;
				b++;
			}
		}
		else {
			while (a <= (s + e) / 2) {
				Sarr[c] = arr[a];
				c++;
				a++;
			}
		}

		for (int k = s; k <= e; k++) {
			arr[k] = Sarr[k];
		}
	}
}


int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}

	Sort(1,n);
	ll sum = 0;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] - cnt > 0) {
			sum += arr[i] - cnt;
			cnt++;
		}
		else {
			break;
		}
	}

	printf("%lld",sum);
}