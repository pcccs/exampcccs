#include<stdio.h>
#include<stdlib.h>

typedef struct SET
{
    float v[10][10];
    int m,n;
}fuzzy;

fuzzy *getval(fuzzy *R,char *x)
{
    int i,j;
    R=(fuzzy*)malloc(sizeof(fuzzy*));
    
    printf("Enter number of rows and cols of fuzzy relation \n");
    scanf("%d%d",&R->m,&R->n);

    printf("Enter the set %s\n",x);
    for(i=0;i<R->m;i++)
    {
        for(j=0;j<R->n;j++)
        {
            scanf("%f",&R->v);
        }
    }
    return(R);
}

fuzzy *printval(fuzzy *R,char *x)
{
    int i,j;
    printf("Enter the set %s\n",x);
    for(i=0;i < R->m;i++)
    {
        for(j=0;j<R->n;j++)
        {
            printf("%f\t",&R->v);
        }
        printf("\n");
    }
    return(R);
}

fuzzy *max_min(fuzzy *R,fuzzy *S)
{
    int i,j,k,p,q;
    int min[10];
    int max = 0;

    fuzzy *result=(fuzzy*)malloc(sizeof(fuzzy*));
    result->m=R->m;
    result->n=S->n;
    printf("\n enter the set %s");
    for(i=0;i<R->m;i++)
    {
        k=0;
        for(j=0;j<R->n;j++)
        {
            if(R->v[i][j]<S->v[j][i])
            {
                min[k]=R->v[i][j];
            }
            
            else
            {
                min[k]=S->v[j][i];
            }
            k++;
        }
    
        max = min[0];

        for(k=1;k<R->m;k++)
        {
            if(max<min[k])
            {
                max=min[k];
            }
        }

        for(p=0;p<result->m;p++)
        {
            for(q=0;q<result->n;q++)
            {
                result->v[p][q]=max;
            }
        }
    }    
    return(result);
}

fuzzy *max_product(fuzzy *R,fuzzy *S)
{
    int i,j,k,p,q;
    int prod[10];
    int max = 0;

    fuzzy *result=(fuzzy*)malloc(sizeof(fuzzy*));
    result->m=R->m;
    result->n=S->n;

    printf("\n enter the set %s");
    for(i=0;i < R->m ;i++)
    {
        k=0;
        for(j=0;j<S->n;j++)
        {
            prod[k]=R->v[i][j]*S->v[j][i];
            k++;
        }
        max=prod[0];
        for(k=1;k<R->m;k++)
        {
            if(max<prod[k])
            {
                max=prod[k];
            }
            
            for(p=0;p<result->m;p++)
            {   
                for(q=0;q<result->n;q++)
                {
                    result->v[p][q]=max;
                }
            }
        }
    }
    return(result);
}

int main()
{
    fuzzy *a=NULL;
    fuzzy *b=NULL;
    fuzzy *result1,*result2,*result3;

    a=getval(a,"A");
    b=getval(b,"B");
    printval(a,"A");
    printval(b,"B");
    printf("\n Max Min Composition is as follows");
    
    result1=max_min(a,b);
    printval(result1,"C");

    printf("\n Max Product Composition is as follows");
    result2=max_product(a,b);
    printval(result2,"D");

    return 0;
} 