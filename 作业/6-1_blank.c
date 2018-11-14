#include<stdio.h>

int main(void)
{
    enum{N=100}; //预估测验次数不会超过 100 次
    int score[N],i=0,n=0,count=0; // n 为学生应参加测验次数，count 为学生真实参加测验次数
    double average=0,variance=0; // average 为平均成绩，variance 为成绩方差

    while(1)
    {
        printf("请输入学生测验次数:");
        fflush(stdin);
        scanf("%d",&n);
        if(n<=0 || n>N)
        {
            printf("输入错误！\n");
            continue;
        }
        else
        {
            break;
        }
    }

    //输入成绩并统计算术平均值


    //统计成绩方差


    //输出成绩方差
    printf("学生成绩方差:%.2lf\n",variance);

    return 0;
}
