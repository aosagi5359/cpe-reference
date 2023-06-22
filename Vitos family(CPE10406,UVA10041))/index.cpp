#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num; //宣告一個vector為num

int main(){
    int n ,r ,s;
    cin>>n; //個資筆數
    while(n--){
        cin>>r;
        num.clear();
        for(int i = 0; i < r; i++){  //13 ~ 16 親戚接號輸入到vector中
            cin>>s; //親戚個數
            num.push_back(s);
        } 
        sort(num.begin(), num.end()); //取vector內的號碼排序
        int mid=num[r/2];//取出中位數
        int sum = 0;
        for(int i = 0; i<r; i++){ //計算本家到各個親戚家的距離
        sum+=abs(num[i]-mid);
        }
        cout<<sum<<endl;
    }
    return 0;
}