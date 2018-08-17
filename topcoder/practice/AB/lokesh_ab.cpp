#include <iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int n,k;
char a[1000]="",b[1000]="",d[1000]="";

char* pattern()
{
    int i,j,s=0,rem,c=0;

    if(k%2 != 0)
    {
        c=1;
        k=k-1;
    }

        j=k/2;
        for(i=0;i<j;i++)
        {
            a[s++]='A';
        }
        for(i=0;i<k/j;i++)
        {
            a[s++]='B';
        }



      /*  if(strlen(a)+2 >= n)
        {
            cout<<a<<"AB";
            exit(0);
        }

*/
        rem=n-strlen(a);

        if(rem < 0)
        {
            return "";
            exit(0);
        }
        for(j=0;j<rem-1;j++)
        {

            b[j]='B';
        }
    //if(c==0)
     a[s]='\0';

     strcat(b,a);


    if(c==1)
     {

         strncat(d,b,strlen(b)-1);
         strcat(d,"AB");
     }

   return d;

}

int main()
{
    cin>>n>>k;
    cout<<pattern();
    return 0;
}
