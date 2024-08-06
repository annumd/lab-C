#include <stdio.h>
void search(int [],int);
void insert(int [],int);
void delete(int [],int);
void sort(int [],int);
void merge(int[],int);

void main()
{
	int len,i,a[20],ch;
	printf("Enter number of elements in the array: ");
	scanf("%d",&len);
	printf("Enter the elements: ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("-array recorded- \n");
	printf(" Do you want to \n (1) search \n (2) insertion \n (3) deletion \n (4) sorting \n (5) merge \n");
	printf(" Enter your choice: ");
	scanf("%d",&ch);
	
	if (ch==1)
	{
		search(a,len);	 /// a is array name
	}
	if (ch==2)
	{
		insert(a,len);	
	}
	if (ch==3)
	{
		delete(a,len);
	}
	if (ch==4)
	{
		sort(a,len);
	}
	if (ch==5)
	{
		merge(a,len);
	}
}

void search(int a[10],int len)  ///function works 
{
	int i,flag=0,a1,loc=0;
	printf("Enter the number to be searched for : ");
	scanf("%d",&a1);
	for(i=0;i<len;i++)
	{
		if(a1==a[i])
			{
				flag=1;
				loc=i+1;
				break;
			}
	}
	if (flag==1)
		{
			printf("number found at %d",loc);
		}
		else
		{
			printf("number not found");
		}
	
}
		
void insert(int a[20],int len)  ///function works
{
	int num,i,pos;
	printf("Existing array is displayed below:\n ");
	for(i=0;i<len;i++)
	{
		printf("%d",a[i]);	/// prints the existing array
	}
	printf("\nEnter the number to be inserted:\n ");
	scanf("%d",&num);
	printf("Enter the position where it has to be inserted:\n ");
	scanf("%d",&pos);
	
	while(i>=pos-1)
	{
		a[i+1]=a[i];
		i--;
	}
	a[pos-1]=num; ///must be =

        
	printf("The new array is displayed below\n");
	for(i=0;i<=len;i++)
	{
		printf("%d",a[i]);	/// prints the existing array
	}
}

void delete(int a[20],int len)  ///function works
{
	int i=0,num,pos=-1,flag=0;
	printf("\nEnter the number to be deleted:\n ");
	scanf("%d",&num);
	while(i<len)
	{
		if(a[i]==num)
		{
			flag=1;
			pos=i;
			break;
		}
		else
		{
			i++;
		}
	}
	if(flag==0)
	{
		printf("invalid\n");
	}
	else
	{
		for(i=pos;i<=len-1;i++)
		{
			a[i]=a[i+1];
		}
	}
	len=len-1;
	printf("array elements are:");
	for(i=0;i<len;i++)
	{
		printf("%d",a[i]);	/// prints the existing array
	}
	
}	
	
void sort(int a[20],int len)  ///function works
{
	int i=0,j,temp;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted array is :");
	for(i=0;i<len;i++)
	{
		printf("%d",a[i]);	/// prints the existing array
	}
	
}

void merge(int a[20],int len) 	///function works
{
	int b[50],sizeb,i=0,c[100],j;
	printf("Enter number of elements of the second array: ");
	scanf("%d",&sizeb);
	printf("Enter the array elements : ");
	for(i=0;i<sizeb;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<len;i++)
	{
		c[i]=a[i];
	}
	i=len;
	for(j=0;j<sizeb;j++)
	{
		c[i]=b[j];
		i++;
	}
	printf("The merged array is : ");
	for(i=0;i<(len+sizeb);i++)
	{
		printf("%d",c[i]);
	}
}
