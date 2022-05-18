//  This program uses the basic C++ language
//  This program was created by Brett Bax and Brandon O'Haver
//  Class: CS 4500
//  Date: February 9, 2022

//  This program allows the user to participate in the 21 card trick in
//  which the user memorizes a card and then the program guess their card.
//  The central data structure(s) can be found at the bottom which is in our
//  main function.
//  This program does not include any external files.

#include <iostream>
using namespace std;

// This function prints out the 21 total cards to the user so they may
// select one to memorize, but not tell the program which card they are
// choosing.
void dealCards(string arr[]) {
    cout << "Pick a card and memorize it (or write it down)." << endl << endl;
    for (int i = 21; i > 0; i--) {
        cout << arr[i - 1] << "  ";
    }
    cout << endl << endl;
}

// This function takes in the 2D array after the user chooses which column
// their card is in,
// and shuffles the cards back together to then print out the new columns
// for the user to choose from.
void reDealCards(int userInput, string piles[][3]) {
    int columnChoice = userInput;
    int row = 7;
    int col = 3;
    if (columnChoice == 1) {
        for (int i = 0; i < row; i++) {
            swap(piles[i][1], piles[i][0]);
        }
    } else if (columnChoice == 2) {
        for (int i = 0; i < row; i++) {
            swap(piles[i][0], piles[i][2]);
        }
    } else {
        for (int i = 0; i < row; i++) {
            swap(piles[i][2], piles[i][1]);
        }
    }
    string newPiles[7][3];
    int newLine = 0;
    int newCol = 0;
    int newRow = 0;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            // if else statements below reorder array accordingly after
            // redeal using a placeholder 2d array
            if (newCol < 2) {
                newPiles[newRow][newCol] = piles[i][j];
                newCol++;
            } else if (newCol == 2) {
                newPiles[newRow][newCol] = piles[i][j];
                newCol = 0;
                newRow++;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            piles[i][j] = newPiles[i][j];
        }
    }
    // printing reordered array
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (j < 2) {
                cout << piles[i][j] << " ";
            }
            if (j == 2) {
                cout << piles[i][j] << endl;
            }
        }
    }
}
// This function takes in the user final choice for the column with their
// card and prints out which card they chose.
void finalRun(int userInput, string piles[][3]) {
    int columnChoice = userInput;
    int row = 7;
    int col = 3;
    if (columnChoice == 1) {
        for (int i = 0; i < row; i++) {
            swap(piles[i][1], piles[i][0]);
        }
    } else if (columnChoice == 2) {
        for (int i = 0; i < row; i++) {
            swap(piles[i][0], piles[i][2]);
        }
    } else {
        for (int i = 0; i < row; i++) {
            swap(piles[i][2], piles[i][1]);
        }
    }
    cout << endl;
    string newPiles[7][3];
    int newLine = 0;
    int newCol = 0;
    int newRow = 0;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            // if else statements below reorder array accordingly after
            // redeal using a placeholder 2d array
            if (newCol < 2) {
                newPiles[newRow][newCol] = piles[i][j];
                newCol++;
            } else if (newCol == 2) {
                newPiles[newRow][newCol] = piles[i][j];
                newCol = 0;
                newRow++;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            piles[i][j] = newPiles[i][j];
        }
    }
    cout << "Your card is.... " << piles[3][1] << endl << endl;
}
// This is the central function that the program runs from, holding all of
// the global variables and using the local functions as needed.
int main() {
    string cards[21] = {"7H", "9S", "9C", "5D", "7C", "6D", "JD",
                        "QC", "8H", "2S", "7D", "4D", "8C", "3D",
                        "4H", "8D", "2H", "QS", "2D", "4C", "KS"};
    string originalPile[7][3] = {{"7H", "9S", "9C"}, {"5D", "7C", "6D"},
                                 {"JD", "QC", "8H"}, {"2S", "7D", "4D"},
                                 {"8C", "3D", "4H"}, {"8D", "2H", "QS"},
                                 {"2D", "4C", "KS"}};
    bool redo = true;
    int counter = 1;
    int firstColumnPick;
    int secondColumnPick;
    int thirdColumnPick;
    while (redo) {
        dealCards(cards);
        // This allows the user to press the Enter key before the deck is
        // shuffled.
        cout << "To continue press Enter key" << endl;
        cin.ignore();
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 3; j++) {
                if (j < 2) {
                    cout << originalPile[i][j] << " ";
                }
                if (j == 2) {
                    cout << originalPile[i][j] << endl;
                }
            }
        }
        cout << endl << "Which column is your card in? (Choose number: 1 = left column, 2 = middle column, 3 = right column)." << endl << endl;
        cin >> firstColumnPick;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input was not an integer. Please choose a column : 1 = left column, 2 = middle column, 3 = right column." << endl << endl;
            cin >> firstColumnPick;
            cout << endl;
        }
        while (firstColumnPick < 1 || firstColumnPick > 3) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input does not fit the criteria. Please choose a column : 1 = left column, 2 = middle column, 3 = right column." << endl << endl;
            cin >> firstColumnPick;
            cout << endl;
        }
        reDealCards(firstColumnPick, originalPile);
        cout << endl << "Which column is your card in? (Choose number: 1 = left column, 2 = middle column, 3 = right column)." << endl << endl;
        cin >> secondColumnPick;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input was not an integer. Please choose a column : 1 = left column, 2 = middle column, 3 = right column." << endl << endl;
            cin >> secondColumnPick;
            cout << endl;
        }
        while (secondColumnPick < 1 || secondColumnPick > 3) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input does not fit the criteria. Please choose  a column : 1 = left column, 2 = middle column, 3 = right column." << endl << endl;
            cin >> secondColumnPick;
            cout << endl;
        }
        reDealCards(secondColumnPick, originalPile);
        cout << endl << "Which column is your card in? (Choose number: 1 = left column, 2 = middle column, 3 = right column)." << endl << endl;
        cin >> thirdColumnPick;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input was not an integer. Please choose a column : 1 = left column, 2 = middle column, 3 = right column." << endl << endl;
            cin >> thirdColumnPick;
            cout << endl;
        }
        while (thirdColumnPick < 1 || thirdColumnPick > 3) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Input does not fit the criteria. Please choose a column : 1 = left column, 2 = middle column, 3 = right column." << endl 
                            << endl;
            cin >> thirdColumnPick;
            cout << endl;
        }
        finalRun(thirdColumnPick, originalPile);
        cout << "Would you like to play again? Enter Y/y for yes or N/n for no." << endl << endl;
        char yes_no;
        while (cin >> yes_no) {
            if (yes_no == 'y' || yes_no == 'Y') {
                counter++;
                cout << endl;
                break;
            } else if (yes_no == 'n' || yes_no == 'N') {
                cout << endl;
                break;
            } else {
                cout
                    << endl << "Error: Incorrect input! Please enter Y/y for yes or N/n for no." << endl << endl;
            }
        }
        if (yes_no == 'n' || yes_no == 'N') {
            break;
        }
    }
    if (counter == 1) {
        cout << "Thanks for playing! You played once.\n";
    } else {
        cout << "Thanks for playing! You played a total of " << counter << " times !\n";
    }

    return 0;
}