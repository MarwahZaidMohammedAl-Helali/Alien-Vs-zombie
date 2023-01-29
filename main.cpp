// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T13L
// Names: Marwah Zaid Mohammed AL-helali| | Thabit Mahmood Thabit Ahmed Ibrahim| khaled saeed yaslam joban| 
// IDs: (1211307415)  | (1211305813) |(1211306821)| 
// Emails: 1211307415@student.mmu.edu.my|1211305813@student.mmu.edu.my|
// Phones: +60166287972 | +60109189556 | +601140088286 |
// *********************************************************


// TODO: Fill in the missing information above and delete this line

#include <iostream>
#include "pf/helper.h"
//#include "pf/helper.cpp"
#include <vector>    ///// this for vector;
#include <cstdlib>  ////// this for rand();
#include <iomanip>  ////// this for setw() ;
#include <string>



using namespace std;
void game_initializer();
void new_setting(string) ;
void print_setting() ;
void commander(vector<pf::Position>);
void help();
void quite();
void up() ;
void down();
void left();
void right();
void health();
void find_left();
void find_right();
void go_down();
void go_up();
void rock();
class Alien{

        int life = 100 ;
        int attack = 0 ;
        int x , y ;
    public :
        void printA(){
            cout<< " -->  Alien     :  " << "life ==> " << life << ", attack ==> " << attack << endl;
        }
        void life_plus(){
            if(life + 20 > 100) life = 100;
            else life += 20 ;
        }
        void attack_plus(){
            attack += 20 ;
        }
};
//////////////////////
// Global Variables
//////////////////////
int board_row = 3 ;
int board_col = 19 ;
int zombi_count = 2 ;
int Health_count = 5 ;
int Pod_count = 5 ;
int Rock_count = 5 ;
bool stopR  ;
bool stopL  ;
bool stopU  ;
bool stopD  ;
bool stop ;
int newx ;
int newy ;
string GO_to ;
Alien A ;
vector<pf::Position> POS ;
////////////////////////
///////////////////////
////objects///////////


class Zombie{

    private :
        int life ;
        int attack ;
        int range ;
    public :
        Zombie(int l , int a , int r ){
            life = l ; attack = a , range = r ;
        }

        static void printZombies(vector<Zombie> zombies) {
            for (int i = 0; i < zombies.size(); i++) {
                cout << "      ";
                cout << "Zombie " << setfill('0') << setw(2) << i+1 << " :  " ;
                cout << "life ==> " << setfill('0') << setw(3) << zombies[i].life ;
                cout << ", attack ==> " << setfill('0') << setw(3) << zombies[i].attack ;
                cout << ", range ==> " << setfill('0') << setw(3) << zombies[i].range ;
                cout << endl;
            }
        }
};
vector<Zombie> createZombies(int count) {
    std::vector<Zombie> zombies;
    for (int i = 0; i < count; i++) {
        int life = 50 + rand() % 151;  // random number between 50 and 200
        int attack = rand() % 26;  // random number between 0 and 25
        int range = 1 + rand() % 3;  // random number between 1 and 3
        // Get values for life, attack, and range from the user
        zombies.push_back(Zombie(life, attack, range));
    }
    return zombies;
}

