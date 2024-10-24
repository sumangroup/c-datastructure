#include <stdio.h>
#define size 100
int insert(int LA[], int N, int k, int value);
int delete(int LA[], int N, int K);
void display(int LA[], int N);
void display_P(int *p, int N);
int linearsearch(int LA[], int N, int value);
void BubbleSort(int LA[], int N);
void Insertionsort(int LA[], int N);
int MIN(int LA[], int N, int K);
void SelectionSort(int LA[], int N);
int MAX(int LA[], int N, int K);
void ShellSort(int LA[], int N);
void Radix(int LA[], int N);
int Mergeing(int A[], int NA, int B[], int NB, int LA[]);
int BinarySearch(int LA[], int N, int value);
int MERGE(int A[],int NA,int LBA,int B[],int NB,int LBB,int LA[],int LBLA);
void MERGEPASS(int LA[],int N,int L,int B[]);
void MERGESORT(int LA[],int N);  
int main()
{
    int A[] = {12, 15, 21, 27, 30, 45};
    // number of elements in A
    int NA = 6;
    //lower bound of A
    int LBA;

    int B[] = {19, 26, 28, 30, 35, 49, 50};
    // number of elements in B
    int NB = 7;
    // lower bound of B
    int LBB;
    // define an array
    int LA[size]={120,245,79,45,925,54,80,345,101,86,80,745,24,45,965,6,52,1,37};
    // number of elements present in an array
    int N = 19;
    // position
    int K;
    // value
    int value;
    // location
    int LOC;
    int choice;
    do
    {
        printf("\n 1:insert");
        printf("\n 2:delete");
        printf("\n 3:display");
        printf("\n 4:search");
        printf("\n 5:Bubble Sort");
        printf("\n 6:Insertion Sort");
        printf("\n 7:Min");
        printf("\n 8:Selection Sort");
        printf("\n 9:Max");
        printf("\n 10:display_P");
        printf("\n 11:Shell Sort");
        printf("\n 12:Radix Sort");
        printf("\n 13:Mergeing");
        printf("\n 14:Binary Search");
        printf("\n 15:Merge");
        printf("\n 16:Merge Sort");
        printf("\n 0:exit");
        printf("\n Enter your choices: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the position: ");
            scanf("%d", &K);
            printf("\n Enter the value: ");
            scanf("%d", &value);
            N = insert(LA, N, K, value);
            printf("\n Total Number of elements:%d", N);
            printf("\n Inserted Element Sucessfully");
            break;

        case 2:
            printf("\n Enter the position: ");
            scanf("%d", &K);
            N = delete (LA, N, K);
            printf("\n Total Number of elements:%d", N);
            printf("\n Deleted Element Sucessfully");
            break;

        case 3:
            display(LA, N);
            break;

        case 4:
            printf("\n Enter the value: ");
            scanf("%d", &value);
            K = linearsearch(LA, N, value);

            if (K > N)
            {
                printf("\nthe elements not present and it is added at this location %d", K - 1);
                N = N + 1;
            }
            else
            {
                printf("\nthe elements %d, present at this location %d", value, K);
            }
            break;

        case 5:
            BubbleSort(LA, N);
            break;

        case 6:
            Insertionsort(LA, N);
            break;

        case 7:
            LOC = MIN(LA, N, 0);
            if (LOC == -1)
            {
                printf("\n Array is empty");
            }
            else
            {
                printf("\n MIN: LOC:%d and element:%d", LOC, LA[LOC]);
            }
            break;

        case 8:
            SelectionSort(LA, N);
            break;

        case 9:
            LOC = MAX(LA, N, 0);
            if (LOC == -1)
            {
                printf("\n Array is empty");
            }
            else
            {
                printf("\n MAX: LOC:%d and element:%d", LOC, LA[LOC]);
            }
            break;

        case 10:
            display_P(LA, N);
            break;

        case 11:
            ShellSort(LA, N);
            break;

        case 12:
            Radix(LA, N);
            break;

        case 13:
            printf("\nElements in A: ");
            display(A, NA);
            printf("\nElements in B: ");
            display(B, NB);
            N = Mergeing(A, NA, B, NB, LA);
            printf("No elements in LA is %d", N);
            break;

        case 14:
            printf("\n Enter the value: ");
            scanf("%d", &value);
            K = BinarySearch(LA, N, value);
            if (K == -1)
            {
                printf("\n the value %d is not present", value);
            }
            else
            {
                printf("\n the value %d is present at this location %d", LA[K], K);
            }
            break;
        
        case 15:
            printf("\n Enter the lower bound of A: ");
            scanf("%d",&LBA);
            printf("\n Enter the number of elements in A: ");
            scanf("%d",&NA);
            printf("\n");
            printf("\n Enter the lower bound of B: ");
            scanf("%d",&LBB);
            printf("\n Enter the number of elements in B: ");
            scanf("%d",&NB);
            N=MERGE(A,NA,LBA,B,NB,LBB,LA,0);
            printf("total number of elements in LA %d",N);
            break;

        case 16:
        MERGESORT(LA,N);
        break;
        case 0:
            exit(0);

        default:
            printf("\n Invalid input");
            break;
        }

    } while (choice != 0);
    return 0;
}
int insert(int LA[], int N, int K, int value)
{

    // check the overflow condition
    if (N == size)
    {
        printf("\nOverflow");
    }
    else
    {
        if (N == 0)
        {
            LA[N] = value;
            N = N + 1;
        }
        else if (K > N - 1)
        {
            LA[N] = value;
            N = N + 1;
        }
        else
        {
            int J = N - 1;
            while (J >= K)
            {
                LA[J + 1] = LA[J];
                J = J - 1;
            }
            LA[K] = value;
            N = N + 1;
        }
    }
    return N;
}

