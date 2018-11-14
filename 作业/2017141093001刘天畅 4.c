#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int n=24,i=0,player1=0,player2=0; //player1,player2保存玩家每次抓取的石子数
    char player[5][11]={"","刘备","关羽","张飞","旺财"};

	//输入真实玩家姓名
	printf("共有%d颗石子，请每次抓取1~4颗，最后一位抓完的获胜！\n",n);
	printf("请输入玩家姓名:");
	fflush(stdin); //清理输入缓冲区
	scanf("%10s",player[0]);

	//生成电脑玩家姓名
	srand(time(NULL)); //设置随机数种子
	i=rand()%4+1; //生成1~4随机数，用来取出预定义的玩家姓名
	printf("%s VS. %s，%s先抓！\n\n",player[0],player[i],player[0]);

	while(n>0)
	{
		//真实玩家抓石头
		printf("%s:",player[0]);
		do
		{
			fflush(stdin);
			scanf("%d",&player1);
		    if(player1<1 || player1>4)
			{
    		    printf("输入错误，请重新输入！\n");
    		    player1=0;
		    }
		}while(!player1);

		//判断真实玩家是否获胜
		if( n < player1 )
		{
			player1=n;
		}
		n-=player1;
		if(n==0)
		{
			printf("%s获胜！\n",player[0]);
			break;
		}

		//电脑玩家抓石头并判断电脑玩家是否获胜
    player2=rand()%4+1;
	printf("%s抓了%d颗\n",player[i],player2);
	if( n < player2 )
		{
			player2=n;
		}
		n-=player2;
		if(n==0)
		{
			printf("%s获胜！\n",player[i]);
			break;
		}
		//打印剩余石头数
        printf("还剩%d颗!\n\n",n);  
	}

	return 0;
}
