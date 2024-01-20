#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <dirent.h>
#include <Windows.h>



using namespace std;

// global variables //

bool check = false ;
vector<int> positionj ;
vector<int> positioni ;
vector<vector<int>> copycopymaze ;
vector<int> paintingi ;
vector<int> paintingj ;
vector<int> paintingiz ;
vector<int> paintingjz ;


// global variables //


vector<vector<int>> vector_generating ( int copyrow , int copycolumn);
void path_finding (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length);
void path_generating (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length);
bool check_is_valid (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn);
void print_table(const vector<vector<int>>& table);
void print_table_color (const vector<vector<int>>& table);
void hard_maze(vector<vector<int>> maze , int copyrow , int copycolumn , int length , int max , int min , int maxblock , int minblock);
void maze_generating (vector<vector<int>> copymaze , int max , int min , int maxblock , int minblock , int length);
void simple_maze (vector<vector<int>> maze , int copyrow , int copycolumn);
void setConsoleColor(int color);
void playground (vector<vector<int>> custom_maze);
bool check_is_in (int row , int column );
void main_output ();


int main(){ 



main_output ();


}

void main_output(){
    srand(time(0));
    int row=0 , column=0 , copyrow=0 , copycolumn=0 , sum=0 , length , max , min , maxblock=0 , minblock=0 , num ;
    string x ;

    setConsoleColor (10);
    cout << "      *********Hello and welcom to the game *********" << endl << endl ;
    setConsoleColor(7);

    jump :
    
    cout << " Enter the option to access different parts of the program : " << endl ;
	cout << "1. Create a New Map" << endl ;
    cout << "2. Playground " << endl ;
	cout << "3. Solve a Maze" << endl ;
    cout << "4. History " << endl ;
    cout << "5. Leaderboard" << endl ;
    cout << "6. Exit" << endl ;

    cin >> num ;
    if (num == 1){
        cout << "chose witch map do you want to make :" << endl ;
        cout << "1. easy maze" << endl ;
        cout << "2. hard maze" << endl ;
        cout << "3. go back to menu " << endl ;
        cin >> num ;
        jump1 :
        if (num == 1){
            jump3 :
            cout << "select your row and column " << endl ;
            cout << "row :" ;
            cin >> copyrow ;
            cout<< "column :" ;
            cin >> copycolumn ;
            length = copyrow + copycolumn - 2 ;
        if (length < copyrow + copycolumn - 2 or length%2 != (copyrow + copycolumn)%2 or length > (copyrow*copycolumn)-1 or length + 5 >  (copyrow*copycolumn) ){
                cout << "there are no such maze exsist , please try again " << endl ;
                goto jump3 ;
            }
            vector<vector<int>> maze = vector_generating (copyrow , copycolumn);
            vector<vector<int>> copymaze = maze ;
            simple_maze (maze , copyrow , copycolumn);
        }
        else if (num == 2){
            jump2 :
            cout << "select your row and column " << endl ;
            cout << "row :" ;
            cin >> copyrow ;
            cout<< "column :" ;
            cin >> copycolumn ;
            cout << "select your length " << endl ;
            cout << "length :" ;
            cin >> length ;
            cout << "select your maximum of the maze and minum of the maze " << endl ;
            cout << "max :" ;
            cin >> max ;
            cout<< "min :" ;
            cin >> min ;
            cout << "select your maximum of blocks and minum of blocks" << endl ;
            cout << "max block :" ;
            cin >> maxblock ;
            cout<< "min block :" ;
            cin >> minblock ;         
            vector<vector<int>> maze = vector_generating (copyrow , copycolumn);
            vector<vector<int>> copymaze = maze ;
            if (length < copyrow + copycolumn - 2 or length%2 != (copyrow + copycolumn)%2 or length > (copyrow*copycolumn)-1 or length + maxblock + 1 >  (copyrow*copycolumn) ){
                cout << "there are no such maze exsist , please try again " << endl ;
                goto jump2 ;
            }
            hard_maze (maze , copyrow , copycolumn , length , max , min , maxblock , minblock);
        }
        else if (num == 3){
            goto jump ;
        }
        else {
            cout << "your choise is not valid , please try again " << endl ;
            goto jump1 ;
        }

    }
    else if (num == 2){
        jump4 :
        cout << "choose one of these options " << endl ; 
        cout << "1. Choose from Existing Maps"<< endl ;
        cout << "2. Import a Custom Map" << endl ;
        cout << "3. go back to menu " << endl ;
        cin >> num ;
        if (num == 1){

            // file //

        }
        else if (num == 2){
            int row , column ;
            jump7 :
            cout << "please enter your row and column then enter your numbers of custom maze that you want to put in " << endl ;
            cout << " row :";
            cin >> row ;
            cout << " column :"; 
            cin >> column ;
            vector<vector<int>> custom_maze = vector_generating (row , column);
            cout << "please enter your custom maze numbers " << endl ;
            for (int i=0 ; i<row ; ++i)
                for (int j=0  ; j<column ; ++j)
                    cin >> custom_maze[i][j] ;
            jump8 :
            cout << "if you want to play this map press y" << endl ;
            cout << "if you want to make another one and delete this one press n" << endl ;
            
            cin >> x ;

            if (x== "y" or x == "Y"){
                playground (custom_maze); 
            }
            else if (x == "n" or x == "N"){
                goto jump7 ;
            }
            else {
                cout << "please choose Y or N" << endl ;
                goto jump8 ;
            }


        }
        else if (num == 3){
            goto jump ;
        }
        else {
            cout << "your choise is not valid , please try again " << endl ;
            goto jump4 ; 
        }
    }
    else if(num == 3){
        cout << "choose one of these options " << endl ; 
        cout << "1. Choose from Existing Maps"<< endl ;
        cout << "2. Import a Custom Map" << endl ;
        cout << "3. go back to menu " << endl;
        cin >> num ;
        if (num == 1){

            // file //

        }
        else if (num == 2){
            int row , column ;
            cout << "please enter your row and column and length then enter your numbers of custom maze that you want to put in " << endl ;
            cout << " row :";
            cin >> row ;
            cout << " column :"; 
            cin >> column ;
            cout << " length :" ;
            cin >> length ;
            vector<vector<int>> custom_maze = vector_generating (row , column);
            vector<vector<int>> copycustom_maze = vector_generating (row , column);
            cout << "please enter your custom maze numbers " << endl ;
            for (int i=0 ; i<row ; ++i){ 
                for (int j=0  ; j<column ; ++j){ 
                    cin >> custom_maze[i][j] ;
                    copycustom_maze[i][j] = custom_maze[i][j];
                }
            }

            path_finding (custom_maze , 0 , 0 , row , column , sum , length);

            for (int i=0 ; i<positioni.size() ; ++i){
                paintingi.push_back(positioni[i]);
                paintingj.push_back(positionj[i]);
            }
            for (int i=0 ; i<positioni.size() ; ++i){
                cout << paintingi[i] << " " << paintingj[i] << endl ;
            }

            print_table_color (copycustom_maze);

        }

    }


}

