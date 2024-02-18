#include <stdio.h>
#include <stdlib.h>

int* array_input(int* len)
{
    printf("Number of elements:");
    scanf("%d", len);
    int* A=(int*)malloc(*len *sizeof(int));
    if (!A)
    {
        printf("Filed to allocate memory\n");
    }
    for(int i=0; i<*len; ++i)
    {
        printf("Index %d:", i);
        scanf("%d", &A[i]);
    }
    return A;
}

int* array_delete(int* A, int *len)
{
    int n, i;
    printf("element:");
    scanf("%d", &n);
    if(n>=*len)
    {
        printf("It isn't correct\n");
    }
    else
    {
        printf("Deleted\n");
        for(i=n; i<*len-1; i++)
        {
            A[i]=A[i+1];
        }
        (*len)--;
        A=(int*)realloc(A,*len*sizeof(int));
    }
    return A;
}

int* array_insert(int* A, int *len)
{
    int index, i;
    printf("element:");
    scanf("%d", &index);
    int new_element;
    printf("new_element:");
    scanf("%d", &new_element);
    (*len)++;
    A=(int*)realloc(A,(*len)*sizeof(int));
    if(index>=*len)
    {
        printf("it isn't correct number\n");
    }
    else
    {
        printf("element inserted\n");
        for(i=*len-1; i>index; i--)
        {
            A[i]=A[i-1];
        }
        A[index]=new_element;


    }
    return A;
}

void array_print(int* A, int len)
{
    for(int i=0; i<len; ++i)
    {
        printf("A[%d]= ", i);
        printf("%d\n", A[i]);
    }
    printf("\n");
}

int* Tor(int* A1, int* len1, int* A2, int* len2)
{
    *len2=0;
    A2=(int*)malloc(*len1*sizeof(int));
    int n, posit;
    int h=0;
	int posit2=0;
	for (int i=0; i<*len1; i++)
    {
		n=A1[i];
		posit=i;
		int c=0;
		for (int j=0; j<*len1; j++)
        {
			if (A1[i]==A1[j])
			{
				c++;
			}
		}
		if (c==1)
        {
			(*len2)++;
			A2=(int*)realloc(A2, *len2*sizeof(int));
			A2[posit2]=n;
			posit2++;
			h++;
		}
		else
		{
            A1[i-h]=A1[i];
        }
	}
	(*len1)-=h;
	A1=(int*)realloc(A1, *len1*sizeof(int));
	for(int i=0; i<*len2; i++)
    {
        printf("%d\n", A2[i]);
    }
	return A2;
}


int main()
{

    int* A1;
    int* A2;
    int len1, len2;
    int x;
    printf("Press 1. Array input 1\n");
    printf("Press 2. Array insert 1\n");
    printf("Press 3. Array delete 1\n");
    printf("Press 4. Array print 1\n");
    printf("Press 5. Tor\n");
    printf("Press 0. Exit\n");

    do
    {
        printf("Press:");
        scanf("%d", &x);
        switch(x)
        {
            case 1: A1 = array_input(&len1); break;
            case 2: A1 = array_insert(A1, &len1); break;
            case 3: A1 = array_delete(A1, &len1); break;
            case 4: array_print(A1, len1); break;
            default: Tor(A1, &len1, A2, &len2); break;
        }
    }while (x!=0);
    return 0;
}