////////////////////////////
/////////////////////////////
////////////main/////////////
int main()
{
    game_initializer();
    pf::ClearScreen();
    pf::CreateGameBoard(board_row,board_col,zombi_count,Health_count,Pod_count,Rock_count);
    pf::ShowGameBoard(board_row,board_col);
    POS = pf::getPOS() ;
    commander(POS) ;

    return 0;
}
//////////////////////////////
/////////////////////////////
//////////functions//////////
void game_initializer(){

    string state ;
    cout<< "Default Game Setting"<< endl;
    cout<< "--------------------"<< endl ;
    print_setting() ;
    cout<< "Do you wish to change Game setting (Y/N) => " ;
    cin >> state ;
    new_setting(state) ;

}
void new_setting(string st){
    string state = st ;
    if( (state == "Y") || (state=="y")) {
        pf::ClearScreen();
        cout << "Board Setting" << endl ;
        cout << "-------------" << endl ;
        cout<< endl;
        do{
            cout<< "Enter new Board Rows and must be odd Number      : " ;
            cin >> board_row ;
        }while(board_row%2 == 0);

        do{
            cout<< "Enter new Board Columns and must be odd Number   : " ;
            cin >> board_col ;
        }while(board_col%2 == 0);

        cout<< "Enter new Zombie Count     : " ;
        cin >> zombi_count ;
        cout << endl <<"Setting updated ......." << endl << endl;
    }
    cout << endl ;
    pf::Pause();

}
void print_setting(){

    cout<< "Board Rows       : " << board_row << endl;
    cout<< "Board Columns    : " << board_col << endl;
    cout<< "Zombie Count     : " << zombi_count << endl << endl ;
}
void commander(vector<pf::Position> POS){
    vector<Zombie> zombies = createZombies(zombi_count) ;
    string command ;
    while(true){
        A.printA();
        Zombie::printZombies(zombies);
        cout << POS[0].x+1 << " , " <<POS[0].y+1 ;
        cout << endl <<"command > " ;
        cin >> command ;
        if(command == "help") help() ;
        else if(command == "quite") quite();
        else if(command == "up") {
            up() ;
           POS[0].x = newx ;
        }
        else if(command == "down"){
            down() ;
            POS[0].x = newx ;
        }
        else if(command == "left"){
            left() ;
            POS[0].y = newy ;
        }
        else if(command == "right"){
            right() ;
            POS[0].y = newy ;
        }
        pf::ClearScreen();
        pf::ShowGameBoard(board_row,board_col);
    }
}
void help(){
    cout << endl ;
    cout << "1. UP      -  Move up." << endl ;
    cout << "2. Down    -  Move down." << endl ;
    cout << "3. left    -  Move left." << endl ;
    cout << "4. Right   -  Move right." << endl ;
    cout << "5. arrow   -  Change direction of arrow." << endl ;
    cout << "6. help    -  Display these user commands." << endl ;
    cout << "7. save    -  Save the game." << endl ;
    cout << "8. load    -  Load a game." << endl ;
    cout << "9. quite   -  Quite the game." << endl ;
    cout << endl ;
    pf::Pause();
}
void quite(){
    string state ;
    cout << endl;
    cout << "Are you sure to quite game (Y/N) : " ;
    cin >> state ;
    if((state == "Y") || (state=="y")){
        exit(0);
    }
    else{
        pf::Pause();
    }
}
void up(){
    stop = false;
    while(POS[0].x != 0 && (stop == false )){
        int rowid = POS[0].x - 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == rowid) && (POS[i].y==POS[0].y))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                if(POS[i].type == '>'){
                        find_right();
                        GO_to = "right";
                }
                if(POS[i].type == '<'){
                        find_left();
                        GO_to = "left" ;
                }
                if(POS[i].type == '^'){
                        go_up();
                       // GO_to = "up" ;
                }
                if(POS[i].type == 'v'){
                        go_down();
                        GO_to = "down" ;
                }
                if(POS[i].type == 'r'){
                        stopU = true ;
                        rock();
                }
                POS[i].type = 'x' ;
            }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].x = POS[0].x - 1 ;

        newx = POS[0].x ;
        cout<< newx +1 << " , " << POS[0].y+1 <<endl ;

    }
    pf::set_board('A',POS[0].x,POS[0].y);
    if(GO_to == "down") {
            down() ;
            GO_to = "stop";
    }
    else if(GO_to == "up") {
            up();
            GO_to = "stop";
    }
    else if(GO_to == "left") {
            left();
            GO_to = "stop";
    }
    else if(GO_to == "right") {
            right();
            GO_to = "stop";
    }
    else GO_to = "stop" ;
    pf::Pause();
}
void down(){
    stop = false;
    while(POS[0].x != board_row-1 && (stop == false )){
        int rowid = POS[0].x + 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == rowid) && (POS[i].y==POS[0].y))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                if(POS[i].type == '>'){
                        find_right();
                        GO_to = "right";
                }
                if(POS[i].type == '<'){
                        find_left();
                        GO_to = "left" ;
                }
                if(POS[i].type == '^'){
                        go_up();
                        GO_to = "up" ;
                }
                if(POS[i].type == 'v'){
                        go_down();
                      //  GO_to = "down" ;
                }
                if(POS[i].type == 'r'){
                        stopD = true ;
                        rock();
                }

                POS[i].type = 'x' ;
            }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].x = POS[0].x + 1 ;
        newx = POS[0].x ;
        cout<< POS[0].x +1<< " , " << POS[0].y +1 <<endl ;

    }
    pf::set_board('A',POS[0].x,POS[0].y);
    if(GO_to == "down") down() ;
    else if(GO_to == "up") up();
    else if(GO_to == "left") left();
    else if(GO_to == "right") right();
    pf::Pause();
}
void left(){
    stop = false ;
    while( (POS[0].y != 0) && (stop == false )){
        int colid = POS[0].y - 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == POS[0].x) && (POS[i].y==colid))
            {
                if(POS[i].type == 'h') {
                        health();
                }
                if(POS[i].type == '>'){
                        find_right();
                        GO_to = "right";
                        stop = true;

                }
                if(POS[i].type == '<'){
                        find_left();
                    //    GO_to = "left" ;
                    //    stop = true;
                }
                if(POS[i].type == '^'){
                        go_up();
                        GO_to = "up" ;
                        stop = true;

                }
                if(POS[i].type == 'v'){
                        go_down();
                        GO_to = "down" ;
                        stop = true;
                }
                if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                POS[i].type = 'x' ;
            }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].y = POS[0].y - 1 ;
        newy = POS[0].y ;
        cout<< POS[0].x+1 << " , " << POS[0].y+1 <<endl ;

    }
    pf::set_board('A',POS[0].x,POS[0].y);
    if(GO_to == "down") {
            down() ;
            GO_to = "stop";
    }
    else if(GO_to == "up") {
            up();
            GO_to = "stop";
    }
    else if(GO_to == "left") {
            left();
            GO_to = "stop";
    }
    else if(GO_to == "right") {
            right();
            GO_to = "stop";
    }
    else GO_to = "stop" ;
    pf::Pause();
}
void right(){
    stop = false;
    while(  (POS[0].y != board_col-1) && (stop == false )){
        int colid = POS[0].y + 1 ;
        for(int i=0 ; i < POS.size() ; i++){
            if( (POS[i].x == POS[0].x) && (POS[i].y==colid))
            {
                if(POS[i].type == 'h') {
                    health();
                }
                if(POS[i].type == '>'){
                        find_right();
                     //   GO_to = "right";
                     //   stop == true ;

                }
                if(POS[i].type == '<'){
                        find_left();
                        GO_to = "left";
                        stop = true ;

                }
                if(POS[i].type == '^'){
                        go_up();
                        GO_to = "up" ;
                        stop = true ;

                }
                if(POS[i].type == 'v'){
                        go_down();
                        GO_to = "down" ;
                        stop = true ;
                }
                if(POS[i].type == 'r'){
                        stop = true ;
                        rock();
                }
                POS[i].type = 'x' ;
            }
        }
        pf::set_board('.',POS[0].x,POS[0].y);
        POS[0].y = POS[0].y + 1 ;
        newy = POS[0].y ;
        cout<< POS[0].x+1 << " , " << POS[0].y+1 <<endl ;

    }
    pf::set_board('A',POS[0].x,POS[0].y);
    if(GO_to == "down") down() ;
    else if(GO_to == "up") up();
    else if(GO_to == "left") left();
    else if(GO_to == "right") right();
    pf::Pause();
}
void health(){
    A.life_plus() ;
    cout << "Alien finds health pack +20 ";
}
void find_left(){
    A.attack_plus() ;
    cout << "move to the left and +20 attack ";

}
void find_right(){

    A.attack_plus() ;
    cout << "move to the right and +20 attack ";

}
void go_up(){
    A.attack_plus() ;
    cout << "move up and +20 attack ";

}
void go_down(){
    A.attack_plus() ;
    cout << "move down and +20 attack ";

}
void rock(){
    cout << "it's a rock ==> ";
    int random_object = std::rand() % 6 ;
    switch(random_object){
          case 1 :
                go_down();
            break ;
          case 2 :
                go_up();
            break ;
          case 3 :
                find_right();
            break ;
          case 4 :
                find_left();
            break ;
          case 5 :
                health();
            break ;
          case 6 :
                cout<<"POD" ;
            break ;
          default:
            cout<<" empty  " ;
    }

}
