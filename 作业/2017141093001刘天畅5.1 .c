#include<stdio.h>

int main(void)
{
	int f1=0,f2=1,f3,n,i;

	printf("�����������������: ");
	while(1)
	{
		fflush(stdin);
		scanf("%d",&n);
		if(n<=0)
			printf("�������\n");
		else
			break;
	}

	if(n==1)
		f3=0;
	else if(n==2)
		f3=1;
	else
	{  
	    for(i=3;i<=n;i++)
		{
		f3=f1+f2;	
		f1=f2;
	    f2=f3;
		}
	} 
	
	printf("F%d = %d\n",n,f3);

	return 0;
}
