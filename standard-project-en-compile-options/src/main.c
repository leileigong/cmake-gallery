#include <stdio.h>
#include "array/array.h"
#include "config.h"

int main(void){
    int a1[] = {1,2,3,3,4,4};
    int a2[] = {2,3,4,5,6};
    merge_array(a1, sizeof(a1)/sizeof(a1[0]), a2, sizeof(a2)/sizeof(a2[0]));

    #ifdef ENABLE_LOG  
    printf("\nrun ok!\n");
    #endif
    
    return 0;
}
