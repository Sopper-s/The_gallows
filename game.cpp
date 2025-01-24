#include "game.h"




Game::Game(){}




//логика игры
void Game::play_the_game() {
    std::string game_word = random_word(); 
    int word_size = SizeWord(game_word) ; 
    int flag = 1 ;

    adding_letters_in_word_for_game(game_word, word_for_game) ; 
    inserting_empty_cells_in_game_status(game_status, word_size)  ; 

    while (true) {
        

        print_current_gallows(number_of_lives); 
        if (flag == 1) {
            print_current_statisic(game_status); 
            flag = 0 ; 
        }
        char letter_on_current_move = adding_players_letter();
        players_turn(letter_on_current_move, game_word, word_for_game, game_status);
        print_current_statisic(game_status);
        if (number_of_lives <= 0) {
            std::cout << "    +----------------------------------------------+" << '\n'; 
            std::cout << "    | К сожалению, вы проиграли! Загаданное слово: | " << game_word <<std::endl;
            std::cout << "    +----------------------------------------------+" << '\n'; 
            print_current_gallows(number_of_lives); 
            break;
        }
        if (check_win(game_status, game_word)) {

            std::cout << "               +-----------------------+" << '\n'; 
            std::cout << "               | Ура! Вы угадали слово! |" << std::endl;
            std::cout << "               +-----------------------+" << '\n'; 
            break;
        }
    }
}


void Game::print_current_gallows(int number_of_lives){
    if (number_of_lives == 5) {
        std::cout << "            -------------------------" << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |     The beginning     |"  << '\n'; 
        std::cout << "            |  of the Gallows game  |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            |                       |"  << '\n'; 
        std::cout << "            -------------------------"  << '\n'; 
    }
    if (number_of_lives == 4) {
        std::cout << "            -------------------------"  << '\n'; 
        std::cout << "            |                       |" << '\n';
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |                       |" << '\n';
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |                       |" << '\n';
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |         _____         |" << '\n'; 
        std::cout << "            |         |   |         |" << '\n'; 
        std::cout << "            | --------+--+-----+--- |" << '\n'; 
        std::cout << "            -------------------------" << '\n'; 
    }
    if (number_of_lives == 3) {
        std::cout << "            -------------------------" << '\n';
        std::cout << "            |                       |" << '\n'; 
        std::cout << "            |                  |    |" << '\n';
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n';
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |         _____    |    |" << '\n'; 
        std::cout << "            |         |   |    |    |" << '\n'; 
        std::cout << "            | --------+--+-----+--- |" << '\n'; 
        std::cout << "            -------------------------" << '\n'; 
    }
    if (number_of_lives == 2) {
        std::cout << "            -------------------------" << '\n'; 
        std::cout << "            |           +------+    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n';
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |         _____    |    |" << '\n'; 
        std::cout << "            |         |   |    |    |" << '\n'; 
        std::cout << "           | --------+--+-----+--- |" << '\n';
        std::cout << "            -------------------------" << '\n'; 
    }
    if (number_of_lives == 1) {
        std::cout << "            -------------------------" << '\n';
        std::cout << "            |           +------+    |" << '\n';
        std::cout << "            |           |      |    |" << '\n'; 
        std::cout << "            |                  |    |"  << '\n';
        std::cout << "            |                  |    |" << '\n'; 
        std::cout << "            |                  |    |"  << '\n';
        std::cout << "            |                  |    |"  << '\n';
        std::cout << "            |                  |    |"  << '\n';
        std::cout << "            |                  |    |"  << '\n';
        std::cout << "            |         _____    |    |"  << '\n';
        std::cout << "            |         |   |    |    |"  << '\n';
        std::cout << "            | --------+--+-----+--- |"  << '\n';
        std::cout << "            -------------------------" << '\n';
    }
    if (number_of_lives == 0) {
        std::cout << "            -------------------------" << '\n';
        std::cout << "            |           +------+    |"  << '\n';
        std::cout << "            |           |      |    |"  << '\n';
        std::cout << "            |           O      |    |"  << '\n';
        std::cout << "            |         / П \\    |    |"  << '\n';
        std::cout << "            |        |  U  |   |    |"  << '\n';
        std::cout << "            |          /  \\    |    |"  << '\n';
        std::cout << "            |         |    |   |    |"  << '\n';
        std::cout << "            |         I    I   |    |"  << '\n';
        std::cout << "            |         _____    |    |"  << '\n';
        std::cout << "            |         |   |    |    |"  << '\n';
        std::cout << "            | --------+--+-----+--- |"  << '\n';
        std::cout << "            -------------------------"  << '\n';
    }

}

