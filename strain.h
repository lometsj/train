#include <stdio.h>
#include <tchar.h>
#include <thread>
#include <iostream>

#define INF 1000000000
#pragma once

using namespace std;


struct node
{
	int next;
	int s;
	int t;
	int price;
	string name;
	string id;
};


class train
{
public:
    node find(int x);
    int getprice(int s, int t);
	void printa();
	//void printm();
	void buy(int s, int t,string name,string id);
    int rest(int s, int t);
	int find_by_name(string name);
	int find_by_id(string id);
	void refund_by_name(string name);
	void refund_by_id(string id);
	void printc();
	train();
private:

	int query(int i,int l,int r,int L,int R);
	void update(int i, int l, int r, int L, int R, int val);
	void build(int i, int l, int r);
	int a[20];
	int d[20];
	int m[10 * 4 + 10];
	int lazy[10 * 4 + 10];
	int min(int a,int b);
	//-----------------segment tree-------------
	node c[100];
	int head;
	bool vis[100];
	int scc;
	void insert(int s, int t, string name, string id);
	void del(int x);
	//----------------link list---------
};

