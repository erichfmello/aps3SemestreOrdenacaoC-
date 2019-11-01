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

void quicksort(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end - 1;
	pivo = values[(began + end) / 2];
	while (i <= j)
	{
		while (values[i] < pivo && i < end)
		{
			i++;
		}
		while (values[j] > pivo && j > began)
		{
			j--;
		}
		if (i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if (j > began)
		quicksort(values, began, j + 1);
	if (i < end)
		quicksort(values, i, end);
}

int main() {
	// variáveis para definição dos métodos de ordenação
	int tamanho1, tamanho2, tamanho3, tamanho4;
	int *bbSort1, *bbSort2, *bbSort3, *bbSort4;
	int *istSort1, *istSort2, *istSort3, *istSort4;
	int *qkSort1, *qkSort2, *qkSort3, *qkSort4;
	int i;

	// variáveis para calcular o tempo de execução
	double tempo, tempoMerger;
	double tempoBubble1, tempoBubble2, tempoBubble3, tempoBubble4;
	double tempoInsert1, tempoInsert2, tempoInsert3, tempoInsert4;
	double tempoQuick1, tempoQuick2, tempoQuick3, tempoQuick4;

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

	qkSort1 = (int*)malloc(tamanho1 * sizeof(int));
	qkSort2 = (int*)malloc(tamanho2 * sizeof(int));
	qkSort3 = (int*)malloc(tamanho3 * sizeof(int));
	qkSort4 = (int*)malloc(tamanho4 * sizeof(int));
	
	// Atribuição de valores aleatórios nos vetores
	for (i = 0; i < tamanho1; i++) {
		int valor = rand();
		
		bbSort1[i] = valor;
		istSort1[i] = valor;
		qkSort1[i] = valor;
	}

	for (i = 0; i < tamanho2; i++) {
		int valor = rand();

		bbSort2[i] = valor;
		istSort2[i] = valor;
		qkSort2[i] = valor;
	}

	for (i = 0; i < tamanho3; i++) {
		int valor = rand();

		bbSort3[i] = valor;
		istSort3[i] = valor;
		qkSort3[i] = valor;
	}

	for (i = 0; i < tamanho4; i++) {
		int valor = rand();

		bbSort4[i] = valor;
		istSort4[i] = valor;
		qkSort4[i] = valor;
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

	// QuickSort
	tempo = clock();
	quicksort(qkSort1, 0, tamanho1);
	tempoQuick1 = clock() - tempo;

	tempo = clock();
	quicksort(qkSort2, 0, tamanho2);
	tempoQuick2 = clock() - tempo;

	tempo = clock();
	quicksort(qkSort3, 0, tamanho3);
	tempoQuick3 = clock() - tempo;

	tempo = clock();
	quicksort(qkSort4, 0, tamanho4);
	tempoQuick4 = clock() - tempo;
	
	// Escreve os valores dos vetores ordenados
	printf("Ordenacao 1\n");
	for (i = 0; i < tamanho1; i++) {
		printf("%d ", bbSort1[i]);
		printf("\t%d ", istSort1[i]);
		printf("\t%d ", qkSort1[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 2\n");
	for (i = 0; i < tamanho2; i++) {
		printf("%d ", bbSort2[i]);
		printf("\t%d ", istSort2[i]);
		printf("\t%d ", qkSort2[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 3\n");
	for (i = 0; i < tamanho3; i++) {
		printf("%d ", bbSort3[i]);
		printf("\t%d ", istSort3[i]);
		printf("\t%d ", qkSort3[i]);
		printf("\n");
	}
	printf("\n");
	printf("Ordenacao 4\n");
	for (i = 0; i < tamanho4; i++) {
		printf("%d ", bbSort4[i]);
		printf("\t%d ", istSort4[i]);
		printf("\t%d ", qkSort4[i]);
		printf("\n");
	}
	printf("\n");

	// Escreve o tempo de ordenação
	printf("Tempo de ordenacao do bubbleSort 1 = %f", tempoBubble1);
	printf("\n");
	printf("Tempo de ordenacao do bubbleSort 2 = %f", tempoBubble2);
	printf("\n");
	printf("Tempo de ordenacao do bubbleSort 3 = %f", tempoBubble3);
	printf("\n");
	printf("Tempo de ordenacao do bubbleSort 4 = %f", tempoBubble4);
	printf("\n");
	printf("\n");

	printf("Tempo de ordenacao do insertSort1 = %f", tempoInsert1);
	printf("\n");
	printf("Tempo de ordenacao do insertSort2 = %f", tempoInsert2);
	printf("\n");
	printf("Tempo de ordenacao do insertSort3 = %f", tempoInsert3);
	printf("\n");
	printf("Tempo de ordenacao do insertSort4 = %f", tempoInsert4);
	printf("\n");
	printf("\n");

	printf("Tempo de ordenacao do quickSort1 = %f", tempoQuick1);
	printf("\n");
	printf("Tempo de ordenacao do quickSort2 = %f", tempoQuick2);
	printf("\n");
	printf("Tempo de ordenacao do quickSort3 = %f", tempoQuick3);
	printf("\n");
	printf("Tempo de ordenacao do quickSort4 = %f", tempoQuick4);
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
