#include <iostream>

#include <stdio.h>

#include <conio.h>

using namespace std;

 

int main( ) {


int x,toplam=0;


cout<<"enter a number : "<<endl;

cin>>x;

while(x>0){


toplam=toplam+(x%10);

x=x/10;

}

cout<<"basamak deðeri toplamý "<<toplam;

return 0;}
