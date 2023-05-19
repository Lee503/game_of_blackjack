#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std; 

//functionn declarations
int rollDice();
int getWager(int money);
void playerTurn(bool & playerBust, int & playerTotal);
void houseTurn( bool &houseBust, int & houseTotal);



int main() {
//a silly little thing i did to look cool 
cout << "----------------------------------------------------------------------------------------------------" << endl;
cout << "--------------------------------------Join us at the Dice-Club--------------------------------------" << endl;
cout << "------------------------------------------------and-------------------------------------------------" << endl;
cout << "-------------------------------------Make sure you wager wisely-------------------------------------" << endl;
cout << "----------------------------------------------------------------------------------------------------" << endl;

//vars 
bool playing = true;
int money = 100;
int playerTotal; 

//seed in srand
srand(time(NULL));

//while loop to make the game go
while (money > 0) {
    int bet = getWager(money);
    bool playerBust = false;
    bool houseBust = false;
    int playerTotal;
    int houseTotal;
    playerTurn(playerBust, playerTotal);
        if (!playerBust) {
            houseTurn(houseBust, houseTotal);
            if (!houseBust) {
                if (playerTotal == houseTotal) {
                    cout << "Its a push! You and the house have tied." << endl;
                }
                else if (playerTotal > houseTotal) {
                    cout << "You win" << endl; 
                    money = money + bet;
                }
                else {
                    cout << "You lost and will lose money" << endl; 
                    money = money - bet; 
                    if (money == 0) {
                        cout << "You have no money left. Thank you for playin!" << endl; 
                    }
                }
            }
            else {
                cout << "The house has busted, you win!" << endl;
                money = money + bet;
            }
        }
        else {
            cout << "You have busted, you lost!" << endl;
            money = money - bet;
            if (money == 0) {
                cout << "You have no money left. Thank you for playin!" << endl; 
            }
        }
}

    return 0;
}

//function defs

//a function to roll
int rollDice(){
    int roll = rand() % 10 + 2;
    return roll;
}

//function to gather the wage
int getWager(int money) { 
    int bet;
    cout << "You currently have: $" << money << endl;
    cout << "How much would you like to bet?" << endl;
    cin >> bet; 
 while ((bet > money) || (bet <= 0)){
         if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout << "Please enter a valid bet." << endl;
        cin >> bet; 
    }
    return bet;
}

//function for the players turn
void playerTurn(bool & playerBust, int & playerTotal) {
int rollOne = rollDice();
int rollTwo = rollDice();
playerTotal = rollOne + rollTwo; 
cout << "Player, you got a " << rollOne << " and " << rollTwo << endl; 
cout << "This gives you a total of " << playerTotal << endl; 
while(true) {
    char choice; 
    cout << "Do you want to HIT (h) or would you like to STAND (s)?"; 
    cin >> choice; 
    if (choice == 's') {
    return;
    }
    else if (choice == 'h') {
        int roll = rollDice();
        playerTotal += roll; 
        cout << "You just rolled a " << roll << endl;
        cout << "This gives you a new total of: " << playerTotal << endl;
            if (playerTotal > 21) {
            playerBust = true; 
                return; 
            }
    }
    else {
        cout << "Invalid choice. Please try again" << endl;
    }
}
}

//function for the house turn 
void houseTurn( bool &houseBust, int & houseTotal) {
int houseroll = rollDice();
houseTotal = houseroll;
cout << "The house rolled a " << houseroll << endl;
cout << "The house now has a total of:  " << houseTotal << endl;
while (houseTotal < 17) {
    houseroll = rollDice();
    houseTotal += houseroll; 
    cout << "The house hit and rolled: " << houseroll << endl;
    cout << "The house has a new total of: " << houseTotal << endl;
    if (houseTotal > 21) {
        houseBust = true;
        return;
    }
}
}
