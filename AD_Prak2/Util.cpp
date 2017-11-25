#include "Util.h"

void charcpy(char *arr1, const char *arr2, int gr){
	for(int i = 0; i < gr; i++){
		arr1[i] = arr2[i];
	}
}

int compchar(const char *arr1, int gr1, const char *arr2, int gr2){
	int i;
	for(i = 0; i < gr1 && i < gr2; i++){
		if(arr1[i] != arr2[i]){
			return arr1[i] - arr2[i];
		}
	}
	if(gr1 == gr2){
		return 0;
	} else if(gr1 < i){
		return -arr2[i];
	} else{
		return arr1[i];
	}
}