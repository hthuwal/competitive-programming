#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *a,*top,*max,*min;
char element;

int push(char x)
{
	if(top==max)
	{
		printf("overflow");
	}
	else
	{
		top=top+1;
		*top=x;
	}
}
int pop()
{
	if(top<min)
	{
		printf("underflow");
	}
	else
	{
		element=*top;
		top=top-1;
	}
}
int hc(char a,char b)
{
	switch(a)
	{
		case '+':if(b==')'||b=='(')
				 return 0;
				 else
				 return 1;
		case '-':if(b==')'||b=='(')
				 return 0;
				 else
				 return 1;
		case '*':if(b==')'||b=='(')
				 return 0;
				 else if(b=='+'||b=='-')
					return 0;
				 else
				 	return 1;
		case '/':if(b==')'||b=='(')
				 return 0;
				 if(b=='+'||b=='-')
					return 0;
				 else
				 	return 1;
		case '^':return 0;
	}
}
int main()
{
	char *b,*c;
	int t,i,j=0,temp;
	a=(char*)malloc(sizeof(char)*500);
	b=(char*)malloc(sizeof(char)*500);
	c=(char*)malloc(sizeof(char)*500);
	top=a-1;
	max=a+499;
	min=a;
	scanf("%d",&t);
	while(t--)
	{
		j=0;
		scanf("%s",b);
		push('(');
		*(b+strlen(b))=')';
		for(i=0;top>=min;i++)
		{

			if(*(b+i)=='(')
				push('(');
			else if(*(b+i)==')')
			{
				while(1)
				{
					pop();
					if(element!='(')
					{
						*(c+j)=element;
						j++;
					}
					else
						break;
				}
			}
			else if(*(b+i)=='+'||*(b+i)=='-'||*(b+i)=='*'||*(b+i)=='/'||*(b+i)=='^')
			{
				while(1)
				{
					temp=hc(*(b+i),*top);
					if(temp==1)
					{
						pop();
						*(c+j)=element;
						j++;
					}
					else
					{
						break;
					}
				}
				push(*(b+i));
			}
			else
			{
				*(c+j)=*(b+i);
				j++;
			}
		}
	for(i=0;i<j;i++)
	{
		printf("%c",*(c+i));
	}
	printf("\n");
	}
	return 0;
}
