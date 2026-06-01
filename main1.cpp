#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

int main() {
    // Windows terminalinde renkleri yeþil yapmak için sistem komutu
    // (Arka plan siyah '0', yazýlar parlak yeþil 'A')
    system("COLOR 0A");
    
    // Rastgele sayý üreticiyi sýfýrlýyoruz
    srand(time(0));
    
    std::string karakterler = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%&*";
    int uzunluk = karakterler.length();
    
    std::cout << "Matrise hos geldin, Mehmet... Cikmak icin Ctrl+C yapabilirsin.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 2 saniye bekle
    
    // Sonsuz döngü - Matris akýþý baþlýyor
    while (true) {
        // Ekran geniþliði kadar rastgele karakter ve boþluk basýyoruz
        for (int i = 0; i < 80; ++i) {
            if (rand() % 10 < 2) {
                // Rastgele bir karakter seç ve yazdýr
                std::cout << karakterler[rand() % uzunluk] << " ";
            } else {
                // Akýþýn güzel görünmesi için boþluklar býrak
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
        
        // Akýþ hýzýný ayarlamak için milisaniye cinsinden gecikme (Hýzý buradan deðiþtirebilirsin)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    
    return 0;
}
