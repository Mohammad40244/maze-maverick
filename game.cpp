#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

vector<int> simplemaze (int row , int column);

int main(){
    vector <int> v;
    srand(time(0));
    int x,y , row=0 , column=0;
    cin>>x>>y;
    int arr[x][y];
    v = simplemaze (x , y);

    cout<<char(218);
    for(int i=1;i<y;i++){
        int a=4;
        while (a--){
            cout<<char(196);
        }
        cout<<char(194);
    }
          
    int a=4;
    while (a--){
        cout<<char(196);
    }
    cout<<char(191);
    cout<<endl;
    for(int i=1;i<=x;i++){
      
         cout<<char(179);
    
        for(int j=1;j<=y;j++){
            int a=4;
            while (a--){
                cout<<" ";
            }
            cout<<char(179);
            a=4;
        }
        
        cout<<endl;
        cout<<char(179);


        for(int j=0;j<y;j++){
            int random_number = rand() % 7 - 3;
            if (random_number == 0){
                random_number++;
            }
            arr[i-1][j] = random_number ;
            if ((i!=x or j!=y-1)){ 
                if (random_number >= 0 ){
                        cout << "  " << arr[i-1][j]<<" "<<char(179);
                } 
                else {
                    cout<<" " << arr[i-1][j] <<" "<<char(179);
                }
            }
        }    
    int kol = 0;
    row = 0;
    column = 0;
    for (int k=0 ; k<v.size() ; ++k){
        kol += arr[row][column];
        if (v[k]==1){
            column++;
        }
        if (v[k]==0){
            row++;
        }
    }
    if (i==x){ 
        if (kol>=0){ 
            cout << "  " << kol << " " << char (179);
        }
        else {
            cout << " " << kol << " " << char (179);            
        }
    }

        
        cout<<endl;
        cout<<char(179);

        for(int i=1;i<=y;i++){
        
            int a=4;
            while (a--){    
                cout<<" ";
            }
            cout<<char(179);
            a=4;
        }
        cout<<endl;
        cout<<char(195);

        for(int i=1;i<=y-1;i++){ 
        cout<<char(196)<<char(196)<<char(196)<<char(196)<<char(197);
        }
        cout<<char(196)<<char(196)<<char(196)<<char(196)<<char(180);    
        cout<<endl;
    }
    //*****************hanoz delete nakon momkene be kar biad*****************
    //int kol = 0;
    //row = 0;
    //column = 0;
    //for (int i=0 ; i<v.size() ; ++i){
    //    kol += arr[row][column];
    //    cout << arr[row][column]<< " ";
    //    if (v[i]==1){
    //        column++;
    //    }
    //    if (v[i]==0){
    //        row++;
    //    }
    //}
    //cout <<endl << kol;



    return 0;
}



vector<int> simplemaze (int row , int column){
    vector <int> v;
    for(int x = 0 ; x < row-1; x++){
        v.push_back(0);
    }
    for(int x = 0 ; x < column-1; x++){
        v.push_back(1);
    }

    random_shuffle(v.begin(),v.end());

    return (v);
}











