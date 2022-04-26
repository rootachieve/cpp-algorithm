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
map<string,int> m;
char te[35];
string temp;

int base[10001];
int Count;
int sum;
int main() {
	while (!cin.eof()) {
		cin.getline(te,31);
		temp = te;
		if (temp == "") {
			break;
		}
		if (m.find(temp) == m.end()) {
			m.insert({temp,++Count});
			base[Count]++;

		}
		else {
			base[m.find(temp)->second]++;
		}
		sum++;
	}

	map<string,int>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		cout<<iter->first;
		printf(" %.4lf\n",(double)base[iter->second]/(double)sum*100);
	}
}