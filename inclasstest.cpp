#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <new>

#include <thread>
#include <mutex>

typedef double real_function_t(double);

double numeric = 0;
std::recursive_mutex numeric_mutex;
struct numeric_guard{
	numeric_guard() { numeric_mutex.lock() }
	~numeric_guard() { numeric_mutex.unlock()}
};



double f(double x){
	double y = sin(x);
	return y;
}

Job() {
	thread = 0;
}