void path_finding (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length){

    //cout << sum << " " ;
    //print_table(maze);
    //cout << endl;
    if (row==copyrow-1 and column == copycolumn-1 and length == 0 and sum == maze[copyrow-1][copycolumn-1] ){
        //cout << "gg" ;
        check = true ;
        positioni.push_back(row);
        positionj.push_back(column);
        return ;
    }
    sum += maze[row][column];
    maze[row][column] = 0;

    if(length >= 0 and length >= (copyrow-row+copycolumn-column-2)  and ((row!=copyrow-1) or (column!=copycolumn-1) )){
    
        if (check_is_valid(maze , row+1 , column , copyrow , copycolumn)){
            path_finding (maze , row+1 , column , copyrow , copycolumn , sum , length-1);
            if (check ){
            positioni.push_back(row);
            positionj.push_back(column);
                return ;
            }
        }

        if (check_is_valid(maze , row , column+1 , copyrow , copycolumn)){
            path_finding (maze , row , column+1 , copyrow , copycolumn , sum , length-1);
            if (check ){
            positioni.push_back(row);
            positionj.push_back(column);               
                return ;
            }
        }

        if (check_is_valid(maze , row-1 , column , copyrow , copycolumn)){
            path_finding (maze , row-1 , column , copyrow , copycolumn , sum , length-1);
            if (check ){
            positioni.push_back(row);
            positionj.push_back(column);              
                return ;
            }            
        }

        if (check_is_valid(maze , row , column-1 , copyrow , copycolumn)){
            path_finding (maze , row , column-1 , copyrow , copycolumn , sum , length-1);
            if (check ){
            positioni.push_back(row);
            positionj.push_back(column);             
                return ;
            }                  
        }
    }

    return ;

}

