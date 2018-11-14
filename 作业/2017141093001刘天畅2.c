#include<stdio.h>

int main(void)
{
    double average_scoring_LinD_1,average_scoring_LinD_2,average_scoring_LiCW_1,average_scoring_LiCW_2;

    //取得第1局统计数据
    average_scoring_LiCW_1 = 11./5;
    average_scoring_LiCW_2 = 5./3;
    average_scoring_LinD_1 = 10./4;
    average_scoring_LinD_2 = 11./4;
    //对比第1局统计情况
    printf("第1局李宗伟平均连续得分\n上半局：%.2lg\n下半局：%.2lg\n\n",average_scoring_LiCW_1,average_scoring_LiCW_2);
    printf("第1局林丹平均连续得分\n上半局：%.2lg\n下半局：%.2lg\n\n",average_scoring_LinD_1,average_scoring_LinD_2);
    printf("第1局李宗伟平均连续得分上半局比下半局%s。\n",(average_scoring_LiCW_1>=average_scoring_LiCW_2)?"高":"低");
    printf("第1局林丹平均连续得分上半局比下半局%s。\n\n",(average_scoring_LinD_1>=average_scoring_LinD_2)?"高":"低");
    printf("第1局上半局李宗伟平均连续得分比林丹%s。\n",(average_scoring_LiCW_1>=average_scoring_LinD_1)?"高":"低");
    printf("第1局下半局李宗伟平均连续得分比林丹%s。\n",(average_scoring_LiCW_2>=average_scoring_LinD_2)?"高":"低");

    //取得第2局统计数据（请补充注释行下面的代码）
    average_scoring_LiCW_1 = 11./7;
    average_scoring_LiCW_2 = 6./5;
    average_scoring_LinD_1 = 10./7;
    average_scoring_LinD_2 = 11./5;
    //对比第2局统计情况（请补充注释行下面的代码）
    printf("第2局李宗伟平均连续得分\n上半局：%.2lg\n下半局：%.2lg\n\n",average_scoring_LiCW_1,average_scoring_LiCW_2);
    printf("第2局林丹平均连续得分\n上半局：%.2lg\n下半局：%.2lg\n\n",average_scoring_LinD_1,average_scoring_LinD_2);
    printf("第2局李宗伟平均连续得分上半局比下半局%s。\n",(average_scoring_LiCW_1>=average_scoring_LiCW_2)?"高":"低");
    printf("第2局林丹平均连续得分上半局比下半局%s。\n\n",(average_scoring_LinD_1>=average_scoring_LinD_2)?"高":"低");
    printf("第2局上半局李宗伟平均连续得分比林丹%s。\n",(average_scoring_LiCW_1>=average_scoring_LinD_1)?"高":"低");
    printf("第2局下半局李宗伟平均连续得分比林丹%s。\n",(average_scoring_LiCW_2>=average_scoring_LinD_2)?"高":"低");


    return 0;
}
