#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<time.h>

void draw(char (*customer)[12],int records,char** winner,int count);

int main(void){
    FILE* fp;
    char c;
    char (*customer)[12];
    char** winner;
    int records=0,count=3,i;

    //打开 customer 文件
    fp=fopen("customer.csv","r");
    if(!fp){
        printf("文件打开失败！\n");
        exit(1);
    }

    while((c=fgetc(fp))!=EOF){
        if(c=='\n')
            records++;
    }
    rewind(fp);

    //分配 customer 表内存空间
    customer=(char(*)[12])malloc(records*12);
    winner=(char**)malloc(count*sizeof(char*));
    if(!customer || !winner){
        printf("内存分配失败！\n");
        exit(2);
    }

    //分配的空间清零
    memset(customer,0,records*12);
    memset(winner,0,count*sizeof(char*));

    //读入 customer 文件内容
    for(i=0;!feof(fp)&&i<records;i++){
        fgets((char*)(customer+i),12,fp);
        fgetc(fp);
    }

    for(i=0;i<records;i++){
        puts((char*)(customer+i));
    }

    //抽奖
    draw(customer,records,winner,count);

    //打印中奖者名单
	printf("\n中奖者:\n");
    for(i=0;i<count;i++){
        puts(winner[i]);
    }

    //关闭文件, 释放堆空间
    fclose(fp);
    free(customer);
    free(winner);

    return 0;
}

void draw(char (*customer)[12],int records,char** winner,int count){
	int a,i,j;	
	char* tmp;
	
	srand(time(NULL));
	for(i=0;i<count;){
		a=1;
    	tmp=(char*)(customer+rand()%records);
    	for(j=0;j<=i;j++){
			if(tmp==winner[j]){
				a=0;
				break;
			}	
		}	
		if(a==1)
			winner[i++]=tmp;	
	}

	for(i=0;i<count;i++){
		for(j=0;j<count-i-1;j++){
			if(strcmp(winner[j],winner[j+1])>0){
	      		tmp=winner[j];
          		winner[j]=winner[j+1];
	      		winner[j+1]=tmp;
			}
		}
	}

}
