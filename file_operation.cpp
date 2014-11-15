#include <iostream>
#include<istream>
#include <string>
#include <fstream>
#include <sstream>
#include  <math.h> 
#include <cstdlib>
using namespace std;
int main (void )
{
 int i,Datalen=-1,len=-1;  // i 为循环变量，Datalen 为数组长度
 string Data[1000],Data1[1000];// 存储数据


//读取样本数据 
ifstream fin("d:\\1.txt");
if( ! fin )
 {
  cerr<<"Can not open  file."<<endl;
  getchar();
  return 1;
 }
 while (!fin.eof())
 {
  ++Datalen;
   fin>>Data[Datalen];
 }


string s [Datalen][5];
for(int i=0;i<Datalen;i++)
for (int j=0;j<5;j++)
{
int pos=Data[i].find(',');
s[i][j]=Data[i].substr(0,pos);
    Data[i]=Data[i].substr(pos+1,Data[i].length());
    
   //cout<<s[i][j]<<endl;
}
//读取待测数据
ifstream fin1("d:\\0.txt");
if( ! fin1 )
 {
  cerr<<"Can not open  file."<<endl;
  getchar();
  return 1;
 }
 len=-1;
 while (!fin1.eof())
 {
  ++len;
   fin1>>Data[len];
   
   
 }
 
string s1 [len][4];
for(int i=0;i<len;i++)
for (int j=0;j<4;j++)
{
int pos=Data[i].find(',');
s1[i][j]=Data[i].substr(0,pos);
    Data[i]=Data[i].substr(pos+1,Data[i].length());
    //cout<<s1[i][j]<<endl;
}
//计算距离 
double Dis[Datalen],temp[4];
 
for(int j=0;j<len;j++)
 for (int i=0;i<Datalen;i++)
  {
  double a,b,c,d;
 a=atof(s[i][0].c_str())-atof(s1[j][0].c_str());
 b=atof(s[i][1].c_str())-atof(s1[j][1].c_str());
 c=atof(s[i][2].c_str())-atof(s1[j][2].c_str());
 d=atof(s[i][3].c_str())-atof(s1[j][3].c_str());
 Dis[i]=sqrt(a*a+b*b+c*c+d*d);
 cout<<Dis[i]<<endl;
 
  }


 return 0;


}