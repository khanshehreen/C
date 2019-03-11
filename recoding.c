#include<math.h>
#include<stdio.h>
int a = 0,b = 0, c = 0, a1 = 0, b1 = 0, com[5] = { 1, 0, 0, 0, 0};
int anum[5] = {0}, anumcp[5] = {0}, bnum[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, pro[5] = {0}, res[5] = {0}, recode[5] ={0};
int result[10]= {0};
int COUNT = 10,sum[10] ={0};
void recode1(){
	int i=0;
	{
	if(anum[i]==0)
	{
		recode[0] = 0;
	}
	if(anum[i]==1)
	{
		recode[0] = -1;
	}
	for(i=0;i<5;i++)
	{
	if(anum[i]==anum[i+1])
	{
		recode[i+1] = 0;
	}
	else if(anum[i]<anum[i+1])
	{
		recode[i+1] = -1;
	}
	else if(anum[i]>anum[i+1])
	{
		recode[i+1] = 1;
	}
	}
	}		
}
int add_bin(int x[],int y[]){
	int i,carry=0;
	for(i = COUNT-1;i>=0;i--){
		if(x[i]==0 && y[i]==0 && carry==0){
			sum[i] = 0;
			carry = 0;
		}
		else if(x[i]==0 && y[i]==0 && carry==1){
                        sum[i] = 1;
                        carry = 0;
                }
		else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==0){
			sum[i] = 1;
			carry = 0;
		}
		else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==1){
                        sum[i] = 0;
                        carry = 1;
                }
		else if(x[i]==1 && y[i]==1 && carry==0){
			sum[i] = 0;
			carry = 1;
		}
		else if(x[i]==1 && y[i]==1 && carry==1){
                       sum[i] = 1;
                        carry = 1;
                }
	}
	for(i = COUNT-1;i>=0;i--){
	result[i] = y[i];
	}	
}
void binary(){
     a1 = fabs(a);
     b1 = fabs(b);
     int r, r2, i, temp;
     for (i = 0; i < 5; i++){
           r = a1 % 2;
           a1 = a1 / 2;
           r2 = b1 % 2;
           b1 = b1 / 2;
           anum[i] = r;
           anumcp[i] = r;
           bnum[i] = r2;
           if(r2 == 0){
                bcomp[i] = 1;
           }
           if(r == 0){
                acomp[i] =1;
           }
     }
   //part for two's complementing
   c = 0;
   for ( i = 0; i < 5; i++){
           res[i] = com[i]+ bcomp[i] + c;
           if(res[i] >= 2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i] % 2;
     }
   for (i = 4; i >= 0; i--){
     bcomp[i] = res[i];
   }
   //in case of negative inputs
   if (a < 0){
      c = 0;
     for (i = 4; i >= 0; i--){
           res[i] = 0;
     }
     for ( i = 0; i < 5; i++){
           res[i] = com[i] + acomp[i] + c;
           if (res[i] >= 2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i]%2;
     }
     for (i = 4; i >= 0; i--){
           anum[i] = res[i];
           anumcp[i] = res[i];
     }
   }
   if(b < 0){
     for (i = 0; i < 5; i++)
     {
           temp = bnum[i];
           bnum[i] = bcomp[i];
           bcomp[i] = temp;
     }
   }
}
void main()
{
   int i, q = 0;
   printf("\t\tBOOTH'S  RECODING MULTIPLICATION ALGORITHM");
   printf("\nEnter two numbers to multiply: ");
   printf("\nBoth must be less than 16");
   do{

        printf("\nEnter A: ");
        scanf("%d",&a);
        printf("Enter B: ");
        scanf("%d", &b);
     }while(a >=16 || b >=16);
    printf("\nExpected product = %d", a * b);
    binary();
    printf("\n\nBinary Equivalents are: ");
    printf("\nA = ");
    for (i = 4; i >= 0; i--){

        printf("%d", anum[i]);

    }
    printf("\nB = ");
    for (i = 4; i >= 0; i--){

        printf("%d", bnum[i]);
    }
    recode1();
    printf("\nrecoded value of A = ");
    for (i = 4; i >= 0; i--){

        printf("%d", recode[i]);
    }
    printf("\n");
int result1[10] ={0};
int j;	
printf("\n\t  ");
for(i=4;i>=0;i--)
printf("%d",bnum[i]);
printf("\n\tX ");
for(i=4;i>=0;i--)
printf("%d",recode[i]);
printf("\n\t----------\n");
 for(i = 0;i<5;i++)
 	{
 		{
 		if(recode[i] ==0)
 		{
 		for(j=0;j<10;j++)
 					result1[j] = 0;
 		
 		}
 		if(recode[i]==1)
 			{
 			if(b>0)
 			{
 				for(j=0;j<5;j++)
 					result1[j] = bnum[j];
 				for(j=5;j<10;j++)
 		        		result1[j] = 0;
 			}
 			if(b<0)
 			{
 				for(j=0;j<5;j++)
 					result1[j] = bnum[j];
 				for(j=5;j<10;j++)
 					result1[j] = 1;
 			}
 			}
 		if(recode[i]==-1)
 			{
 			if(b>0)
 			{
 				for(j=0;j<5;j++)
 					result1[j] = bcomp[j];
 				for(j=5;j<10;j++)
 					result1[j] = 1;
 			}
 			if(b<0)
 			{
 				for(j=0;j<5;j++)
 					result1[j] = bcomp[j];
 				for(j=5;j<10;j++)
 					result1[j] = 0;
 			}
 			}
 			}
 		for(j=0;j<i;j++)
 			{
 			int k,temp;
 			result1[9] = result1[8];
 			result1[8] = result1[7];
 			result1[7] = result1[6];
 			result1[6] = result1[5];
 			result1[5] = result1[4];
 			result1[4] = result1[3];
 			result1[3] = result1[2];
 			result1[2] = result1[1];
 				result1[1] = result1[0];
 				result1[0] = 0;
 			}
 			printf("\t");
 			if(i>0);
 			printf("+");
 			  for (j = 9; j >=i ; j--){
           printf("%d", result1[j]);
           }  
           for (j = i; j >0 ; j--){
           printf("x");
           }  
           int result2[10] ={0};
 		for (j = 9; j >= 0; j--){

           result2[j] = result[j];
           }
 		printf("\n");
   int carr = 0;
 		for(j = 0; j < 10 ; j++){
   	result[j] = ((result2[j] ^ result1[j]) ^ carr); // c is carry
  	 carr = ((result2[j] & result1[j]) | (result2[j] & carr)) | (result1[j] & carr); 
	}
		 
 	}
 printf("\t------------\n\t ");
  for (j = 9; j >=0 ; j--){

           printf("%d", result[j]);
           }  
     printf("\n\nProduct is = ");

     for (i = 9; i >= 0; i--){

           printf("%d", result[i]);
     }
}
