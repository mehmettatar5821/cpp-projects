#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ofstream dY("C:\\Users\\beun28\\Documents\\Test\\metinnn.txt");   //C:\Users\beun28\Documents\Test  //C:\\Test\\MetinC.TXT
	string str;
	
	cout<<"Metni giriniz: ";
	cin>>str;
	dY<<str<<"\n";
	dY.close();
	return 0;
}
