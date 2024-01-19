#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <dirent.h>
#include <Windows.h>

// list of things that you should fix -----> 1. cin of vector_generating  2. why there are random big numbers in output //

using namespace std;




// global variables //

bool check = false ;
vector<int> positionj ;
vector<int> positioni ;
vector<vector<int>> maze;
// global variables //




vector<vector<int>> vector_generating ( int copyrow , int copycolumn);
void path_finding (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length);
void path_generating (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn , int sum , int length);
bool check_is_valid (vector<vector<int>> maze , int row , int column , int copyrow , int copycolumn);
void print_table(const vector<vector<int>>& table);
void hard_maze(vector<vector<int>> maze , int copyrow , int copycolumn , int length);
void maze_generating (vector<vector<int>> copymaze , int max , int min , int maxblock , int minblock , int length);
void simple_maze (vector<vector<int>> maze , int copyrow , int copycolumn , int length);


int main(){ 
    srand(time(0));
    int row=0 , column=0 , copyrow , copycolumn , sum=0 , length , max , min , maxblock , minblock ;

    cin >> copyrow >> copycolumn >> length;

    vector<vector<int>> maze = vector_generating (copyrow , copycolumn);
    vector<vector<int>> copymaze = maze ;

    simple_maze (maze , copyrow , copycolumn , length);

    //for (int i=0 ; i<length ; ++i){
    //    cout << positioni[i] << positionj[i] << " ";
    //}

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

    if(length >= 0 and ((row!=copyrow-1) or (column!=copycolumn-1) )){
    
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
    print_table(maze);
    cout << endl;
    if (row==copyrow-1 and column == copycolumn-1 and length == 0 ){
    //    cout << "gg" ;
        check = true ;
        positioni.push_back(row);
        positionj.push_back(column);
        return ;
    }

    if(length >= 0 and ((row!=copyrow-1) or (column!=copycolumn-1) )){
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

vector<vector<int>> vector_generating ( int copyrow , int copycolumn){

    vector<vector<int>> maze(copyrow, vector<int> (copycolumn, 0));
    
    for (int i=0 ; i<maze.size() ; ++i)
        for (int j=0 ; j<maze[0].size() ; ++j)
            maze[i][j] = 1;




//    for(vector<int> &i : maze){
//        for(int &j : i){
//            int x;
//            cin >> x;
//            j = x;
//        }
//    }
    return maze ;


}

void hard_maze(vector<vector<int>> maze , int copyrow , int copycolumn , int length){
    int row = 0 , column = 0 , sum=0 , max , min , maxblock , minblock;
    cin >> max >> min >> maxblock >> minblock ;

    vector<vector<int>> copymaze = maze ;
    path_generating (maze , row , column , copyrow , copycolumn , sum , length);
    maze_generating (copymaze , max , min , maxblock , minblock , length); 

}
void maze_generating (vector<vector<int>> copymaze , int max , int min , int maxblock , int minblock , int length){
    int sum=0 , midblock ;
    midblock = (rand()%(maxblock-minblock+1) + minblock-1) ;

    vector<int> v ;
    for (int i=0 ; i<midblock ; ++i){
        v.push_back(0);
    }
    for (int i=0 ; i<((copymaze.size())*(copymaze[0].size()) - length - midblock-1) ; ++i){
        v.push_back( rand()%(max-min+1) + min);
    }
    
    random_shuffle(v.begin(),v.end());

    for (int i=0 ; i<v.size() ; ++i){
        cout << v[i] << " " ;
    }
    cout << endl;
    
    for (int i=0 ; i<copymaze.size() ; ++i){ 
        for (int j=0 ; j<copymaze[0].size() ; ++j){
            if (copymaze[i][j]!=0){
                copymaze[i][j]= v[v.size()-1] ;
                v.pop_back() ;
            }
        }   
    }

for (int i=0 ; i<positioni.size() ; ++i){
    copymaze[positioni[i]][positionj[i]] = rand()%(max-min+1) + min ;
    sum += copymaze[positioni[i]][positionj[i]] ;
}
    sum -= copymaze[positioni[0]][positionj[0]] ;
    copymaze[positioni[0]][positionj[0]] = sum;

    print_table (copymaze);


}


void simple_maze(vector<vector<int>> maze , int copyrow , int copycolumn , int length){
    int row = 0 , column = 0 , sum=0 , max=3 , min=-3 , maxblock=4 , minblock=2;

    vector<vector<int>> copymaze = maze ;
    path_generating (maze , row , column , copyrow , copycolumn , sum , length);
    maze_generating (copymaze , max , min , maxblock , minblock , length); 

}






