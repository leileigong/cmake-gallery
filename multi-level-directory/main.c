#include <stdio.h>
#include "util/array.h"

int main(void){
    int a1[] = {1,2,3,3,4,4};
    int a2[] = {2,3,4,5,6};
    merge_array(a1, sizeof(a1)/sizeof(a1[0]), a2, sizeof(a2)/sizeof(a2[0]));
    return 0;
}
