#include <cstdio>
using namespace std;

int cstrlen(char* str)
{
  int i;
  for(i=0;str[i];i++);
  return i;
}

int cstrcmp(char* A,char* B)
{
  int i=0;
  while(A[i]!='\0')
  {
    if(A[i]!=B[i])
      break;
    i++;
  }
  return (A[i]-B[i]);
}

void cstrcpy(char* A,char* B)
{
  while(*B!='\0')
  {
    *A=*B;
    A++;
    B++;
  }
  *A='\0';
}

void reverse(char* buf,int len)
{
  int l=0,r=len-1;
  char t;
  while(l<r)
  {
    t=buf[l];
    buf[l++]=buf[r];
    buf[r--]=t;
  }
}
