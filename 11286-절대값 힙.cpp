#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include<cmath>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
using namespace std;

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second>b.second;
		}
		return a>b;
	}
};
priority_queue<pair<int,int>,vector<pair<int, int>>,comp> pq;
int n;
int main() {
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		if (a == 0) {
		if(!pq.empty()){
			printf("%d\n",pq.top().second);
			pq.pop();
		}
		else {
			printf("0\n");
		}
		}
		else {
			pq.push({abs(a),a});
		}
	}
}