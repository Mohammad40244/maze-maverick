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
#include <unistd.h>

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

int incrementNumberInFile(string fileName, bool incrementSecondLine);
bool createFile(string name) ;
void deleteFirstLineIfMoreThanTenLines();
void appendToFile(string input, bool result , int num , string date , string mapname);
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
bool check_is_number (string variable );


int main(){ 
    int row=0 , column=0 , copyrow=0 , copycolumn=0 , sum=0 , length=0 , max=0 , min=0 , maxblock=0 , minblock=0 , num=0 ;
    vector<vector<int>> maze = vector_generating (30 , 30);

    main_output ();

}

void main_output(){
    srand(time(0));
    int row=0 , column=0 , copyrow=0 , copycolumn=0 , sum=0 , length=0 , max=0 , min=0 , maxblock=0 , minblock=0 , num=0 ;
    char x ;
    string variable ;

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
    system("cls");

    if(x == '1'){
        jump1 :
        cout << "choose witch map do you want to make :" << endl ;
        setConsoleColor(11);
        cout << "1. easy maze" << endl ;
        setConsoleColor(4);    
        cout << "2. hard maze" << endl ;
        setConsoleColor(14);
        cout << "3. go back to menu " << endl ;
        setConsoleColor (7);
        x=_getch();
        if (x == '1'){
            jump3 :
            cout << "select your row and column " << endl ;
            cout << "row :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                copyrow = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump3 ;
            }

            cout<< "column :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                copycolumn = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump3 ;
            }


            length = copyrow + copycolumn - 2 ;
            if (length < copyrow + copycolumn - 2 or length%2 != (copyrow + copycolumn)%2 or length > (copyrow*copycolumn)-1 or length + 5 >  (copyrow*copycolumn) ){
                cout << "there are no such maze exsist , please try again " << endl ;
                goto jump3 ;
            }
            vector<vector<int>> maze = vector_generating (copyrow , copycolumn);
            vector<vector<int>> copymaze = vector_generating (copyrow , copycolumn);
            simple_maze (maze , copyrow , copycolumn);
            maze.clear();
            maze.shrink_to_fit();
            copymaze.clear();
            copymaze.shrink_to_fit();

            //Sleep(2000);
            jump11 :
            cout << "if you want to continue choose yes if you want to quit choose no " << endl ;
            setConsoleColor(2);
            cout << " 1.yes" << endl ;
            setConsoleColor(4);            
            cout << " 2.no" << endl ;
            setConsoleColor(7); 
            x=_getch();
            if (x == '1'){
            goto jump ;
            }
            if (x == '2'){
                cout << "GOOD GAME " << endl ;
                return ;
            }
            else {
                cout << "please choose 1 or 2 " << endl ;
                goto jump11 ;
            }
        }

        else if (x == '2'){
            jump2 :
            cout << "select your row and column " << endl ;
            cout << "row :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                copyrow = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }
 
            cout<< "column :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                copycolumn = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }

            cout << "select your length " << endl ;
            cout << "length :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                length = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }

            cout << "select your maximum of the maze and minum of the maze " << endl ;

            cout << "max :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                max = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }
            cout<< "min :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                min = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }


            cout << "select your maximum of blocks and minum of blocks" << endl ;
            cout << "max block :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                maxblock = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }
            cout<< "min block :" ;
            getline(cin , variable); 
            if (check_is_number(variable)){
                minblock = stoi(variable);
            }
            else {
                cout << "please enter a number !!" << endl ;
                goto jump2 ;
            }
            if (minblock < 0 or maxblock < 0){
                cout << " you can not have negetive number of block please choose a positive number " << endl;
                goto jump2 ;
            }

            if (minblock > maxblock){
                swap (minblock , maxblock);
            }
            if (min > max){
                swap (min , max);
            }
        
            vector<vector<int>> maze = vector_generating (copyrow , copycolumn);
            vector<vector<int>> copymaze = vector_generating (copyrow , copycolumn);
            if (length < copyrow + copycolumn - 2 or length%2 != (copyrow + copycolumn)%2 or length > (copyrow*copycolumn)-1 or length + maxblock + 1 >  (copyrow*copycolumn) ){
                cout << "there are no such maze exsist , please try again " << endl ;
                goto jump2 ;
            }
            hard_maze (maze , copyrow , copycolumn , length , max , min , maxblock , minblock);
            maze.clear();
            maze.shrink_to_fit();
            copymaze.clear();
            copymaze.shrink_to_fit();
            jump10 :
            cout << "if you want to continue choose yes if you want to quit choose no " << endl ;
            setConsoleColor(2);
            cout << " 1.yes" << endl ;
            setConsoleColor(4);            
            cout << " 2.no" << endl ;
            setConsoleColor(7); 
            x=_getch();
            if (x == '1'){
            goto jump ;
            }
            if (x == '2'){
                setConsoleColor(2);
                cout << "GOOD GAME " << endl ;
                setConsoleColor(7);
                return ;
            }
            else {
                cout << "please choose 1 or 2 " << endl ;
                goto jump10 ;
            }

        }
        else if (x == '3'){
            goto jump ;
        }
        else {
            cout << "your choise is not valid , please choose 1 or 2 or 3 " << endl ;
            goto jump1 ;
        }

    }
    else if (x == '2'){
        jump4 :
        cout << "choose one of these options " << endl ; 
        setConsoleColor(11);
        cout << "1. Choose from Existing Maps"<< endl ;
        setConsoleColor(4);
        cout << "2. Import a Custom Map" << endl ;
        setConsoleColor(14);
        cout << "3. go back to menu " << endl;
        setConsoleColor(7);
        x=_getch();
        if (x == '1'){

            

        }
        else if (x == '2'){
            int row , column , linee = 0 , soton=0 ;
            string name = "" , address = "" , liner = "" ;
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
            if (maze1[maze1.size()-1][maze1[0].size()-1]!=0 ){ 
                playground(maze1);
                v.clear();
                v.shrink_to_fit();
                check = false ;
                positionj.clear() ;
                positionj.shrink_to_fit() ;
                positioni.clear() ;
                positioni.shrink_to_fit() ;
                copycopymaze.clear() ;
                copycopymaze.shrink_to_fit();
                paintingi.clear() ;
                paintingi.shrink_to_fit();
                paintingj.clear() ;
                paintingj.shrink_to_fit();
                paintingiz.clear() ;
                paintingiz.shrink_to_fit();
                paintingjz.clear() ;
                paintingjz.shrink_to_fit();
                jump12 :
                cout << "if you want to continue choose yes if you want to quit choose no " << endl ;
                setConsoleColor(2);
                cout << " 1.yes" << endl ;
                setConsoleColor(4);            
                cout << " 2.no" << endl ;
                setConsoleColor(7); 
                x=_getch();
                if (x == '1'){
                goto jump ;
                }
                if (x == '2'){
                    setConsoleColor(2);
                    cout << "GOOD GAME " << endl ;
                    setConsoleColor(7);
                    return ;
                }
                else {
                    cout << "please choose 1 or 2 " << endl ;
                    goto jump12 ;
                }

    
            }
            else {
                cout << "this is not possible please try again " << endl ;
            }
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
        setConsoleColor(11);
        cout << "1. Choose from Existing Maps"<< endl ;
        setConsoleColor(4);
        cout << "2. Import a Custom Map" << endl ;
        setConsoleColor(14);
        cout << "3. go back to menu " << endl;
        setConsoleColor(7);
        x=_getch();
        if (x == '1'){

            // file //

        }
        else if (x == '2'){

            int row=0 , column =0 , linee = 0 , soton = 0 , length =0  ;
            string name , address = "" , liner = "" ;
            vector<int> v;
            jump14:
            // how to get a file and put it in the maze //
            cout << "please enter your custom map adress :" << endl;
            cin >> address ;
            // remember to delete "maps/" and ".txt" //
            address = "maps/" + address + ".txt" ;
            ifstream map(address);
            if (map.fail()){
                cout << " there is no such file found please try again " << endl ;
                goto jump14;
            }
            while (getline (map , liner)){
                linee++;
            }
            map.close() ;
            ifstream map2(address);
            while (map2>>soton){
                v.push_back(soton);
            }
            soton = v.size() / linee ;  

            jump6 :
            cout << "please enter your length :" << endl ;
            cin >> length ;
            if ((length> soton*linee) or (length < soton + linee -2)){
                cout << "please enter another length , there is no such path exsist " << endl ;
                goto jump6 ;
            }
            vector<vector<int>> custom_maze = vector_generating (linee , soton);
            vector<vector<int>> copycustom_maze = vector_generating (linee , soton);
            //int ** maze = new int* [linee];
            //for (int i=0 ; i<soton ; ++i){
            //    maze[i] = new int [soton];
            //}    
            //for (int i=0 ; i<linee ; ++i)
            //    for (int j=0 ; j<soton ; ++j)
            //        custom_maze[i][j] = v[i*soton+ j];

            for (int i=0 ; i<linee ; ++i){ 
                for (int j=0 ; j<soton ; ++j){ 
                    custom_maze[i][j] = v[i*soton+ j];
                    copycustom_maze[i][j] = v[i*soton+ j];
                }
            }
            
            if (copycustom_maze[copycustom_maze.size()-1][copycustom_maze[0].size()-1]!=0 ){ 
                path_finding (custom_maze , 0 , 0 , linee , soton , sum , length);

                for (int i=0 ; i<positioni.size() ; ++i){
                    paintingi.push_back(positioni[i]);
                    paintingj.push_back(positionj[i]);
                }

                //auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                //string timeString = std::ctime(&currentTime);
                //ofstream fout(address);
                //cout << timeString << endl ;
                print_table_color (copycustom_maze);
                sum = 0;
                v.clear();
                v.shrink_to_fit();
                copycustom_maze.clear();
                copycustom_maze.shrink_to_fit();
                custom_maze.clear();
                custom_maze.shrink_to_fit();
                check = false ;
                positionj.clear() ;
                positionj.shrink_to_fit() ;
                positioni.clear() ;
                positioni.shrink_to_fit() ;
                copycopymaze.clear() ;
                copycopymaze.shrink_to_fit();
                paintingi.clear() ;
                paintingi.shrink_to_fit();
                paintingj.clear() ;
                paintingj.shrink_to_fit();
                paintingiz.clear() ;
                paintingiz.shrink_to_fit();
                paintingjz.clear() ;
                paintingjz.shrink_to_fit();
                jump13 :
                cout << "if you want to continue choose yes if you want to quit choose no " << endl ;
                setConsoleColor(2);
                cout << " 1.yes" << endl ;
                setConsoleColor(4);            
                cout << " 2.no" << endl ;
                setConsoleColor(7); 
                x=_getch();
                if (x == '1'){
                goto jump ;
                }
                if (x == '2'){
                    setConsoleColor(2);
                    cout << "GOOD GAME " << endl ;
                    setConsoleColor(7);
                    return ;
                }
                else {
                    cout << "please choose 1 or 2 " << endl ;
                    goto jump13 ;
                }




            }
            else {
                cout << "this not possible please try again " << endl ;
            }

        }
    
    }
    else {
    system("cls");        
    cout << "your number is not valid please choose a number beetwen 1 to 6 " << endl ;
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
    //cout << "gg" ;
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
    return ;
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
    v.clear();
    v.shrink_to_fit();
    copymaze.clear();
    copymaze.shrink_to_fit();
    return ;

}

void simple_maze(vector<vector<int>> maze , int copyrow , int copycolumn){
    int row = 0 , column = 0 , sum=0 , max=3 , min=-3 , maxblock=5 , minblock=2 , length=0 ;
    length = copyrow + copycolumn - 2;

    vector<vector<int>> copymaze = maze ;
    path_generating (maze , row , column , copyrow , copycolumn , sum , length);
    maze_generating (copymaze , max , min , maxblock , minblock , length); 
    return ;
}

void playground (vector<vector<int>> custom_maze){
    string move , username , mapsname;
    int x=0 , y=0 , num =custom_maze[0][0] ;
    vector<vector<int>> copycustom_maze(custom_maze.size(), vector<int> (custom_maze[0].size(), 1));
    for (int i=0 ; i<custom_maze.size() ; ++i)
        for (int j=0 ; j<custom_maze[0].size() ; ++j)
            copycustom_maze[i][j] = custom_maze[i][j] ;
        

    cout << "please enter your username " << endl ;
    cin >> username ;
    cout << "please enter your maps name " << endl ;
    cin >> mapsname ;

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
        //cout<< "sum :" << num << endl ;
        print_table_color (custom_maze);
    }
    num -= custom_maze[x][y] ;
    int timesecond = time(0) ;

    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    string timeString = std::ctime(&currentTime);

    //cout << timeString << endl ;


    if (num == custom_maze[x][y]){
        appendToFile (username , true , timesecond - timebase , timeString , mapsname );
        deleteFirstLineIfMoreThanTenLines();
        createFile (username);
        incrementNumberInFile( username, true);
        //cout <<" win " << endl ; 
        cout << timesecond - timebase << endl ;
    }
    else {
        appendToFile (username , false , timesecond - timebase , timeString , mapsname);    
        deleteFirstLineIfMoreThanTenLines();
        createFile (username);
        incrementNumberInFile( username, false);
        //cout << "lost " << endl ;
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
    positionj.clear() ;
    positioni.clear() ;
    positioni.shrink_to_fit();
    positionj.shrink_to_fit();
    copycopymaze.clear() ;
    copycopymaze.shrink_to_fit();
    check = false ;
    return ;


}

bool check_is_number (string variable){
    for (int i=0 ; i<variable.size() ; ++i){
        if (variable[i] != '-' and variable[i] != '0' and variable[i] != '1' and variable[i] != '2' and variable[i] != '3' and variable[i] != '4' and variable[i] != '5' and variable[i] != '6' and variable[i] != '7' and variable[i] != '8' and variable[i] != '9'){
            return false ;
        }    
    }
    return true ;
}

void appendToFile(string input, bool result , int num , string date , string mapname) {
    // Open the file in append mode
    ofstream outputFile("output.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    // Write the result (won or lose) and the input to the file
    outputFile<< input<< " " << mapname  << " "  << (result ? "win" : "lose") << " " << num << "seconds " << date ;

    // Close the file
    outputFile.close();


    //cout << "Text appended to file." << endl;
}

void deleteFirstLineIfMoreThanTenLines() {
    int maxLines = 10;
    const string filename = "output.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    // Count the number of lines in the file
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);

    }

    inputFile.close();

    // Check if the file has more than 10 lines
    if (lines.size() > maxLines) {
        // Open the file in truncate mode to delete the first line
        ofstream outputFile(filename, ios::trunc);

        if (!outputFile.is_open()) {
            cerr << "Error opening the file for truncation!" << endl;
            return;
        }

        // Write lines 2 to n to the file
        for (size_t i = 1; i < lines.size(); ++i) {
            outputFile << lines[i] << endl;
        }

        outputFile.close();

    }
}

