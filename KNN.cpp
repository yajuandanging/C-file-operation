//k=4,
#include <iostream>
#include <string>
#include <fstream>


#include  <math.h> 
#include <cstdlib>
using namespace std;
//结构体数组
struct structdis
{
//保存待测花朵到所有样本数据的距离 
double distance ;
//花朵所在的类别 
string classfic ; 
};
//比较K个节点中最多的种类是哪个，并输出 
void compare(int Irissetosaconut,int Irisversicolorcount,int Irisvirginicacount)
{
 int max=0;     //最多种类的数量 
 string maxname="";  // 最多种类的名称 
   if (Irissetosaconut>Irisversicolorcount)
  {
        max=Irissetosaconut;
        maxname="Iris-setosa";
       } 
       else
  {
        max=Irisversicolorcount;
        maxname="Iris-versicolor";
       }
     if(max<Irisvirginicacount)
{
  max=Irisvirginicacount;
        maxname="Iris-virginica ";
  }
 std::cout<<maxname<<endl;
  
}
//结构体进行交换赋值，使用指针 
void Swap(structdis * array1,  structdis * array2)  
{  
    
   structdis tmp;  
    tmp = *array1;  
    *array1 = *array2;  
    *array2= tmp;  
}  
 //堆的建立过程 ,大堆 
void MinHeapify(structdis array[], int heapSize, int currentNode)  
{  
    int  leftChild, rightChild,  minimum;  
    leftChild = 2*currentNode + 1;  
    rightChild = 2*currentNode + 2;  
    if(leftChild < heapSize && array[leftChild].distance > array[currentNode].distance)  
        minimum = leftChild;  
    else  
        minimum = currentNode;  
    if(rightChild < heapSize && array[rightChild].distance > array[minimum].distance)  
        minimum = rightChild;  
    if(minimum != currentNode)  
    {  
        Swap(&array[minimum], &array[currentNode]); 
        MinHeapify(array, heapSize, minimum);  
    }  
}  
/*构建大根堆*/  
void MinHeapCreat(structdis  array[], int heapSize)  
{  
    int i;  
    for(i = heapSize/2; i >= 0; i--)  
    {  
        MinHeapify(array, heapSize, i);  
    }  
}
//堆的调整的过程
void Adjust(structdis array[],int top, int j)//从j=K+1个节点开始调整进入堆 
 
 {
 while(array[top].distance>array[j].distance)// 当待排的数据比大根堆的根的距离值大，就替换掉 
 {
 
 Swap(&array[top],&array[j]);
 MinHeapify(array, 4,  top);
 ++j;
 } 
 
 }  
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
structdis Dis[Datalen],temp[4];
int maxcount;


for(int j=0;j<len;j++)


{
  for (int i=0;i<Datalen;i++)
  {
  double a,b,c,d;
 a=atof(s[i][0].c_str())-atof(s1[j][0].c_str());
 b=atof(s[i][1].c_str())-atof(s1[j][1].c_str());
 c=atof(s[i][2].c_str())-atof(s1[j][2].c_str());
 d=atof(s[i][3].c_str())-atof(s1[j][3].c_str());
 Dis[i].distance=sqrt(a*a+b*b+c*c+d*d);
 Dis[i].classfic=s[i][4];
 //cout<<Dis[i].distance<< Dis[i].classfic<<endl;
  }
  //根据距离构造堆 
   MinHeapCreat(Dis,4);                   // 默认k的值为4，先对4个数据进行测试，建堆， 
   Adjust(Dis,0,5)  ;  
   int Irissetosaconut=0,Irisversicolorcount=0,Irisvirginicacount=0; //种类的数量                   
   // 利用剩余的数据与这四个数据进行比较，选出最小的四个 
   for(int i=0;i<4;i++)
  {
     //cout<<Dis[i].distance;
//cout<< Dis[i].classfic<<endl;
     if( Dis[i].classfic=="Iris-setosa") Irissetosaconut++;
      else  if( Dis[i].classfic=="Iris-versicolor")Irisversicolorcount++;  
     else  Irisvirginicacount++;
     }
     cout<< Irissetosaconut<<Irisversicolorcount<< Irisvirginicacount<<endl;
    compare(Irissetosaconut,Irisversicolorcount, Irisvirginicacount);
}
 return 0;


}

所使用的编译软件是c-free 5 CJY版 ，编译所使用的数据
