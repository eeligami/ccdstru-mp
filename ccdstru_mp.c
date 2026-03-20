#include <stdio.h>
#include <stdbool.h>

#include "ccdstru_mp.h"

//System Intialization
void InitGame(GameState *state)
{
  state->good = false;
  state->go = true;
  state->start = true;
  state->found = false;
  state->over = false;
  state->val = 0;

  int i;
  int j;
  for (i = 0; i < GRID_SIZE; i++){
    for (j = 0; j < GRID_SIZE; j++){
      state->R[i][j] = 0; //R = empty
      state->B[i][j] = 0; //B = empty
      state->S[i][j] = 0; //S = empty
      state->T[i][j] = 0; //T = empty
    }
  }
}

void RemovePos(GameState *state, int r, int c)
{
    if (r < 0 || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE)
    {
    return;
    }
  
    if (state->go)
    {
      state->R[r][c] = 0;
    }
    else
    {
      state->B[r][c] = 0;
    }

    state->S[r][c] = 0;
    state->T[r][c] = 0;
    
  }
  
}

int main()
{
  int board[GRID_SIZE][GRID_SIZE];
  
  return 0;
}
