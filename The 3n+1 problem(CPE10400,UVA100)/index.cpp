#include <iostream>
using namespace std;
int main(){
    int a, b;
    while(cin>>a>>b){
        cout<<a<<" "<<b<<" ";
        if(a > b) {int c = a; a = b; b = c;} //較小值存到a，較大值存到b
        int maxLen = 0;
        for(int k = a; k <= b; k++){ //列舉所有[a,b]間的數字k
            int n = k, len = 1; //將k轉交給n，n在執行過程中會變動，保持k不變，使用len紀載考拉茲長度(計數器)
            while(1){
                if(n == 1) break;
                if(n % 2) n = n*3+1;    //當n為奇數:3*n+1
                else n /= 2;            //當n為偶數:n/2
                len++;
            }
            maxLen = max(len, maxLen);
        }
        cout<<maxLen<<endl;
    }
    return 0;
}