#include<iostream>
#include<vector>
using namespace std;
int maximum(vector<vector<int>> &v,int mid){
    int index=0;
    int max=v[0][mid];
for (int i = 0; i < v.size(); i++)
{
    if(v[i][mid]>max){
        max = v[i][mid];
        index =i;
    }
}
return index;
};

int findpeak(vector<vector<int>> &v,int low,int high){
    
int mid = (low+high)/2;
int n = maximum(v,mid);

if(v[n][mid]<v[n][mid-1] && mid>low)
    return findpeak(v,low,mid-1);

if(v[n][mid]<v[n][mid+1] && mid<high)
    return findpeak(v,mid+1,high);

else cout<<"index of peak element is "<<n<<","<<mid;
return v[n][mid];

}
int main(){
    int rows, columns;
    cout<<"enter number of rows"<<endl;
    cin>>rows;
    cout<<"enter number of columns"<<endl;
    cin>>columns;
    vector <vector<int>> vec(rows,vector<int>(columns));

    for (int i = 0; i < rows; i++)
    {
        cout<<"enter elements of "<<i+1<<"th row"<<endl;
        for (int j = 0; j < columns; j++)
        {
            cin>>vec[i][j];
        }  
    }
    cout<<endl;
for (int i = 0; i < rows; i++)
    {
        
        for (int j = 0; j < columns; j++)
        {
            cout<<vec[i][j]<<" ";
        }  
        cout<<endl;
    }
    int postion = findpeak(vec,0,columns-1);

}