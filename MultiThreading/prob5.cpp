/*
* CSE 330 Assignment #3
* Name: Akshay M Nair
* akshayms@asu.edu
* ID: 1212981859

 * Usage info:
 *    To compile: g++ -fopenmp -o prob5 prob5.cpp
 *    To run: ./prob5
 * To save the output in a file, redirect stdout to a file, i.e.,
 *    ./prob5 > outputFile.txt
 * where outputFile.txt is the desired name of the output file.
 */

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <omp.h>

using namespace std;

int sumWithLoop(int * A, int n);
int sumWithLoop_OMP(int * A, int n);
int sumRec(int * A, int n, int start, int end);
int sumRec_OMP(int * A, int n, int start, int end);

int main()
{
   double wtime;
   int n;
   printf ( " How many random numbers do you want to generate?\n" );
   scanf ( "%d", &n );
   int * A;
   A = new int[n];

   //generate n of random numbers
   srand( (unsigned) time(NULL) );
   printf("\n # Random Numners: %d\n", n);
   for(int i = 0; i < n; i++)
   {
      A[i] = rand() % 100;
   }

   int num_procs = omp_get_num_procs ( );
   int max_threads = omp_get_max_threads ( );
   printf ( " Number of processors available = %d\n", num_procs );
   printf ( " Number of threads = %d\n\n", max_threads );

   //executing sumWithLoop and also measuring its execution time
   wtime = omp_get_wtime( );
   int sum1 = sumWithLoop(A, n);
   wtime = omp_get_wtime( ) - wtime;
   printf( "\n sum loop is %d\n", sum1 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumWithLoop_OMP and also measuring its execution time
   wtime = omp_get_wtime ( );
   int sum2 = sumWithLoop_OMP(A, n);
   wtime = omp_get_wtime ( ) - wtime;
   printf( "\n sum loop OMP is %d\n", sum2 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumRec and also mesuring its execution time
   wtime = omp_get_wtime( );
   int sum3 = sumRec(A, n, 0, n-1);
   wtime = omp_get_wtime( ) - wtime;
   printf( "\n sum recursion is %d\n", sum3 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumRec_OMP and also mesuring its execution time
   wtime = omp_get_wtime ( );
   int sum4 = sumRec_OMP(A, n, 0, n-1);
   wtime = omp_get_wtime ( ) - wtime;
   printf( "\n sum recursion OMP is %d\n", sum4 );
   printf ( " time  %14f\n\n", wtime );
}

int sumWithLoop(int * A, int n)
{
//this function will return sum calculate with loop function
	int sum=0;
	for(int i = 0; i < n; i++)
   {	//printf("%d ", A[i]);
      sum+= A[i];
   }

   return sum;
}

int sumWithLoop_OMP(int * A, int n)
{
// this function will calculate the sum with 4 threads and return it
	int sum=0,i;
	#pragma omp parallel shared(sum) private(i) //num_threads(4)	
	{	//printf ( " Number of threads = %d", omp_get_max_threads ( ));
		#pragma omp for 
		for(i = 0; i < n; i++ )
			{	//printf("%d ", A[i]);
				sum+= A[i];
			}

	}
	return sum;
}

int sumRec(int * A, int n, int start, int end)
{	int mid,lsum,rsum,rsize;
// this will return the sum calculated recursively 
	 if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return A[0];
    }
    //printf("%p , %p ", A, A+mid);
    
    mid = n / 2;
    //mid = (start+end)/2;
    rsize = n - mid;
    lsum = sumRec(A, mid,start,end);
    rsum = sumRec(A+ mid,rsize,start,end);
    
    return lsum + rsum;

}

int sumRec_OMP(int * A, int n, int start, int end)
{
	int mid,lsum,rsum,rsize;
// this will return the parallelly calculated sum calculated recursively 
	 if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return A[0];
    }
    //printf("%p , %p ", A, A+mid);
    
    mid = n / 2;
    //mid = (start+end)/2;
    rsize = n - mid;
    #pragma omp parallel num_threads(4)
    {
    	#pragma omp sections
    {
    	#pragma omp section 	
 		   lsum = sumRec(A, mid,start,end);
 		#pragma omp section
 		   rsum = sumRec(A+ mid,rsize,start,end);
    }	
	}
    
    return lsum + rsum;

}
