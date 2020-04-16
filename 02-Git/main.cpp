

#include <iostream>

typedef struct {
    const char *gamer1_choise; // <- typo
    const char *gamer2_choice;
    const char *explanation;
} WINNING_COMBINATION;


int main() {

    std::cout << "Rock / Paper / Scissors gambling game (single player - human vs computer) @ Bot Inc." << std::endl;
    /*
     *  Scissors cuts paper
     * Paper covers rock.
     *  Rock crushes lizard.
     *  Lizard poisons Spock. Spock smashes scissors. Scissors decapitates lizard. Lizard eats paper. Paper disproves Spock. Spock vaporizes rock. 
     * Rock crushes scissors.     
     */
    WINNING_COMBINATION winning_combinations[] = {
        {"s", "p", "Scissors cuts paper"},
        {"r", "p", "Paper covers rock"},
        {"r","s", "Rock crushes scissors"}
    };

    
    return 0;
}