#include <iostream>
#include <string>

using namespace std;

int main() {

    string message;

    cout << "=== MINI AI BOT ===" << endl;
    cout << "Bot ile konusabilirsin. Cikmak icin 'q' yaz.\n" << endl;

    while (true) {

        cout << "Sen: ";
        getline(cin, message);

        if (message == "q") {
            cout << "Bot: Gorusuruz kral ??" << endl;
            break;
        }

        else if (message == "nasilsin") {
            cout << "Bot: Iyiyim sen nasilsin?" << endl;
        }

        else if (message == "adýn ne") {
            cout << "Bot: Ben mini C++ botuyum." << endl;
        }

        else if (message == "canim sýkýlýyor") {
            cout << "Bot: Git biraz kod yaz ??" << endl;
        }

        else {
            cout << "Bot: Seni tam anlayamadim." << endl;
        }
    }

    return 0;
}
