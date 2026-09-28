#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Öðrenci yapýsý (Struct)
struct Student {
    int id;
    string name;
    string surname;
    double midterm;
    double finalExam;
    double average;
    char letterGrade;
};

// Harf notu hesaplama fonksiyonu
char calculateLetterGrade(double avg) {
    if (avg >= 85) return 'AA'; // wait, char tek karakter alýr, düzeltelim:
} // <- Pardon, alttakini kullan:

char getLetterGrade(double avg) {
    if (avg >= 85) return 'A';
    else if (avg >= 70) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 50) return 'D';
    else return 'F';
}

// Öðrencileri listeleme fonksiyonu
void listStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\n[!] Henuz sistemde kayitli ogrenci yok.\n";
        return;
    }

    cout << "\n============================================================\n";
    cout << left << setw(6) << "ID" 
         << setw(15) << "Ad" 
         << setw(15) << "Soyad" 
         << setw(10) << "Vize" 
         << setw(10) << "Final" 
         << setw(10) << "Ortalama" 
         << setw(6) << "Harf" << endl;
    cout << "============================================================\n";

    for (const auto& s : students) {
        cout << left << setw(6) << s.id
             << setw(15) << s.name
             << setw(15) << s.surname
             << setw(10) << s.midterm
             << setw(10) << s.finalExam
             << setw(10) << fixed << setprecision(2) << s.average
             << setw(6) << s.letterGrade << endl;
    }
    cout << "============================================================\n";
}

// Dosyaya kaydetme fonksiyonu
void saveToFile(const vector<Student>& students) {
    ofstream file("ogrenci_listesi.txt");
    if (!file.is_open()) {
        cout << "[Hata] Dosya acilamadi!\n";
        return;
    }

    file << "ID | Ad | Soyad | Vize | Final | Ortalama | Harf\n";
    file << "--------------------------------------------------\n";
    for (const auto& s : students) {
        file << s.id << " | " << s.name << " | " << s.surname << " | " 
             << s.midterm << " | " << s.finalExam << " | " 
             << s.average << " | " << s.letterGrade << "\n";
    }
    file.close();
    cout << "\n[Basarili] Veriler 'ogrenci_listesi.txt' dosyasina kaydedildi.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- OGRENCI NOT TAKIP SISTEMI ---\n";
        cout << "1. Ogrenci Ekle\n";
        cout << "2. Ogrencileri Listele\n";
        cout << "3. Dosyaya Kaydet (.txt)\n";
        cout << "4. Cikis\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student s;
                cout << "Ogrenci ID: ";
                cin >> s.id;
                cout << "Adi: ";
                cin >> s.name;
                cout << "Soyadi: ";
                cin >> s.surname;
                cout << "Vize Notu: ";
                cin >> s.midterm;
                cout << "Final Notu: ";
                cin >> s.finalExam;

                // Ortalama: %40 vize, %60 final
                s.average = (s.midterm * 0.4) + (s.finalExam * 0.6);
                s.letterGrade = getLetterGrade(s.average);

                students.push_back(s);
                cout << "[Bilgi] Ogrenci basariyla eklendi!\n";
                break;
            }
            case 2:
                listStudents(students);
                break;
            case 3:
                saveToFile(students);
                break;
            case 4:
                cout << "Programdan cikiliyor. Iyi gunler!\n";
                break;
            default:
                cout << "[Hata] Gecersiz secim, tekrar dene.\n";
        }
    } while (choice != 4);

    return 0;
}
