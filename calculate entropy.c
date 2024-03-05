#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define n 10

double entropy_calculator(int []);
void display_entropy(int [], double);


int main()
{
    int x;
    double y;
    int counter;
    srand(time(NULL));
    int bucket[n];

    for(counter=0; counter<n; counter++)
    {
        bucket[counter] = 1 + (int) rand() % 6;
    }

    y=entropy_calculator(bucket);

    display_entropy(bucket, y);

    return 0;
}

double entropy_calculator(int bucket[])
{
    double c1=0.0,c2=0.0,c3=0.0,c4=0.0,c5=0.0,c6=0.0;
    int counter, ent_count;
    double entropy;

    for(counter=0; counter<n; counter++)
    {
        if(bucket[counter]==1)
            c1++;
        else if(bucket[counter]==2)
            c2++;
        else if(bucket[counter]==3)
            c3++;
        else if(bucket[counter]==4)
            c4++;
        else if(bucket[counter]==5)
            c5++;
        else if(bucket[counter]==6)
            c6++;

    }
    if(c1==0)
    {
        entropy=-(((c2/10.0)*log10(2)*(c2/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c5/10.0)*log10(2)*(c5/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }


    else if(c2=0)
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c5/10.0)*log10(2)*(c5/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }


    else if(c3==0)
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c2/10.0)*log10(2)*(c2/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c5/10.0)*log10(2)*(c5/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }


    else if(c4==0)
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c2/10.0)*log10(2)*(c2/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c5/10.0)*log10(2)*(c5/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }


    else if(c5==0)
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c2/10.0)*log10(2)*(c2/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }


    else if(c6==0)
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c2/10.0)*log10(2)*(c2/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c5/10.0)*log10(2)*(c5/10.0)));
    }


    else
    {
        entropy=-(((c1/10.0)*log10(2)*(c1/10.0))+((c2/10.0)*log10(2)*(c2/10.0))+((c3/10.0)*log10(2)*(c3/10.0))+((c4/10.0)*log10(2)*(c4/10.0))+((c5/10.0)*log10(2)*(c5/10.0))+((c6/10.0)*log10(2)*(c6/10.0)));
    }



    return entropy;

}

void display_entropy(int bucket[], double entropy)
{
    int counter;
    printf("With %d samples, you have the following balls in the bucket:\n", n);

    for(counter=0; counter<10; counter++)
    {
        printf("%d ", bucket[counter]);
    }
    printf("\nAnd the entropy is: %lf", entropy);

}
