
/* Decimal to binary,hex octal conversion */

#include<stdio.h>
#include<stdlib.h>

void dec_to_binary(int arg);
void dec_to_oct(int arg);
void dec_to_hex(int arg);
void main()
{
	//dec_to_binary(13);
	//dec_to_oct(20);
	
	dec_to_hex(20);
}
void dec_to_hex(int arg)
{
	int bit=-1;
	char binary[20]={0};
	int binary_count=0;
	char Hex_arr[]={'A','B','C','D','E','F'};
	while(arg!=0)
	{
		bit=arg%16;
		arg/=16;
		if (bit > 9)
		{
			binary[binary_count]=Hex_arr[bit-10];
		}
		else
		{
			binary[binary_count]=bit+0x30;
		}
		binary_count++;
		//printf(" binary_count %d %d ",binary_count,bit);
	}
	printf("\n");
	binary_count--;
	for(int i=binary_count;i>=0;i--)
	{
		printf("%c ",binary[binary_count]);
		binary_count--;
	}

}

void dec_to_oct(int arg)
{
	int bit=-1;
	int binary[20]={0};
	int binary_count=0;
	while(arg!=0)
	{
		bit=arg%8;
		arg/=8;
		binary[binary_count]=bit;
		binary_count++;
		//printf(" binary_count %d %d ",binary_count,bit);
	}
	printf("\n");
	binary_count--;
	for(int i=binary_count;i>=0;i--)
	{
		printf("%d ",binary[binary_count]);
		binary_count--;
	}

}
void dec_to_binary(int arg)
{
	int bit=-1;
	int binary[20]={0};
	int binary_count=0;
	while(arg!=0)
	{
		bit=arg%2;
		arg/=2;
		binary[binary_count]=bit;
		binary_count++;
		//printf(" binary_count %d %d ",binary_count,bit);
	}
	printf("\n");
	binary_count--;
	for(int i=binary_count;i>=0;i--)
	{
		printf("%d ",binary[binary_count]);
		binary_count--;
	}

}
