#include <stdio.h>
#include <stdbool.h> 
#include <ctype.h>

const int MAX_TEXT_LEN = 50;

int main()
{
  char text[MAX_TEXT_LEN+1],ch;
  scanf("%s", text);
      // printf("%s\n", text);
  char scanned[MAX_TEXT_LEN+1];
  int n = 0;
  for(int h = 0; text[h] != '\0'; h++)
  {
      char search = tolower(text[h]);
      text[h] = search;

      bool inside = false;
      for (int j = 0; j<n; ++j)
      {
          inside = inside || (search == scanned[j]);
      }
      
      if(!inside)
      {
          scanned[n] = search;n++;
          
          int count = 0;
          for (int i = 0; text[i] != '\0'; ++i) 
          {
              if (search ==text[i]) ++count;
          }
          printf("%c  %d\n", search, count);          
          
      }
  }
  return 0;
}
