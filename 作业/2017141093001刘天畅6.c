#include<stdio.h>

int main(void)
{
    enum{N=100}; //Ԥ������������ᳬ�� 100 ��
    int score[N],i=0,n=0,count=0; // n Ϊѧ��Ӧ�μӲ��������count Ϊѧ����ʵ�μӲ������
    double average=0,variance=0; // average Ϊƽ���ɼ���variance Ϊ�ɼ�����

    while(1)
    {
        printf("������ѧ���������:");
        fflush(stdin);
        scanf("%d",&n);
        if(n<=0 || n>N)
        {
            printf("�������\n");
            continue;
        }
        else
        {
            break;
        }
    }

    //����ɼ���ͳ������ƽ��ֵ
     int sum=0;
    for(i=0;i<=n-1;i++)
   { 	
    printf("������ѧ������ɼ�(ȱ��������-1):");
    fflush(stdin);
    scanf("%d",&score[i]); 
     if(score[i]<-1 || score[i]>100) 
	 {
         printf("�������\n");
         i--;
       }
        if(score[i]!=-1)
	{
	count++;
	sum+=score[i];
	}
   }
	average=sum/count;
	 
    //ͳ�Ƴɼ�����
    for(i=0;i<=n-1;i++)
    {
	if(score[i]!=-1)
    variance+=(score[i]-average)*(score[i]-average)/count;
    }
    //����ɼ�����
    printf("ѧ���ɼ�����:%.2lf\n",variance);

    return 0;
}
