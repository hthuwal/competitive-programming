#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student {
	char name[20];
	int roll;
	struct student *link;
};
struct student *start=NULL;
int rol;
char nam[20];
void display()
{ struct student *p;
	p=start;
	while(p!=NULL)
	{
		printf("%s\t%d\n",p->name,p->roll);
		p=p->link;
	}
	printf("\n");
}
void bsort()
{
	struct student *temp1,*temp2,*temp3,*temp4,*temp5;
	temp4=NULL;
	while(temp4!=start->link)
	{
		temp3=temp1=start;
		temp2=temp1->link;
		while(temp1!=temp4)
		{
			if(temp1->roll>temp2->roll)
			{
				if(temp1==start)
				{
					temp5=temp2->link;
					temp2->link=temp1;
					temp1->link=temp5;

					start=temp2;
					temp3=temp2;
				}
				else
				{
					temp5=temp2->link;
					temp2->link=temp1;
					temp1->link=temp5;

					temp3->link=temp2;
					temp3=temp2;
				}
			}
			else
			{
				temp3=temp1;
				temp1=temp1->link;
			}
			temp2=temp1->link;
			if(temp2==temp4)
			{
				temp4=temp1;
			}
		}
	}
}

void add()
{
	struct student *temp,*p;
	if(start==NULL)
	{
		temp=(struct student *)malloc(sizeof(struct student));
		temp->roll=rol;
		strcpy(temp->name,nam);
		temp->link=start;
		start=temp;
		free(temp);
		bsort();
		display();
	}
	else
	{
		temp=(struct student *)malloc(sizeof(struct student));
		temp->roll=rol;
		strcpy(temp->name,nam);
		p=start;
		while(p->link!=NULL)
			p=p->link;
        temp->link=NULL;
		p->link=temp;
		free(temp);
		bsort();
		display();
	}
}

int main()
{
	int n;
	do
	{
		printf("1 Insert\t2Delete\t3 Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1 :
			scanf("%d%s",&rol,nam);
			add();
			break;
			case 3 : exit(1);
			default : printf("wrong choice\n");
		}

	}while(n!=3);
	return 0;
}



