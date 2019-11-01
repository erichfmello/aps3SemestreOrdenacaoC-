// Ordenacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void No(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

double bubbleSort(int *v, int n) {
	if (n < 1) {
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		if (v[i] > v[i + 1]) {
			No(&v[i], &v[i + 1]);
		}
	}
	
	bubbleSort(v, n - 1);
}

void insertionSort(int arr[], int n) {
	int i, key, j;
	
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void merge(int *saida, int *auxiliar, int inicio, int meio, int fim) {
	int i, j, k;
	i = inicio;
	j = meio + 1;
	k = inicio;

	while (i <= meio && j <= fim) {
		if (auxiliar[i] < auxiliar[j]) {
			saida[k] = auxiliar[i];
			i++;
		} else {
			saida[k] = auxiliar[j];
			j++;
		}

		k++;
	}

	while (i <= meio) {
		saida[k] = auxiliar[i];
		i++;
		k++;
	}

	while (j <= fim) {
		saida[k] = auxiliar[j];
		j++;
		k++;
	}
	
	for (int p = inicio; p <= fim; p++)
		auxiliar[p] = saida[p];
}


void mergeSort(int *saida, int *auxiliar, int inicio, int fim) {

	if (inicio < fim) {
		int meio = (inicio + fim) / 2;

		mergeSort(saida, auxiliar, inicio, meio);
		mergeSort(saida, auxiliar, meio + 1, fim);
		merge(saida, auxiliar, inicio, meio, fim);
	}
}



int main() {
	int tamanho, i, *bbSort, *istSort, *mergeSort;
	double tempo, tempoBubble, tempoInsert, tempoMerger;

	tamanho = 1000;

	bbSort = (int*)malloc(tamanho * sizeof(int));
	istSort = (int*)malloc(tamanho * sizeof(int));
	mergeSort = (int*)malloc(tamanho * sizeof(int));
	
	for (i = 0; i < tamanho; i++) {
		int valor = rand();
		bbSort[i] = valor;
		istSort[i] = valor;
		mergeSort[i] = valor;
	}
	
	tempo = clock();
	tempoBubble = bubbleSort(bbSort, tamanho - 1);
	tempoBubble = clock() - tempo;
	
	tempo = clock();
	insertionSort(istSort, tamanho);
	tempoInsert = clock() - tempo;
	
	
	for (i = 0; i < tamanho; i++) {
		printf("%d ", bbSort[i]);
		printf("\t");
		printf("%d ", istSort[i]);
		printf("\n");
	}
	printf("%f", tempoBubble);
	printf("\n%f", tempoInsert);
	//printf("\n%d", tempoBubble);
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
