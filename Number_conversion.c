
//Number format conversion

#include<stdio.h>
void binary(int );
void octal();
void hexa();

int bin[20]={0};
int oct[20]={0};
char hex[20]={0};

int pow1(int ,int );


void main()
{
int num=0,rem=0;
printf("Enter the Number\n");
scanf("%d",&num);
binary(num);
octal();
hexa();

}


void binary(int num)
{
int i=19,rem=0;

while(num!=1)
{
    rem=num%2;
    num=num/2;
    bin[i]=rem;
      if(num==1)
      {
          bin[i-1]=1;    // FOR Last one quotient
      }
       i--;
   
}
                                //   printf("\n\n");
      printf("\n\n Bin:");                          //   printf("Binary is=0b:");
   for(int j=0;j<=19;j++)
  {
      printf("%d",bin[j]);
   }
                                //  printf("\n\n");
}


int pow1(int x, int y)
{
int z;
z=x;
if(y==0)
{ return 1;
}
for(int i=1;i<y;i++)
{
    z=z*x;
}
return z;
}





void octal()
{
int i=19,z=19,sum=0; //j=0,
for(int j=0;j<6;j++)
{
  sum= ( bin[i] * ( pow1(2,0) ) )+( bin[i-1] * ( pow1(2,1) ) )+( bin[i-2] * ( pow1(2,2) ) );
  // printf("\n%d\n",sum);
   i=i-3;   // For set of numbers oct =3
   oct[z]=sum;
   z--;
}
printf("\n\n oct:");
for(int j=0;j<=19;j++)
{
 printf("%d",oct[j]);
}
}


void hexa()
{
int i=19,z=19;
int sum=0; //j=0,
for(int j=0;j<6;j++)
{
                        // sum= ( bin[i] * ( pow1(2,0) ) ) ;
                        //  printf(" bin[i] * ( pow1(2,0) =%d\n",sum);
                        //  sum=( bin[i-1] * ( pow1(2,1) ) );
                        // printf(" bin[i-1] * ( pow1(2,1) ) =%d\n",sum);
                        // sum=( bin[i-2] * ( pow1(2,2) ) );
                        // printf(" bin[i-2] * ( pow1(2,2) ) =%d\n",sum);
                        // sum=( bin[i-3] * ( pow1(2,3) ) );
                        // printf(" bin[i-3] * ( pow1(2,3) ) =%d\n",sum);

  sum= ( bin[i] * ( pow1(2,0) ) ) +( bin[i-1] * ( pow1(2,1) ) ) + ( bin[i-2] * ( pow1(2,2) ))  + ( bin[i-3] * ( pow1(2,3) ) ) ;

//    printf("\n%d\n",sum);
   i=i-4;   // For set of numbers hex =4
if(sum>=10)
{
   hex[z]=sum+55;
} 
else{
    hex[z]=sum+48;
}
   z--;
}

 printf("\n\n Hex:");
    for(int j=0;j<=19;j++)
   {
   printf("%c",hex[j]);
     }
      printf("\n");
}