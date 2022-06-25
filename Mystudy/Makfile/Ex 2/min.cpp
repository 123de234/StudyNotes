#include "min.h"

int min(int array[], int n){
    int i;
    int m = array[0];
    for (i=0; i<n; i++){
        if (array[i]<m){
            m= array[i];
        }
    }
    return m;
}