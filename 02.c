#include <stdio.h>
struct poly
{
	float coeff;
	int exp;
}
p1[10],p2[10],p3[20]'
int readpoly(struct poly []);
void displaypoly(struct poly[],int t3);
int addpoly(structpoly[],struct poly[],int,int,struct poly[]);

void main()
{
	int t1,t2,t3;
	t1=readpoll(p1);
	printf("First polynomial: ");
	dispoly(p1,t1);
	
	t2=readpoll(p2);
	printf("First polynomial: ");
	dispoly(p2,t2);
	
	t3=addpoly(p1,p2,t1,t2,t3,p3)
	printf("Resultant polynomail: ");
	displaypoly(p3,t3);
	return 0;
}

int readpoly(struct poly p[])
{
	int t1,i;
	printf("Enter the number of terms :");
	scanf("%d",&t1);
	printf("Enter the coeff and exp for each term\n")
	for(i=0;i<t1;i++)
	{
		printf("Enter the coeff for element %d",i+1);
		scanf("%f"&p1[i].coeff);
		printf("Enter the exp for the element %d",i+1);
		scanf("%d",p1[i].exp);
	}
	return t1;

void displaypoly(struct poly p[],int term)
{
	if(term==0)
	{
		printf("0");
		return;
	}
	for(int i=0;i<term;i++)
	{
		if(p[i].coeff==0)
		{
		continue;
		}
			
		if(i>0 && p[i].coeff>0)
		{
			printf("+");
		}
		
		else if id(p[i].coeff<0)
		{
			printf("-");
		}
		if(p[i].expo==0)
		{
			printf("%f",p[i].coeff);
		}
		else if(*p[i].expo==1)
		{
			printf("%f",p[i].coeff)'
		}
		else
		{
			printf("%f%d",p[i].coeff,p[i].expo);
		}
	}
	printf("\n")
	
int addpoly(struct poly p1[],struct poly p2[],int t1,int t2,struct poly p3[])
{
	int i=0,j=0,k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].expo== p2[j].expo)
		{
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			j++;
		}
		else
		{
			p3[k]=p2[j];
			j++
		}
		k++;
	}
	while(i<t1)
	{
	p3[k++]=p1[j++];
	}
	while(j<t2)
	{
	p3[k++]=p2[j++];
	}
	return k;
}
