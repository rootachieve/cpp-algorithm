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
int n;
int Count[8001];
int sum;
vector<int> v;
int main() {
	scanf("%d",&n);
	int a;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		sum+=a;
		v.push_back(a);
		Count[a+4000]++;
	}
	int Max = 0;
	stack<int> s;
	for (int i = 0; i <= 8000; i++) {
		if (Max < Count[i]) {
			while(!s.empty()) s.pop();
			Max = Count[i];
			s.push(i);
		}
		else if (Max == Count[i]) {
			if (s.size() == 1) {
				s.push(i);
			}
		}
	}
	int d = round((double)sum / (double)n);
	sort(v.begin(),v.end());
	printf("%d\n",d);
	printf("%d\n",v[n/2]);
	printf("%d\n",s.top()-4000);
	printf("%d",v[n-1]-v[0]);
}