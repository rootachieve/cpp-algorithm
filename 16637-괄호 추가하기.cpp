#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 100000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
string s;
long long Max = -MAX;
void back(int index,long long value) {
	if (index == s.size() - 1) {
		Max= max(Max,value);
	}else{
		int a = 0;
		if(index+4<s.size()){
			if (s[index + 3] == '+') {
				a = (s[index+2]-48)+(s[index+4]-48);
			}
			else if (s[index + 3] == '*') {
				a = (s[index + 2] - 48) * (s[index + 4] - 48);
			}
			else {
				a = (s[index + 2] - 48) - (s[index + 4] - 48);
			}
		}



		if (s[index+1] == '+') {
			back(index + 2, value + (s[index + 2] - 48));
			if (index + 4 < s.size()) {
				back(index+4,value+a);
			}
		}
		else if (s[index+1]== '*') {
			back(index + 2, value * (s[index + 2] - 48));
			if (index + 4 < s.size()) {
				back(index + 4, value * a);
			}
		}
		else {
			back(index + 2, value - (s[index + 2] - 48));
			if (index + 4 < s.size()) {
				back(index + 4, value - a);
			}
		}
	}
}
int n;
int main() {
	scanf("%d",&n);
	cin>>s;

	if (n == 1) {
		printf("%d",s[0]-48);
		return 0;
	}
	back(0,s[0]-48);
	if (s[1] == '+') {
		back(2, (s[0]-48) + (s[2]-48));
	}
	else if (s[1] == '*') {
		back(2, (s[0] - 48) * (s[2] - 48));
	}
	else {
		back(2, (s[0] - 48) - (s[2] - 48));
	}
	printf("%lld",Max);
}