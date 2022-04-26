#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include<cmath>
#include<cstring>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;
int n;
string temp;

int main() {
	int left = 4;
	int right = 4;
	bool del = false;
	bool err = false;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		cin>>temp;
		left = 4;
		right = 4;
		err = false;
		del = false;
		int a = 0;
		int b = temp.size()-1;
		while (a <= b) {
			if (temp[a] != temp[b]) {
				if (del) {
					err = true;
					break;
				}
				else {
					del = true;
					a--;
				}
			}
			a++;
			b--;
		}
		if (err) {
			left = 2;
		}
		else if (del) {
			left = 1;
		}
		else {
			left = 0;
		}

		err = false;
		del = false;
		a = 0;
		b = temp.size() - 1;
		while (a <= b) {
			if (temp[a] != temp[b]) {
				if (del) {
					err = true;
					break;
				}
				else {
					del = true;
					b++;
				}
			}
			a++;
			b--;
		}
		if (err) {
			right = 2;
		}
		else if (del) {
			right = 1;
		}
		else {
			right = 0;
		}
		printf("%d\n",min(left,right));
	}
}