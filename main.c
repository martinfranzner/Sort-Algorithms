//
//  main.c
//  OrdenacaoEstruturas
//
//  Created by Martin Franzner on 19/06/17.
//  Copyright © 2017 Martin Franzner. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncsOrdena.h"

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int i,j;
    clock_t tInicial, tFinal;
    double tempoGasto,tQuick,tInsertion,tShell,tHeap,tMerge,tSelection;
    double tQuickDes,tInsertionDes,tShellDes,tHeapDes,tMergeDes,tSelectionDes;
    double tQuickQuase,tInsertionQuase,tShellQuase,tHeapQuase,tMergeQuase,tSelectionQuase;


    
  
    int tam = solicitaTamanho();
    int *vBase = alocaVetor(tam);
    int *vetQuick = alocaVetor(tam);
    int *vetQuickDes = alocaVetor(tam);
    int *vetShell = alocaVetor(tam);
    int *vetShellDes = alocaVetor(tam);
    int *vetMerge = alocaVetor(tam);
    int *vetMergeDes = alocaVetor(tam);
    int *vetHeap = alocaVetor(tam);
    int *vetHeapDes = alocaVetor(tam);
    int *vetInserction = alocaVetor(tam);
    int *vetInserctionDes = alocaVetor(tam);
    int *vetSelection = alocaVetor(tam);
    int *vetSelectionDes = alocaVetor(tam);
    
    int *vetQuaseOrd = alocaVetor(tam);
    int *vetQuickQuase = alocaVetor(tam);
    int *vetShellQuase = alocaVetor(tam);
    int *vetMergeQuase = alocaVetor(tam);
    int *vetHeapQuase = alocaVetor(tam);
    int *vetInserctionQuase = alocaVetor(tam);
    int *vetSelectionQuase = alocaVetor(tam);
    
    printf("tamanho: %d\n",tam);
    
    
    //inserindo no vetor normal
    tInicial = clock();
    for(i = 0; i<tam;i++){
        vBase[i] = (rand()*rand());
    }
    tFinal = clock();
    tempoGasto = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    printf("Tempo para inserir no vetor: %f\n\n", tempoGasto);
    
    
    for(i=0;i<tam;i++){
        vetQuaseOrd[i] = vBase[i];
    }
    
    
    //criando os vetores desordenados
    for(i=0;i<tam;i++){
        vetQuick[i] = vBase[i];
    }
    for(i=0;i<tam;i++){
        vetShell[i] = vBase[i];
    }
    for(i=0;i<tam;i++){
        vetMerge[i] = vBase[i];
    }
    for(i=0;i<tam;i++){
        vetHeap[i] = vBase[i];
    }
    for(i=0;i<tam;i++){
        vetInserction[i] = vBase[i];
    }
    for(i=0;i<tam;i++){
        vetSelection[i] = vBase[i];
    }
    
    
    //criando vetores decrescentes
    quickSort( vBase, 0, tam -1);
    
    j=0;
    printf("\n\n");
    for(i=tam-1;i>=0;i--){
        vetQuickDes[j] = vBase[i];
        j++;
    }
    for(i=0;i<tam;i++){
        vetShellDes[i] = vetQuickDes[i];
    }
    for(i=0;i<tam;i++){
        vetMergeDes[i] = vetShellDes[i];
    }
    for(i=0;i<tam;i++){
        vetHeapDes[i] = vetMergeDes[i];
    }
    for(i=0;i<tam;i++){
        vetInserctionDes[i] = vetHeapDes[i];
    }
    
    for(i=0;i<tam;i++){
        vetSelectionDes[i] = vetInserctionDes[i];
    }
    
    
    
    //criando vetores quase ordenado
    insertionSort(vetQuaseOrd, tam);
    quaseOrdena(vetQuaseOrd, tam);
    for(i=0;i<tam;i++){
        vetQuickQuase[i] = vetQuaseOrd[i];
    }
    for(i=0;i<tam;i++){
        vetInserctionQuase[i] = vetQuickQuase[i];
    }
    for(i=0;i<tam;i++){
        vetShellQuase[i] = vetInserctionQuase[i];
    }
    for(i=0;i<tam;i++){
        vetMergeQuase[i] = vetShellQuase[i];
    }
    for(i=0;i<tam;i++){
        vetSelectionQuase[i] = vetMergeQuase[i];
    }
    for(i=0;i<tam;i++){
        vetHeapQuase[i] = vetSelectionQuase[i];
    }

   
    
    
    tInicial = clock();
    insertionSort(vetInserction, tam);
    tFinal = clock();
    tInsertion = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    
    tInicial = clock();
    quickSort( vetQuick, 0, tam -1);
    tFinal = clock();
    tQuick = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
   
    
    tInicial = clock();
    shellSort(vetShell, tam);
    tFinal = clock();
    tShell = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    mergeSort(vetMerge, 0, tam - 1);
    tFinal = clock();
    tMerge = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    heap(vetHeap,tam);
    tFinal = clock();
    tHeap = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    

    tInicial = clock();
    selection_sort(vetSelection, tam);
    tFinal = clock();
    tSelection = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    //vetores decrescentes
    tInicial = clock();
    insertionSort(vetInserctionDes, tam);
    tFinal = clock();
    tInsertionDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    tInicial = clock();
    quickSort( vetQuickDes, 0, tam -1);
    tFinal = clock();
    tQuickDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    shellSort(vetShellDes, tam);
    tFinal = clock();
    tShellDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    
    tInicial = clock();
    mergeSort(vetMergeDes, 0, tam - 1);
    tFinal = clock();
    tMergeDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    

    
    tInicial = clock();
    heap(vetHeapDes,tam);
    tFinal = clock();
    tHeapDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    
    tInicial = clock();
    selection_sort(vetSelectionDes, tam);
    tFinal = clock();
    tSelectionDes = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    //Vetores Quase Ordenados
    tInicial = clock();
    insertionSort(vetInserctionQuase, tam);
    tFinal = clock();
    tInsertionQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    tInicial = clock();
    quickSort( vetQuickQuase, 0, tam -1);
    tFinal = clock();
    tQuickQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    shellSort(vetShellQuase, tam);
    tFinal = clock();
    tShellQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    mergeSort(vetMergeQuase, 0, tam - 1);
    tFinal = clock();
    tMergeQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
   
    
    tInicial = clock();
    heap(vetHeapQuase,tam);
    tFinal = clock();
    tHeapQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    tInicial = clock();
    selection_sort(vetSelectionQuase, tam);
    tFinal = clock();
    tSelectionQuase = ((double)(tFinal-tInicial))/(((double)CLOCKS_PER_SEC)/1);
    
    
    printf("-------------------------------------------------------------\n");
    printf("| Tamanho do Conjunto: %d                                  |\n",tam);
    printf("-------------------------------------------------------------\n");
    printf("|             |Tempo Obtido pelos Algoritmos                |\n");
    printf("-------------------------------------------------------------\n");
    printf("|Algoritmo    |Vetor Desord | Vetor Decres | Vetor Quase Ord|\n");
    printf("-------------------------------------------------------------\n");
    printf("|QuickSort    |%f     |%f      |%f        |\n", tQuick,tQuickDes,tQuickQuase);
    printf("-------------------------------------------------------------\n");
    printf("|ShellSort    |%f     |%f      |%f        |\n", tShell,tShellDes,tShellQuase);
    printf("-------------------------------------------------------------\n");
    printf("|HeapSort     |%f     |%f      |%f        |\n", tHeap,tHeapDes,tHeapQuase);
    printf("-------------------------------------------------------------\n");
    printf("|MergeSort    |%f     |%f      |%f        |\n", tMerge,tMergeDes,tMergeQuase);
    printf("-------------------------------------------------------------\n");
    printf("|InsetionSort |%f     |%f      |%f        |\n", tInsertion,tInsertionDes,tInsertionQuase);
    printf("-------------------------------------------------------------\n");
    printf("|SelectionSort|%f     |%f      |%f        |\n", tSelection,tSelectionDes,tSelectionQuase);
    printf("-------------------------------------------------------------\n");



    return 0;
}
