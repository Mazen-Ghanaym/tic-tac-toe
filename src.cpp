#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;
const int max_size = 3;
class player{
    public:
    char sign;
};
void print_row(){
    //------------
    cout<<"  ";
    for(int i = 0; i < 13; i++)
        cout << "-";
    cout << "\n";
}
void print_grid(char grid[max_size][max_size]){
    system("cls");
    cout << "\n    ";
    for(int i = 1; i <= 3; i++){
        cout<<i<<"   ";
    }
    cout<<"\n";
    print_row();
    for(int i = 0; i < 3; i++){
        cout<< i+1 << " | ";
        for(int j = 0; j < 3; j++){
            cout<<grid[i][j]<<" | ";
        }
        cout<<"\n";
        print_row();
    }
    cout<<"\n";
}
bool check_row(char grid[max_size][max_size], char sign){

    for(int i = 0; i < 3; i++){
        int cnt=0;
        for(int j = 0; j < 3; j++){
            if(grid[i][j]==sign)
                cnt++;
        }
        if(cnt==3)
            return true;
    }

    return false;
}
bool check_col(char grid[max_size][max_size], char sign){

    for(int i = 0; i < 3; i++){
        int cnt=0;
        for(int j = 0; j < 3; j++){
            if(grid[j][i]==sign)
                cnt++;
        }
        if(cnt==3)
            return true;
    }

    return false;
}
bool check_diagonal(char grid[max_size][max_size], char sign){
    // left diagonal
    int cnt=0;
    for (int i = 0; i < 3; i++){
        if(grid[i][i]==sign)cnt++;
    }
    if(cnt==3)
        return true;

    // right diagonal
    cnt=0;
    for(int i = 0, col = 2; i < 3; i++, col--){
        if(grid[i][col]==sign)
            cnt++;
    }
    if(cnt==3)
        return true;

    return false;
}
bool check(char grid[max_size][max_size],char sign){
    bool ch1=check_row(grid,sign);
    bool ch2=check_col(grid,sign);
    bool ch3=check_diagonal(grid,sign);
    return ch1 || ch2 || ch3;
}
int main(){
    ios_base::sync_with_stdio(0);
    char grid[max_size][max_size];
    // initializing the grid with " " sign
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            grid[i][j]=' ';
    }
    // declare two objects from class player
    player p1,p2;

    // assign a sign for player 1 from x : o
    cout<<"player 1 sign [ X : O ] : ";
    do{
        cin>>p1.sign;
        if(p1.sign != 'X' && p1.sign != 'O')
            cout<<"Please provide right sign: ";

    }while(p1.sign!='X' && p1.sign!='O');

    // assign player 2 with the another sign
    if(p1.sign=='X')
        p2.sign='O';
    else
        p2.sign='X';

    system("cls");
    cout << "Player 1: " << p1.sign << "\t Player 2:  " << p2.sign << endl;
    sleep(2);
    system("cls");
    cout << "\t\tLet's start:" <<endl;
    sleep(1);
    bool running=1;
    bool turn = 1;
    while(running){
        running = 0;
        system("cls");
        print_grid(grid);
        if(turn){
            cout<<"Player 1 turn:"<<endl;
            cout<<"choose place [ row  column ] : [ ";
            int i,j;
            cin>>i>>j;
            grid[--i][--j]=p1.sign;
            turn = !turn;
        }else{
            cout<<"Player 2 turn:" << endl;
            cout<<"choose place [ row  column ] : [ ";
            int i,j;
            cin>>i>>j;
            grid[--i][--j]=p2.sign;
            turn = !turn;
        }
        if(check(grid, p1.sign)){
            system("cls");
            print_grid(grid);
            cout<<"Player 1 wins"<<endl;
            continue;
        }
        if(check(grid,p2.sign)){
            system("cls");
            print_grid(grid);
            cout<<"Player 2 wins"<<endl;
            continue;
        }
        running = 1;
    }
    return 0;
}
