//
//  main.c
//  GPRS2.1
//
//  Created by 20161104585 on 17/6/27.
//  Copyright © 2017年 20161104585. All rights reserved.
//

#include <stdio.h>
#define LEN sizeof(struct GPRS)
int main()
{
    FILE *fp=fopen("//Users//a20161104585//Desktop//GPRS2.1//GPRS2.1//GPS170510.log", "r");
    struct GPRS
    {
        char g1[63];
        char g2[70];
        char lat[8];//纬度
        char lng[9];//经度
        char time[6];//时间
        struct GPRS *next;
    };
    
    struct GPRS *p;
    p=(struct GPRS *)malloc(sizeof(struct GPRS));
    p->next=NULL;
    
    if(fp==NULL)
    {
        printf("文件读取错误，请检查文件GPS170510.log是否存在!");
    }
    else
    {
        struct GPRS *q;
        while(fscanf(fp,"%s%s",p->g1,p->g2)!=EOF)
        {
            q=(struct GPRS *)malloc(sizeof(struct GPRS));
            q->next=NULL;
            p->next=q;
            p=p->next;
        }
        printf("%s\n%s\n",p->g1,p->g2);
    }
    
    fclose(fp);
    return 0;
}
