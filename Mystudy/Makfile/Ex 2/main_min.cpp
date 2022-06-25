#include <iostream>
#include "min.h"

using namespace std;

int main(){

    int array[]={2,45,34,12,14,78};
    int n = sizeof(array)/sizeof(array[0]);
    cout<< min(array,n)<<endl;
    return 0;
}