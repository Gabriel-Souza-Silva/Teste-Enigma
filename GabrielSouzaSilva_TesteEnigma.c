#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mensagemIO.h"



void codificarMsg(Mensagem *,Mensagem *,Matriz *);
void decifrarMsg(Mensagem *,Mensagem *,Matriz *);
void mostrarMsg(Mensagem *);




void main() {
	
	Mensagem msgm,codmsg,decod;
	unsigned char msg[81];
	Matriz mtrz;
	unsigned char chave[10] = "TESTE";
	
	

	msgm.msg = msg;
	mtrz.chave = chave;
	mtrz.chave = (unsigned char*)malloc(10*sizeof(unsigned char));
	
	
	
	
	
     
	lerTexto(&msgm);                            //le a msg do txt e retorna ela e o tamanho                             OK
	construirQuadroSecreto(&mtrz ,chave);       //constroi quadro secreto e manda a chave do main para a funcão         OK
	codificarMsg(&msgm,&codmsg,&mtrz);          //codifica a msg que eu recebi em 'msgm' da função 'lerTexto'           OK
	decifrarMsg(&decod,&codmsg,&mtrz);          //decodifica  a msg que foi retorna em 'codmsg' para a nova 'decod'     NAO OK
	
	
	//printf("/////////////////////////////MAIN///////////////////////////////\n:");
	
	printf("////////////////////////////MOSTRAR MSG////////////////////////////////////\n");
	printf("MENSAGEM:");
	mostrarMsg(&msgm);
	printf("MENSAGEM CODIFICADA:");
	mostrarMsg(&codmsg);
	printf("MENSAGEM DECODIFICADA:");
	mostrarMsg(&decod);
	
	
    
  	getch();
	
	
}

////////////////////////////////////////////////////////////////////CODOFICAR MENSAGEM //////////////////////////////////////////////////////////////////////////////////////


void codificarMsg(Mensagem *normal , Mensagem *codificada,Matriz *matriz){
 
		int correchave,tamanhochave,tamanhomsg,tamanhocodificada,l,k,j,coluna,linha,achou,okay;
		unsigned char arrayparacod[normal->tamanho],msgcodificada[normal->tamanho+1];
		
		
		
		l = 0;
		j = 0;
		achou = 0;
		correchave = 0;                                                  //VARIAVEL PARA CORRER A STRING DE CHAVE
		tamanhomsg = normal->tamanho;									 //TAMANHO DA MENSAGEM DADA
		tamanhochave = strlen(matriz->chave);							 //TAMANHO DA STRING DE CHAVE	
		
		
		
		for( k = 0; k < tamanhomsg; k++ ){							     //'FOR' QUE VAI DO PREIMEIRO ATÉ A ULTIMA LETRA DA STRING	
			
			if(correchave > (tamanhochave-1)){							 //SE A VARIAVEL QUE PERCORRE A CHAVE CHEGAR NO TAMANHO DA CHAVE ELE VOLTA PRO COMEÇO
				correchave = 0;
			}
			
			arrayparacod[k] = matriz->chave[correchave];				//ATRIBUI A LETRA DA CHAVE PARA A STRING QUE VAI CODIFICAR	
			correchave++;				
		}
			 	
	 	
		k = 1;
	 	
	 	do{
														
			 	do{                                                                                //VERIFICA A LINHA PARAA ENCONTRAR O CARACATERE J DE ARRAYPARACOD
			 		
			 		if(matriz->Q[k][1] == arrayparacod[j]){                                        
			 			
			 			linha = k;
			 			achou = 1;
						//printf("Linha %d \t",linha);
					}else{
						achou = 0;
					}
					 
					k++;
					 	
				}while(achou != 1);
				
				
				 
				k=1;                                                                              //VOLTA PARA O INICIAO A VARIAVEL QUE CORRE A COLUNA
				achou = 0;
				
				
				
				
				do{                                                                               //VERIFICA A COLUNA PARA ENCONTRAR O CARACTERE J DE MENSAGEM 
			 		
			 		if(matriz->Q[1][k] == normal->msg[j]){                                        //SE A LETRA DA MSG FOR IGUAL A COLUNA K ELE SALVA A LETRA NA VARIAVEL'COLUNA'
			 			
			 			coluna = k;
			 			achou = 1;                                                                //PARA SAIR DO LOOP
			 			//printf("\t\t\t\tLinha %d  Coluna %d   Letra codificada: %c\n",linha,coluna,matriz->Q[linha][coluna]);
					}
					
					k++;
				
				//printf("\tColuna  %d\n",coluna);	 	
				}while(achou != 1);
			 	
			 	k=1;                                                                            //VOLTA PARA O INICIAO A VARIAVEL QUE CORRE A LINHA
			 	msgcodificada[l] = matriz->Q[linha][coluna];                                    //SALVA O CARACTERE CODIFICADO EM 'MSGCODIFICADA' NA LINHA E COLUNA ACHADA 
			 	j++;                                                                            //INCREMENTA 1 A VARIAVEL QUE CORRE A STRING 'ARRAYPARACOD'
			 	l++;                                                                            //INCREMENTA 1 A VARIAVEL QUE CORRE A STRING  QUE ARMAZENA A MSG 
		 
		 
		}while(l < tamanhomsg);                                                             //SE O 'L' FOR MAIOR QUE A MENSAGEM ELE PARA DE CODIFICAR POIS CHEGOU NO FINAL DA STRING 
		
		
		msgcodificada[tamanhomsg] = '\0';                                                  //DEFINE UM FINAL PARA A STRING
		codificada->msg = msgcodificada;												   //PASSA PARA A STRUCT 'CODIFICADA'
		codificada->tamanho = tamanhomsg; 												   //PASSA O TAMANHO PARA A STRUCT 'CODIFICADA'	 
		printf("///////////////////////////CODIFICAR MSG///////////////////////////////////////\n");
		//printf("msfcodificada %s\n",msgcodificada);
		printf("Mensagem codificada na funcao codificarMsg: %s\n\n\n",codificada->msg);
		//printf("codificada->tamanho  %d\n",codificada->tamanho);
		
}


