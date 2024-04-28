#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string input;
bool game_active = true;
string word;


void clear(){
    system("clear");
}

void input_custom(){
    //create and open file 
    ofstream custom_words ("custom_words.txt");
    clear();
    cout << "Input a word or quit by typing \"q\"";
    cin >> input;
    while (input != "q")
    {
        clear();
        custom_words << input;
        cout << "Input next word or quit by typing \"q\"";
        cin >> input;
    }

    custom_words.close();
    
}

void edit_custom(){
    input_custom();
    clear();
    cout << "Custom words edit sucessfully!\n";
}

bool is_custom(int input){
    if(input == 1){
        return false;
    }else if(input == 2){
        return true;
    }else{
        EXIT_FAILURE;
    }
}

string random_word(){

}

void random_words(){
    int counter = 0;

    ifstream random_words ("random_words.txt");

    if (!random_words)
    {
        cerr << "Error opening file " << "random_words.txt" << "\n";
        EXIT_FAILURE;
    }

    while(getline(random_words, word))
    {
        counter++;
        if(counter == 3)
        {
            cout << word;
        }

    }

    random_words.close();
    
}

void custom_words(){

}

void help(){

}

void menu(bool game_active){
    int input;

    while(game_active){
        clear();
        cout << "\t Welcome to Hangman! \n"
        << "1. Play with random words (english) \n"
        << "2. Play with custom words \n" 
        << "3. Edit custom words \n"
        << "4. Help \n"
        << "5. Exit \n";

        cin >> input;

        switch(input){
            case 1:
                random_words();
                break;
            case 2:
                custom_words();
                break;
            case 3:
                edit_custom();
                break;
            case 4:
                help();
                break;
            case 5:
                game_active = false;
                return;
                break;
            default:
                break;
        }
    }
}

int main()
{
    random_words();

    return 0;

}
