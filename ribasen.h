#include "stdlib.h"
#include <iostream>
#include <fstream>
using namespace std;

char result[]={};
int len,max_baseN_width,start_range,x=0,y=0;
enum states {began,continued};
states mode;
ofstream file;

//max_baseN_width play role in incrementing the (len)
//len is length of each array of characters printed or generated

//basen is core function which do the recursive approach for generating the data as baseN

void basen(char baseN_arr[], int baseN_arr_len, int len, int max_baseN_width) 
{ 
  if(len == 0)
  {  
  file.open("example.txt", std::ios_base::app);
  file<<result<<endl;
  file.close();
  return;
  }

  for(int index=0; index < baseN_arr_len; index++)
  {
  result[max_baseN_width-len]=baseN_arr[index];         
  basen(baseN_arr, baseN_arr_len, len-1, max_baseN_width);
  }
}

void basen(string stopped, char baseN_arr[], int baseN_arr_len, int len, int max_baseN_width, states mode) 
{ 
  int start[]={};
  if(mode==1)
  {
    for ( int j = 0; j < stopped.size(); j++)
    {
      for ( int i = 0; i < baseN_arr_len; i++)
      {
      
        if(stopped[j]==baseN_arr[i])
        { 
          start[j]=i;
            
        }
      }
    }
  }
    
  if(len == 0)
  {
  file.open("example.txt", std::ios_base::app); //opening and appending to the file
  file<<result<<endl;                           //appending data to the file
  file.close();
  return;
  }

if(mode==continued)
 {
  for(int index=start[x]; index < baseN_arr_len; index++)
  {
  result[max_baseN_width-len]=baseN_arr[index];

    if(x<stopped.size())
    { 
      x++;
      start[x];
    }
    else
    {
      mode=began;
    }  
  basen(stopped, baseN_arr, baseN_arr_len, len-1, max_baseN_width, mode);
  }
 }
else if(mode==began)
 {
  for(int index=0; index < baseN_arr_len; index++)
  {
  result[max_baseN_width-len]=baseN_arr[index];
  basen(stopped, baseN_arr, baseN_arr_len, len-1, max_baseN_width, mode);
  }
}
}

//ribasen is core function doing the incrementing feature
  
void ribasen(string stopped,char baseN_arr[], int baseN_arr_len , int len, int start_range, int max_baseN_width, states mode)
{
  if(mode==continued)
  {
  for(int crnt_len=start_range;crnt_len<len+1;crnt_len++)
   {
   basen(stopped, baseN_arr, baseN_arr_len, crnt_len, crnt_len, mode);
   mode=began;
   }
  }
  else if(mode==began)
  {
  for(int crnt_len=start_range;crnt_len<len+1;crnt_len++)
   {
   basen(baseN_arr, baseN_arr_len, crnt_len, crnt_len);
   }
  }

}

