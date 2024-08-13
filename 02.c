#include <stdio.h>

struct poly 
{
    int exp,coeff;
} p1[10], p2[10], p3[20];

int readpoly(struct poly []);
void displaypoly(struct poly[], int);
int addpoly(struct poly[], struct poly[], int, int, struct poly[]);

int main() 
{
    int t1, t2, t3;
    t1 = readpoly(p1);
    printf("First polynomial: ");
    displaypoly(p1, t1);

    t2 = readpoly(p2);
    printf("Second polynomial: ");
    displaypoly(p2, t2);

    t3 = addpoly(p1, p2, t1, t2, p3);
    printf("Resultant polynomial: ");
    displaypoly(p3, t3);

    return 0;
}

int readpoly(struct poly p[]) 
{
    int t1, i;
    printf("Enter the number of terms: ");
    scanf("%d", &t1);
    printf("Enter the coeff and exp for each term\n");
    for (i = 0; i < t1; i++) 
    {
        printf("Enter the coeff for element %d: ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exp for element %d: ", i + 1);
        scanf("%d", &p[i].exp);
    }
    return t1;
}

void displaypoly(struct poly p[], int term) 
{
    if (term == 0) 
    {
        printf("0");
        return;
    }
    for (int i = 0; i < term; i++) 
    {
        if (p[i].coeff == 0) 
        {
            continue;
        }
        if (i > 0 && p[i].coeff > 0) 
        {
            printf("+");
        }
        if (p[i].coeff < 0) 
        {
            printf("-");
        }
        if (p[i].exp == 0) 
        {
            printf("%d", p[i].coeff);
        } 
        else if (p[i].exp == 1) 
        {
            printf("%dX", p[i].coeff);
        } 
        else 
        {
            printf("%dX^%d", p[i].coeff, p[i].exp);
        }
    }
    printf("\n");
}

int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) 
{
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2) 
    {
        if (p1[i].exp == p2[j].exp) 
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
        } 
        else if (p1[i].exp > p2[j].exp) 
        {
            p3[k] = p1[i];
            i++;
        } 
        else 
        {
            p3[k] = p2[j];
            j++;
        }
        k++;
    }
    while (i < t1) {
        p3[k++] = p1[i++];
    }
    while (j < t2) {
        p3[k++] = p2[j++];
    }
    return k;
}
///  output
ubuntu@ubuntu-H81M-S:~/SCS1051123$ gcc poly.c
ubuntu@ubuntu-H81M-S:~/SCS1051123$ ./a.out
Enter the number of terms: 3
Enter the coeff and exp for each term
Enter the coeff for element 1: 4
Enter the exp for element 1: 3
Enter the coeff for element 2: 3
Enter the exp for element 2: 2
Enter the coeff for element 3: 6
Enter the exp for element 3: 1
First polynomial: 4X^3+3X^2+6X
Enter the number of terms: 3
Enter the coeff and exp for each term
Enter the coeff for element 1: 5
Enter the exp for element 1: 3
Enter the coeff for element 2: 1
Enter the exp for element 2: 2
Enter the coeff for element 3: 3
Enter the exp for element 3: 1
Second polynomial: 5X^3+1X^2+3X
Resultant polynomial: 9X^3+4X^2+9X
ubuntu@ubuntu-H81M-S:~/SCS1051123$ 

///
///
