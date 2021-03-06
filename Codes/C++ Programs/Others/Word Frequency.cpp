Word Frequency

#include <stdio.h>

#define SIZE 80
#define LEN  80


int strword(char[],char[][]);
int strword_p(char*,char**);


void main(){
	char* s;
	char** w;
	char ch;

	do{
	   clrscr();
	   gotoxy(10,1);
	   printf("Enter a string :");
	   gets(s);
	   gotoxy(10,2);
	   printf("\nNumber of words :%d",strword_p(s,w));
	   gotoxy(10,24);
	   printf(" Continue(y/n)?");
	   ch=getch();

	} while (ch=='y' || ch=='Y');
}

int strword_p(char *s,char **w){
    int is_space=0,
	i=0,
	word_counter=0,
	j=0,
	is_printed=0,
	frequency=0;

	while (*(s+i)!='\0'){
		if (*(s+i)==' ' ||
		    *(s+i)==',' ||
		    *(s+i)=='.' ||
		    *(s+i)==':'){

		     if (is_space==0){
			 *(*(w+word_counter)+j)='\0';
			 word_counter++;
			 is_space=1;
			 j=0;
		     }
		}
		else{
		   *(*(w+word_counter)+j)=*(s+i);
		   j++;
		   is_space=0;
		}
		i++;
	}
     if (is_space==0){
	 *(*(w+word_counter)+j)='\0';
	word_counter++;
     }

     for(j=0;j<word_counter;j++){
	frequency=0;
	is_printed=0;
	for(i=0;i<word_counter;i++){
	    if (strcmp(w[i],w[j])==0){
		 frequency++;
		 if (j<i)
			is_printed=1;
	    }
	}
	if (!is_printed)
		printf("\n Word %d : %s ,frequency->%d",j+1,w[j],frequency);
     }
     printf("\n");


     return word_counter;


}
