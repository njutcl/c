#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int n=24,i=0,player1=0,player2=0; //player1,player2�������ÿ��ץȡ��ʯ����
    char player[5][11]={"","����","����","�ŷ�","����"};

	//������ʵ�������
	printf("����%d��ʯ�ӣ���ÿ��ץȡ1~4�ţ����һλץ��Ļ�ʤ��\n",n);
	printf("�������������:");
	fflush(stdin); //�������뻺����
	scanf("%10s",player[0]);

	//���ɵ����������
	srand(time(NULL)); //�������������
	i=rand()%4+1; //����1~4�����������ȡ��Ԥ������������
	printf("%s VS. %s��%s��ץ��\n\n",player[0],player[i],player[0]);

	while(n>0)
	{
		//��ʵ���ץʯͷ
		printf("%s:",player[0]);
		do
		{
			fflush(stdin);
			scanf("%d",&player1);
		    if(player1<1 || player1>4)
			{
    		    printf("����������������룡\n");
    		    player1=0;
		    }
		}while(!player1);

		//�ж���ʵ����Ƿ��ʤ
		if( n < player1 )
		{
			player1=n;
		}
		n-=player1;
		if(n==0)
		{
			printf("%s��ʤ��\n",player[0]);
			break;
		}

		//�������ץʯͷ���жϵ�������Ƿ��ʤ
    player2=rand()%4+1;
	printf("%sץ��%d��\n",player[i],player2);
	if( n < player2 )
		{
			player2=n;
		}
		n-=player2;
		if(n==0)
		{
			printf("%s��ʤ��\n",player[i]);
			break;
		}
		//��ӡʣ��ʯͷ��
        printf("��ʣ%d��!\n\n",n);  
	}

	return 0;
}
