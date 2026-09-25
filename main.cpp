#include <iostream>
#include <string>
using namespace std;

int main() {

    char hex[100];
    int ok = 0;
    int x;
    int letter;

    cout << "Color Program\n";

    while (ok == 0) {

        cout << "Enter 6 digit hex: ";
        cin >> hex;

        if (strlen(hex) != 6) {
            cout << "Wrong size. Must be 6 digits.\n";
        } else {

            x = 0;
            letter = 1;

            do {
                if (!((hex[x] >= '0' && hex[x] <= '9') ||
                      (hex[x] >= 'A' && hex[x] <= 'F') ||
                      (hex[x] >= 'a' && hex[x] <= 'f'))) {

                    letter = 0;
                }
                x = x + 1;
            } while (x < 6);

            if (letter == 1) {
                ok = 1;
            } else {
                printf("Not hex. Try again.\n");
            }
        }
    }

    cout << "You picked: " << hex << endl;

    char first = hex[0];
    first = toupper(first);

    switch (first) {
        case '0':
            printf("Theme: Dark\n");
            break;
        case '1':
            printf("Theme: Middle\n");
            break;
        case '2':
            printf("Theme: Bright\n");
            break;
        case '3':
            printf("Theme: Ultra\n");
            break;
        default:
            printf("Theme: ???\n");
            break;
    }

    int bright = 0;
    int dark = 0;

    if (first == '8' || first == '9' || first == 'A') {
        bright = 1;
    }

    if (first == '0' || first == '1') {
        dark = 1;
    }

    if (bright == 1 && !(dark == 1)) {
        cout << "Brightness: High\n";
    } else if (dark == 1 || first == '4') {
        cout << "Brightness: Low\n";
    } else {
       cout << "Brightness: Medium\n";
    }

int r, g, b;

    r = 0;
    g = 0; 
    b = 0;

    cout << "\nColor Blind Info:\n";

    
    if (r > g && r > b) {
        cout << "This color looks mostly RED.\n";
    } else if (g > r && g > b) {
        cout << "This color looks mostly GREEN.\n";
    } else if (b > r && b > g) {
        cout << "This color looks mostly BLUE.\n";
    } else {
        cout << "This color is a MIX.\n";
    }

    // warn color blind users
    if (g > 150 && r < 100) {
        cout << "Warning: May be hard for Deuteranopia.\n";
    }

    if (r > 150 && g < 100) {
        cout << "Warning: May be hard for Protanopia.\n";
    }

    if (b > 150 && g < 100) {
        cout << "Warning: May be hard for Tritanopia.\n";
    }

    // suggest high contrast alternative
    if (r + g + b < 120) {
        cout << "Suggested Alternative: #FFFFFF (high contrast)\n";
    } else if (r + g + b > 600) {
        cout << "Suggested Alternative: #000000 (high contrast)\n";
    } else {
        cout << "Suggested Alternative: #00FFFF (good visibility)\n";
    }

    cout << "Screen color changed to #" << hex << endl;

    return 0;
}
