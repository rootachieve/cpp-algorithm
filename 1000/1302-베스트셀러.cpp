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

map<string,int> m1;
map<int,string> m2;
int n;
int Count;
int ans[1002];
int main() {
	cin>>n;
	string temp;
	for (int i = 1; i <= n; i++) {
		cin>>temp;
		if (m1.find(temp) == m1.end()) {
			ans[++Count]++;
			m1.insert({temp,Count});
			m2.insert({Count,temp});
		}
		else {
			ans[m1.find(temp)->second]++;
		}
	}

	int Max = 0;
	int MaxLoc = -1;
	for (int i = 1; i <= Count; i++) {
		if (Max < ans[i]) {
			Max = ans[i];
			MaxLoc = i;
		}
		else if (Max == ans[i]) {
			if (m2.find(i)->second < m2.find(MaxLoc)->second) {
				Max = ans[i];
				MaxLoc = i;
			}
		}
	}

	cout<<m2.find(MaxLoc)->second;

}