#ifndef __ConmmentConvert_H__
#define __ConmmentConvert_H__

#include<stdio.h>
#include<stdlib.h>
//#include<io.h>

typedef enum State
{
	NUL_State,
	C_State,
	CPP_State,
	END_State
}State;

void CommentConvert(FILE *PRead, FILE *PWrite);         //ע��ת��

void DO_NUL_State(FILE *PRead, FILE *PWrite, State *PState);    //��״ִ̬�в���

void DO_C_State(FILE *PRead, FILE *PWrite, State *PState);     //cע��״ִ̬�в��� /*

void DO_CPP_State(FILE *PRead, FILE *PWrite, State *PState);   //c++״ִ̬�в���  //

#endif // !__ConmmentConvert_H__

