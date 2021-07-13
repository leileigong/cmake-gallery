#include <stdlib.h>
#include <stdio.h>

int merge_array(int *arr1, int arr1len,  int *arr2, int arr2len)
{
    int i,j,k, m;
    i = j = k = m = 0;

    int *outarr = (int *)malloc((arr1len + arr2len)*4);
    if(!outarr){
        return -1;
    }
    // int outarr[20] = {0};

    while( i < arr1len && j < arr2len){
        if(arr1[i] == arr1[i+1] && (i < arr1len-1)){
            i++;
            continue;
        }
        if(arr2[j] == arr2[j+1] && (j < arr2len-1)){
            j++;
            continue;
        }
        if(arr1[i] < arr2[j]){
            outarr[k++] = arr1[i];
            i++;
        }else if(arr1[i] == arr2[j]){
            outarr[k++] = arr1[i];
            i++;
            j++;
        }else{
            outarr[k++] = arr2[j];
            j++;
        }
    }

    if(i == arr1len){
        for(m = j; m < arr2len; m++){
            outarr[k++] = arr2[m];
        }
    }else{
        for(m = i; m < arr1len; m++){
            outarr[k++] = arr1[m];
        }
    }
    for(i = 0; i < 6; i++)
    {
        printf("%d ", outarr[i]);
    }
    if(outarr){
        free(outarr);
    }
    return 0;
}