void path_generating (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length){
    int random = rand()%4 ;
    maze[row][column] = 0;
    //print_table(maze);
    //cout << endl;
    if (row==copyrow-1 and column == copycolumn-1 and length == 0 ){
    //    cout << "gg" ;
        check = true ;
        positioni.push_back(row);
        positionj.push_back(column);
        return ;
    }

    if(length >= 0 and length >= (copyrow-row+copycolumn-column-2) and ((row!=copyrow-1) or (column!=copycolumn-1) )){
        if (random==0){             
            if (check_is_valid(maze , row , column-1 , copyrow , copycolumn)){
                path_generating (maze , row , column-1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);             
                    return ;
                }            
            }
            if (check_is_valid(maze , row+1 , column , copyrow , copycolumn)){
                path_generating (maze , row+1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);
                    return ;
                }
            }
            if (check_is_valid(maze , row , column+1 , copyrow , copycolumn)){
                path_generating (maze , row , column+1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);               
                    return ;
                }
            }
            if (check_is_valid(maze , row-1 , column , copyrow , copycolumn)){
                path_generating (maze , row-1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);              
                    return ;
                }            
            }
        }
        if (random==1){ 
            if (check_is_valid(maze , row-1 , column , copyrow , copycolumn)){
                path_generating (maze , row-1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);              
                    return ;
                }            
            }
            if (check_is_valid(maze , row , column-1 , copyrow , copycolumn)){
                path_generating (maze , row , column-1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);             
                    return ;
                }            
            }
            if (check_is_valid(maze , row+1 , column , copyrow , copycolumn)){
                path_generating (maze , row+1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);
                    return ;
                }
            }
            if (check_is_valid(maze , row , column+1 , copyrow , copycolumn)){
                path_generating (maze , row , column+1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);               
                    return ;
                }
            }
        }
        if (random==2){ 
            if (check_is_valid(maze , row , column+1 , copyrow , copycolumn)){
                path_generating (maze , row , column+1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);               
                    return ;
                }
            }
            if (check_is_valid(maze , row-1 , column , copyrow , copycolumn)){
                path_generating (maze , row-1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);              
                    return ;
                }            
            }
            if (check_is_valid(maze , row , column-1 , copyrow , copycolumn)){
                path_generating (maze , row , column-1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);             
                    return ;
                }            
            }
            if (check_is_valid(maze , row+1 , column , copyrow , copycolumn)){
                path_generating (maze , row+1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);
                    return ;
                }
            }
        }
        if (random==3){ 
            if (check_is_valid(maze , row+1 , column , copyrow , copycolumn)){
                path_generating (maze , row+1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);
                    return ;
                }
            }
    
            if (check_is_valid(maze , row , column+1 , copyrow , copycolumn)){
                path_generating (maze , row , column+1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);               
                    return ;
                }
            }
    
            if (check_is_valid(maze , row-1 , column , copyrow , copycolumn)){
                path_generating (maze , row-1 , column , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);              
                    return ;
                }            
            }
    
            if (check_is_valid(maze , row , column-1 , copyrow , copycolumn)){
                path_generating (maze , row , column-1 , copyrow , copycolumn , sum , length-1);
                if (check ){
                positioni.push_back(row);
                positionj.push_back(column);             
                    return ;
                }            
            }
        }
    }

    return ;

}

bool check_is_valid (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn){
    if (row<copyrow and column<copycolumn and row>=0 and column>=0 && maze[row][column] != 0){ 
        //cout << row << " " << column <<endl ;
        return true ;
    }   
    else {
        return false ;
    } 

}

