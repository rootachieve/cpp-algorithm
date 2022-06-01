#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

typedef struct Node {
	Node * left;
	Node * right;
	char V;
};

void insert(char data, Node* loc) {
	Node * N = (Node*)malloc(sizeof(Node));
	N->left = loc;
	N->right = NULL;
	N->V = data;
	if (loc->right != NULL) {
		loc->right->left = N;
		N->right = loc->right;
	}
	else {
		N->right = NULL;
	}
	loc->right = N;
}

void del(Node* loc) {
	if (loc->right != NULL) {
		loc->right->left = loc->left;
		loc->left->right = loc->right;
	}
	else {
		loc->left->right = NULL;
	}
	free(loc);
	
}

string in;

int main() {
	int t;
	cin>>t;
	Node * G = (Node*)malloc(sizeof(Node));

	Node* p = (Node*)malloc(sizeof(Node));
	G->left = NULL;
	G->right = NULL;
	while (t--) {
		cin>>in;
		p = G;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == '-') {
				if(p->left!=NULL){
					Node * temp = p->left;
					del(p);
					p = temp;
				}
			}
			else if (in[i] == '<') {
				if (p->left != NULL) {
					p = p->left;
				}
			}
			else if (in[i] == '>') {
				if (p->right != NULL) {
					p = p->right;
				}
			}
			else {
				insert(in[i],p);
				p = p->right;
			}
		}

		p = G;
		while (p->right != NULL) {
			p = p->right;
			printf("%c",p->V);
			del(p);
			p = G;
		}
		printf("\n");
	}
	p = G;
	free(p);
}
