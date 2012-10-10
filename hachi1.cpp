#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
int find(vector<string> v,string s){
for(int i=0;i<v.size();i++) {if(v[i]==s) return i; }
return -1;
}
 
int main(void)
{
int p,r,i,j,k,index1,index2;
cin>>p>>r;
string s1,s2;
vector<string> str;
int arr[p][p];
for(i=0;i<p;i++) for(j=0;j<p;j++) arr[i][j]=0;
for(i=0;i<r;i++)
{cin>>s1>>s2;
index1= find(str,s1);
index2= find(str,s2);
if(index1==-1) {str.push_back(s1);index1=str.size()-1;}
if(index2==-1) {str.push_back(s2);index2=str.size()-1;}
arr[index1][index2]=1;arr[index2][index1]=1;
arr[index1][index1]=1;arr[index2][index2]=1;
}
int sz=str.size();//cout<<"sz="<<sz<<endl;;
for(k=0;k<sz;k++)
for(i=0;i<sz;i++)
for(j=0;j<sz;j++)
if(arr[i][k]!=0 && arr[k][j]!=0) {if(arr[i][j]!=0) arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);else arr[i][j]=arr[i][k]+arr[k][j]; }
//for(i=0;i<p;i++) {for(j=0;j<p;j++) cout<<arr[i][j];cout<<endl;}
//cout<<arr[0][3]<<"hi";
int flag=1,f=1,maxm=0;
for(i=0;i<sz;i++)
{
for(j=0;j<sz;j++) {if(arr[i][j]==0) f=0;maxm=max(maxm,arr[i][j]); }
if(!f) {flag=0;break;}
}
if(flag) cout<<maxm;
else cout<<"DISCONNECTED";
// system("pause");
}
/*
 
*/
