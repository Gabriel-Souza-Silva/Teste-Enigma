#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 81 



	typedef struct{
		unsigned int tamanho;
		unsigned char * msg;
	}Mensagem;
	
	typedef struct{
		unsigned char * chave;
		unsigned char Q[27][27];
		
	}Matriz;
	
	
	void lerTexto(Mensagem * a){
		
		unsigned char b[MAX];
		
		
		FILE * file;
		file = fopen ("mensagem.txt" , "r");
		
			if (file == NULL){
			printf("\n nao encontrado\n");
			
			} 
			else{
				//printf("arquivo mensagem.txt encontrado:\n");
				fscanf(file , "%s",a->msg);                                                       
				//printf("%s\n",a->msg);
				a->tamanho = strlen(a->msg);
				//printf("%d\n",a->tamanho);
				fclose(file);
			}
		
		
		
		
	}
	
	
	void construirQuadroSecreto(Matriz *b, char *c){
		
		int i,j;
		
		
		Matriz d = {
				"",
			
			{
			
			   { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
			   { ' ','B','C', 'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'},
			   { ' ','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B' },
			   { ' ','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C' },
			   { ' ','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D' },
			   { ' ','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E' },
			   { ' ','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F' },
			   { ' ','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G' },
			   { ' ','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H' },
			   { ' ','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I' },
			   { ' ','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J' },
			   { ' ','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K' },
			   { ' ','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L' },
			   { ' ','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M' },
			   { ' ','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N' },
			   { ' ','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O' },
			   { ' ','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' },
			   { ' ','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q' },
			   { ' ','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R' },
			   { ' ','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S' },
			   { ' ','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T' },
			   { ' ','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U' },
			   { ' ','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V' },
			   { ' ','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W' },
			   { ' ','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X' },
			   { ' ','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y' },
			   { ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' }
			   
			},

		};
		
		
		
		for(i=0;i<27;i=i+1){
			for(j=0;j<27;j=j+1){
				b->Q[i][j] = d.Q[i][j];
				//printf("%c ",b->Q[i][j]);
			}
			//printf("\n");
		}
		
//		for(i=0;d.chave[i] != '\0';i++){
//			b->chave[i] = d.chave[i];
//		}
		d.chave = c;
		b->chave = d.chave;
		
		
		//printf("%s",b->chave);			
											
	}
	
	
	
	
	
	
	
	
	
	
	
