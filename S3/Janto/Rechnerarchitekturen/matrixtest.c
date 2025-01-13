/*
 * matrixtest.c
 *
 *  Created on: Mar 14, 2022
 *      Author: auch
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <x86intrin.h>

#define PREFERRED_ALIGNMENT 64

// 4 doubles -> 256 bits
#define DOUBLE_SIZE_VEC (4)


void dgemm(int n, double * a, double * b, double * c)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			double cij = c[i + j*n];
			for(int k=0; k<n; k++)
			{
				cij += a[i + k*n] * b[k + j*n];
			}
			c[i + j*n] = cij;
		}
	}
}

void dgemm2(int n, double * a, double * b, double * c)
{
	for(int j=0; j<n; j++)
	{
		for(int i=0; i<n; i++)
		{
			double cij = c[i + j*n];
			for(int k=0; k<n; k++)
			{
				cij += a[i + k*n] * b[k + j*n];
			}
			c[i + j*n] = cij;
		}
	}
}

void vectorized_dgemm(int n, double * a, double * b, double * c)
{
	for(int i=0; i<n; i+=DOUBLE_SIZE_VEC)
	{
		for(int j=0; j<n; j++)
		{
			// cij=c[i][j]
			__m256d cij=_mm256_load_pd(c+i+j*n);
			for(int k=0; k<n; k++)
				// cij= cij +a[i][k] * b[k][j]
				cij=_mm256_add_pd(cij,
						_mm256_mul_pd(_mm256_load_pd(a+i+k*n),_mm256_broadcast_sd(b+k+j*n))
					);
			// c[i][j] = cij
			_mm256_store_pd(c+i+j*n,cij);
		}
	}}

double trace(int n, double * matrix)
{
	double trace = 0;
	double temp;
	for(int i = 0; i < n; i++)
	{
		temp = 0.0;
		for(int j = 0; j < n; j++)
			temp += matrix[i + j*n] * matrix[i + j*n];
		trace += temp * temp;
	}

	return trace;
}

double trace2(int n, double * matrix)
{
	double trace = 0;
	double temp;
	for(int j = 0; j < n; j++)
	{
		temp = 0.0;
		for(int i = 0; i < n; i++)
			temp += matrix[i + j*n] * matrix[i + j*n];
		trace += temp;
	}

	return trace;
}

double gettime()
{
  struct timeval ttime;
  gettimeofday(&ttime , NULL);
  return ttime.tv_sec + ttime.tv_usec * 0.000001;
}

double* create_rnd_matrix(int n)
{
	size_t matrix_size = sizeof(double) * (size_t)n * (size_t)n;
	double* matrix = aligned_alloc(PREFERRED_ALIGNMENT, matrix_size);

	srand(time(0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			matrix[i*n + j] = drand48();

	return matrix;
}

int main (int argc, char *argv[])
{
	int n = 2048;

	if(argc >= 2)
		n = atoi(argv[1]);

	printf("n = %d ... ", n);

	double* a = create_rnd_matrix(n);
	double* b = create_rnd_matrix(n);
	double* c = create_rnd_matrix(n);
	printf("Matrices created.\n");

	double start_time, end_time;

	start_time = gettime();
	dgemm(n, a, b, c);
	end_time = gettime();
	printf("Time dgemm: %f sec\n", end_time - start_time);

	start_time = gettime();
	vectorized_dgemm(n, a, b, c);
	end_time = gettime();
	printf("Time vec-dgemm: %f sec\n", end_time - start_time);

	start_time = gettime();
	//dgemm(n, a, b, c);
	trace(n, a);
	end_time = gettime();
	printf("Time trace: %f sec\n", end_time - start_time);

	start_time = gettime();
	//dgemm(n, a, b, c);
	trace2(n, a);
	end_time = gettime();
	printf("Time trace2: %f sec\n", end_time - start_time);

	free(a);
	free(b);
	free(c);
}
