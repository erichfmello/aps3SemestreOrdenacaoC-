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
	// variáveis para definição dos métodos de ordenação
	int tamanho1, tamanho2, tamanho3, tamanho4;
	int *bbSort1, *bbSort2, *bbSort3, *bbSort4;
	int *istSort1, *istSort2, *istSort3, *istSort4;
	int *mergeSort;
	int i;

	// variáveis para calcular o tempo de execução
	double tempo, tempoMerger;
	double tempoBubble1, tempoBubble2, tempoBubble3, tempoBubble4;
	double tempoInsert1, tempoInsert2, tempoInsert3, tempoInsert4;

	tamanho1 = 1000;
	tamanho2 = 2000;
	tamanho3 = 3000;
	tamanho4 = 4000;

	bbSort1 = (int*)malloc(tamanho1 * sizeof(int));
	bbSort2 = (int*)malloc(tamanho2 * sizeof(int));
	bbSort3 = (int*)malloc(tamanho3 * sizeof(int));
	bbSort4 = (int*)malloc(tamanho4 * sizeof(int));
	
	
	istSort1 = (int*)malloc(tamanho1 * sizeof(int));
	istSort2 = (int*)malloc(tamanho2 * sizeof(int));
	istSort3 = (int*)malloc(tamanho3 * sizeof(int));
	istSort4 = (int*)malloc(tamanho4 * sizeof(int));

	mergeSort = (int*)malloc(tamanho1 * sizeof(int));
	
	// Atribuição de valores aleatórios nos vetores
	for (i = 0; i < tamanho1; i++) {
		int valor = rand();
		
		bbSort1[i] = valor;
		istSort1[i] = valor;

		mergeSort[i] = valor;
	}

	for (i = 0; i < tamanho2; i++) {
		int valor = rand();
		
		if (i <= tamanho1) {
			bbSort2[i] = bbSort1[i];
			istSort2[i] = istSort1[i];
		}
		else {
			bbSort2[i] = valor;
			istSort2[i] = valor;
		}
	}

	for (i = 0; i < tamanho3; i++) {
		int valor = rand();

		if (i <= tamanho2) {
			bbSort3[i] = bbSort2[i];
			istSort3[i] = istSort2[i];
		}
		else {
			bbSort3[i] = valor;
			istSort3[i] = valor;
		}
	}

	for (i = 0; i < tamanho4; i++) {
		int valor = rand();

		if (i <= tamanho3) {
			bbSort4[i] = bbSort3[i];
			istSort4[i] = istSort3[i];
		}
		else {
			bbSort4[i] = valor;
			istSort4[i] = valor;
		}
	}
	
	// Calcular o tempo de execução da ordenação
	// BubbleSort
	tempo = clock();
	bubbleSort(bbSort1, tamanho1 - 1);
	tempoBubble1 = clock() - tempo;

	tempo = clock();
	bubbleSort(bbSort2, tamanho2 - 1);	
	tempoBubble2 = clock() - tempo;

	tempo = clock();
	bubbleSort(bbSort3, tamanho3 - 1);
	tempoBubble3 = clock() - tempo;

	tempo = clock();
	bubbleSort(bbSort4, tamanho4 - 1);
	tempoBubble4 = clock() - tempo;

	// InsertSort
	tempo = clock();
	insertionSort(istSort1, tamanho1);
	tempoInsert1 = clock() - tempo;

	tempo = clock();
	insertionSort(istSort2, tamanho2);
	tempoInsert2 = clock() - tempo;

	tempo = clock();
	insertionSort(istSort3, tamanho3);
	tempoInsert3 = clock() - tempo;

	tempo = clock();
	insertionSort(istSort4, tamanho4);
	tempoInsert4 = clock() - tempo;
	
	printf("Ordenacao 1\n");
	for (i = 0; i < tamanho1; i++) {
		printf("%d ", bbSort1[i]);
		printf("\t%d ", istSort1[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 2\n");
	for (i = 0; i < tamanho2; i++) {
		printf("%d ", bbSort2[i]);
		printf("\t%d ", istSort2[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 3\n");
	for (i = 0; i < tamanho3; i++) {
		printf("%d ", bbSort3[i]);
		printf("\t%d ", istSort3[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 4\n");
	for (i = 0; i < tamanho4; i++) {
		printf("%d ", bbSort4[i]);
		printf("\t%d ", istSort4[i]);
		printf("\n");
	}

	printf("Tempo de ordenação do bubbleSort 1 = %f", tempoBubble1);
	printf("\n");
	printf("Tempo de ordenação do bubbleSort 2 = %f", tempoBubble2);
	printf("\n");
	printf("Tempo de ordenação do bubbleSort 3 = %f", tempoBubble3);
	printf("\n");
	printf("Tempo de ordenação do bubbleSort 4 = %f", tempoBubble4);
	printf("\n");
	printf("\n");

	printf("Tempo de ordenação do insertSort1 = %f", tempoInsert1);
	printf("\n");
	printf("Tempo de ordenação do insertSort2 = %f", tempoInsert2);
	printf("\n");
	printf("Tempo de ordenação do insertSort3 = %f", tempoInsert3);
	printf("\n");
	printf("Tempo de ordenação do insertSort4 = %f", tempoInsert4);
	printf("\n");
	
	
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
