#include<iostream>
#include<stdio.h>
int main()
{
	FILE* f, * g;
	int a, b, c, t;
	fopen_s(&f,"SO.INP", "rt");
	fscanf_s(f, "%d%d%d", &a, &b, &c);
	t = a + b + c;
	fopen_s(&g,"KETQUA.OUT", "wt");
	fprintf(g, "%d\n", t);
	fprintf(g, "%.2f\n", t / 3.0);
	fclose(f);
	fclose(g);
	return 0;
}