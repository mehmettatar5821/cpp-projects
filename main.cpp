#include <iostream>
// basit hesap makinesi 
using namespace std;

int main() {
    char islem;
    double sayi1, sayi2;

    cout << "--- Basit Hesap Makinesi ---" << endl;
    
    cout << "Birinci sayiyi giriniz: ";
    cin >> sayi1;

    cout << "Yapmak istediginiz islemi secin (+, -, *, /): ";
    cin >> islem;

    cout << "Ikinci sayiyi giriniz: ";
    cin >> sayi2;

     
    switch(islem) {
        case '+':
            cout << "Sonuc: " << sayi1 + sayi2 << endl;
            break;

        case '-':
            cout << "Sonuc: " << sayi1 - sayi2 << endl;
            break;

        case '*':
            cout << "Sonuc: " << sayi1 * sayi2 << endl;
            break;

        case '/':
             
            if(sayi2 != 0)
                cout << "Sonuc: " << sayi1 / sayi2 << endl;
            else
                cout << "Hata: Bir sayi 0'a bolunemez!" << endl;
            break;

        default:
            
            cout << "Hata: Gecersiz bir islem girdiniz!" << endl;
            break;
    }

    return 0;
}
