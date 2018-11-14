#include<stdio.h>
#include<string.h>

int main(void)
{
    enum{M=3,N=4}; // M 为学生人数，N 为测验次数 
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
	int score_row,score_col,report_row,report_col,count; // FIND 为查找标志， count 为学生真实参加测验次数
	
    double average=0; // average 为平均成绩，variance 为成绩方差

    // 初始化报表数据 
    memset(report,0,sizeof(report));
   	
	// 将测验成绩预置为 -1 
 	for(report_row=0;report_row<M;report_row++)
    {
		for(report_col=1; report_col<=N; report_col++)
    	{
	    	report[report_row][report_col]=-1;
	    }
    }
    
    // 将测验成绩写入报表
    for(score_row=0; score[score_row][0]!=0 && score_row<M*N; score_row++)
    {
	    //定位报表中需写入数据的行 
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
	// 统计报表中每行成绩的算术平均值
	for(report_row=0; report[report_row][0]!=0 && report_row<M; report_row++)
	{
		for(average=0,count=N,report_col=1;report_col<=N;report_col++)
		{
			if(report[report_row][report_col]<0) //如果学生没参加测验，则测验次数减 1
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
	
	// 按学生成绩倒序对报表排序 
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
	
	// 输出报表表头 
    printf("%10s","学号 ");
	for(count=1;count<=N;count++)
	{
		printf("测验%d ",count);
	}
	printf("平均成绩\n");
	
	// 输出报表数据 
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
