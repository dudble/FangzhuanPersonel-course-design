/***************************************************************************************
 
Copyright: 2024-2025
Version: 1.0
Date: 2024.6.18 
Author: double
Description：此程序用以实现铁道信息的简单记录查询，train头文件包含了结构体的声明以及排序时所用函数

**************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"train.h"

void write(){
    message msg;
    printf("请输入新增车次\n"
           "格式：车次 始发站 终点站 发车时间 到站时间 总票数 余票数 金额\n");
    scanf("%s %s %s %s %s %d %d %d",msg.trip,msg.begin,msg.end,msg.begin_t,msg.end_t,&msg.total,&msg.left,&msg.money);
    FILE *fp = fopen("message","a");//message文件在下没有提供，反正运行后自动就创建了（
    if(fp==NULL){
        printf("文件打开失败！\n");
        return ;
    }
    fwrite(&msg,sizeof(message),1,fp);
    fclose(fp);
    printf("\n");
}


//按照车次查询
void find_t(){

    FILE *fp = fopen("message","r");
    if(fp==NULL){
        printf("暂无数据QAQ\n");
        return ;
    }

    char s[7];
    printf("请输入需要查询的车次\n");
    scanf("%s",s);
    message msg;
    while(fread(&msg,sizeof(message),1,fp))
    {
        if(strcmp(msg.trip,s)==0)
        {
            printf("%s次 %s至%s 由%s开往%s方向，总票数 %d ,余 %d,票价 %d 元\n",msg.trip,msg.begin_t,msg.end_t,msg.begin,msg.end,msg.total,msg.left,msg.money);
            return ;
        }
    }
    printf("\n");
    fclose(fp);
}

//按照出发站查询
void find_begin(){

    FILE *fp = fopen("message","r");
    if(fp==NULL){
        printf("暂无数据QAQ\n");
        return ;
    }

    char b[50];
    printf("请输入始发站\n");
    scanf("%s",b);
    message msg;
    int f=1;
    while(fread(&msg,sizeof(message),1,fp))
    {
        if(strcmp(msg.begin,b)==0)
        {
            f=0;
            printf("%s次 %s至%s 开往%s方向，总票数 %d ,余 %d,票价 %d 元\n",msg.trip,msg.begin_t,msg.end_t,msg.end,msg.total,msg.left,msg.money);
        }
    }
    if(f) printf("暂无数据\n");
    printf("\n");
}

//按照目标站查询
void find_end(){

    FILE *fp = fopen("message","r");
    if(fp==NULL){
        printf("暂无数据QAQ\n");
        return ;
    }

    char e[50];
    printf("请输入目标站\n");
    scanf("%s",e);
    message msg;
    int f = 1;
    while(fread(&msg,sizeof(message),1,fp))
    {
        if(strcmp(msg.end,e)==0)
        {
            f = 0;
            printf("%s次 %s至%s %s发，总票数 %d ,余 %d,票价 %d 元\n",msg.trip,msg.begin_t,msg.end_t,msg.begin,msg.total,msg.left,msg.money);
        }
    }
    if(f) printf("暂无数据\n");
    printf("\n");
    fclose(fp);
}

//排序并输出
void msg_sort(){

    FILE *fp = fopen("message","r");
    if(fp==NULL){
        printf("暂无数据\n");
        return ;
    }

    fseek(fp,0L,SEEK_END);
    long size = ftell(fp);
    int n = size/sizeof(message);
    fseek(fp,0L,SEEK_SET);

    message msg[n];
    fread(msg,sizeof(message),n,fp);
    qsort(msg,n,sizeof(message),cmp);
 
    for(int i=0;i<n;i++){
        printf("%s次 %s至%s 由%s开往%s方向，总票数 %d ,余 %d,票价 %d 元\n",msg[i].trip,msg[i].begin_t,msg[i].end_t,msg[i].begin,msg[i].end,msg[i].total,msg[i].left,msg[i].money);
    }
    printf("\n");
    fclose(fp);
}

int main(){
    printf("----~*~*|\\欢迎使用本铁道信息查询系统/|*~*~----\n\n");
    int t = 1;
    while(t){
        printf(
            "---------按1-->添加新的车次信息---------\n"
            "------------按2-->按车次查询------------\n"
            "-----------按3-->按始发站查询-----------\n"
            "-----------按4-->按目标站查询-----------\n"
            "----按5-->按票价降序输出所有的列车信息----\n"
            "----------按0-->退出此程序----------\n"
        );
        scanf("%d",&t);
        switch (t)
        {
        case 1:
            write();
            break;
        case 2:
            find_t();
            break;
        case 3:
            find_begin();
            break;
        case 4:
            find_end();
            break;
        case 5:
            msg_sort();
            break;
        case 0:
            break;
        default:
            printf("\n");
            break;
        }
    }
    system("pause");
    return 0;
}