bool createFile(string name) {
    std::string filename = name + ".txt";

    std::ifstream fileCheck(filename.c_str());
    if (!fileCheck.good()) {
        std::ofstream file(filename.c_str());
      //  std::cout << "File '" << filename << "' created successfully." << std::endl;
        return true;  // File created successfully
    } else {
       // std::cout << "File '" << filename << "' already exists. Choose a different name." << std::endl;
        return false;  // File already exists
    }
}

int incrementNumberInFile(string fileName, bool incrementSecondLine) {
    std::ifstream inFile(fileName.c_str());  // Open the file for reading

    int number1 = 0, number2 = 0;
    
    if (inFile.is_open()) {
        // If the file exists, read the current numbers
        inFile >> number1;
        inFile >> number2;
        inFile.close();
    }
    //else {
    //    std::cerr << "Error opening file for reading!" << std::endl;
    //    return 1;  // Return an error code
    //}

    // Increment the first number
    number1++;

    // Increment the second number if the boolean is true
    if (incrementSecondLine) {
        number2++;
    }

    std::ofstream outFile(fileName.c_str());  // Open the file for writing

    if (outFile.is_open()) {
        // Write the updated numbers to the file
        outFile << number1 << std::endl;
        outFile << number2 << std::endl;
        outFile.close();
        //std::cout << "Numbers written to file: " << number1 << " and " << number2 << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;  // Return an error code
    }

    return 0;
}