int delete(int LA[], int N, int K)
{
    if (N == 0)
    {
        printf("\nUnderflow");
    }
    else
    {
        if (K > N - 1)
        {
            printf("\nElements Not present");
        }
        else
        {
            printf("\n%d this element is deleted", LA[K]);
            int J = K;
            while (J < N)
            {
                LA[J] = LA[J + 1];
                J = J + 1;
            }
            N = N - 1;
        }
    }
    return N;
}

void display(int LA[], int N)
{
    if (N == 0)
    {
        printf("\nArray is empty");
    }
    else
    {
        printf("\nElements in Array");
        int J = 0;
        while (J < N)
        {
            printf("\nLA[%d]:%d", J, LA[J]);
            J = J + 1;
        }
    }
}
int linearsearch(int LA[], int N, int value)
{
    int K = 0;
    while (LA[K] != value && K++ < N)
        ;
    // insert
    if (N == K - 1)
    {
        LA[K - 1] = value;
        printf("%d", LA[K - 1]);
        return N + 1;
    }
    else
    {
        return K;
    }
}
void BubbleSort(int LA[], int N)
{
    int i, p, temp;
    if (N == 0)
    {
        printf("\n Array is empty");
    }
    else
    {
        int i;
        for (i = 1; i < N; i++)
        {
            p = N-1;
            while (p >=0+i)
            {
                if (LA[p] > LA[p - 1])
                {
                    temp;
                    temp = LA[p];
                    LA[p] = LA[p - 1];
                    LA[p - 1] = temp;
                }
                p = p - 1;
            }
        }
        printf("\nArray is Sorted");
    }
}
void Insertionsort(int LA[], int N)
{
    if (N == 0)
    {
        printf("\n Array is empty");
    }
    else
    {
        int i, j, k;
        for (i = 1; i < N; i++)
        {
            k = LA[i];
            for (j = i - 1; j >= 0 && k < LA[j]; j--)
            {
                LA[j + 1] = LA[j];
            }
            LA[j + 1] = k;
        }
        printf("\nArray is Sorted");
    }
}

int MIN(int LA[], int N, int K)
{
    int LOC = K;
    int Min = LA[K];
    int i;
    if (N == 0)
    {
        return -1;
    }
    else
    {
        for (i = K + 1; i < N; i++)
        {
            if (Min > LA[i])
            {
                Min = LA[i];
                LOC = i;
            }
        }
        return LOC;
    }
}

void SelectionSort(int LA[], int N)
{
    if (N == 0)
    {
        printf("\n Array is empty");
    }
    else
    {
        int i, LOC, temp;
        for (i = 0; i < N; i++)
        {
            LOC = MIN(LA, N, i);
            temp = LA[i];
            LA[i] = LA[LOC];
            LA[LOC] = temp;
        }
        printf("\nArray is Sorted");
    }
}
int MAX(int LA[], int N, int K)
{
    int LOC = K;
    int Max = LA[K];
    int i;
    if (N == 0)
    {
        return -1;
    }
    else
    {
        for (i = K + 1; i < N; i++)
        {
            if (Max < LA[i])
            {
                Max = LA[i];
                LOC = i;
            }
        }
        return LOC;
    }
}
void display_P(int *p, int N)
{
    if (N == 0)
    {
        printf("\nArray is empty");
    }
    else
    {
        printf("\nElements in Array");
        int J = 0;
        while (J < N)
        {
            printf("\nLA[%d]:%d", J, *(p + J));
            J = J + 1;
        }
    }
}
void ShellSort(int LA[], int N)
{
    int i, j, temp;
    if (N == size)
    {
        printf("Array is empty");
    }
    else
    {
        for (i = N / 2; i; i--)
        {
            for (j = 0; i + j < N; j++)
            {
                if (LA[j] > LA[i + j])
                {
                    temp = LA[j];
                    LA[j] = LA[i + j];
                    LA[i + j] = temp;
                }
            }
        }
        printf("Array Sorted");
    }
}

