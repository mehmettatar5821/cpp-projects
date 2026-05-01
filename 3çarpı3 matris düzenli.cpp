#include <iostream>
using namespace std;

int main() {
    // float kullanýyoruz çünkü tersi ondalýklý çýkacaktýr
    float a[3][3], kof[3][3], ters[3][3], det;

    // Matrisin elemanlarýný giriyoruz 
    cout << "3x3 Matrisin elemanlarini giriniz:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matris[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    // Girilen matrisi bastýrýyoruz 
    cout << "\nGirilen matris:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Determinant hesabý
    det = (a[0][0] * ((a[1][1] * a[2][2]) - (a[1][2] * a[2][1])) 
         - a[0][1] * ((a[1][0] * a[2][2]) - (a[1][2] * a[2][0])) 
         + a[0][2] * ((a[1][0] * a[2][1] - a[1][1] * a[2][0])));

    cout << "\nDeterminant = " << det << endl;

    if (det != 0) {
        // Kofaktör matrisini hesaplama
        kof[0][0] =  (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
        kof[0][1] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
        kof[0][2] =  (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
        kof[1][0] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
        kof[1][1] =  (a[0][0] * a[2][2] - a[0][2] * a[2][0]);
        kof[1][2] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
        kof[2][0] =  (a[0][1] * a[1][2] - a[0][2] * a[1][1]);
        kof[2][1] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);
        kof[2][2] =  (a[0][0] * a[1][1] - a[0][1] * a[1][0]);

        // Tersini alma iþlemi: Kofaktör matrisinin TRANSPOZUNU determinanta bölüyoruz
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ters[i][j] = kof[j][i] / det; // Dikkat: kof[j][i] transpoz saðlar
            }
        }

        cout << "\nMatrisin Tersi:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << ters[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Determinant 0 oldugu icin matrisin tersi yoktur." << endl;
    }

    return 0;
}

