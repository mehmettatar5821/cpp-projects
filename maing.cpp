#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

// Oyun alaný boyutlarý
const int genislik = 20;
const int yukseklik = 20;

int yilanX, yilanY, yemX, yemY, skor;
int kuyrukX[100], kuyrukY[100];
int nKuyruk;

enum Yon { DUR = 0, SOL, SAG, YUKARI, ASAGI };
Yon yon;
bool oyunBitti;

void Kurulum() {
    oyunBitti = false;
    yon = DUR;
    yilanX = genislik / 2;
    yilanY = yukseklik / 2;
    yemX = rand() % genislik;
    yemY = rand() % yukseklik;
    skor = 0;
    nKuyruk = 0;
}

void HaritayiCiz() {
    // Ekranýn sürekli kýrpýþmasýný önlemek için imleci baþa sarýyoruz
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Üst duvar
    for (int i = 0; i < genislik + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < yukseklik; i++) {
        for (int j = 0; j < genislik; j++) {
            // Sol duvar
            if (j == 0) cout << "#";

            // Yýlanýn kafasý
            if (i == yilanY && j == yilanX)
                cout << "O";
            // Yem
            else if (i == yemY && j == yemX)
                cout << "X";
            else {
                bool kuyrukBasildi = false;
                // Yýlanýn kuyruðu
                for (int k = 0; k < nKuyruk; k++) {
                    if (kuyrukX[k] == j && kuyrukY[k] == i) {
                        cout << "o";
                        kuyrukBasildi = true;
                    }
                }
                if (!kuyrukBasildi) cout << " ";
            }

            // Sað duvar
            if (j == genislik - 1) cout << "#";
        }
        cout << endl;
    }

    // Alt duvar
    for (int i = 0; i < genislik + 2; i++) cout << "#";
    cout << endl;

    cout << "Skor: " << skor << "  [Cikismak icin 'X'e bas]" << endl;
}

void Girdi() {
    // Klavyeden bir tuþa basýldý mý kontrolü
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': yon = SOL; break;
            case 'd': yon = SAG; break;
            case 'w': yon = YUKARI; break;
            case 's': yon = ASAGI; break;
            case 'x': oyunBitti = true; break;
        }
    }
}

void Mantik() {
    int oncekiX = kuyrukX[0];
    int oncekiY = kuyrukY[0];
    int onceki2X, onceki2Y;
    kuyrukX[0] = yilanX;
    kuyrukY[0] = yilanY;

    // Kuyruðu takip ettirme
    for (int i = 1; i < nKuyruk; i++) {
        onceki2X = kuyrukX[i];
        onceki2Y = kuyrukY[i];
        kuyrukX[i] = oncekiX;
        kuyrukY[i] = oncekiY;
        oncekiX = onceki2X;
        oncekiY = onceki2Y;
    }

    // Yönlere göre kafayý hareket ettir
    switch (yon) {
        case SOL: yilanX--; break;
        case SAG: yilanX++; break;
        case YUKARI: yilanY--; break;
        case ASAGI: yilanY++; break;
        default: break;
    }

    // Duvara çarpma kontrolü
    if (yilanX >= genislik || yilanX < 0 || yilanY >= yukseklik || yilanY < 0)
        oyunBitti = true;

    // Kendi kuyruðuna çarpma kontrolü
    for (int i = 0; i < nKuyruk; i++)
        if (kuyrukX[i] == yilanX && kuyrukY[i] == yilanY)
            oyunBitti = true;

    // Yemi yeme kontrolü
    if (yilanX == yemX && yilanY == yemY) {
        skor += 10;
        yemX = rand() % genislik;
        yemY = rand() % yukseklik;
        nKuyruk++;
    }
}

int main() {
    Kurulum();
    // Oyun döngüsü
    while (!oyunBitti) {
        HaritayiCiz();
        Girdi();
        Mantik();
        Sleep(40); // Oyunun hýz ayarý (milisaniye)
    }
    
    system("cls");
    cout << "=========================" << endl;
    cout << " GAME OVER, MEHMET! :(" << endl;
    cout << " Toplam Skorun: " << skor << endl;
    cout << "=========================" << endl;
    return 0;
}
