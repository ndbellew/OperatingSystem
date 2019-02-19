#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

typedef double integrand(double);

double f(double x){
	double y = sin(x);
	return y;
}

double integrate(integrand *f, double a, double b, int n){
	double ans = 0;
	double h = (b-a)/n;
	for (int i=0;i<n;++i){
		double x = a+h*i;
		ans = ans + h*f(x);
	}
	return ans;
}

struct job_struct{
	integrand *f;
	double a;
	double b;
	int n;
	double A;
	pthread_t thread;
};

typedef struct job_struct job_t;

void* worker(void *arg){
	job_t *job = (job_t*) arg;
	job->A = integrate(job->f,job->a,job->b,job->n);
	return 0;
}

int main(int argc, char *argv[]){

	double a = atof(argv[1]);
	double b = atof(argv[2]);
	int n = atoi(argv[3]);
	int njobs = atoi(argv[4]);

	double A = integrate(f,a,b,n);
	
	job_t *jobs = malloc(sizeof(job_t)*njobs);
	
	
	for (int i=0;i<njobs;++i){
		jobs[i].a = a + (b-a) *((double) i/((double) njobs));
		jobs[i].b = a + (b-a) *((double) (i+1)/((double) njobs));
		jobs[i].n = n/njobs;
		jobs[i].f = &f;
		jobs[i].A=0;
	}
	
	A = 0;
	for(int i = 0; i<njobs; ++i){
		pthread_create(&jobs[i].thread, 0, worker, &jobs[i]);
		//worker(&jobs[i]);
	}
	for (int i= 0; i<njobs;++i){
		pthread_join(jobs[i].thread,0);
	}
	 for (int i = 0; i<njobs; ++i){
		 A = A + jobs[i].A;
	 }
	
	printf("integrate(f, %lf, %lf, %d) = %lf\n",a,b,n,A);

	return 0;
}
