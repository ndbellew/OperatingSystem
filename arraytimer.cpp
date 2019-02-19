#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int num = 5000;
int foo [num][num];

int main(int argc, char *argv[]){

	time_t start = clock();
	for ( int i = 0; i < num; i++)
		for (int j = 0; j<num;j++)
			foo[i][j] = 0;
	
	double duration = ( clock() - start) / (double) CLOCKS_PER_SEC;
	printf("Row to Column\nTime to Completion: %f\n", duration);
	
	time_t start2 = clock();
	for (int i = 0; i<num;i++)
		for(int j = 0; j<num; j++)
			foo[j][i]=1;
	double duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;
	printf("Column to Row\nTime to Completion: %f\n", duration2);
	
	return 0;
	
}
