 #include <iostream>

using namespace std;

int main() {
    long long sayi;
    int adim = 0;

    cout << "--- COLLATZ SANISI SIMULATORU ---" << endl;
    cout << "Pozitif bir sayi girin: ";
    cin >> sayi;

    if (sayi <= 0) {
        cout << "Lutfen pozitif bir tam sayi girin!" << endl;
        return 0;
    }

    cout << "\nBasliyoruz: " << sayi;

    // Sayi 1 olana kadar dongu doner
    while (sayi != 1) {
        if (sayi % 2 == 0) {
            // Sayi ciftse
            sayi = sayi / 2;
        } else {
            // Sayi tekse
            sayi = (sayi * 3) + 1;
        }
        
        cout << " -> " << sayi;
        adim++;
        
        // Cok fazla sayi yazdirinca ekran karismasin diye her 10 adimda alt satira gecelim
        if (adim % 10 == 0) cout << endl;
    }

    cout << "\n\nIslem tamamlandi!";
    cout << "\nToplamda " << adim << " adimda 1 sayisina ulasildi." << endl;

    return 0;
}
