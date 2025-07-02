#include "5leha 3la allah.h"
// Undo functionality using a stack
stackptr top = NULL;

// Push a node onto the stack
void push(nodptr n) {
    stackNode* s = (stackNode*) malloc(sizeof(stackNode));
    if (s == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    s->next = NULL;
    s->data = n;
    if(top == NULL) {
        top = s;
    }else {
        s->next = top;
        top = s;
    }
}

// Pop a node from the stack and return the new top node
nodptr pop_and_peek() {
    if(top == NULL) {
         return NULL;
    }
    stackptr temp = top;
    nodptr temp2 = top->data;
    top = top->next;
    free(temp);
    return temp2;
}

// Undo the last move, returning to the previous node in the tree
nodptr Undo(){
    if (top == NULL) {
        printf("No more actions to undo.\n");
        return root;
    }
    if (top->data == root) {
        printf("You are already at the root. Cannot undo further.\n");
        return root;
    }
    return pop_and_peek();
}
//============================
// Functionality to create a custom guessing game

// Helper function to build the body of the decision tree recursively
void build_tree_body(nodptr root){
    if (root == NULL){
        return;
    }
    root->yes = (nodptr)malloc(sizeof(node));
    root->no = (nodptr)malloc(sizeof(node));

    if (root->yes == NULL || root->no == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter node for YES branch of '%s': ", root->q);
    scanf(" %[^\n]%*c", root->yes->q);
    if (strcmp(root->yes->q, "-1") == 0){
        free(root->yes);
        root->yes = NULL;
    }
    else{
        build_tree_body(root->yes);
    }
    printf("Enter node for NO branch of '%s': ", root->q);
    scanf(" %[^\n]%*c", root->no->q);

    if (strcmp(root->no->q, "-1") == 0){
        free(root->no);
        root->no = NULL;
    }
    else{
        build_tree_body(root->no);
    }
}

// Creates the root and calls build_tree_body to construct the tree
nodptr build_tree(){
    nodptr create_root = (nodptr)malloc(sizeof(node));
    if (create_root == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter root q : ");
    scanf(" %[^\n]%*c", create_root->q);
    build_tree_body(create_root);
    return create_root;
}

//===============TIMER
// Calculates and prints the duration of a turn
time_t start_time, end_time;
void time_of_turn() {
    end_time = time(NULL);
    double mode_time = difftime(end_time, start_time);
    printf("---------------------------------------------\n\n");
    printf("The mode lasted for %.2f seconds.\n", mode_time);
    printf("---------------------------------------------\n");
}
//==============print tree
// Recursively prints the decision tree with indentation for levels
void print_tree(nodptr n, int level) {
    if(n==NULL) return;
    for(int i = 0;i<level;i++)printf("  ");
    printf("%s\n", n->q);//root
    print_tree(n->yes, level+ 1);//left
    print_tree(n->no, level+ 1);//right
}

//====================multi
Player* players; //to hold all players data
int num_players;//num of players
//this for multi_mode
void multi() {
    printf("-------------------------------------------------\n");
    printf("Rules:\nThe Winner is  who defeat the game wins\none point for each victory\n");
    printf("----------------------------------------------\n");
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    players = (Player*) malloc(num_players * sizeof(Player));
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    for (int i = 0; i < num_players; i++) {
        printf("Player[%d]:%s ", i+1,players[i].name);
        for (int round=0; round < num_players+1; round++){
            decision_multi(root,i,round);
        }
    }
    display_scores();
}

//function to display the scores
void display_scores() {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    int max_score = 0;
    int winners[num_players];
    int winner_count = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].score >= max_score) {
            max_score = players[i].score;
        }
    }
    for (int i = 0; i < num_players; i++) {
        if (players[i].score == max_score) {
            winners[winner_count] = i;  // Store index of the player
            winner_count++;
        }
    }
    if (winner_count > 1) {
        printf("---------------------------------------------\n");
        printf("Deuce! They have the highest score of %d:\n", max_score);
        for (int i = 0; i < winner_count; i++) {
            printf(" %s\n", players[winners[i]].name);
        }
    }
    else {
        printf("---------------------------------------------\n");
        printf("\nThe winner is %s with %d points!\n\n", players[winners[0]].name, max_score);
        printf("---------------------------------------------\n");
    }
}
//new func for decision for multi mode
void decision_multi(nodptr n,int player_num,int round) {
    system("cls");
    printf("---------------------------------------------\n");
    printf("Rules of input:\n\n\"yes\" for YES\n\"no\" for NO \n\n");
    printf("---------------------------------------------\n\n");
    printf("player[%d]: %s \nRound %d\n",player_num+1,players[player_num].name,round+1);
    printf("---------------------------------------------\n");
    if (n== NULL) {
        printf("Node is NULL. Returning.\n");
        return;
    }
    char ans[10];
    if (n->yes == NULL && n->no == NULL) {
        printf("Guess is %s.\n",n->q);
        printf("Is The guess correct?\n");
        fflush(stdin);
        scanf("%s",ans);
        if(!strcmp(ans,"yes")){
            return;
        }
        if(!strcmp(ans,"no")){
            players[player_num].score++;
            printf("point++");
            return;
        }
        else {
            printf("invalid input\n");
            decision_multi(n,player_num,round);
            return;
        }
    }
    // Traverse the tree based on user input.
    printf("%s",n->q);
    scanf("%s",ans);
    if(!strcmp(ans,"yes")) {
        decision_multi(n->yes,player_num,round);
    }
    else if (!strcmp(ans,"no")) {
            decision_multi(n->no,player_num,round);
    }
    else {
        printf("invalid input, retry with yes / no\n");
        decision_multi(n,player_num,round);
    }
}