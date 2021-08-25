#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	double b = DBL_MAX;
	float c = FLT_MAX;
	printf("INT: size=%d, max_value=%d\n",sizeof(a), a);
	printf("DOUBLE: size=%d, max_value=%f\n",sizeof(b), b);
	printf("FLOAT: size=%d, max_value=%f\n",sizeof(c), c);
	return 0;
}
