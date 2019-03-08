/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncsOrdena.h
 * Author: martinfranzner
 *
 * Created on May 31, 2017, 9:25 PM
 */

#ifndef FUNCSORDENA_H
#define FUNCSORDENA_H

#ifdef __cplusplus
extern "C" {
#endif


int solicitaTamanho();
int* alocaVetor(int tamanho);
void quickSort( int v[], int inf, int sup);
int particao( int v[], int l, int r);
void shellSort(int *vet, int size);
void mergeSort(int v[], int l, int r);
void merge(int v[], int l, int m, int r);
void heap(int a[], int n);
void insertionSort(int v[], int tam);
void selection_sort(int v[], int tam);
void quaseOrdena(int v[], int tam);


#ifdef __cplusplus
}
#endif

#endif /* FUNCSORDENA_H */

