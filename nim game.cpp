#include <bits/stdc++.h>
using namespace std;

int main()
{
    int coins = 21;
    int take;
    string PName , P2Name;
    cout << "What is your Name ";
    cin >> PName;
    cout << "Choose Player 2 name or 'computer' to play with computer :" ;
    cin >> P2Name;
    if (P2Name == "computer") {
        while (coins > 0 ) {
            cout << PName << " take coins :" ;   cin >> take;
            coins -= take;
            cout << coins <<'\n';
            if (coins <= 0) {
                cout << PName << "Are loses"<<'\n';
                cout << "Computer is win "<<'\n';
                break;
            }
            srand(time(NULL));   int p = rand() % 3 + 1;
            cout << "computer picks :" ;  cout << p <<'\n';
            coins -= p;
            cout << coins<<'\n';
            if (coins <= 0) {
                cout << PName << " is win"<<'\n';
                cout << "Computer is lose "<<'\n';
                break;
            }
        }
    }
    else {
        while (coins > 0 ) {
            cout << PName << " take coins :" ;   cin >> take;
            coins -= take;
            cout << coins <<'\n';
            if (coins <= 0) {
                cout << PName << "Are loses"<<'\n';
                cout << "Computer is win "<<'\n';
                break;
            }
            cout <<P2Name << " take coins :" ;  cin >> take;
            coins -= take;
            cout << coins<<'\n';
            if (coins <= 0) {
                cout << PName << " is win"<<'\n';
                cout <<P2Name << " is lose "<<'\n';
                break;
            }
        }
    }
    return 0;
}
