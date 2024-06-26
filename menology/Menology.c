/********************************************************************************

Copyright: 2024-2025
Version: 1.0
Date: 2024.6.17 
Author: dudble
Description：此程序用以实现月历的查询，Menology头文件包含了全局变量的声明与函数的定义

*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"Menology.h"



int main(){
    int year,month;
    printf("----------欢迎使用月历查询系统----------\n");
    printf("---请输入需要查询的月份 格式：（年 月）---\n");
    int n=1;
    while(n){
        scanf("%d %d",&year,&month);
        if(month<1||month>12){
            printf("月份错误，请重新输入\n");
        }else{
            n = 0;
        }
    }

    //计算闰年
    int leap=0;
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        leap = 1;
    }

    //计算该月第一天为星期几
    int c_month = month;
    if(c_month<=2) c_month+=12;
    int w = calculation(1,c_month,c_month>2 ? year : year-1);

    //依据该月第一天，将每一天计算出来
    int date[6][7] = {0};
    int d=1;
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(d>a_month[leap][month-1]){
                break;
            }
            if((i==0&&j>w)||i>0){
                date[i][j]=d;
                d++;
            }
        }
    }

    printf("\n\n");
    printf("     %d 年 %d 月\n",year,month);
    for(int i=0;i<7;i++)
        printf(" %s",week[i]);
    printf("\n");
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(date[i][j]==0) printf("   ");
            else{
                printf("%3d",date[i][j]);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
