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
  char board[3][3];
  int K[3][3]; //1 or 0, tracks the squares that was touched during the current turn 
  int D[3][3]; //1 or 0, tracks the squares that have already "expanded" or exploded

  int good;
  int go;
  int found;
  int over;
  int val;
}GameState;
