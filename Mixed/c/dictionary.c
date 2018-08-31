#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define x 50
struct dictionary{
    char word[x];
    char meaning[x];
};
struct dictionary hc[x];
int pos=0;
void find()
{
    int i,flag;
    char jp[x];
    printf("Enter The word :");
    scanf("%s",jp);
    for(i=0,flag=0;i<pos;i++)
    {
        if(strcmp(hc[i].word,jp)==0)
        {
            printf("The meaning of %s is %s\n\n",jp,hc[i].meaning);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Word doesn't exists in the dictionary!\n\n");
    }
}
void sort()
{
    int i,j;
    struct dictionary jp;
    for(i=0;i<pos;i++)
    {
        for(j=i+1;j<pos;j++)
        {
            if(strcmp(hc[j].word,hc[i].word)<1)
            {
                strcpy(jp.word,hc[i].word);
                strcpy(jp.meaning,hc[i].meaning);
                strcpy(hc[i].word,hc[j].word);
                strcpy(hc[i].meaning,hc[j].meaning);
                strcpy(hc[j].word,jp.word);
                strcpy(hc[j].meaning,jp.meaning);
            }
        }
    }
}
void add()
{
    int i;
    char tempword[x],tempmeaning[x];
    FILE *fp;
    printf("Enter the word:");
    scanf("%s",hc[pos].word);
    printf("Enter Meaning:");
    scanf("%s",hc[pos].meaning);
    pos++;
    sort();
    fp=fopen("hc.txt","w");
    for(i=0;i<pos;i++)
    {
        fprintf(fp,"%s - %s\n",hc[i].word,hc[i].meaning);
    }
    fclose(fp);
}
void display()
{
    int i;
    printf("Word\tMeaning\n");
    for(i=0;i<pos;i++)
    {
        printf("%s\t%s\n",hc[i].word,hc[i].meaning);
    }
    printf("\n");
}

int main()
{
    int n;
    while(1)
    {
        printf("1.Insert\n2.Find Meaning\n3.DisplayEntireDictionary\n4.Exit\nEnter Your Choice:");
        scanf("%d",&n);
        switch(n){
            case 1:add();
                   break;
            case 2:find();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("Please Enter a Valid Input!\n");
                   break;
        }
    }
}
