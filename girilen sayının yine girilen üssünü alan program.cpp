#include <iostream>
#include <string>
using namespace std;                                                   
  
 float exp(float x, float y);
   
int main( ) {
	float base,result=0;
	int exponent;
	cout<<"Enter base and exponent values:";
	cin>>base>>exponent;
	result=exp(base,exponent);
	cout<<"result:"<<result<<"\n";
 
	return 0;
}
float exp(float x, float y){
	float result=1;
	int i;
	if(x==0){
		result=0;
	}else {
		if(y==0){
			result=1;
		}else if(y<0){
			for(i=0;i<-y;i++)
			result*=1/x;
		}else{
			for(i=0;i<y;i++)
			result*=x;
		}
	}
	return result;
}
