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

    //�� customer �ļ�
    fp=fopen("customer.csv","r");
    if(!fp){
        printf("�ļ���ʧ�ܣ�\n");
        exit(1);
    }

    while((c=fgetc(fp))!=EOF){
        if(c=='\n')
            records++;
    }
    rewind(fp);

    //���� customer ���ڴ�ռ�
    customer=(char(*)[12])malloc(records*12);
    winner=(char**)malloc(count*sizeof(char*));
    if(!customer || !winner){
        printf("�ڴ����ʧ�ܣ�\n");
        exit(2);
    }

    //����Ŀռ�����
    memset(customer,0,records*12);
    memset(winner,0,count*sizeof(char*));

    //���� customer �ļ�����
    for(i=0;!feof(fp)&&i<records;i++){
        fgets((char*)(customer+i),12,fp);
        fgetc(fp);
    }

    for(i=0;i<records;i++){
        puts((char*)(customer+i));
    }

    //�齱
    draw(customer,records,winner,count);

    //��ӡ�н�������
	printf("\n�н���:\n");
    for(i=0;i<count;i++){
        puts(winner[i]);
    }

    //�ر��ļ�, �ͷŶѿռ�
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
