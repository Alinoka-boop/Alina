#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int M;
int N;
int K;
int kol=0;
int Size=0;
int st=0;
int **mat1;
int **mat2;
int *pr1;
int *pr2;
int a=0;
int g=0;
void *ThreadWorker(void *arg)
{
    int number = *((int *)arg);
    for (int i = Size*number; i<Size*(number + 1) && i<N*M; i++)
    {
       if (pr1[i]==pr2[i])
        {
          g=(i/M)+1;
          cout<<"Stroka  "<<g<<"  "<<"Element   "<<pr1[i]<<"   ";
          cout<<endl;
        }
    }
}

int main()
{
    cout << "Enter M" << endl;
    cin >> M;
    cout << "Enter N" << endl;
    cin >> N;
    cout << "Enter K" << endl;
    cin >> K;

    mat2=new int *[M];
    mat1 = new int *[M];
    int D=M*N;
    pr1 = new int [D];
    pr2 = new int [D];
    for (int i = 0; i < M; i++)
    {
        mat1[i] = new int[N];
        mat2[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat1[i][j] = rand()%5;
            mat2[i][j] = rand()%5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pr1[a]=mat1[i][j];
            pr2[a]=mat2[i][j];
            a++;
        }
    }
    pthread_t *threads = new pthread_t[K];
    Size=D/K+1;
    for (int i = 0; i < K; i += 1)
    {
        int *number = new int(i);
        int errorCode = pthread_create(
            &threads[i],
            NULL,
            ThreadWorker,
            (void *)number);
        if (errorCode != 0)
        {
            cout << "Error creating thread: " << errorCode << endl;

            delete[] threads;

            return -1;
        }
    }

    for (int i = 0; i < K; i++)
    {
        pthread_join(threads[i],NULL);
    }

    delete[] threads;

    return 0;
}
