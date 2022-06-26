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
struct Info {
	int tag = 0;
	int vote = 0;
	int t = 0;
	Info() {
		tag = 0;
		vote = 0;
		t  = 0;
	}
	Info(int a, int b) {
		tag = a;
		vote = 1;
		t = b;
	}

	
};
int in[101];
Info arr[21];
int Size = 0;
int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a;
	for (int i = 1; i <= m; i++) {
		cin>>a;
		if (in[a]!=0) {
			arr[in[a]].vote++;
		}
		else {
			if (Size < n) {
				++Size;
				arr[Size] = Info(a,i);
				in[a] = Size;
			}
			else {
				int Min = 9999;
				int t = 9999;
				int loc = 0;
				for (int i = 1; i <= n; i++) {
					if (Min > arr[i].vote) {
						Min = arr[i].vote;
						t = arr[i].t;
						loc = i;
					}
					else if (Min == arr[i].vote) {
						if (t > arr[i].t) {
							Min = arr[i].vote;
							t = arr[i].t;
							loc = i;
						}
					}
				}

				in[arr[loc].tag] = 0;
				arr[loc] = Info(a,i);
				in[a] = loc;
			}
		}
	}
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		if (arr[i].tag != 0) {
			v.push_back(arr[i].tag);
		}
	}

	sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++) {
		printf("%d ",v[i]);
	}
}