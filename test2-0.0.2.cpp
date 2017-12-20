#include <iostream>
#include <sstream>
using namespace std;
void reverse(int *& mas,unsigned int n){
    for(unsigned int j=0;j<n/2;j++) swap(mas[j],mas[n-(j+1)]);
}
void  doublereverse(int *& mas,unsigned int pos1,unsigned int n){
    for( unsigned int j = 0; j < pos1/2; j++) swap(mas[j],mas[pos1-(j+1)]);
    for( unsigned int i = 0; i < (n-pos1)/2; i++)  swap(mas[pos1+i],mas[n-(i+1)]);
}
int main() {
     int n;
    char er;
    string line;
    getline(cin,line);
    istringstream numstream(line);
    if(!(numstream>>n)||!(n>0)){
        cout<<"An error has occuried while reading input data.";
        exit(0);
    }
    getline(cin,line);
    istringstream arrstream(line);
    int *nums=new int[n];
    for(unsigned int i=0;i<n;i++){
        if(!(arrstream>>nums[i])){
            cout<<"An error has occuried while reading input data.";
            exit(0);
        }
    }
    if(arrstream>>er){
          cout<<"An error has occuried while reading input data.";
            exit(0);	
    }
    int pos;
    getline(cin,line);
    istringstream posstream(line);
    if(!(posstream>>pos)||!(pos>0)){
        cout<<"An error has occuried while reading input data.";
        exit(0);
    }
    doublereverse(nums,n-pos,n);
    reverse(nums,n);
    for(unsigned int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    delete[] nums;
    return 0;
}
