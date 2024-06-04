#include <stdio.h>
#include "str.h"

#include <string.h>

void encrypt (char from[], char to[], char key[])
{
  int len_from = strlen(from), len_key = strlen(key);
  if (len_from > 1023) {
    printf("Too Long...\n");
    return;
  }

  int k_idx = 0;
  for (int i = 0; i <= len_from; i++) {
    to[i] = from[i];
    if (97 <= from[i] && from[i] <= 122)
      to[i] -= 32;
    
    if (!((65 <= from[i] && from[i] <= 90) || (97 <= from[i] && from[i] <= 122)))
      continue;
    
    if (65 <= key[k_idx] && key[k_idx] <= 90)
      to[i] += key[k_idx] - 65;
    else if (97 <= key[k_idx] && key[k_idx] <= 122)
      to[i] += key[k_idx] - 97;
    k_idx = (k_idx + 1) % len_key;
  }
}
