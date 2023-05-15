#include<stdio.h>
#include<stdlib.h>

typedef struct SET
{
    float nr[10];
    float dr[10];
    int n;
}fuzzy;

fuzzy *getval(fuzzy *m,int ch,char *x)
{
    int i;
    float f,g;
    m=(fuzzy*)malloc(sizeof(fuzzy*));
    m->n=ch;
    printf("\n enter the set %s",x);
    for(i=0;i<m->n;i++)
    {
        printf("numerator element %d",i+1);
        scanf("%f",&f);
        m->nr[i]=f;
        printf("denominator element %d",i+1);
        scanf("%f",&g);
        m->dr[i]=g;
    }
    return(m);
}

void printval(fuzzy *m,char *x)
{
    int i;
    float f;
    printf("\n The set %s=(",x);
    for(i=0;i<m->n;i++)
    {
        printf("%6.1f / %6.1f",m->nr[i],m->dr[i]);
        if(i!=m->n-1)
        {
            printf(",");
        }
    }
    printf(")");
}

fuzzy *unionset(fuzzy *a,fuzzy *b)
{
    fuzzy *temp;
    temp=(fuzzy*)malloc(sizeof(fuzzy*));
    char ch;
    int i;
    temp->n=a->n;
    for(i=0;i<a->n;i++)
    {
        if(a->dr[i]==b->dr[i])
        {
            if(a->nr[i]>=b->nr[i])
            {
                temp->nr[i]=a->nr[i];
            }
            else
            {
                temp->nr[i]=b->nr[i];
                temp->dr[i]=a->dr[i];        
            }
        }
    }
    return temp;
}

fuzzy *intersectionset(fuzzy *a,fuzzy *b)
{
    fuzzy *temp;
    temp=(fuzzy*)malloc(sizeof(fuzzy*));
    char ch;
    int i;
    temp->n=a->n;
    for(i=0;i<a->n;i++)
    {
        if(a->dr[i]==b->dr[i])
        {
            if(a->nr[i]<=b->nr[i])
            {
                temp->nr[i]=a->nr[i];
            }
            else
            {
                temp->nr[i]=b->nr[i];
                temp->dr[i]=a->dr[i];
            }
        }
    }
    return temp;
}

fuzzy *complement(fuzzy *a)
{
    fuzzy *temp;
    temp=(fuzzy*)malloc(sizeof(fuzzy*));
    int i;
    temp->n=a->n;
    
    for(i=0;i<a->n;i++)
    {
        temp->nr[i]=1-(a->nr[i]);
        temp->dr[i]=a->dr[i];
    }
    return temp;
}

void main()
{
    fuzzy *a=NULL;
    fuzzy *b=NULL;
    fuzzy *result1,*result2,*result3,*result4,*lhs,*rhs;
    int c;

    printf("\n enter the no.of components");
    scanf("%d",&c);

    a = getval(a,c,"A");
    b = getval(b,c,"B");

    printval(a,"A");
    printval(b,"B");
    
    result1=unionset(a,b);
    result2=intersectionset(a,b);
    result3=complement(a);
    result4=complement(b);
    
    printf("To prove De-Morgan’s law...");
    printf("(AUB)’=A’ B’");
    
    lhs = complement(result1);
    rhs = intersectionset(result3,result4);
    
    if(lhs == rhs)
    {
        printf("De-Morgan’s Law is proved for set A & B");
    }
    else
    {
        printf("De-Morgan’s Law doesnot proved for set A & B");
    }
}