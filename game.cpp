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
#include <conio.h>
#include <chrono>

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
    //system("cls");
    srand(time(0));
    int row=0 , column=0 , copyrow=0 , copycolumn=0 , sum=0 , length , max , min , maxblock=0 , minblock=0 , num ;
    char x ;

    setConsoleColor (10);
    cout << "      *********Hello and welcom to the game *********" << endl << endl ;

    jump :
    setConsoleColor(15);    
    cout << " Enter the option to access different parts of the program : " << endl ;
    setConsoleColor(2);
	cout << "1. Create a New Map" << endl ;
    setConsoleColor(1);
    cout << "2. Playground " << endl ;
    setConsoleColor(4);
	cout << "3. Solve a Maze" << endl ;
    setConsoleColor(14);
    cout << "4. History " << endl ;
    setConsoleColor(13);
    cout << "5. Leaderboard" << endl ;
    setConsoleColor(11);
    cout << "6. Exit" << endl ;
    setConsoleColor(7);


    x=_getch();
    if(x == '1'){
        cout << "chose witch map do you want to make :" << endl ;
        cout << "1. easy maze" << endl ;
        cout << "2. hard maze" << endl ;
        cout << "3. go back to menu " << endl ;
        jump1 :
        x=_getch();
        if (x == '1'){
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
        else if (x == '2'){
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
        else if (x == '3'){
            goto jump ;
        }
        else {
            cout << "your choise is not valid , please chose 1 or 2 or 3 " << endl ;
            goto jump1 ;
        }

    }
    else if (x == '2'){
        jump4 :
        cout << "choose one of these options " << endl ; 
        cout << "1. Choose from Existing Maps"<< endl ;
        cout << "2. Import a Custom Map" << endl ;
        cout << "3. go back to menu " << endl ;
        x=_getch();
        if (x == '1'){

            

        }
        else if (x == '2'){
            int row , column , linee = 0 , soton ;
            string name , address , address2 , liner ;
            vector<int> v;

            // how to get a file and put it in the maze //
            cout << "please enter your custom map adress " << endl;
            cin >> address ;

            address = "maps/" + address + ".txt";
            ifstream map(address);
            while (getline (map , liner)){
                linee++;
            }
            map.close() ;
            ifstream map2(address);
            while (map2>>soton){
                v.push_back(soton);
            }
            soton = v.size() / linee ;  

            vector<vector<int>> maze1 = vector_generating (linee , soton);

            int ** maze = new int* [linee];
            for (int i=0 ; i<soton ; ++i){
                maze[i] = new int [soton];
            }    
            for (int i=0 ; i<linee ; ++i)
                for (int j=0 ; j<soton ; ++j)
                    maze[i][j] = v[i*soton+ j];

            for (int i=0 ; i<linee ; ++i){ 
                for (int j=0 ; j<soton ; ++j){ 
                    maze1[i][j] = maze[i][j] ;
                }
            }
            playground(maze1);
        //auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        //string timeString = std::ctime(&currentTime);
        //ofstream fout(address);
        //cout << timeString << endl ;
        }
        else if (x == '3'){
            goto jump ;
        }
        else {
            cout << "your choise is not valid , please try again " << endl ;
            goto jump4 ; 
        }
    }
    else if(x == '3'){
        cout << "choose one of these options " << endl ; 
        cout << "1. Choose from Existing Maps"<< endl ;
        cout << "2. Import a Custom Map" << endl ;
        cout << "3. go back to menu " << endl;
        x=_getch();
        if (x == '1'){

            // file //

        }
        else if (x == '2'){

            int row , column , linee = 0 , soton ;
            string name , address , liner ;
            vector<int> v;

            // how to get a file and put it in the maze //
            cout << "please enter your custom map adress :" << endl;
            cin >> address ;
            cout << "please enter your length :" << endl ;
            cin >> length ;
            // remember to delete "maps/" and ".txt" //
            address = "maps/" + address + ".txt" ;
            ifstream map(address);
            while (getline (map , liner)){
                linee++;
            }
            map.close() ;
            ifstream map2(address);
            while (map2>>soton){
                v.push_back(soton);
            }
            soton = v.size() / linee ;  

            vector<vector<int>> custom_maze = vector_generating (linee , soton);
            vector<vector<int>> copycustom_maze = vector_generating (linee , soton);
            int ** maze = new int* [linee];
            for (int i=0 ; i<soton ; ++i){
                maze[i] = new int [soton];
            }    
            for (int i=0 ; i<linee ; ++i)
                for (int j=0 ; j<soton ; ++j)
                    maze[i][j] = v[i*soton+ j];

            for (int i=0 ; i<linee ; ++i){ 
                for (int j=0 ; j<soton ; ++j){ 
                    custom_maze[i][j] = maze[i][j] ;
                    copycustom_maze[i][j] = maze[i][j] ;
                }
            }
            path_finding (custom_maze , 0 , 0 , linee , soton , sum , length);

            for (int i=0 ; i<positioni.size() ; ++i){
                paintingi.push_back(positioni[i]);
                paintingj.push_back(positionj[i]);
            }
            for (int i=0 ; i<positioni.size() ; ++i){
                cout << paintingi[i] << " " << paintingj[i] << endl ;
            }

            auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            string timeString = std::ctime(&currentTime);
            //ofstream fout(address);
            cout << timeString << endl ;
            print_table_color (copycustom_maze);

        }

    }
    else {
    cout << "your number is not valid please chose a number beetwen 1 to 6 " << endl ;
    goto jump ; 
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
    //  cout << "gg" ;
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
    //system("cls");
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
    if (maxblock < minblock ){
        swap (maxblock , minblock ) ;
    }
    if (max < min ){
        swap (max , min) ;
    }

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



    if ((copymaze.size())*(copymaze[0].size()) - length - midblock-1 < 0){
        cout << "it is impossible to generate this maze , please try again " << endl ;
        return ;
    }

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
    int timebase = time(0) ;
    //cout << timebase << endl ;
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
            if (paintingiz.size()==0){
                cout << "your move is not valid , please try again" << endl ;
                goto jump9 ;  
            }
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
    int timesecond = time(0) ;
    if (num == custom_maze[x][y]){
        cout <<" win " << endl ; 
        cout << timesecond - timebase << endl ;
    }
    else {
    cout << "lost " << endl ;
    cout << timesecond - timebase << endl ;
    //cout << num ;
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