void print_table_color(const vector<vector<int>>& table) {
    
    int rows = table.size();
    //find how much the space be
    int width = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < table[0].size(); j++) {
            int len = to_string(table[i][j]).length();
            if (len > width) {
                width = len;
            }
        }
    }

    //print the table based on the space we need
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <  table[0].size(); j++) {
        	if (i == 0 && j == 0) {
        		setConsoleColor(9);
        		cout << setw(width) << table[i][j] << " ";
            }
            
            else if (i == rows - 1 and j ==  table[0].size() - 1) {
            	setConsoleColor(9);
            	cout << setw(width) << table[i][j] << " ";
            }
            
            else if(check_is_in(i , j)){
            	setConsoleColor(10);
                 cout<< setw(width)<<table[i][j]<<" ";
            }


            else{
            	setConsoleColor(7);
                cout<< setw(width)<<table[i][j]<<" ";
            }
        }
        cout << endl;
    }
    setConsoleColor(7);

}

vector<vector<int>> vector_generating ( int copyrow , int copycolumn){

    vector<vector<int>> maze(copyrow, vector<int> (copycolumn, 0));
    
    for (int i=0 ; i<maze.size() ; ++i)
        for (int j=0 ; j<maze[0].size() ; ++j)
            maze[i][j] = 1;
    return maze ;

}

void hard_maze(vector<vector<int>> maze , int copyrow , int copycolumn , int length , int max , int min , int maxblock , int minblock ){
    int row = 0 , column = 0 , sum=0;

    vector<vector<int>> copymaze = maze ;
    path_generating (maze , row , column , copyrow , copycolumn , sum , length);
    maze_generating (copymaze , max , min , maxblock , minblock , length); 

}

void maze_generating (vector<vector<int>> copymaze , int max , int min , int maxblock , int minblock , int length){
    int sum=0 , midblock ;
    midblock = (rand()%(maxblock-minblock+1) + minblock) ;
    
    vector<vector<int>> copycopymaze(copymaze.size(), vector<int> (copymaze[0].size(), 1));

    for (int i=0 ; i<positioni.size() ; ++i){
        copycopymaze[positioni[i]][positionj[i]] = 0 ;      
    }

    vector<int> v ;
    for (int i=0 ; i<midblock ; ++i){
        v.push_back(0);
    }
    int num = 0 ;
    for (int i=0 ; i<((copymaze.size())*(copymaze[0].size()) - length - midblock-1) ; ++i){
        num =  rand()%(max-min+1) + min ;
        if (num == 0 and min<=0){ 
            v.push_back(num+1); 
        }
        else if (num == 0 and max>=0){ 
            v.push_back(num-1); 
        }
        else { 
            v.push_back(num);
        }
    }
    random_shuffle(v.begin() , v.end());

    
    for (int i=0 ; i<copycopymaze.size() ; ++i){ 
        for (int j=0 ; j<copycopymaze[0].size() ; ++j){
            //cout << copycopymaze[i][j] << " " ;
            if (copycopymaze[i][j]==1){
                copycopymaze[i][j]= v[v.size()-1] ;
                v.pop_back() ;
            }
        }   
        //cout << endl ;
    }

for (int i=0 ; i<positioni.size() ; ++i){
    num =  rand()%(max-min+1) + min ;
    if (num == 0){
        num ++;
    }
    copycopymaze[positioni[i]][positionj[i]] = num ;
    sum += copycopymaze[positioni[i]][positionj[i]] ;
}
    sum -= copycopymaze[positioni[0]][positionj[0]] ;
    copycopymaze[positioni[0]][positionj[0]] = sum;

    print_table (copycopymaze);
    return ;

}

void simple_maze(vector<vector<int>> maze , int copyrow , int copycolumn){
    int row = 0 , column = 0 , sum=0 , max=3 , min=-3 , maxblock=4 , minblock=2 ;
    int length = copyrow + copycolumn - 2;

    vector<vector<int>> copymaze = maze ;
    path_generating (maze , row , column , copyrow , copycolumn , sum , length);
    maze_generating (copymaze , max , min , maxblock , minblock , length); 

}

