#include <stdio.h>
#include <locale.h>
#include <math.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int a, *pa;
	float b, *pb;
	char c, *pc;
	
	a = 123;
	printf("/n A = %i", a);
	pa = &a;
	printf("/n a = %i", *pa);
	*pa = 321;
	printf("/n a = %i", a);
	
	b = 987;
	printf("/n b = %f", b);
	pb = &b;
	printf("/n b = %f", *pb);
	*pb = 789;
	printf("/n b = %f", b);
	
	c = '567';
	printf("/n c = %c", c);
	pc = &c;
	printf("/n c = %c", *pc);
	*pc = '765';
	printf("/n c = %c", c);
	
	
	printf("/n/n b = %f /n a = %f /n c = %f /n pb = %f /n pa = %f /n pc = %f", b, a, c, *pb, *pa, *pc);
}
