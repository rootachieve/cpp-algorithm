#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 1000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

multiset<int> s;
string temp;
int n;
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		s.clear();
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			cin>> temp;
			if (temp == "I") {
				cin >> temp;
				s.insert(stoi(temp));
			}
			else {
				cin>>temp;
				if (temp == "-1") {
					if (!s.empty())
						s.erase(s.begin());
				}
				else {
					if (!s.empty())
						s.erase(--s.end());
				}
			}

		}
		if (s.empty()) {
			printf("EMPTY\n");
		}else{
			printf("%d %d\n", *--s.end(), *s.begin());
		}
	}
}