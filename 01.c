#include <stdio.h>
void search(int [],int);
void insert(int [],int);
void delete(int [],int);
void sort(int [],int);
void merge(int[],int);

void main()
{
	int len,i,a[20],ch,con;
	printf("Enter number of elements in the array: ");
	scanf("%d",&len);
	printf("Enter the elements: ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);	//reads the elements
	}
	printf("-array recorded- \n");
	do
	{
		printf(" Do you want to \n (1) search \n (2) insertion \n (3) deletion \n (4) sorting \n (5) merge \n ");	//prints menu
		printf(" Enter your choice: "); 	// asks for users choice
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
	
		printf("\n Do you want to continue? (PRESS 1 TO CONTINUE) : \n");
		scanf("%d",&con);
	}while(con==1);
}
void search(int a[10],int len)  
{
	int i,flag=0,a1,loc=0;
	printf("Enter the number to be searched for : ");
	scanf("%d",&a1);	//reads number to be searched for
	for(i=0;i<len;i++)	//goes through each element
	{
		if(a1==a[i])	//if element found
			{
				flag=1;	//set flag variable as 1
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
		
void insert(int a[20],int len)  
{
	int num,i,pos;
	printf("Existing array is displayed below:\n ");
	for(i=0;i<len;i++)
	{
		printf("%d",a[i]);	// prints the existing array
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
	a[pos-1]=num; 

	printf("The new array is displayed below\n");
	for(i=0;i<=len;i++)
	{
		printf("%d",a[i]);	/// prints the existing array
	}
}

void delete(int a[20],int len)  
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
	
void sort(int a[20],int len)  
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

void merge(int a[20],int len) 	
{
	int b[50],sizeb,i=0,c[100],j;
	printf("Enter number of elements of the second array: ");
	scanf("%d",&sizeb);
	printf("Enter the array elements : ");
	for(i=0;i<sizeb;i++)
	{
		scanf("%d",&b[i]);	//reads the array
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

/// output
ubuntu@ubuntu-H81M-S:~/SCS1051123$ gcc operation.c
ubuntu@ubuntu-H81M-S:~/SCS1051123$ ./a.out
Enter number of elements in the array: 5
Enter the elements: 1 2 4 5 6
-array recorded- 
 Do you want to 
 (1) search 
 (2) insertion 
 (3) deletion 
 (4) sorting 
 (5) merge 
  Enter your choice: 1
Enter the number to be searched for : 1
number found at 1
 Do you want to continue? (PRESS 1 TO CONTINUE) : 
1
 Do you want to 
 (1) search 
 (2) insertion 
 (3) deletion 
 (4) sorting 
 (5) merge 
  Enter your choice: 2
Existing array is displayed below:
 12456
Enter the number to be inserted:
 6
Enter the position where it has to be inserted:
 3
The new array is displayed below
126456
 Do you want to continue? (PRESS 1 TO CONTINUE) : 
1 
 Do you want to 
 (1) search 
 (2) insertion 
 (3) deletion 
 (4) sorting 
 (5) merge 
  Enter your choice: 3

Enter the number to be deleted:
 6
array elements are:1245
 Do you want to continue? (PRESS 1 TO CONTINUE) : 
1
 Do you want to 
 (1) search 
 (2) insertion 
 (3) deletion 
 (4) sorting 
 (5) merge 
  Enter your choice: 4
Sorted array is :12456
 Do you want to continue? (PRESS 1 TO CONTINUE) : 
1
 Do you want to 
 (1) search 
 (2) insertion 
 (3) deletion 
 (4) sorting 
 (5) merge 
  Enter your choice: 5
Enter number of elements of the second array: 3
Enter the array elements : 2 3 5
The merged array is : 12456235
 Do you want to continue? (PRESS 1 TO CONTINUE) : 
0
///
