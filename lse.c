Ir para o conteúdo
ufam-icomp-ALGOsEDs
/
introdução-como-lse-ishmac

Escreva /para pesquisar

Código
Problemas
Solicitações pull
1
Ações
Projetos
Wikipédia
Segurança
Percepções
Configurações
Comprometer-se
Atualizar lse.c
 principal
@ishmac
ishmac comprometido em 18 de dezembro de 2023 
1 pai 3c7d867
cometer 46f5d25
Mostrando 1 arquivo alterado com 75 adições e 63 exclusões .
 138 alterações: 75 adições e 63 exclusões138 
src/lse.c
@@ -1,99 +1,111 @@
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>  

typedef  estrutura  elem_se
{
    int  carga_util ;
    estrutura  elem_se  * prox ; // endereco próximo elemento referenciando a si mesma

typedef  struct  elem_se {
    int  idade ;
     peso flutuante ;
    float  altura ;
    estrutura  elem_se  * prox ;
} t_elemento_lse ;

typedef  estrutura  lse
{
    // enderecos dos elementos, ponteiros para t_elemento_lse
typedef  estrutura  lse {
    t_elemento_lse  * inicio ;
    t_elemento_lse  * fim ;
     tamanho interno ;
} t_lse ;


int  acessar_lse ( t_lse  * lse , int  pos ){
  pos  =  pos % lse -> tamanho ;
  pos = ( pos  == 0 ? lse -> tamanho : pos ); // pos ==0? = if e ==0 caso verdadeiro e :pos caso falso
  t_elemento_lse *  cam  =  lse -> inicio ;
  for ( int  i  =  1 ; i <  pos ; i ++ ){
    cam  =  cam -> prox ;
  }
  retornar  cam -> carga_util ;
}

t_lse *  criar_lse (){
t_lse  * criar_lse (){
    t_lse  * l  =  malloc ( sizeof ( t_lse ));
    l -> inicio  =  l -> fim  =  NULL ;
    eu -> tamanho  =  0 ;
    //l->imprimir = imprimir;
    //l->comparar = comparar;
    retornar  eu ;
}

t_elemento_lse *  criar_elemento_lse ( int  carga_util ){
    t_elemento_lse *  novo  =  malloc ( sizeof ( t_elemento_lse ));
    novo -> carga_util  =  carga_util ;
t_elemento_lse  * criar_elemento_lse ( int  idade , float  peso , float  altura ) {
    t_elemento_lse  * novo  =  malloc ( sizeof ( t_elemento_lse ));
    novo -> idade  =  idade ;
    novo -> peso  =  peso ;
    novo -> altura  =  altura ;
    novo -> prox  =  NULL ;

    //printf("Criando: %p %p %p\n", novo, novo->carga_util, novo->prox);

    retornar  novo ;
}

void  inserir_lse ( t_lse * lse , int carga_util ) {  
    t_elemento_lse * novo = criar_elemento_lse ( carga_util );   
void  inserir_final_lse ( t_lse * lse , int idade , float peso , float altura ) {    
    t_elemento_lse * novo = criar_elemento_lse ( idade , peso , altura );   

    if ( lse -> inicio  ==  NULL ){
    if ( lse -> início  ==  NULL )  {
        lse -> inicio  =  lse -> fim  =  novo ;
    } outro {
        novo -> prox  =  lse -> inicio ;
        lse -> início  =  novo ;
    } outro {  
        lse -> fim -> prox  =  novo ;
        lse -> fim  =  novo ;
    }

    lse -> tamanho ++ ;
}

void  inserir_final_lse ( t_lse *  lse , int  carga_util ){
void  removedor_inicio_lse ( t_lse  * lse , t_elemento_lse  * * buffer , int  * buffer_size ) {
    if ( lse -> início  !=  NULL ) {
        t_elemento_lse  * removido  =  lse -> inicio ;
        lse -> inicio  =  lse -> inicio -> prox ;
        buffer [ * buffer_size ] =  removido ;
        ( * buffer_size ) ++ ;
        lse -> tamanho -- ;
    }
}

    t_elemento_lse *  novo  =  criar_elemento_lse ( carga_util );
int  tamanho_lse ( t_lse  * lse ) {
    return  lse -> tamanho ;
}

    if ( lse -> inicio  ==  NULL ){
        lse -> inicio  =  lse -> fim  =  novo ;
    } outro {
       lse -> fim -> prox  =  novo ;
        lse -> fim  =  novo ;
void  imprimir_buffer ( t_elemento_lse  * * buffer , int  buffer_size ) {
    for ( int  i  =  0 ; i  <  tamanho_buffer ; i ++ ) {
        if ( buffer [ i ] -> peso  ==  0  ||  buffer [ i ] ->  altura  ==  0 ) {
            printf ( "%d\n" , buffer [ i ] -> idade );
        } outro {
        printf ( "%d %.1f %.1f\n" , buffer [ i ] -> idade , buffer [ i ] -> peso , buffer [ i ] -> altura );
        }
        grátis ( buffer [ i ]);
    }
    lse -> tamanho ++ ;

}

int  principal () {
    t_lse  * lista  =  criar_lse ();
     comando interno ;
    int  idade ;
     peso flutuante , altura ;
    t_elemento_lse  * buffer [ 100 ];
    int  buffer_size  =  0 ;

    enquanto ( 1 ) {
        scanf ( "%d" , & comando );

        switch ( comando ) {
            caso  0 :
                quebrar ;

            caso  1 :
                scanf ( "%d %f %f" , & idade , & peso , & altura );
                inserir_final_lse ( lista , idade , peso , altura );
                quebrar ;

            caso  2 :
                remove_inicio_lse ( lista , buffer e buffer_size ) ;
                quebrar ;

            caso  3 :
                buffer [ buffer_size ] =  criar_elemento_lse ( tamanho_lse ( lista ), 0 , 0 );
                tamanho_buffer ++ ;
                quebrar ;
        }

        if ( comando  ==  0 ) {
            quebrar ; //Saia do loop quando o comando for 0
        }
    }

    imprimir_buffer ( buffer , buffer_size );

// tarefa se me der um elemento -1 eu quero acessar o penúltimo número - acesso reverso da lista
    grátis ( lista ); // Liberar a lista após a impressão

int  principal () {
  t_lse  * nros  =  criar_lse ();
  //povoando a lista
   número interno ;
  scanf ( "%d" , & num );
  enquanto ( num >= 0 ){
    inserir_final_lse ( nros , num );
    scanf ( "%d" , & num );
  }
  //acessando
   posição interna ;
  scanf ( "%d" e pos ) ;
  enquanto ( pos > 0 ){
    num  =  acessar_lse ( nros , pos );
    printf ( "valor: %d na posição: %d\n" , num , pos );
    scanf ( "%d" e pos ) ;

  }
    retornar  0 ;
}
0 comentários no commit46f5d25
@ishmac
Comente
 
Deixe um comentário
 
Rodapé
© 2024 GitHub, Inc.
Navegação no rodapé
Termos
Privacidade
Segurança
Status
Documentos
Contato
Gerenciar cookies
Não compartilhe minhas informações pessoais
Atualizar lse.c · ufam-icomp-ALGOsEDs/intro-as-lse-ishmac@46f5d25
