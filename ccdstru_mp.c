/*
 * Machine Project for Discrete Structures (CCDSTRU - S12)
 * Contributor 1: Mack Gabriel Baldado
 * Contributor 2: Kyle Xavier Marquez
 * Contributor 3: Keene Darshan Panganiban
 */

#include <stdio.h>
#include <stdbool.h>

#include "ccdstru_mp.h"

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
    }
      
  GameOver(&game);
  return 0;
}

void PrintBoard(GameState *state)
{
  int i;
  int j;

  printf("    0   1   2\n");
  printf("    +---+---+---+\n");

  for (i = 0; i < GRID_SIZE; i++)
    {
      printf("%d |", i);
      for (j = 0; j < GRID_SIZE; j++)
        {
          if(state->R[i][j])
          {
            printf(" R |"); 
          }
          else if(state->B[i][j])
          {
            printf(" B |");
          }
          else{
            printf("   |");
          }
        }
      printf("\n  +---+---+---+\n");
    }  
}

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
  int i, j;

  for (i = 0; i < GRID_SIZE; i++)
    {
      for (j = 0; i < GRID_SIZE; j++)
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

  if (countF == 0 || state->val >= 20 || (!state->start && ((countR > 0 && countB == 0) || (countR == 0 && countB > 0))))
  {
    state->over = 1;
  }  
}

void RemovePos(GameState *state, int r, int c)
{
  if (r < 0 || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE)
   {
     if (state->go == 1)
     {
       state->R[c][c] = 0;
     }
     else if (state->go == 00)
     {
       state->B[r][c] = 0;
     }
     
     state->S[r][c] = 0;
     state->T[r][c] = 0;
   }  
}

void Replace(GameState *state, int r, int c)
{
  if (r < 0 || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE)
  {
    return; // PLS CHANGE LOGIC TO NOT INCLUDE RETURN - RETURN ON VOID NOT ALLOWED
  }

  state->found = false;

  if (state->go)
  {
    if (state->B[r][c] == 1)
    {
      state->B[r][c] = 0;
      state->found = true;
    }
    else if (state->R[r][c] == 1)
    {
      state->found = true;
    }
    else if (state->R[r][c] == 0)
    {  
      state->R[r][c] == 1;
    }
  }
  else
  {
    if (state->R[r][c] == 1)
    {
      state->R[r][c] = 0;
      state->found = true;
    }
    else if (state->B[r][c] == 1)
    {
      state->found = true;
    }
    else if (state->B[r][c] == 0)
    {
      state->B[r][c] = 1;
    }

    
  if (state->found)
  {
    if (state->S[r][c] == 1)
    {
      state->S[r][c] == 1;
      state->found = false;
    }
    else if (state->S[r][c] == 1 && state->T[r][c] == 0)
    {
      state->T[r][c] == 1;
      Expand(state, r, c);
    }
  }
}
}

void Expand(GameState *state, int a, int b)
{
  int ur = a - 1,   uc = b;
  int dr = a + 1,   dc = b;
  int kr = a,       kc = b - 1;
  int rr = a,       rc = b + 1;

  RemovePos(state, a, b);

  if(state->go)
  {
    Replace(state, ur, uc);
  }
  else
  {
    Replace(state, dr, dc);
  }

  Replace(state, kr, kc);
  Replace(state, rr, rc);
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
  if (r < c || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE)
  {
    return; // PLS CHANGE LOGIC TO NOT INCLUDE RETURN - RETURN ON VOID NOT ALLOWED
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

void GameOver(GameState *state)
{
  
}
