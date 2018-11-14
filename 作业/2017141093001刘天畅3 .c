#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(void)
{
    enum {N=6};
    char coupon[N][100]={"谢谢参与",
                    "京豆 2 个",
                    "京豆 3 个",
                    "京豆 6 个",
                    "京豆 8 个",
                    "￥50 券"};
    int place[N],count=0,n,i;

    //将位置数组中数据全部预置为 -1
    memset(place,-1,sizeof(place));

    //显示 6 个位置
    printf("┌──────────┬──────────┬──────────┐\n");
    printf("│  位置 1  │  位置 2  │  位置 3  │\n");
    printf("├──────────┼──────────┼──────────┤\n");
    printf("│  位置 4  │  位置 5  │  位置 6  │\n");
    printf("└──────────┴──────────┴──────────┘\n");

    //将随机数 0~5 放入位置数组
    srand(time(NULL)); //设置随机数种子
    while(count<6)
    {
        n=rand()%6; //生成 0~5 之间的随机数放入变量 n
        for(i=0;i<N;i++)
        {
            if(n==place[i])
                break;
        }
        if(i==N)
        {
            place[count++]=n;
        }
    }

    //用户选择位置
    printf("请选择 1 个位置（1~6）：");
    scanf("%d",&n);

    //输出抽中结果
    printf("┌──────────┬──────────┬──────────┐\n");
    printf("│%10s│%10s│%10s│\n",coupon[place[0]],coupon[place[1]],coupon[place[2]]);
    printf("├──────────┼──────────┼──────────┤\n");
    printf("│%10s│%10s│%10s│\n",coupon[place[3]],coupon[place[4]],coupon[place[5]]);
    printf("└──────────┴──────────┴──────────┘\n");
    printf("您获得了：%s ！\n",coupon[place[n-1]]);

    return 0;
}
