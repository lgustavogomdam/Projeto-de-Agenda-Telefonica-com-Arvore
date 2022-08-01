#ifndef libArvore_h
#define libArvore_h

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Declaração da Struct

typedef struct TipoNo{
	char nome[50];
	char numero [11];
	struct TipoNo *esq, *dir;
}TNo;

//Declaração de Métodos

void inicializarArvore(TNo **r);

TNo *consultarPorNome(TNo *r, char nome[]);

void inserirNo(TNo **r, TNo *novo);

int inserirNaArvore(TNo **r, char nome[], char num[]);

TNo *encontrarMaior(TNo *r);

int removerDaArvore(TNo **r, char nome[]);

void percorrerEmOrdem(TNo *r);

TNo *consultarPorNumero(TNo *r, char num[]);

void exibirArvore(TNo *r);

#endif