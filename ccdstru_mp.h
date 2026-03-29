#define MAX_TURNS 20
#define GRID_SIZE 3

typedef struct{
  int R[GRID_SIZE][GRID_SIZE]; 
  int B[GRID_SIZE][GRID_SIZE];
  int S[GRID_SIZE][GRID_SIZE]; 
  int T[GRID_SIZE][GRID_SIZE];
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
void Replace(GameState *state, int r, int c);
void CheckGameOver(GameState *state);
void Update(GameState *state, int r, int c);
void Expand(GameState *state, int a, int b);
void NextPlayerMove(GameState *state, int r, int c);
void PrintBoard(GameState *state);
void GameOver(GameState *state);