#include <iostream>




char getComputerOption() {
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if (num == 1) return 'r';
    if (num == 2) return 'p';
    if (num == 3) return 's';
}


std::string getSelectedOption(char option) {
    if (option == 'r') {
        return "Rock";
    }
    if (option == 'p') {
        return "Paper";
    }
    return "Scissors";
}

void chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        std::cout << "Computer Wins! Paper wraps Rock." << std::endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        std::cout << "Computer Wins! Scissors cut Paper." << std::endl;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        std::cout << "Computer Wins! Rock smashes Scissors." << std::endl;

    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        std::cout << "You Win! Paper wraps Rock." << std::endl;

    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        std::cout << "You Win! Paper wraps Rock." << std::endl;

    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        std::cout << "You Win! Scissors cut Paper." << std::endl;
    }
    else {
        std::cout << "Tie. Play again win the Game." << std::endl;
    }
}

int main() {
    while (true) {
        char userChoice;
        char computerChoice;

        std::cout << "Enter r for rock, s for scissors, and p for paper: ";
        std::cin >> userChoice;       
        std::cout << "Your choice is: " << getSelectedOption(userChoice) << std::endl;
        computerChoice = getComputerOption();
        std::cout << "Computer's choice is: " << getSelectedOption(computerChoice) << std::endl;

        chooseWinner(userChoice, computerChoice);
        char shouldExit;
        std::cout << "Would you like to keep playing? Enter y to keep playing, n to exit: ";
        std::cin >> shouldExit;
        if (shouldExit == 'n') {
            break;
        }
    }

    return 0;
}