#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

int main(void){
    enum{M=3,N=9}; // M 为数独题目数，N 为数组行列宽度
    FILE* fp;
    int a[N][N],b[N][N]; // b 存储原始数据
	int count_row[N];
	int count_column[N];
	int count_block[N];
	int line,n,count,row,col,block,w; //line 为题目号, n 为用户输入数, count 为空格子数

    //打开数独数据文件
    fp=fopen("sudoku.dat","r");
    if(!fp){
        printf("文件打开失败！\n");
        exit(1);
    }

    //随机选择一套数独题
    srand(time(NULL));
    line=rand()%M;
    fseek(fp,163*line,0); //每套题的数据在文件中存储占用 163 字节

    //从数据文件读出数据并写入数组
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            fscanf(fp,"%d,",a[row]+col);
            b[row][col]=a[row][col];
            if(a[row][col]<0||a[row][col]>9){
                printf("数据读取错误！\n");
                exit(2);
            }
        }
    }

    //关闭数据文件
    fclose(fp);

    //显示初始界面
    system("cls");
    printf("┌─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");
    for(row=0;row<N;row++){
        printf("│");

        for(col=0;col<N;col++){
            if(!a[row][col])
                printf("  │");
            else
                printf("%2d│",a[row][col]);
        }

        if(row<N-1){
            printf("\n├");
            for(col=0;col<N-1;col++){
                printf("─┼");
            }
            printf("─┤\n");
        }
    }
    printf("\n└─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");

    //接收用户数据并刷新显示界面
    while(1){
        //统计空格子数
        count=0;
        for(row=0;row<N;row++){
            for(col=0;col<N;col++){
                if(!a[row][col]){
                    count++;
                }
    	    }
        }

        //结束循环的条件
        if(!count)
            break;

        //输入数据
        fflush(stdin);
        printf("请输入行号列号与数值：");
        scanf("%d%d%d",&row,&col,&n);

        //检验数据有效性
        if(row<0 || row>9 || col<0 || col>9 || n<0 || n>9)
            continue;

        //写入数据
        if(b[row-1][col-1]==0) //原始位置为空的格子可以允许用户放入数据
            a[row-1][col-1]=n;

        //刷新显示界面
        system("cls");
	    printf("┌─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");
	    for(row=0;row<N;row++){
            printf("│");

            for(col=0;col<N;col++){
                if(!a[row][col])
                    printf("  │");
                else
                    printf("%2d│",a[row][col]);
            }

		    if(row<N-1){
                printf("\n├");
		        for(col=0;col<N-1;col++){
        			printf("─┼");
        		}
   			    printf("─┤\n");
		    }
    	}
    	printf("\n└─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");
	}

    //判定胜负
    //针对9行与9列的检查 
    
   for(row=0;row<N;row++)
	 {
	    memset(count_row,0,9*sizeof(int));
		for(col=0;col<N;col++)
		{
			count_row[a[row][col]-1]++;
		}
	 }
     for(col=0;col<N;col++)
		{
	if(count_row[col]!=1)
	 {    
	        w=0;
			return 0;
		}
    }

     for(col=0;col<N;col++)
	 {
	    memset(count_column,0,9*sizeof(int));
		for(row=0;row<N;row++)
		{
			count_column[a[row][col]-1]++;
		}
	 }
     for(row=0;row<N;row++)
		{
	if(count_column[row]!=1)
	 {    
	        w=0;
			return 0;
		}
    }
    //针对9个块的检查 
	
    for(block=0;block<N;block++)
		memset(count_block,0,9*sizeof(int));
	for(row=block/3*3;row<block/3*3+3;row++)
	{
		for(col=block/3*3;col<block%3*3+3;col++)
		{
			count_block[a[row][col]-1]++;
		}
	}
	for(col=0;col<N;col++)
	{
		if(count_block[col]!=1)
		{
			w=0;
			return 0;
		}
    }
   if(w==1)
  {
  	      printf("你赢啦！\n");
  }

   if(w==0)
 {
          printf("你输了！\n");
 }
   return 0; 
}


