

#include <iostream>
#include <stdlib.h> 
#include <string.h> 

typedef struct {
    const char *gamer1_choise; // <- typo
    const char *gamer2_choice;
    const char *explanation;
} WINNING_COMBINATION;

bool is_good_option(std::string & user_input) {
    static const char *good_options[] = {
        "r", "p", "s", "exit"
    };
    for (auto good_option : good_options) {
        if (user_input == good_option) {
            return true;
        }
    }
    return false;
}

typedef struct {
    const char *short_option;
    const char *name;
} GAME_OPTION;

GAME_OPTION game_options[] = {
    {"r", "rock"},
    {"p", "paper",},
    {"s", "scissors"}
};

#define NUMBER_OF_GAME_OPTIONS (sizeof (game_options) / sizeof (GAME_OPTION))

const char * bot_picks() {
    return game_options[ rand() % NUMBER_OF_GAME_OPTIONS ].short_option;
}

const char * get_option_name_by_code(const char *option_code) {
    for (auto option : game_options) {
        if (strcmp(option.short_option, option_code) == 0) {
            return option.name;
        }
    }
    return "unk";
}

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
        {"r", "s", "Rock crushes scissors"}
    };



    while (1) {
        std::string answer;
        do {
            std::cout << "Please choose: rock (r) - paper (p) - scissors (s)" << std::endl;
            std::cin >> answer;
        } while (!is_good_option(answer));
        
        if (answer == "exit") {
            break;
        }

        std::string bot_choice = bot_picks();

        std::cout
                << "You choose " << get_option_name_by_code(answer.c_str())
                << ", I choose " << get_option_name_by_code(bot_choice.c_str())
                << std::endl;

        //TODO: implement arbiter
        //TODO: tell user who won

    }



    return 0;
}