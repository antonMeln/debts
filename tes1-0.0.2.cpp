#include <iostream>
#include <sstream>
using namespace std;
int main(){
	bool check=false;
	int mas[10],num,sum,i1,j1;
		string str;
    getline(cin,str);
    cin>>sum;
    istringstream stream(str);
    for(int i=0;i<10;i++){
    	if(!(stream>>num)){
    		cout<<"An error has occured while reading the input sequence.";
    		exit(0);
    	}
    	mas[i]=num;
    }
    for (int i=0;i<10;i++){
      if (mas[i]>mas[i+1]){
        cout<<"The input sequence must be non-decreasing.";
        cin.get();
        exit(0);
      }
    }
    for(int j=0;j<10;j++){
      for(int i=0;i<10;i++){
    	if((mas[i]+mas[j]==sum)&&(i!=j)){
    	i1=i;
    	j1=j;
    	check=true;  
    	  }
      }
    }
    	if(check) cout<<mas[i1]<<" "<<mas[j1];
    	else cout<<"There is no such pair of numbers";
	return 0;
}
