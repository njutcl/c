#include<stdio.h>

int main(void)
{
    double average_scoring_LinD_1,average_scoring_LinD_2,average_scoring_LiCW_1,average_scoring_LiCW_2;

    //ȡ�õ�1��ͳ������
    average_scoring_LiCW_1 = 11./5;
    average_scoring_LiCW_2 = 5./3;
    average_scoring_LinD_1 = 10./4;
    average_scoring_LinD_2 = 11./4;
    //�Աȵ�1��ͳ�����
    printf("��1������ΰƽ�������÷�\n�ϰ�֣�%.2lg\n�°�֣�%.2lg\n\n",average_scoring_LiCW_1,average_scoring_LiCW_2);
    printf("��1���ֵ�ƽ�������÷�\n�ϰ�֣�%.2lg\n�°�֣�%.2lg\n\n",average_scoring_LinD_1,average_scoring_LinD_2);
    printf("��1������ΰƽ�������÷��ϰ�ֱ��°��%s��\n",(average_scoring_LiCW_1>=average_scoring_LiCW_2)?"��":"��");
    printf("��1���ֵ�ƽ�������÷��ϰ�ֱ��°��%s��\n\n",(average_scoring_LinD_1>=average_scoring_LinD_2)?"��":"��");
    printf("��1���ϰ������ΰƽ�������÷ֱ��ֵ�%s��\n",(average_scoring_LiCW_1>=average_scoring_LinD_1)?"��":"��");
    printf("��1���°������ΰƽ�������÷ֱ��ֵ�%s��\n",(average_scoring_LiCW_2>=average_scoring_LinD_2)?"��":"��");

    //ȡ�õ�2��ͳ�����ݣ��벹��ע��������Ĵ��룩
    average_scoring_LiCW_1 = 11./7;
    average_scoring_LiCW_2 = 6./5;
    average_scoring_LinD_1 = 10./7;
    average_scoring_LinD_2 = 11./5;
    //�Աȵ�2��ͳ��������벹��ע��������Ĵ��룩
    printf("��2������ΰƽ�������÷�\n�ϰ�֣�%.2lg\n�°�֣�%.2lg\n\n",average_scoring_LiCW_1,average_scoring_LiCW_2);
    printf("��2���ֵ�ƽ�������÷�\n�ϰ�֣�%.2lg\n�°�֣�%.2lg\n\n",average_scoring_LinD_1,average_scoring_LinD_2);
    printf("��2������ΰƽ�������÷��ϰ�ֱ��°��%s��\n",(average_scoring_LiCW_1>=average_scoring_LiCW_2)?"��":"��");
    printf("��2���ֵ�ƽ�������÷��ϰ�ֱ��°��%s��\n\n",(average_scoring_LinD_1>=average_scoring_LinD_2)?"��":"��");
    printf("��2���ϰ������ΰƽ�������÷ֱ��ֵ�%s��\n",(average_scoring_LiCW_1>=average_scoring_LinD_1)?"��":"��");
    printf("��2���°������ΰƽ�������÷ֱ��ֵ�%s��\n",(average_scoring_LiCW_2>=average_scoring_LinD_2)?"��":"��");


    return 0;
}
