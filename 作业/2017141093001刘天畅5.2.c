#include<stdio.h>


int main(void)
{
	int k,i;
	double a,x1,x2,power;

	while(1)
	{
		//输入并验证 k 合法性
		printf("请输入 k: ");
		fflush(stdin);
		scanf("%d",&k);
		if(k<=0)
		{
			printf("输入错误！\n");
			continue;
		}	
		
		//输入并验证 a 合法性 
		printf("请输入 a: ");
		fflush(stdin);
		scanf("%lf",&a);
		if(a<0 && k%2==0)
	 		printf("输入错误！\n");
		else
			break;
	}

	if(a==0)
	{
		x2=0;
	}
	else
	{
		x2=a;
		do
		{	
			x1=x2;
        	power=1;
			for(i=0;i<k-1;i++)
        	{
        		power*=x1;//power 运算 x1 的 (k-1) 次方 
        	}
			x2=((double)(k-1)/k)*x1+(double)a/(k*power);
        	
		} while(abs(x2-x1)>=1E-7);	
	}
 		
	printf("%d√%lg : %lg\n",k,a,x2);

	return 0;
}
