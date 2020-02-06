#include <stdio.h>
int main()
{ 
 int codeA[]={1,1,1,1};
 int codeB[]={1,-1,1,-1}; 
 int codeC[]={1,1,-1,-1};
 int codeD[]={1,-1,-1,1};  
 int x,x1,y,z,w,A,B,C,D,As[8],Bs[8],Ss[8],Cs[8],Ds[8],frame[8],i,a=0,b=0,c=0,d=0;
 int s,r,choice=1;
 int sb,Y;
 
 printf("\t\t\t\t\t\t\t\t\t-----------CDMA-----------\n");
 printf("Network Outlook : \n");
 printf("\t\t\t|1|- - - - - - - - - - - - - - - - -|2|\n\t\t\t |                                   |\n\t\t\t |                                   |\n\t\t\t |                                   |\n\t\t\t |                                   |\n\t\t\t |                                   |\n\t\t\t|3|- - - - - - - - - - - - - - - - -|4|\n");
 printf("\nEnter The 4 bit Frame : ");
 for(i=0;i<4;i++)
 {
      scanf("%d",&frame[i]);
 }
 x=frame[0];
 y=frame[1];
 z=frame[2];
 w=frame[3];
 if(x==1)
    A=1;
 else 
    A=0; 
 if(y==1)
    B=1;
 else 
    B=0;
 if(z==1)
    C=1;
 else 
    C=0;
 if(w==1)
    D=1;
 else 
    D=0;

 printf("\nData on Station 1 : ");
 printf("%d\n",A);
 printf("Data on Station 2 : ");
 printf("%d\n",B);
 printf("Data on Station 3 : ");
 printf("%d\n",C);
 printf("Data on Station 4 : ");
 printf("%d\n",D);


 printf("\nCode of station 1 : ");
 for(i=0;i<4;i++)
 {
    if(codeA[i]>0)
        printf("+%d ",codeA[i]);
    else
        printf("%d ",codeA[i]);
 }


 printf("\nCode of station 2 : ");
 for(i=0;i<4;i++)
 {
  if(codeB[i]>0)
        printf("+%d ",codeB[i]);
    else
        printf("%d ",codeB[i]);
 }
 printf("\nCode of station 3 : ");
 for(i=0;i<4;i++)
 {
    if(codeC[i]>0)
        printf("+%d ",codeC[i]);
    else
        printf("%d ",codeC[i]);
 }
 printf("\nCode of station 4 : ");
 for(i=0;i<4;i++)
 {
    if(codeD[i]>0)
        printf("+%d ",codeD[i]);
    else
        printf("%d ",codeD[i]);
 }
 for(i=0;i<4;i++)
 {
  As[i]=A*codeA[i];
  Bs[i]=B*codeB[i];
  Cs[i]=C*codeC[i];
  Ds[i]=D*codeD[i];
  Ss[i]=As[i]+Bs[i]+Cs[i]+Ds[i];
 }
 printf("\n\nData On Network  : ");
 for(i=0;i<4;i++)
 {
 if(Ss[i]>0)
        printf("+%d ",Ss[i]);
    else
        printf("%d ",Ss[i]);
 }

while(choice)
{
    printf("\n\n\nChannel Details -------\n ");
    printf("\nEnter the Receiver Station: ");
    scanf("%d",&r);
    printf("Enter the Sender Station  : ");
    scanf("%d",&s);
switch(s)
{
    case 1:{
             for(i=0;i<4;i++)
                {
                    a=a+codeA[i]*Ss[i];
                }
             a=a/4;
             if(a==1)
                Y=1;
             else 
                Y=0; 
            }
            break;
    case 2:{
             for(i=0;i<4;i++)
                {
                    b=b+codeB[i]*Ss[i];
                }
             b=b/4;
             if(b==1)
                Y=1;
             else 
                Y=0; 
            }
            break;
    case 3:{
             for(i=0;i<4;i++)
                {
                    c=c+codeC[i]*Ss[i];
                }
             c=c/4;
             if(c==1)
                Y=1;
             else 
                Y=0; 
            }
            break;
    case 4:{
             for(i=0;i<4;i++)
                {
                    d=d+codeD[i]*Ss[i];
                }
             d=d/4;
             if(d==1)
                Y=1;
             else 
                Y=0; 
            }break;
    default:("\n\nIn valid Sender:");
    
 }
 
 x1=rand()%2;
 if(x1==1)
 {
    printf("\nConnection Established!!\n");
    printf("Sender %d received data bit %d from Reciever %d\n",s,Y,r);
 }
 else
    printf("\nConnection Failed!!\n");
 printf("Do you want to test another channel ? 1-y,0-n  ");
 scanf("%d",&choice);
}
 return 0;
}
