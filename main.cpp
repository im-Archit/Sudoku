#include<bits/stdc++.h>
#define N 9
using namespace std;


bool isEmpty(int **a,int &row,int &col)
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool check(int **a,int no,int row,int col)
{

    // case1
     for(int i=0;i<9;i++)
     {
         if(a[row][i]==no) return false;
     }
    // case2
     for(int i=0;i<9;i++)
     {
         if(a[i][col]==no) return false;
     }
    //case3  -> in 3x3 grid
    int rowfactor=row-(row%3);// 5 -> 5-2= 3
    int colfactor=col-(col%3);//
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i+rowfactor][j+colfactor]==no) return false;
        }
    }

    return true;

}

bool solve(int **a)
{
  int row,col;
     if(!isEmpty(a,row,col)) return true;
          for(int i=1;i<=9;i++)
          {
              if(check(a,i,row,col)) //check if i is present or not
              {
                a[row][col]=i;
                  if(solve(a))
                      return true; // imp.
                  a[row][col]=0;   // imp.
              }
          }
    return false;
}

int main(){
    int n=9;
    int **a=new int*[n];

    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
        {
         cin>>a[i][j];
        }
    }

   int x= solve(a);
    // cout<<x;
    if(x==1)
        cout<<"true";
    else
        cout<<"false";

    // write your code here
    return 0;
}









