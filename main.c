/*
 * This software scrambles the stdin except for first and last letter of every word.
 * This software is distributed under the terms of BSD 3-Clause License (see ./LICENSE)
 * Copyright (c) 2022, sarmun0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scramble(char** text,unsigned long long start,unsigned long long stop) {
  char* word;
  char buf;
  unsigned long long x,i,length=stop-start-1;
  word=(char*)malloc(length);
  for (i=0;i<length;i++) { //let's copy the working word
    word[i]=(*text)[start+i+1];
  }
  for (i=0;i<length;i++) { //for each letter (apart from the first and last) we randomly select it's new position
    x=rand()%length;
    buf=word[i];
    word[i]=word[x];
    word[x]=buf;
  }
  for (i=0;i<length;i++) { //let's copy word back to the txt
    (*text)[start+i+1]=word[i];
  }
  free(word);
}

int main() {
  const char alf[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; //alfanumerical characters defined
  char* txt; //working array
  unsigned long long l=0,b=0,e=0,i=0,j; //l - length of input, b - beginning of word, e - end of word, i - position in txt counter
  int n=0,alfnum=0; //n=1 if txt[i] is inside a word, n=0 otherwise; alfnum=1 if txt[i] is in alf[], alfnum=0 otherwise
  char u; //input reader
// random initializing as well as our txt[]

  srand(time(NULL));
  txt=(char*)malloc(l);

// Following while loop reads the input to txt dynamic array

  while (1==1) {
    u=getchar();
    l++;
    if (u==EOF) {
      break;
    }
    else {
      txt=realloc(txt,l);
      txt[i]=u;
      i++;
    }
  }
// start scrambling

  i=0;
  while (1==1) {
    alfnum=0;
    if (txt[i]==0) { //we want to end at the end of txt
      e=i-1;
      if (e-b>2) { //we don't want to scramble words shorter than 4 letters
        scramble(&txt,b,e); //but we want to scramble the last word
        break;
      }
    }
    for (j=0;j<=61;j++) { //let's check if txt[i] is alfanumeric character
      if (alf[j]==txt[i]) {
        alfnum=1;
        break;
      }
    }
    if (alfnum==0) {
      if (n==1) { //if it's not and we are in the middle of word - this is the end of word
        e=i-1;
        if (e-b>2) {
          scramble(&txt,b,e); //don't scramble pointless words (i.e. less than 4 letters)
        }
      }
      n=0; //no word start's from a non-alfanumerical word
      i++;
      continue;
    }
    if (n==0) { //if it is alfanumeric and n=0 -> we start a new word
      b=i;
      n=1;
    }
    i++;
  }
  printf("%s\n",txt);
  return 0;
}
