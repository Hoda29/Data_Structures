#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
    int n,x,y;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    };
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        arr[x-1]=x;
    };
    for(int i=0;i<n;i++){
        printf("%d ",arr[n]);
    };
    return 0;
}
