/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "FuncsOrdena.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int solicitaTamanho(){
    int tamanho;
    printf("Insira em numero inteiro o tamanho do vetor: \n");
    scanf("%d", &tamanho);
    return tamanho;
}
int* alocaVetor(int tamanho){
    int *v = (int*)malloc(tamanho*(sizeof(int)));
    if(v == NULL){
      printf("Memoria insuficiente! \n");
        return -1;
    }
    return v;
}

void quickSort( int v[], int inf, int sup)
{
   int j;

   if( inf < sup )
   {
   	// divide and conquer
        j = particao( v, inf, sup);
       quickSort( v, inf, j-1);
       quickSort( v, j+1, sup);
   }
	
}
int particao( int v[], int l, int r) {
   int pivot, i, j, t;
   pivot = v[l];
   i = l; j = r+1;
		
   while( 1){
   	do ++i; while( v[i] <= pivot && i <= r );
   	do --j; while( v[j] > pivot );
   	if( i >= j ) break;
   	t = v[i]; v[i] = v[j]; v[j] = t;
   }
   t = v[l]; v[l] = v[j]; v[j] = t;
   return j;
}

void shellSort(int vet[], int size) {
    int i , j , value;
    int g = 1;
    while(g < size) {
        g = 3*g+1;
    }
    while ( g > 1) {
        g /= 3;
        for(i = g; i < size; i++) {
            value = vet[i];
            j = i - g;
            while (j >= 0 && value < vet[j]) {
                vet [j + g] = vet[j];
                j -= g;
            }
            vet [j + g] = value;
        }
    }
}





void merge(int v[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = v[m + 1+ j];
    }
   
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int v[], int l, int r){
    if (l < r)
    {
 
        int m = l+(r-l)/2;
 
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
 
        merge(v, l, m, r);
    }
}




void heap(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void insertionSort(int v[], int tam){
	int i, chave, j;
	for (i = 1; i < tam; i++){
		chave = v[i];
		j = i-1;
		
		while (j >= 0 && v[j] > chave){
			v[j+1] = v[j];
			j = j-1;
		}
		v[j+1] = chave;
   }
}

void selection_sort(int v[], int tam){
	int i, j, min, aux;
	for (i = 0; i < (tam-1); i++){
	min = i;
	for (j = (i+1); j < tam; j++){
		if(v[j] < v[min])
			min = j;
	}
	if (i != min){
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
	}
}

void quaseOrdena(int v[], int tam){
    srand(time(NULL));
    int i;
    int r;
    int d;
    int aux;
    int size = tam;
    if(size >= 100){
        size = tam*0.1;
    }
    else if(size < 100){
        size = tam/10;
    }
    for(i=0;i<size;i++){
        r = rand()%tam;
        d = rand()%tam;
        aux = v[r];
        v[r] = v[d];
        v[d]= aux;
    }
}
