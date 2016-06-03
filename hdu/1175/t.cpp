#include <iostream>
using namespace std;

int main(){
    int total[10][10];
    cout<<sizeof(total)<<endl;

    int ** arr = new int*[10];
    for(int i=0;i<10;i++)
        arr[i] = new int[10];
    cout<<sizeof(arr)<<endl;

    return 0;
}
