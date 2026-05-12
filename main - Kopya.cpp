#include <iostream>
#include <vector>

using namespace std;

int main() {
    int adet;
    float toplam = 0, sayi;

    cout << "Kac adet sayi girmek istersiniz? ";
    cin >> adet;

    if (adet <= 0) {
        cout << "Gecersiz adet!" << endl;
        return 0;
    }

    vector<float> sayilar;

    for (int i = 0; i < adet; i++) {
        cout << i + 1 << ". sayiyi girin: ";
        cin >> sayi;
        sayilar.push_back(sayi);
        toplam += sayi;
    }

    float enBuyuk = sayilar[0];
    for (int i = 1; i < sayilar.size(); i++) {
        if (sayilar[i] > enBuyuk) {
            enBuyuk = sayilar[i];
        }
    }

    cout << "\n--- Sonuclar ---" << endl;
    cout << "Girdiginiz sayilarin ortalamasi: " << toplam / adet << endl;
    cout << "En buyuk sayi: " << enBuyuk << endl;

    return 0;
}
