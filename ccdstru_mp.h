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
  int R[GRID_SIZE][GRID_SIZE]; // Tracks all the grid coordinates currently owned by Player R
  int B[GRID_SIZE][GRID_SIZE]; // Tracks all the grid coordinates currently owned by Player B
  int S[GRID_SIZE][GRID_SIZE]; // Temporary tracking set used during a players turn
  int T[GRID_SIZE][GRID_SIZE]; // Tracks the spaces that have already triggered the "expand" function
  bool good;
  bool go;
  bool start;
  bool over;
  bool found;
  int val;
} GameState;

//Function Prototypes
void InitGame(GameState *state);
void RemovePos(GameState *state, int r, int c);
