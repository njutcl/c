#include<stdio.h>
#include<string.h>

int main(void)
{
    enum{M=3,N=4}; // M Ϊѧ��������N Ϊ������� 
    int score[M*N][3]={
    	201701001,1,92,
		201701001,2,78,
		201701001,3,83,
		201701001,4,89,
		201701002,1,90,
		201701002,2,89,
		201701002,4,92,
		201701003,1,94,
		201701003,2,90,
		201701003,3,92,
		201701003,4,91
    };
	int report[M][6],i=0,j=0,tmp;
	int score_row,score_col,report_row,report_col,count; // FIND Ϊ���ұ�־�� count Ϊѧ����ʵ�μӲ������
	
    double average=0; // average Ϊƽ���ɼ���variance Ϊ�ɼ�����

    // ��ʼ���������� 
    memset(report,0,sizeof(report));
   	
	// ������ɼ�Ԥ��Ϊ -1 
 	for(report_row=0;report_row<M;report_row++)
    {
		for(report_col=1; report_col<=N; report_col++)
    	{
	    	report[report_row][report_col]=-1;
	    }
    }
    
    // ������ɼ�д�뱨��
    for(score_row=0; score[score_row][0]!=0 && score_row<M*N; score_row++)
    {
	    //��λ��������д�����ݵ��� 
		for(report_row=0; report[report_row][0]!=0 && report[report_row][0]!=score[score_row][0]; report_row++)
	    	 ;
    	
    	for(report_col=1;score[score_row][1]!=report_col && report_col<5; report_col++)
			; 
	    
	    if(report_row<M && report_col<=N)
		{
			report[report_row][0]=score[score_row][0];
			report[report_row][report_col]=score[score_row][2];
		} 
	    
    }
	// ͳ�Ʊ�����ÿ�гɼ�������ƽ��ֵ
	for(report_row=0; report[report_row][0]!=0 && report_row<M; report_row++)
	{
		for(average=0,count=N,report_col=1;report_col<=N;report_col++)
		{
			if(report[report_row][report_col]<0) //���ѧ��û�μӲ��飬���������� 1
			{
				count--;
			}
			else
			{
				average+=report[report_row][report_col];
			}
		}
		average/=count;
		report[report_row][N+1]=average+0.5;
	}
	
	// ��ѧ���ɼ�����Ա������� 
	for(i=0;i<M;i++)
		   for(report_row=0;report_row<M-1;report_row++)
	   {	 		  
		 {
 		}  if(report[report_row][N+1]<report[report_row+1][N+1])
		   {
			   for(j=0;j<=N+1;j++)
			   {
			   tmp=report[report_row][j];
			report[report_row][j]=report[report_row+1][j];
			report[report_row+1][j]=tmp;
			   }
		   }
	   }
	
	// ��������ͷ 
    printf("%10s","ѧ�� ");
	for(count=1;count<=N;count++)
	{
		printf("����%d ",count);
	}
	printf("ƽ���ɼ�\n");
	
	// ����������� 
    for(report_row=0; report_row<M; report_row++)
    {
        printf("%10d",report[report_row][0]);
        for(report_col=1;report_col<=N;report_col++)
        {
        	printf("%6d",report[report_row][report_col]);
        }
        printf("%8d\n",report[report_row][N+1]);
    }
    
    return 0;
}
