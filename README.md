# ribasen
A base N recursive incremental data generator implemented in C++

An implementation of functional programming

**ribasen function (void)**

`ribasen(stopped_at, baseN_arr, baseN_arr_len, len, start_range, max_baseN_width, mode);`

**stopped_at** is the combination of char data declared as string type for stopped_at

**baseN_arr** is the array of char data

**baseN_arr_len** is int type of calculated elements of the array

`int baseN_arr_len = sizeof(baseN_arr)/sizeof(baseN_arr[0]);`

**len** is length or size of character array

**start_range** is range of N to start from then automatically incremental (N+1,N+2,..)

`start_range=stopped_at.size();`

**max_baseN_width** is the runcated width of (len) itself

**mode** to be either began or continued
