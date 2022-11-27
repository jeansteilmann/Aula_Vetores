#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

bool Existe(int valores[],int tam,int valor){
    for (int i = 0; i < tam; i++)
    {
        if(valores[i]==valor)
            return true;
    }
    return false;
}

void GeraPrincipal(int numeros[], int quantNumeros, int limite){
    srand(time(NULL));
    int v;
    for (int i = 0; i < quantNumeros; i++)
    {
        v = rand() % limite;
        while (Existe(numeros,i,v))
        {
           v = rand() % limite;
        }
        numeros[i] = v;
    }
    
    
}
void percorre_exclui(int numeros[],int buffer[],int tam){//Excluir os valores que ja foram pro buffer
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        if (numeros[i] == buffer[j])
        {
            numeros[i] = 0;
        }
    }
    j++;
    for (int i = 0; i < tam; i++)
    {
        if (numeros[i] == buffer[j])
        {
            numeros[i] = 0;
        }
    }
} 
void ordena_numeros(int numeros[],int numeros_ordenados[],int tam){
    int copia,j;
    for (int i = 0; i < tam; i++)//Passando os valores do vet numeros pro vet numeros_ordenados
    {
        numeros_ordenados[i] = numeros[i];
    }
    for (j = 1; j <= tam; j++){//Ordenando o vetor numeros e salvando em numeros_ordenados
        for (int i = 0; i < tam - 1; i++){
           if (numeros_ordenados[i] > numeros_ordenados[i+1]){
            copia = numeros_ordenados[i];
            numeros_ordenados[i] = numeros_ordenados[i+1];
            numeros_ordenados[i+1] = copia;
           }
           
        }
        
    }
}    

  
void select_buffer(int numeros[],int numeros_ordenados[],int buffer[],int j[]){
    for (int i = 0; i < 2; i++)
    {
        buffer[i] = numeros_ordenados[j[0]];
        j[0]++;//Para selecionar o estagio anterior do historico
    }
    
    
}
void executa_historico(int buffer[],int secundario[],int numeros[],int tam,int cont[]){
    printf("\nBuffer: ");
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", buffer[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        printf("\nExecutando processo: %d", buffer[i]);
        secundario[cont[0]] = buffer[i];
        buffer[i] = 0;
        cont[0]++;//Para selecionar o estagio anterior do historico
    }
    printf("\nPrincipal: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\nSecundario: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", secundario[i]);
    }
    printf("\n\n");
    
    
    
    
    
}

void printa_Comandos(int numeros[],int buffer[],int secundario[]){
    printf("Principal: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\nBuffer: ");
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", buffer[i]);
    }
     printf("\nHistorico: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", secundario[i]);
    }
    printf("\n\n");
}   
    
    

int main(){
    int cont[1] = {0};
    int j[1] = {0};
    int contador = 0;
    int numeros[10];
    int numeros_ordenados[10];
    int buffer[2] = {};
    int secundario[10] = {};
    GeraPrincipal(numeros,10,1001);//Gera os valores do vetor principal
    printa_Comandos(numeros,buffer,secundario);
    ordena_numeros(numeros,numeros_ordenados,10);
    while (contador < 5)
    {
        select_buffer(numeros,numeros_ordenados,buffer,j);//Ordena e seleciona os valores prioritarios do principal
        percorre_exclui(numeros,buffer,10);//Percorre o vetor numeros excluindo valores que ja foram pro buffer
        executa_historico(buffer,secundario,numeros,2,cont);//Passa os valores do buffer para o historico
        contador++;
    }
    printf("\n\n"); 
    return 0;
}