#include <stdio.h>
#define KEY_LENGTH 2 // Can be anything from 1 to 13

main(){  
  unsigned char ch;  
  FILE *fpIn, *fpOut;  
  int i;  unsigned char key[KEY_LENGTH] = {0x00, 0x00};
  /* of course, I did not use the all-0s key to encrypt */
  fpIn = fopen("ptext.txt", "r");  
  fpOut = fopen("ctext.txt", "w");
  i=0;  
  while (fscanf(fpIn, "%c", &ch) != EOF) {
   if (ch!='\n') {      
     fprintf(fpOut, "%02X", ch ^ key[i % KEY_LENGTH]); // ^ is logical 
XOR          
     i++;      }    
  }   
 
  fclose(fpIn);  
  fclose(fpOut);  
  return;
} 
