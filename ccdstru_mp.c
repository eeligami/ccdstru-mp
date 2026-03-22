/*
 * Machine Project for Discrete Structures (CCDSTRU - S12)
 * Contributor 1: Mack Gabriel Baldado
 * Contributor 2: Kyle Xavier Marquez
 * Contributor 3: Keene Darshan Panganiban
 */

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

void CheckGameOver(GameState *state)
{
  int countR = 0;
  int countB = 0;
  int countF = 0;
  int i;
  int j;

  for (i = 0; i < GRID_SIZE; i++)
    {
      for (i = 0; i < GRID_SIZE; i++)
      {
        if (state->R[i][j])
        {
          countR++;  
        }
        if (state->B[i][j])
        {
          countB++;  
        }
        if (!state->R[i][j] && !state->B[i][j])
        {
          countF++;
        }
      }
    }

  if (countF = 0 || state->val >= 20 || (!state->start && ((countR > 0 && countB == 0) || (countR == 0 && countB > 0))))
  {
    start->over = 1;
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

void Expand(GameState *state, int a, int b)
{

}

void Update(GameState *state, int r, int c)
{
  state->good = 0;

  if (!state->S[r][c])
  {
    state->S[r][c] = 1;
    state->good = !state->good;
  }
  else if (!state->good && state->S[r][c] && !state->T[r][c])
  {
    state->T[r][c] = 1;
    Expand(state, r, c);
  }
}

void NextPlayerMove(GameState *state, int r, int c)
{
  if (r < o || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE)
  {
    return;
  }

  if (!state->over && state->start && state->go)
  {
    state->R[r][c] = 1;
    state->S[r][c] = 1;
    state->good = 1;
  }
  else if (!state->over && state->start && !state->go) 
  {
    state->B[r][c] = 1;
    state->S[r][c] = 1;
    state->good = 1;
  }
  else if(!state->over && !state->start && ((state->go && state->R[r][c]) || (!state->go && state->B[r][c])))
  {
    Update(state, r, c);
    state->good = 1;
  }

  int countR = 0;
  int countB = 0;
  int i;
  int j;
  
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (state->R[i][j])
      {
        countR++;
      }
      if (state->B[i][j])
      {
        countB++;
      }
    }
  }

  if (state->start && countR == 1 && countB == 1)
  {
    state->start = 0;
  }

  if (!state->over && state->good)
  {
    state->good = !state->good;
    state->go = !state->go;
    state->val++;
  }

  CheckGameOver(state);
}



int main()
{
  GameState game;
  InitGame(&game);

  printf("Game Started!\n");
  printf("Max Turns: %d\n\n", MAX_TURNS);

  while (!game.over)
    {
      int r, c;
      int currentTurn = game.val + 1;

      printf("^-^-^ Turn %d / %d ^-^-^\n", currentTurn, MAX_TURNS);

      if (game.go)
      {
        printf("Player R's move.\n");
      }
      else
      {
        printf("Player B's move.\n");
      }

      printf("Enter row and column (example: 1 1)");

      scanf("%d %d", &r, &c);

      NextPlayerMove(&game, r, c);

      printf("\n");

      
  
  return 0;
}
