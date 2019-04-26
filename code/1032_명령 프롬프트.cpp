#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, cnt;
char cmd[55], temp;

int main()
{
   cin >> N;
   getchar();

   for (int i = 0;; i++)
   {
      temp = cin.get();
      if (temp == '\n')
         break;
      cmd[i] = temp;
      cnt++;
   }


   for (int i = 1; i < N; i++)
   {
      for (int j = 0; j <= cnt; j++)
      {
         temp = cin.get();
         if (temp == '\n')
            break;
         if (cmd[j] != temp)
            cmd[j] = '?';
      }
   }


   cout << cmd << "\n";


   return 0;
}