void playground (vector<vector<int>> custom_maze){
    string move ;
    int x=0 , y=0 , num =custom_maze[0][0] ;
    vector<vector<int>> copycustom_maze(custom_maze.size(), vector<int> (custom_maze[0].size(), 1));
    for (int i=0 ; i<custom_maze.size() ; ++i)
        for (int j=0 ; j<custom_maze[0].size() ; ++j)
            copycustom_maze[i][j] = custom_maze[i][j] ;
        
    print_table_color (custom_maze);
    copycustom_maze[x][y] = 0;

    jump5 :
    cout << "if you want to go right press D" << endl;
    cout << "if you want to go down press S" << endl ;
    cout << "if you want to go left press A" << endl ;
    cout << "if you want to go up press W" << endl ;
    cout << "if you want to undo press Z" << endl ;
    while (x !=custom_maze.size()-1 or y != custom_maze[0].size()-1){ 
        jump9 :
        cin >> move ;
        if (move == "D" or move == "d"){
            if (check_is_valid (copycustom_maze , x , y+1 , custom_maze.size() , custom_maze[0].size())){ 
                y++;
                copycustom_maze[x][y] = 0;
                num += custom_maze[x][y] ;
                paintingiz.push_back(0);
                paintingjz.push_back(1);
                paintingj.push_back(y);
                paintingi.push_back(x);
            }
            else {
                cout << "your move is not valid , please try again" << endl ;
                goto jump9 ;
            }
        }
        else if (move == "S" or move == "s"){
            if (check_is_valid (copycustom_maze , x+1 , y , custom_maze.size() , custom_maze[0].size())){ 
                x++;
                copycustom_maze[x][y] = 0;
                num += custom_maze[x][y] ;
                paintingiz.push_back(1);
                paintingjz.push_back(0);
                paintingj.push_back(y);
                paintingi.push_back(x);
            }
            else {
                cout << "your move is not valid , please try again" << endl ;
                goto jump9 ;
            }
        }
        else if (move == "A" or move == "a"){
            if (check_is_valid (copycustom_maze , x , y-1 , custom_maze.size() , custom_maze[0].size())){ 
                y--;
                copycustom_maze[x][y] = 0;
                num += custom_maze[x][y] ;
                paintingiz.push_back(0);
                paintingjz.push_back(-1);
                paintingj.push_back(y);
                paintingi.push_back(x);
            }
            else {
                cout << "your move is not valid , please try again" << endl ;
                goto jump9 ;
            }
        }
        else if (move == "W" or move == "w"){
            if (check_is_valid (copycustom_maze , x-1 , y , custom_maze.size() , custom_maze[0].size())){ 
                x--;
                copycustom_maze[x][y] = 0;
                num += custom_maze[x][y] ;
                paintingiz.push_back(-1);
                paintingjz.push_back(0);
                paintingj.push_back(y);
                paintingi.push_back(x);
            }
            else {
                cout << "your move is not valid , please try again" << endl ;
                goto jump9 ;
            }
        }
        else if (move == "Z" or move == "z"){
            num -= custom_maze[x][y] ;
            copycustom_maze[x][y] = custom_maze[x][y] ;
            y -= paintingjz[paintingjz.size()-1] ;
            x -= paintingiz[paintingiz.size()-1] ;
            paintingiz.pop_back();
            paintingjz.pop_back();
            paintingj.pop_back();
            paintingi.pop_back();
        }
        
        else {
            cout << "your move is not valid , please try again" << endl ;
            goto jump5 ;
        }
        cout << num << endl ;
        print_table_color (custom_maze);
    }
    num -= custom_maze[x][y] ;
    if (num == custom_maze[x][y]){
        cout <<" win " << endl ;
    }
    else {
    cout << "lost " << endl ;
    cout << num ;
    }
}

bool check_is_in (int row , int column){
    
    for (int i=0 ; i<paintingi.size() ; ++i){
        if (row == paintingi[i] and column == paintingj[i]){
            return true ;
        }
    }
    return false ;

}

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void print_table(const vector<vector<int>>& table) {
    int rows = table.size();

    //find how much space there is//
    int width = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            int len = to_string(table[i][j]).length();
            if (len > width) {
                width = len;
            }
        }
    }

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << setw(width) << table[i][j] << " ";
        }
        cout << endl;
    }
}

