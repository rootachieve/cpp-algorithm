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
int heap[400001];
int n;
int Count;
void push(int x) {
	Count++;
	heap[Count] = x;
	bool ch = false;
	int node = Count;
	do {
	ch = false;
		if (node != 1) {
			if (heap[node / 2] < heap[node]) {
				int temp = heap[node/2];
				heap[node/2] = heap[node];
				heap[node] = temp;

				node = node/2;
				ch = true;
			}
		}
	}while(ch);
}

int pop() {
	if (Count != 0) {
		int top = heap[1];
		heap[1] = heap[Count];
		Count--;
		bool ch = false;
		int node = 1;
		do {
		ch = false;
			if (node*2+1<=Count) {
				if(heap[node*2]>heap[node*2+1]){
					if (heap[node * 2] > heap[node]) {
						int temp = heap[node * 2];
						heap[node * 2] = heap[node];
						heap[node] = temp;

						node = node * 2;
						ch = true;
					}
				}
				else {
					if (heap[node * 2 + 1] > heap[node]) {
						int temp = heap[node * 2 + 1];
						heap[node * 2 + 1] = heap[node];
						heap[node] = temp;

						node = node * 2 + 1;
						ch = true;
					}
				}
			}
			else if(node*2<=Count) {
				if (heap[node * 2] > heap[node]) {
					int temp = heap[node * 2];
					heap[node * 2] = heap[node];
					heap[node] = temp;

					node = node * 2;
					ch = true;
				}
			}
		} while (ch);
		return top;
	}
	return 0;
}

int main() {
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		if (a == 0) {
			printf("%d\n",pop());
		}
		else {
			push(a);
		}
	}
}