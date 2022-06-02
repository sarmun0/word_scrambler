/*
 * This software scrambles the stdin except for first and last letter of every word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scramble(char** text,unsigned long long start,unsigned long long stop) {
  char* word;
  char buf;
  unsigned long long x,i,length=stop-start-1;
  word=(char*)malloc(length);
  for (i=0;i<length;i++) {
    word[i]=(*text)[start+i+1];
  }
  for (i=0;i<length;i++) {
    x=rand()%length;
    buf=word[i];
    word[i]=word[x];
    word[x]=buf;
  }
  for (i=0;i<length;i++) {
    (*text)[start+i+1]=word[i];
  }
  free(word);
}

int main() {
  const char alf[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  char* txt;
  unsigned long long l=0,b=0,e=0,i=0,j,alfnum=0;
  int n=0;
  char u;
  srand(time(NULL));
  txt=(char*)malloc(l);
  while (1==1) {
    scanf("%c",&u);
    l++;
    if (u=='\n') {
      break;
    }
    else {
      txt=realloc(txt,l);
      txt[i]=u;
      i++;
    }
  }
  i=0;
  while (1==1) {
    alfnum=0;
    if (txt[i]==0) {
      e=i-1;
      scramble(&txt,b,e);
      break;
    }
    for (j=0;j<=61;j++) {
      if (alf[j]==txt[i]) {
        alfnum=1;
        break;
      }
    }

    if (alfnum==0) {
      if (n==1) {
        e=i-1;
        scramble(&txt,b,e);
      }
      n=0;
      i++;
      continue;
    }
    if (n==0) {
      b=i;
      n=1;
    }
    i++;
  }
  printf("%s\n",txt);
  return 0;
}
