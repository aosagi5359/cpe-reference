#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(cin>>s && s != "0"){ //輸入字串，字串為 0 時，結束迴圈
        long long sum[2] = {0, 0};
        for(int i = 0; i < s.length(); i++)
            sum[i%2] += s[i] - '0';     //字串字元減去0(值為48)，可得奇數值，然後將奇數與偶數分開相加>
        cout<<s<<" is"<<
            ((sum[0] - sum[1]) % 11?" not":" "); //奇數減偶數和，並減檢查兩者之差是否為11倍數
        cout<<"a multiple of 11."<<endl;
    }
}