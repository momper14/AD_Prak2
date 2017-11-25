#include "Util.h"

void charcpy(char *arr1, const char *arr2, int gr){
	for(int i = 0; i < gr; i++){
		arr1[i] = arr2[i];
	}
}
