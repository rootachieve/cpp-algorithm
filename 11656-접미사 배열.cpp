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
#define RESET 0
using namespace std;
string arr[1001];
string Sortarr[1001];
string in;

void Sort(int s, int e) {
	if (s + 1 == e) {
		if (arr[s] > arr[e]) {
			string temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
		}
	}
	else if (s + 1 < e) {
		Sort(s,(s+e)/2);
		Sort((s+e)/2+1,e);
		int a = s;
		int b = (s+e)/2+1;
		int c = s;
		while (a <= (s + e) / 2 && b <= e) {
			if (arr[a]>arr[b]) {
				Sortarr[c] = arr[b];
				c++;
				b++;
			}
			else {
				Sortarr[c] = arr[a];
				a++;
				c++;
			}
		}

		if (a > (s + e) / 2) {
			while (b <= e) {
				Sortarr[c] = arr[b];
				c++;
				b++;
			}
		}
		else {
			while (a <= (s + e) / 2) {
				Sortarr[c] = arr[a];
				a++;
				c++;
			}
		}

		for (int i = s; i <= e; i++) {
			arr[i] = Sortarr[i];
		}
	}
}

int main() {
	cin>>in;
	for(int i = 0;i<in.size();i++){
		arr[i] = in.substr(i);
	}

	printf("");
	Sort(0,in.size()-1);
	for (int i = 0; i < in.size(); i++) {
		cout<<arr[i]<<endl;
	}
}