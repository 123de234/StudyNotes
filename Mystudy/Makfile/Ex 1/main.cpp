#include <iostream>
#include "foo.h"
#include "bar.h"

using namespace std;

int main(){

    int array[]={2,45,34,12,14,78};
    int n = sizeof(array)/sizeof(array[0]);
    cout<< max(array,n)<<endl;
    cout<< min(array,n)<<endl;
    return 0;
}