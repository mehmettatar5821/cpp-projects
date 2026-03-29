#include <iostream>
using namespace std;
int enk(int,int); 
int enb(int,int);
     //ana program
int main( ) {
	int a,b;
cout<<"iki sayi giriniz: ";
cin>>a;
cout<<"//";
cin>>b;

cout<<"buyuk sayi: "<<enb(a,b);
cout<<"kucuk sayi: "<<enk(a,b);
	
	
	
	return 0;
} 
int enk(int x,int y){
	if(x<y){
		return x;
	}else {
		return y;
	}
}
int enb(int x,int y){
	if(x>y){
		return x;
	}else{
		return y;
	}
}
