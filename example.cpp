#include "ribasen.h"

int main() 
{
  char baseN_arr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'}; 
  int baseN_arr_len = sizeof(baseN_arr)/sizeof(baseN_arr[0]);
  len=2;
  max_baseN_width=2;

    //len is length or size of character array 
    //max_BaseN_width is the runcated width of (len) itself 
    //len and max_baseN_width has to be equal for proper use
    //start_range is range of N to start from then automatically incremental (N+1,N+2,..)
  
  string stopped_at="ss";        //last string at where you were intrupted
                                 //if not intrupted use the overloaded function of basen by
                                 //the mode to (began) and passing the ("") value in stopped_at
  
  start_range=stopped_at.size(); //setting range from where you stopped
  mode=began;                    //mode is mode if you generate from normal begining (began) 
                                 //or continue from intrupted one (continued)
  ribasen(stopped_at, baseN_arr, baseN_arr_len, len, start_range, max_baseN_width, mode);
  return 0;
}
