#ifndef GAME_H
#define GAME_H

#include <iostream> 

#include <string> 
#include <vector> 
#include <algorithm> 
#include <random> 
#include <ctime>
#include <cctype>
#include <unordered_map> 



class Game{
public:
    Game(); 

    std::vector<std::string> all_words_for_game = {
    "play", "win", "wow", "car", "bike", "ski", 
    "skate", "window", "door", "tree", "cat", 
    "dog", "ball", "cup", "book", "pen", "hat", 
    "sun", "star", "moon", "fish", "bird", "flower", 
    "grass", "rain", "snow", "house", "road", "river", 
    "lake", "wave", "air", "sky", "toy", "boat", 
    "light", "shadow", "cloud", "rock", "sand", "ice", 
    "fire", "milk", "juice", "bread", "cake", "egg", 
    "cheese", "shoe", "shirt"
}; 
    std::unordered_map < char , bool> involed_letters; 
    std::vector <char > word_for_game ; 
    std::vector <char> game_status ; 
    static int number_of_lives ; 
    void play_the_game() ; 

private : 
    void print_current_gallows(int numer_of_lives); 
    std::string random_word(); 
    void recording_lives(); 
    bool adding_to_statistics(char letter  );   
    void  players_turn(char letter , std::string game_word , std::vector<char> &word_for_game , std::vector <char> &game_status); 
    void adding_letters_in_word_for_game(std::string game_word, std::vector <char>&word_for_game ); 
    void inserting_empty_cells_in_game_status(std::vector<char>& game_status , int word_size); 
    int SizeWord(std::string game_word); 
    char adding_players_letter(); 
    bool check_win(std::vector<char> game_status , std::string game_word); 
    void print_current_statisic(std::vector <char>& game_status); 

};

#endif
