#ifndef INC_5LEHA_3LA_ALLAH_H
#define INC_5LEHA_3LA_ALLAH_H
// Standard libraries included for various functionalities
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//=============================
// Variable and Typedef Declarations
//=============================

// Definition of a tree node structure
typedef struct node {
    char q[256];
    struct node *no;
    struct node *yes;
}node;
typedef node* nodptr;

// Definition of a stack node structure (used for undo functionality)
typedef struct stackNode {
    nodptr data;
    struct stackNode * next;
}stackNode;

typedef stackNode* stackptr;
typedef char * string;// Alias for a string

//=============================
// Global Variables
//=============================

extern stackptr top ;  // Stack for undo functionality
extern string path; // File path for saving/loading game data
extern nodptr root;// Root of the decision tree
extern time_t start_time, end_time;// Timer variables for tracking durations

//=============================
// Mode Selection Functions
//=============================
// Functions for choosing the game mode and setting paths
extern void mode_choose();
extern string path_choose(int num);

//=============================
// Tree Construction Functions
//=============================
// Functions for constructing and updating the decision tree

extern nodptr newnode(const string q); // Creates a new tree node
extern void print_file(FILE* f,const string q) ; // Prints a string to a file
extern void update_tree_file(FILE* file,nodptr n);  // Updates the tree structure in a file
extern string read_tree(FILE* file_temp);// Reads a tree node from a file
extern void construct_tree(nodptr *n,FILE *f); // Recursively constructs a tree from a file
extern nodptr construction(); // Initializes the construction process

//=============================
// Game Play Functions
//=============================
// Functions for running the game logic and user interactions

extern void decsion(nodptr n); // Handles the game decision-making process
extern void quit();// Ends the game session
extern int start_menu();// Displays the start menu
extern int quit_menu(); // Displays the quit menu
extern void restart();// Restarts the game
extern void run(); // Main game loop

//=============================
// Learning Functions
//=============================

// Functions for learning new data and saving changes
extern void updatetree(nodptr* n);// Updates the tree with new information
extern void save_changes();// Saves changes to the tree
//=============================
// Memory Management Functions
//=============================

// Functions for freeing allocated memory
extern void free_tree(nodptr n_free);// Frees the entire tree structure

//=============================
// Tree Display Function
//=============================
// Recursively prints the tree structure to the terminal
extern void print_tree(nodptr n, int level);

//=============================
// Extra Features
//=============================

// Functions for creating a custom guessing game
extern nodptr build_tree(); // Builds a new decision tree from scratch
extern void build_tree_body(nodptr root);// Helper for recursive tree building

//=============================
// Timer Functions
//=============================

// Tracks and displays the duration of a game turn
extern void time_of_turn();
//=============================
// Undo Feature
//=============================

// Functions for undoing the last action using a stack
extern nodptr Undo(); // Undoes the last move
extern void push(nodptr n);  // Pushes a node onto the stack
extern nodptr pop_and_peek();// Pops a node and returns the next top node
//=============MULTI MODE
typedef struct {
    char name[50];
    int score;
} Player;
//global variables to modify during the game
extern Player* players; //to hold all players data
extern int num_players;
extern void multi();
extern void display_scores();
extern void decision_multi(nodptr n, int player_num,int round);


extern void cour(nodptr ll);
#endif //INC_5LEHA_3LA_ALLAH_H
