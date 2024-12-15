#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0; // Contador de flores, verificação no inicio para o caso em que n é igual a 0

    if (n == 0) {
        return true; 
    }

    for ( int i = 0; i < flowerbedSize; i++ ) {
        if ( flowerbed[i] == 0 ) { // Verifica se a posição atual está vazia
            int anterior, posterior;

            // Define o valor da posição anterior
            if (i == 0) {
               anterior = 0; // Se estivermos na primeira posição, não há vizinho antes, então assumimos que está vazio
            } else {
               anterior = flowerbed[i - 1]; // Caso contrário, olhamos o valor da posição anterior
            }

            // Define o valor da posição seguinte
            if (i == flowerbedSize - 1) { // Se estivermos na última posição, há vizinho depois, então está vazio
                posterior = 0; 
            } else {
                posterior = flowerbed[i + 1]; // Caso contrário, olhamos a posição seguinte
            }

            // Se não há flores nas vizinhas, planta uma flor aqui
            if ( anterior == 0 && posterior == 0 ) {
                flowerbed[i] = 1; 
                count++;          // Incrementa o contador

                // Se já plantamos o suficiente, retorna true
                if (count >= n) {
                    return true;
                }
            }
        }
    }
    
    // Se não conseguimos plantar todas as flores necessárias, retorna false
    return false;
}

// Função main para testar a solução
int main() {
    int flowerbed[] = {1, 0, 0, 0, 1}; // Exemplo de entrada
    int n = 1; // Número de flores a serem plantadas
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]); // Calcula o tamanho do array

    // Chama a função e verifica o resultado
    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);

    // Exibe o resultado
    if (result) {
        printf("Sim, é possível plantar %d flores.\n", n);
    } else {
        printf("Não, não é possível plantar %d flores.\n", n);
    }

    return 0;
}
