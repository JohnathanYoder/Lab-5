#include <iostream>
#include <cstdlib>
#include <ctime>

// Class for Number Guessing Game
class NumberGuessingGame {
private:
    int wins = 0;
    int losses = 0;
    int maxAttempts = 20;

public:
    // Function to start game
    void startGame() {
        bool playAgain;
        do {
            playGame();
            std::cout << "Do you want to play again? (1 for Yes, 0 for No): ";
            std::cin >> playAgain;
        } while (playAgain);
        std::cout << "Total wins: " << wins << std::endl;
        std::cout << "Total losses: " << losses << std::endl;
    }

private:
    // Function to play game
    void playGame() {
        int randomNumber = generateRandomNumber();
        int userGuess;
        int attempts = 0;
        bool hasWon = false;

        do {
            std::cout << "Guess the number (0 to 100): ";
            std::cin >> userGuess;
            attempts++;

            if (userGuess == randomNumber) {
                hasWon = true;
                break;
            }
            else if (userGuess < randomNumber) {
                std::cout << getMessage(1) << std::endl;
            }
            else {
                std::cout << getMessage(2) << std::endl;
            }
        } while (attempts < maxAttempts);

        if (hasWon) {
            std::cout << getMessage(3) << std::endl;
            wins++;
        }
        else {
            std::cout << getMessage(4) << randomNumber << std::endl;
            losses++;
        }
    }

    // Function to generate random number
    int generateRandomNumber() {
        srand(static_cast<unsigned int>(time(0)));
        return rand() % 101;
    }

    // Function to get message based on case number
    std::string getMessage(int caseNumber) {
        int randomMessage = rand() % 10;
        switch (caseNumber) {
        case 1:
            switch (randomMessage) {
            case 0:
                return "Too low! Try again.";
            case 1:
                return "Guess higher!";
            case 2:
                return "Not quite there. Aim higher.";
                // Add more cases here
            default:
                return "Go higher!";
            }
        case 2:
            switch (randomMessage) {
            case 0:
                return "Too high! Try again.";
            case 1:
                return "Guess lower!";
            case 2:
                return "Overshot! Aim lower.";
                // Add more cases here again
            default:
                return "Go lower!";
            }
        case 3:
            switch (randomMessage) {
            case 0:
                return "Congratulations! You guessed it right!";
            case 1:
                return "You win! Great job!";
            case 2:
                return "Spot on! You got it!";
                // Add more cases here yet again
            default:
                return "You're a winner! Well done!";
            }
        case 4:
            switch (randomMessage) {
            case 0:
                return "Sorry, you lost! The number was ";
            case 1:
                return "Game over! The correct number was ";
            case 2:
                return "You lose! The number was ";
                // Add more cases here YET AGAIN
            default:
                return "Better luck next time! The number was ";
            }
        default:
            return "Invalid case number";
        }
    }
};

int main() {
    NumberGuessingGame game;
    game.startGame();
    return 0;
}