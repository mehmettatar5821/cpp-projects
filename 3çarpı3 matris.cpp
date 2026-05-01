#include <iostream>
using namespace std;
 
int main( ) {
int a[3][3],kof[3][3],ters[3][3];
//matrisin elemanlerýný giriyoruz 
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
{cout<<"<"<<j<<","<<j<<">=";
cin>>a[i][j];
}
cout<<endl;}//giriþ iþlemlerinin sonu
//girilen matrisi bastýrýoruz 
cout<<"girilen matris :"<<endl;
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++)
	{cout<<a[i][j]<<" ";
	}
	cout<<endl;
}	
//*************************************************************	
	
	
	return 0;
}