// получение рандомного слова для игры 
std::string Game::random_word(){
    int index = std::rand() % all_words_for_game.size();
    return all_words_for_game[index];
}


int Game::number_of_lives = 5; 


//добавление в статистику использованных элементов + bool вывод было / не было 
bool Game::adding_to_statistics(char letter  ){
    if (involed_letters.find(letter) == involed_letters.end()){

        std::cout << "            +--------------------------+"  << '\n';
        std::cout << "            | Такой буквы еще не было) |" << std::endl ; 
        std::cout << "            +--------------------------+"  << '\n';
        involed_letters[letter] = true; 
        return true; 
    }
    else {

        std::cout << "            +---------------------+"  << '\n';
        std::cout << "            | Вы ее уже вводили ( |" << std::endl ; 
        std::cout << "            +---------------------+"  << '\n';
        return false; 
    }
}

// ход игрока  
void  Game::players_turn(char letter , std::string game_word , std::vector<char> &word_for_game , std::vector <char> &game_status){

    bool correct_guess = false;
    if (adding_to_statistics(letter)) {
        for (int i = 0 ; i < game_word.size() ; i++) {

            if  (letter == word_for_game[i]) {
                game_status[i] = letter ; 
                correct_guess = true; 
            }
        }
        if (!correct_guess) {
            number_of_lives--;
        
        
            std::cout << "        +---------------------------------+"  << '\n';
            std::cout << "        | Неверно! У вас осталось жизней: |  " << number_of_lives << std::endl;
            std::cout << "        +---------------------------------+"  << '\n';
        }
    }

}

// для преобразования из слова в список букв 
void Game::adding_letters_in_word_for_game(std::string game_word, std::vector <char>&word_for_game ){
    for ( auto elem : game_word){
        word_for_game.push_back(elem); 
    }
}




// заполение игрового поля пустыми клетками 
void Game::inserting_empty_cells_in_game_status(std::vector<char>& game_status , int word_size){
    for ( int i = 0 ; i < word_size ; i++){    
        game_status.push_back('_'); 
    }
}

// размер слова 
int Game::SizeWord(std::string game_word){
    return game_word.size(); 
}

// логика ввода символа игроком 
char Game::adding_players_letter(){
    char players_letter ; 
    while (true) {
        std::cout << "               +----------------+" << std::endl; 
        std::cout << "               | Введите букву: |" << std::endl;
        std::cout << "               +----------------+" << std::endl; 
        std::cout << std::endl; 
        std::cin >> players_letter ; 



        if (std::cin.peek() == '\n' && std::isalpha(players_letter)){
            std::cout << "               +----------------+" << std::endl; 
            std::cout << "               | Ваша буква:   " << players_letter << "|" << std::endl;
            std::cout << "               +----------------+" << std::endl; 
            return players_letter; 
        }

        std::cin.clear() ; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускает все символы из входного потока до символа новой строки \n.

            std::cout << "         +--------------------------------+" << std::endl; 
            std::cout << "         | Пожалуйста, введите ОДНУ букву.| \n";
            std::cout << "         +--------------------------------+" << std::endl; 
    }
}

// проверка победы , когда уже не осталось попыток
bool Game::check_win(std::vector<char> game_status , std::string game_word){
    for (int i = 0 ; i < game_status.size() ; i++){
        if (game_status[i] != game_word[i]) {
            return false; 
        }
    }
    return true;

}

void Game::print_current_statisic(std::vector <char>& game_status){
    std::cout << std::endl; 
    std::cout << "+------------------------- "; 
    for ( auto elem : game_status){
        std::cout << elem << " " ; 
    }
    std::cout << " -------------------------+";
    std::cout << std::endl; 
    std::cout<< std::endl; 
}