//////////////////////////////////////////////////////////////////////////DECIFRAR MENSAGEM /////////////////////////////////////////////////////////////////////////////////////////

void decifrarMsg(Mensagem *descod,Mensagem *codific,Matriz *matriz){
	
	
	  int k,l,j,achou,correchave,tamanhochave,tamanhomsg,linha,coluna;
	  unsigned char arrayparadecod[descod->tamanho],msgdecodificada[descod->tamanho+1];
	  
	  printf("///////////////////////////DECIFRAR MSG///////////////////////////////////////\n");
	  printf("Mensagem codificada na funcao codificarMsg: %s\n",codific->msg);
	  
	  
	  l = 0;                                                           //VARIAVEL QUE CONTROLA O ESPAÇO QUE ESTA NA STRING [L]
	  j = 0;                                                           //VARIAVEL QUE CONTROLA O ESPAÇO DA STRING ARRAYPARA 
      achou = 0;
	  correchave = 0;                                                  //VARIAVEL PARA CORRER A STRING DE CHAVE
	  tamanhomsg = codific->tamanho;								   //TAMANHO DA MENSAGEM DADA
	  tamanhochave = strlen(matriz->chave);							   //TAMANHO DA STRING DE CHAVE	
		
		
	  for( k = 0; k < tamanhomsg; k++ ){							     //'FOR' QUE VAI DO PREIMEIRO ATÉ A ULTIMA LETRA DA STRING CODIFICADA
			
			if(correchave > (tamanhochave-1)){							 //SE A VARIAVEL QUE PERCORRE A CHAVE CHEGAR NO TAMANHO DA CHAVE ELE VOLTA PRO COMEÇO
				correchave = 0;
			}
			
			arrayparadecod[k] = matriz->chave[correchave];				//ATRIBUI A LETRA DA CHAVE PARA A STRING QUE VAI CODIFICAR	
			correchave++;				
	   }  
	   
	   
	   
	   
	 do{
	  
			   do{                                                                                //VERIFICA A LINHA PARAA ENCONTRAR O CARACATERE J DE ARRAYPARADECOD
					 		
						if(matriz->Q[k][1] == arrayparadecod[j]){                                        
							
							linha = k;
							achou = 1;
							//printf("Linha %d \t",linha);
						}else{
							achou = 0;
						}
					
					k++;
							 	
				}while(achou != 1);
			   
			   
			    
				k=1;                                                                              //VOLTA PARA O INICIAO A VARIAVEL QUE CORRE A COLUNA
				achou = 0;
			   
			   do{
			   		
			   		if(matriz->Q[linha][k]==codific->msg[l]){
			   		   
						  coluna = k;	
			   		 	  achou = 1;
					}
			   	
			   		k++;
			   		
			   }while(achou!=1);
			   
			   msgdecodificada[l] = matriz->Q[1][coluna];
			   
			   k = 1;
			   j++;
			   l++;
			   
			   
	   
		}while(l < codific->tamanho);                                                            //QUANDO FAZER A ULTIMA LETRA ELE PARA 
	   
	   printf("Mensagem decodificada na funcao decifrarMsg: %s\n\n\n",msgdecodificada);	   
	   
}



//////////////////////////////////////////////////////////////////////////MOSTRAR MENSAGEM /////////////////////////////////////////////////////////////////////////////////////////


void mostrarMsg(Mensagem *msgmostrar){
	
	printf("%s\n",msgmostrar->msg);
	
}







