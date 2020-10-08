#include<stdio.h>
void main()
{
    int ar[50],n,low,high,i,search;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
      scanf("%d",&search);
    low=0;
    high=n-1;
    //mid=(high+low)/2;
    bin(ar,n,high,low,search);

}
int bin(int ar[],int size,int h,int l,int ele)
{
   int m=(h+l)/2;
    if(ar[m]==ele){
        printf("Found at %d",m+1);
        exit(1);}
    else if(ar[m]>ele)
        bin(ar,size,m-1,l,ele);
    else
        bin(ar,size,h,m+1,ele);
    if(l<h){
        printf("not found");
    }
}
