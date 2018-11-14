#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

int main(void){
    enum{M=3,N=9}; // M Ϊ������Ŀ����N Ϊ�������п��
    FILE* fp;
    int a[N][N],b[N][N]; // b �洢ԭʼ����
	int count_row[N];
	int count_column[N];
	int count_block[N];
	int line,n,count,row,col,block,w; //line Ϊ��Ŀ��, n Ϊ�û�������, count Ϊ�ո�����

    //�����������ļ�
    fp=fopen("sudoku.dat","r");
    if(!fp){
        printf("�ļ���ʧ�ܣ�\n");
        exit(1);
    }

    //���ѡ��һ��������
    srand(time(NULL));
    line=rand()%M;
    fseek(fp,163*line,0); //ÿ������������ļ��д洢ռ�� 163 �ֽ�

    //�������ļ��������ݲ�д������
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            fscanf(fp,"%d,",a[row]+col);
            b[row][col]=a[row][col];
            if(a[row][col]<0||a[row][col]>9){
                printf("���ݶ�ȡ����\n");
                exit(2);
            }
        }
    }

    //�ر������ļ�
    fclose(fp);

    //��ʾ��ʼ����
    system("cls");
    printf("�����Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ���\n");
    for(row=0;row<N;row++){
        printf("��");

        for(col=0;col<N;col++){
            if(!a[row][col])
                printf("  ��");
            else
                printf("%2d��",a[row][col]);
        }

        if(row<N-1){
            printf("\n��");
            for(col=0;col<N-1;col++){
                printf("����");
            }
            printf("����\n");
        }
    }
    printf("\n�����ة��ة��ة��ة��ة��ة��ة��ة���\n");

    //�����û����ݲ�ˢ����ʾ����
    while(1){
        //ͳ�ƿո�����
        count=0;
        for(row=0;row<N;row++){
            for(col=0;col<N;col++){
                if(!a[row][col]){
                    count++;
                }
    	    }
        }

        //����ѭ��������
        if(!count)
            break;

        //��������
        fflush(stdin);
        printf("�������к��к�����ֵ��");
        scanf("%d%d%d",&row,&col,&n);

        //����������Ч��
        if(row<0 || row>9 || col<0 || col>9 || n<0 || n>9)
            continue;

        //д������
        if(b[row-1][col-1]==0) //ԭʼλ��Ϊ�յĸ��ӿ��������û���������
            a[row-1][col-1]=n;

        //ˢ����ʾ����
        system("cls");
	    printf("�����Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ���\n");
	    for(row=0;row<N;row++){
            printf("��");

            for(col=0;col<N;col++){
                if(!a[row][col])
                    printf("  ��");
                else
                    printf("%2d��",a[row][col]);
            }

		    if(row<N-1){
                printf("\n��");
		        for(col=0;col<N-1;col++){
        			printf("����");
        		}
   			    printf("����\n");
		    }
    	}
    	printf("\n�����ة��ة��ة��ة��ة��ة��ة��ة���\n");
	}

    //�ж�ʤ��
    //���9����9�еļ�� 
    
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
    //���9����ļ�� 
	
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
  	      printf("��Ӯ����\n");
  }

   if(w==0)
 {
          printf("�����ˣ�\n");
 }
   return 0; 
}