void Radix(int LA[], int N)
{
    if (N == 0)
    {
        printf("\n Array is empty");
    }
    else
    {

        int pocket[10][N];
        int i, j;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < N; j++)
            {
                pocket[i][j] = -9999;
            }
        }
        int k, a, b, x = 1, temp, l, c;
        for (k = 1; k <= 3; k++)
        {

            for (l = 0; l < N; l++)
            {
                temp = (LA[l] / x) % 10;
                pocket[temp][l] = LA[l];
            }
            x = x * 10;
            c = 0;
            for (a = 0; a < 10; a++)
            {
                for (b = 0; b < N; b++)
                {
                    if (pocket[a][b] != -9999)
                    {
                        LA[c] = pocket[a][b];
                        pocket[a][b] = -9999;
                        c = c + 1;
                    }
                }
            }
        }
        printf("\n Array sorted");
    }
}
int Mergeing(int A[], int NA, int B[], int NB, int LA[])
{
    int i = 0, j = 0, k = 0;
    int N = NA + NB;
    while (i < NA && j < NB)
    {
        if (A[i] < B[j])
        {
            LA[k] = A[i];
            k = k + 1;
            i = i + 1;
        }
        else
        {
            LA[k] = B[j];
            k = k + 1;
            j = j + 1;
        }
    }
    if (i >= NA)
    {
        int m;
        for (m = 0; m < NB - j; m++)
        {
            LA[k + m] = B[j + m];
        }
    }
    else
    {
        int m;
        for (m = 0; m < NA - i; m++)
        {
            LA[k + m] = A[i + m];
        }
    }

    return N;
}

int BinarySearch(int LA[], int N, int value)
{
    int K = -1;
    if (N == 0)
    {
        printf("\n Array an empty");
    }
    else
    {
        int BEG = 0;
        int END = N - 1;
        int MID = (BEG + END) / 2;
        while ((BEG <= END) && (LA[MID] != value))
        {
            if (value > LA[MID])
            {
                BEG = MID + 1;
            }
            else
            {
                END = MID - 1;
            }
            MID = (BEG + END) / 2;
        }
        if (LA[MID] == value)
        {
            K = MID;
            return K;
        }
    }
}
int MERGE(int A[],int NA,int LBA,int B[],int NB,int LBB,int LA[],int LBLA){
    int i=LBA,j=LBB,k=LBLA;
    int UBA=NA+LBA-1;
    int UBB=NB+LBB-1;
    int N;
    while(i<=UBA && j<=UBB){
        if(A[i]<B[j]){
            LA[k]=A[i];
            i=i+1;
            k=k+1;
        }
        else{
            LA[k]=B[j];
            j=j+1;
            k=k+1;
        }
    }
    if(i>UBA){
        int m;
        for (m = 0; m <= UBB - j; m++)
        {
            LA[k + m] = B[j + m];
        }
    }
    else{
        int m;
        for (m = 0; m <= UBA - i; m++)
        {
            LA[k + m] = A[i + m];
        }
    }
    N=NA+NB;
    return N;
}
void MERGEPASS(int LA[],int N,int L,int B[]){
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int j;
    int LB;
    for(j=1;j<=Q;j++){
        LB=1+(2*j-2)*L;
        MERGE(LA,L,LB-1,LA,L,L+LB-1,B,LB-1);
    }
    if(R<=L){
        for(j=0;j<R;j++){
            B[S+j]=LA[S+j];
        }
    }
    else{
        MERGE(LA,L,S,LA,R-L,L+S,B,S);
    }
    /*
    for(j=0;j<N;j++){
        printf("B[%d]:%d",j,B[j]);
    }*/
}

void MERGESORT(int LA[],int N){
    if(N==0){
        printf("\nEmpty array");
    }
    else{
        int B[N];
        int L=1;
        while (L<N){
            MERGEPASS(LA,N,L,B);
            MERGEPASS(B,N,2*L,LA);
            L=4*L;
        }
        printf("\nArray Sorted");
    }
    
    
}