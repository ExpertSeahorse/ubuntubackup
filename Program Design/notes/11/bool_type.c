#include <stdio.h>
#include "boolean.h"
/*
#define TRUE 1
#define FALSE 0
typedef int Bool;


Bool logical_and(Bool a, Bool b){
	return a && b;
}


Bool logical_or(Bool a, Bool b){
	return a || b;
}


Bool logical_not(Bool a){
	return !a;
}
*/

int main(){
	Bool a = TRUE;
	Bool b = FALSE;
	
	print_bool(logical_and(a,b));
	print_bool(logical_or(a,b));

	return 0;
}
