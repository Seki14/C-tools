/*--------------------------------------------------------------------------
  Tool name	    :Hexadecimal
  Module name   :Hexadecimal.c
  Detail        :To convert Decimal and Hex
  Implementer   :R.Ishikawa
  Version       :1.2
  Last update   :2018/10/14
 --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Version history
   1. Create new                   R.I   2018/01/01     Ver.1.0
   2. Add outer frame              R.I   2018/02/06     Ver.1.1
   3. Fixed infinite loop bugs     R.I   2018/10/14     Ver.1.2
 --------------------------------------------------------------------------*/
 
#include<stdio.h>
#include<stdlib.h>

#define MAX_DECIMAL 999999999

void to_binary(int decimal)
{
	int buf[32] = {0}; 
	int i = 0; 
	while(decimal > 0){
		buf[i] = decimal % 2; 
		decimal /= 2; 
		i++; 
	}
	while(i > 0){
		printf("%1d", buf[--i]); 
	}
	putchar('\n');
}

int main(void)
{
	int opt;        /* Input Option Number */
	int decimal;    /* For Option1 */
	int hex;        /* For Option2 */
    
    while(1){
        printf("\n*************** Hexadecimal ***************\n");
        printf(" 1: 10base -> 16base  2:16base -> 10base\n");
        printf("99: Quit\n");
        printf("*******************************************\n");
        
        opt = 0;    /* Initialize */
        printf("Input number: ");
        scanf("%d", &opt);
        if(opt < 1 || (opt > 1 && opt < 2) || (opt > 2 && opt < 99) || opt > 99){
            printf("invalid Input number\n");
            exit(0);
        }
        
        switch(opt){
            case 1:              /* Case1: 10base -> 16base */
                decimal = 0;     /* initialize */
                printf("10base -> 16base\n");
                printf("Input 10 base number: ");
                scanf("%d", &decimal);
                if((decimal < 0) || (decimal > MAX_DECIMAL)){
                    printf("Invalid Input number\n");
                    exit(0);
                }
                to_binary(decimal);
                printf("\nHex: %x\n", decimal);
			    break;
            case 2:              /* Case2: 16base -> 10base */
                hex = 0;         /* initialize */
                printf("16base -> 10base");
                printf("Input 16 base number: ");
			    scanf("%x", &hex);
			    printf("\nDec: %d\n", hex);
			    break;
            case 99:
                exit(0);
                break;
            default:
			    printf("Invalid Input number\n");
        }
    }
	return 0;
}
