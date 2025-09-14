#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

char getComputerChoice() {
    char choices[] = {'R', 'P', 'S'};
    return choices[rand() % 3];
}

char getUserChoice() {
    char userChoice;
    cout << "Enter (R)ock, (P)aper, or (S)cissors: ";
    cin >> userChoice;
    return userChoice;
}

void determineWinner(char user, char computer) {
    cout << "Computer chose: " << computer << endl;

    if (user == computer) {
        cout << "It'S a tie!" << endl;
    } else if ((user == 'R' && computer == 'S') ||
               (user == 'P' && computer == 'R') ||
               (user == 'S' && computer == 'P')) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(time(0));
    char playAgain;
    
    do {
        char userChoice = getUserChoice();
        char computerChoice = getComputerChoice();
        determineWinner(userChoice, computerChoice);
        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}
