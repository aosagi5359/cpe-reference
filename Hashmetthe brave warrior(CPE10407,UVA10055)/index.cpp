#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    long long int a, b;
    while(cin>>a>>b){
        cout<<abs(a-b)<<endl; //abs()可以計算絕對值
    }
    return 0;
}