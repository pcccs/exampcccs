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
        printf(",");
    }
    printf(")");
}


void lambda_cut_set(fuzzy *a,float L)
{
    fuzzy *temp;
    temp=(fuzzy*)malloc(sizeof(fuzzy*));
    int i;
    temp->n=a->n;
    for(i=0;i<a->n;i++)
    {
        if(a->nr[i]>L)
        {
            temp->nr[i]=a->nr[i];
            temp->dr[i]=a->dr[i];
            printf("{(%6.1f,1) \t ",temp->dr[i]);
        }
        else
        {
            printf("{(%6.1f,0) \t ",temp->dr[i]);
        }
    }
    printf("}");
}

void main()
{
    fuzzy *a=NULL;
    fuzzy *b=NULL;
    int c;
    float L;

    printf("\n enter the no.of components");
    scanf("%d",&c);

    a=getval(a,c,"A");
    printval(a,"A");

    printf("\n enter the value for lambda");
    scanf("%f",&L);
    lambda_cut_set(a,L);
} 