#include <stdio.h>

struct poly  //define structure
{
    int exp,coeff;
} p1[10], p2[10], p3[20];

int readpoly(struct poly []);
void displaypoly(struct poly[], int);
int addpoly(struct poly[], struct poly[], int, int, struct poly[]);

int main() 
{
    int t1, t2, t3;
    printf("-Enter first polynomial-\n");    
    t1 = readpoly(p1);    //read first polynomial
    printf("\nFirst polynomial: ");
    displaypoly(p1, t1);

    printf("\n-Enter second polynomial-\n");    
    t2 = readpoly(p2);    //read second polynomial
    printf("\nSecond polynomial: ");
    displaypoly(p2, t2);

    t3 = addpoly(p1, p2, t1, t2, p3);
    printf("\nResultant polynomial: ");
    displaypoly(p3, t3);

    return 0;    // Indicating successful execution
}

int readpoly(struct poly p[]) 
{
    int t1, i;
    printf("Enter the number of terms: ");
    scanf("%d", &t1);    //read number of terms
    printf("--Enter the coeff and exp for each term--\n");    
    for (i = 0; i < t1; i++) 
    {
        printf("Enter the coeff for element %d: ", i + 1);
        scanf("%d", &p[i].coeff);    //input coefficient
        printf("Enter the exp for element %d: ", i + 1);
        scanf("%d", &p[i].exp);      //input exponent
    }
    return t1;    //return number of terms
}

void displaypoly(struct poly p[], int term) 
{
    if (term == 0)    //check for empty polynomial
    {
        printf("0");
        return;
    }
    for (int i = 0; i < term; i++)    //loop through each term
    {
        if (p[i].coeff == 0)    //skip terms with zero coefficient
        {
            continue;    
        }
        
        //handle sign display
        if (i > 0 && p[i].coeff > 0)    
        {
            printf("+");
        }
        if (p[i].coeff < 0) 
        {
            printf("-");
        }

        //print term based on exponent
        if (p[i].exp == 0)    //term is a constant
        {
            printf("%d", p[i].coeff);
        } 
        else if (p[i].exp == 1)    //x^1
        {
            printf("%dX", p[i].coeff);
        } 
        else    //exponent greater than 1 display x^exp
        {
            printf("%dX^%d", p[i].coeff, p[i].exp);
        }
    }
    printf("\n");
}

int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) 
{
   // i: Index for traversing the first polynomial (p1)
   // j: Index for traversing the second polynomial (p2)
   // k: Index for storing terms in the resultant polynomial (p3)

    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2) //loop through both polynomials
    {
        if (p1[i].exp == p2[j].exp)    //equal exponents
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            //move to next term
            i++;    
            j++;
        } 
        else if (p1[i].exp > p2[j].exp)    //p1's exp > p2's exp
        {
            p3[k] = p1[i];
            i++;
        } 
        else     //p2's exp > p1's exp
        {
            p3[k] = p2[j];    //copy term from p2 to p3
            j++;
        }
        k++;
    }
    
    // copy all remaining terms in p1
    while (i < t1) 
    {
        p3[k++] = p1[i++];
    }
    // copy all remaining terms in p2
    while (j < t2) 
    {
        p3[k++] = p2[j++];
    }
    return k;    //return number of terms in resultant polynomial p3
}

///  output
ubuntu@ubuntu-H81M-S:~/SCS1051123$ ./a.out
-Enter first polynomial-
Enter the number of terms: 3
--Enter the coeff and exp for each term--
Enter the coeff for element 1: 7
Enter the exp for element 1: 5
Enter the coeff for element 2: 5
Enter the exp for element 2: 2
Enter the coeff for element 3: 1
Enter the exp for element 3: 0

First polynomial: 7X^5+5X^2+1

-Enter second polynomial-
Enter the number of terms: 4
--Enter the coeff and exp for each term--
Enter the coeff for element 1: 4
Enter the exp for element 1: 4
Enter the coeff for element 2: 3
Enter the exp for element 2: 3
Enter the coeff for element 3: 5
Enter the exp for element 3: 2
Enter the coeff for element 4: 6
Enter the exp for element 4: 0

Second polynomial: 4X^4+3X^3+5X^2+6

Resultant polynomial: 7X^5+4X^4+3X^3+10X^2+7



///
