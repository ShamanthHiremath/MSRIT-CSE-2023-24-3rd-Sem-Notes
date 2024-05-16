#include <stdio.h>

struct complex
{
	int r;
	int i;
};

main()
{
	struct complex c1, c2, c;
	
	printf("enter first complex no. \n");
	scanf("%d%d", &c1.r, &c1.i); 
	
	printf("enter second complex no. \n");
	scanf("%d%d", &c2.r, &c2.i);

	c.r = c1.r + c2.r;
	c.i = c1.i + c2.i;

	printf("addtion \n");
	printf("real c.r %d \n", c.r);
	printf("imag c.i %d \n", c.i);
}
	 
