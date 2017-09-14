#include "strain.h"

using namespace std;

train::train()
{
    d[1]=10;//init distances
    d[2]=20;
    d[3]=30;
    d[4]=40;
    d[5]=50;
    d[6]=60;
    d[7]=70;
    d[8]=80;
    d[9]=90;
    for (int i = 1; i < 10; i++)a[i] = 10;
    for (int i = 1; i <= 49; i++)m[i] = INF, lazy[i] = 0; // init segment tree
	
	build(1, 1, 10 - 1);
	//----------------------------------------
	scc = 1;
	head = -1;
    c[0].s = -1;//insert guard
	c[0].next = head;
	head = 0;
	for (int i = 0; i < 100; i++)vis[i] = false;
	vis[0] = true;
}

void train::printa()
{
	for (int i = 1; i < 40; i++)
	{
		printf("%d ",m[i]);
	}
	printf("\n");
}

int train::min(int a, int b)
{
	if (a > b)return b;
	else return a;
}

void train::build(int i, int l, int r)
{
    if (l == r)//lazy-tag
	{
		m[i] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * i, l, mid);
	build(2 * i + 1, mid + 1, r);
	m[i] = min(m[2 * i], m[2 * i + 1]);
}

int train::query(int i, int l, int r, int L, int R)
{
	if (L <= l&&r <= R)
	{
		return m[i] + lazy[i];
	}
	if (lazy[i])
	{
		lazy[i * 2] += lazy[i];
		lazy[i * 2 + 1] += lazy[i];
		lazy[i] = 0;
	}
	int mid = (l + r) / 2;
	int ret = INF;
	if (L <= mid)
		ret = min(ret, query(i * 2, l, mid, L, R));
	if (R > mid)
		ret = min(ret, query(i * 2 + 1, mid + 1, r, L, R));
	return ret;

}

void train::update(int i, int l, int r, int L, int R, int val)
{
	if (L > r || R < l)return;
	if (L <= l&&R >= r)
	{
		lazy[i] += val;
		return;
	}
	if (lazy[i])
	{
		lazy[i * 2] += lazy[i];
		lazy[i * 2 + 1] += lazy[i];
		lazy[i] = 0;
	}
	int mid = (l + r) / 2;
	update(2 * i, l, mid, L, R, val);
	update(2 * i + 1, mid + 1, r, L, R, val);
	m[i] = min(m[2 * i] + lazy[i * 2], m[2 * i + 1] + lazy[i * 2 + 1]);
}

void train::buy(int s,int t, string name, string id)
{
	update(1, 1, 10 - 1, s, t-1,-1);
	insert(s, t, name, id);
}

int train::rest(int s, int t)
{
	int x = query(1, 1, 10 - 1, s, t-1); 
    return x;
}


int train::find_by_name(string name)
{
	for (int i = head; i != -1; i = c[i].next)
	{
		if (c[i].name == name)
			return i;
	}
	return -1;
}
int train::find_by_id(string id)
{
	for (int i = head; i != -1; i = c[i].next)
	{
		if (c[i].id == id)
			return i;
	}
	return -1;
}

void train::refund_by_name(string name)
{
	int x = find_by_name(name);
	int s = c[x].s;
	int t = c[x].t;
	update(1, 1, 10 - 1, s, t - 1, 1);
	del(x);
}
void train::refund_by_id(string id)
{
	int x = find_by_id(id);
	int s = c[x].s;
	int t = c[x].t;
	update(1, 1, 10 - 1, s, t - 1, 1);
	del(x);
}

void train::insert(int s, int t, string name, string id)
{
	int x = -1;
	for (int i = 0; i < 100; i++)
	{
		if (vis[i] == false)
		{
			vis[i] = true;
			x = i;
			break;
		}
	}
	scc = x;
	c[scc].s = s;
	c[scc].t = t;
	c[scc].name = name;
	c[scc].id = id;
	c[scc].next = head;
	c[scc].price = getprice(s, t);
	head = scc;
}

int train::getprice(int s, int t)
{
	int sum = 0;
	for (int i = s; i < t; i++)
	{
		sum += d[i];
	}
	return sum;
}

void train::del(int x)
{
	node y = c[c[x].next];
	vis[c[x].next] = false;
	c[x] = y;

}

node train::find(int x)
{
    return c[x];
}
