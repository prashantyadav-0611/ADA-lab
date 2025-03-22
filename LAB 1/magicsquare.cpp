#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<int>> &v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<"  ";
        }
    cout<<endl;
    }
    
}

void magicsquare(vector<vector<int>> &v,int n){
    int row =0;
    int col =n/2;
    for (int num = 1; num <=n*n; num++)
    {
        v[row][col] =num;

        int new_row = (row-1+n)%n;
        int new_col = (col-1+n)%n;

        if(v[new_row][new_col] !=0){
            row=(row+1)%n;
        }
        else{
            row =new_row;
            col =new_col;
        }
    }
    
}
int main(){
    int n;
    cout<<"enter the order of the magic square"<<endl;
    cin>>n;
    vector <vector<int>> vec;
    vec.assign(n,vector<int>(n,0));
    //display(vec);

    magicsquare(vec,n);
    display(vec);
}