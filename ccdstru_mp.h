#include <stdio.h>
#include <string.h>

#define MAX_TURNS 20
#define GRID_SIZE 3

/* Function prototypes (uncomment if function is fully implemented)
 * void Remove(); 
 * void Replace(); 
 * void Expand(); 
 * void Update(); 
 * void NextPlayerMove(); 
 * int GameOver(); // boolean function
 */

typedef struct{
  int R[GRID_SIZE][GRID_SIZE];
  int B[GRID_SIZE][GRID_SIZE];
  int S[GRID_SIZE][GRID_SIZE];
  int T[GRID_SIZE][GRID_SIZE];
/*
R = Tracks all the grid coordinates currently owned by Player R
B = Tracks all the grid coordinates currently owned by Player B
S = Temporary tracking set used during a players turn
T = Tracks the spaces that have already triggered the "expend" function


*/

  int good;
  int go;
  int found;
  int over;
  int val;
}GameState;

//Function Prototypes
void InitGame(GameState *state);
void RemovePos(GameState *state, int r, int c);
