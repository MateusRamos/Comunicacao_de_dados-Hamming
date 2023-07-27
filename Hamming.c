#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void caso1();
void caso2();

int main (){
    
    int z = 0;
    do{
        printf("||------------------------------------------------------------||");
        printf("\n\n..:: GERADOR E VERIFICADOR DE CODIGO DE HAMMING ::..\n\n");
        printf("Digite o que voce deseja fazer:\n");
        printf("(1) Enviar um grupo de bits\n");
        printf("(2) Verificar um grupo de bits recebido\n");
        printf("(3) Exit\n");
        printf("Opcao: ");
        scanf("%d", &z);
        
        switch (z){

            case 1 :
            caso1();
            break;
            
            case 2 :
            caso2();
            break;

        }

    }while(z != 3);

 printf("\n||------------------------------------------------------------||");
 return 0;
}

void caso1(){

    int bit_entrada, n_um=2, bit_total;
    float resto;
    printf("\n\n# Caso 1:");
    printf("\nDigite a quantidade de bits do grupo original: ");
    scanf("%d", &bit_entrada);
    
    int original[bit_entrada+1];
       
    for(bit_total=3; n_um<=bit_entrada; bit_total++){

        n_um++;
        resto=log(bit_total+1)/log(2);

        resto = resto - (int)resto;
        
        if(resto==0)
        {
            n_um--;
        }
    }

    resto=log(bit_entrada+1)/log(2);
    resto = resto - (int)resto;
    int paridade[bit_total], m;
    
    for(m=0; m<bit_entrada; m++){
        do{
            printf("\nDigite o numero %d: ", m+1);
            scanf("%d", &original[m]);
        }while(original[m]!=0 && original[m]!=1);
    }
    
    printf("\nDados Originais: ");
    int j;
    for(j=0; j<bit_entrada; j++){

        printf("%d", original[j] );
    }

    int controller = 0;
    
    for(j=1; j<=bit_total; j++){

        resto=log(j)/log(2);
        resto = resto - (int)resto;

        if(resto == 0){
            paridade[j-1]=0;
        }
        else{
            paridade[j-1] = original[controller];
            controller++;
        }            
    }
    
    for(j=1; j<=bit_total; j++){
        resto=log(j)/log(2);
        if(resto - (int)resto == 0){
            int i;
            n_um = 0;
            controller=0;
            
            for(i=j-1; i<bit_total; i++){
                if(paridade[i] == 1){
                    n_um++;
                }
                
                if(controller==j-1){
                    controller=0;
                    i = i + j;
                }
                else{
                    controller++;
                }
            }
            
            if(n_um%2!=0){
                paridade[j-1] = 1;
            }
        }
    }

    printf("\nDados que serao enviados: ");
    for(j=0; j<bit_total; j++){

        printf("%d", paridade[j]);
    }
    printf("\n\n");
}

void caso2()
{
    int n_um=0, bit_total=0, controller=0, bit_erro=0, m, j, i;
    float resto;

    printf("\n\n# Caso 2:");
    printf("\nDigite a quantidade de bits total: ");
    scanf("%d", &bit_total);
    
    int original[bit_total+1];
    int novo[bit_total+1];
    
    for(m=0; m<bit_total; m++){
        do{
            printf("\nDigite o numero %d: ", m+1);
            scanf("%d", &original[m]);
        }while(original[m]!=0 && original[m]!=1);
    }
    
    for(j=1; j<=bit_total; j++){
        resto=log(j)/log(2);
        resto = resto - (int)resto;
        if(resto == 0){
            novo[j-1]=0;
        }
        else{
            novo[j-1]=original[j-1];
        }            
    }
    
    for(j=1; j<=bit_total; j++){
        resto=log(j)/log(2);
        if(resto - (int)resto == 0){
            n_um = 0;
            controller=0;
            
            for(i=j-1; i<bit_total; i++){
                if(novo[i] == 1){
                    n_um++;
                }
                if(controller==j-1){
                    controller=0;
                    i=i+j;
                }
                else{
                    controller++;
                }
            }
            if(n_um%2==0){
                novo[j-1] = 0;
            }
            else{
                novo[j-1] = 1;
            }
            
            if(novo[j-1] != original[j-1]){

                printf("\n%d\n", j);
                bit_erro = bit_erro + j;
            }
        }
    }
    
    if(bit_erro!=0){

        printf("\nFoi detectado um erro no %d bit do grupo: ", bit_erro);
        for(i=0; i<bit_total; i++){
           printf("%d", original[i]);
        }
        if(original[bit_erro-1]==1){
           original[bit_erro-1]=0; 
        }
        else{
            original[bit_erro-1]=1; 
        }
    }
    
    printf("\n\nGrupo de bits finais com o bit corrigido: ");
        
    for(i=1; i<=bit_total; i++){
        resto=log(i)/log(2);
        if(resto - (int)resto != 0){
            printf("%d", original[i-1]);
        }  
    }
    printf("\n\n");
}
