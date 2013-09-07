/*
 ============================================================================
 Name        : L001HelloC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MATH_PI 3.141592653
#define MAX (A,B) A>B?A:B


typedef struct{
	int age;
	char* name;
}People;

typedef int PLTER_INT_32;
typedef long int PLTER_INT_64;

void sayHi(){
//	People p;
//	People * p1 = &p;
//	People * p = malloc(sizeof(People));
//
//	int a = 9;
	printf("Hi,C");
}


int main(void) {

//	struct People p;
//	p.age = 18;
//	p.name="ZhangSan";
//
//	printf("p:Name:%s,Age:%d\n",p.name,p.age);
//
//	struct People p1 = p;
//	p1.age = 20;
//
//	printf("[p:Name:%s,Age:%d][p1:Name:%s,Age:%d]",p.name,p.age,p1.name,p1.age);

//	struct People * p = malloc(sizeof(struct People));
//	p->age = 18;
//	p->name = "ZhangSan";
//
//	struct People * p1 = p;
//	p1->age = 20;
//	printf("Name:%s,Age:%d",p->name,p->age);

//	People * p = malloc(sizeof(People));
//	p->age = 90;
//
//	int a = MATH_PI;
//
//	free(p);


	{
		int a = 9;
		int b = 10;
	}

	sayHi();

	return EXIT_SUCCESS;
}
