#include<iostream>
#include<math.h>
using namespace std;
struct 	node
{
	int info;
	struct node* next;
};
struct list
{
	node* head, * tail;
};
node* taonut(int x)
{
	node* p = new node; p->info = x; p->next = NULL;
	return p;
}
void themnut(list& l, node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void nhapdanhsach(list& l)
{
	int x, n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		themnut(l,taonut(x));
	}
}
void xuatdanhsach(list l)
{
	cout << endl;
	for (node* p = l.head; p != NULL; p = p->next)
		cout << p->info << " ";
}
int tong(list l)
{
	int sum = 0;
	for (node* p = l.head; p != NULL; p = p->next)
		sum = sum + p->info;
	return sum;
}
int checknt(int n)
{
	if (n < 2) return 0;
	int k = sqrt(n);
	for (int i = 2; i <= k; i++)
		if (n % i == 0) return 0;
	return 1;
}
int demnt(list l)
{
	int d = 0;
	for (node* p = l.head; p != NULL; p = p->next)
		if (checknt(p->info))
			d++;
	return d;
}
int timkiem(list l)
{
	int x;
	cin >> x;
	int flag = 0;
	for (node* p = l.head; p != NULL; p = p->next)
		if (p->info == x)
		{
			flag = 1;
			break;
		}
	return flag;
}
void tachdanhsach(list l, list& l1, list& l2)
{
	for (node* p = l.head; p != NULL; p = p->next)
		if (p->info % 2 != 0)
			themnut(l1, taonut(p->info));
		else
			themnut(l2, taonut(p->info));
}
void daonguoclist(list& l)
{
	node* parent = l.head;
	node* current = l.head->next;
	l.head = current->next;
	parent->next = NULL;
	current->next = parent;
	while (l.head->next) {
		parent = current;
		current = l.head;
		l.head = l.head->next;
		current->next = parent;
	}
	l.head->next = current;
}
node* xoaso(list &l,int key) 
{
	node* current = l.head;
	node* previous = NULL;
	while (current->info != key) {
		if (current->next == NULL)
			return NULL;
		else {
			previous = current;
			current = current->next;
		}
	}
	if (current == l.head)
		l.head = l.head->next;
	else
		previous->next = current->next;
	return current;
}
list l, l1, l2;
int main()
{
	nhapdanhsach(l);
	cout << "cau a: " << tong(l) << endl;
	cout << "cau b: " << demnt(l) << endl;
	cout << "cau c: " << timkiem(l) << endl;
	tachdanhsach(l, l1, l2);
	cout << "cau d: " << endl << "Danh sach so chan:";
	xuatdanhsach(l2);
	cout << "\nDanh sach so le:";
	xuatdanhsach(l1);
	daonguoclist(l);
	cout << "\ncau e:";
	xuatdanhsach(l);
	for (node* p = l.head; p != NULL; p = p->next)
		if (checknt(p->info))
			xoaso(l,p->info);
	cout << "\ncau f:";
	xuatdanhsach(l);
	return 0;
}