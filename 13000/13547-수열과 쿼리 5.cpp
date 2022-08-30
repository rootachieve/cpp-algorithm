#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int n;
int Nsqrt;
int base[100001];
int num[1000001];
typedef struct Info {
	int l,r,index,ans;
	Info(int a, int b, int c) {
		l = a;
		r = b;
		ans = 0;
		index = c;
	}
};

vector<Info> q;
bool sortByMo(Info a,Info b){
	if (a.l / Nsqrt == b.l / Nsqrt) {
		return a.r<b.r;
	}
	else {
		return a.l / Nsqrt<b.l / Nsqrt;
	}
}

bool sortByIndex(Info a, Info b) {
	return a.index<b.index;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	Nsqrt = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin>>base[i];
	}

	int Qur;
	cin>>Qur;
	int a,b;
	for (int i = 1; i <= Qur; i++) {
		cin>>a>>b;
		q.push_back(Info(a,b,i));
	}

	sort(q.begin(),q.end(),sortByMo);
	int l = q[0].l;
	int r = q[0].r;
	int Cnt = 0;
	for (int i = l; i <= r; i++) {
		if (num[base[i]] == 0) {
			Cnt++;
		}
		num[base[i]]++;
	}
	q[0].ans = Cnt;

	for (int i = 1; i < q.size(); i++) {
		if (l < q[i].l) {
			while (l < q[i].l) {
				num[base[l]]--;
				if (num[base[l]] == 0) {
					Cnt--;
				}
				l++;
			}
		}
		else if (l > q[i].l) {
			while (l > q[i].l) {
				l--;
				if (num[base[l]] == 0) {
					Cnt++;
				}
				num[base[l]]++;
			}
		}

		if (r < q[i].r) {
			while (r < q[i].r) {
				r++;
				if (num[base[r]] == 0) {
					Cnt++;
				}
				num[base[r]]++;
			}
		}
		else if (r > q[i].r) {
			while (r > q[i].r) {
				num[base[r]]--;
				if (num[base[r]] == 0) {
					Cnt--;
				}
				r--;
			}
		}

		q[i].ans = Cnt;
	}

	sort(q.begin(),q.end(),sortByIndex);
	for (int i = 0; i < q.size(); i++) {
		cout<<q[i].ans<<"\n";
	}
}