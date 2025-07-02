#include "5leha 3la allah.h"
string arr[50];
int arr_c=0;
// Displays the start menu and handles user input for the  choice.
int start_menu() {
    int num;
    printf("---------------------------------------------\n");
    printf("Hello! Welcome to our guess game\n");
    printf("---------------------------------------------\n");
    printf("Enter a number to \n");
    printf("0 quit\n");
    printf("1 play solo\n");
    printf("2 play multi mode\n");
    scanf("%d",&num);

    if(num == 1|| num == 0|| num == 2) {
        return num;
    }
    else {
        printf("Invalid input Please enter 0 or 1.\n");
        fflush(stdin);
        return start_menu();
    }
}
// Handles the game logic based on the selected mode.

void run() {
    switch(start_menu()) {
        case 0:
            quit();
            break;
        case 1:
            mode_choose();
            start_time = time(NULL);
            decsion(root);
            restart();
            break;
        case 2:
            mode_choose();
            start_time = time(NULL);
            multi();
            restart();
            break;
        default:run();
    }
}

// a menu for restarting or quitting the game and performs the corresponding actions.
void restart() {
    switch (quit_menu()) {
        case 0:
            quit();
            break;
        case 1:
            system("cls");
            print_tree(root,0);
            restart();
            break;
        case 2:
            start_time = time(NULL);
            decsion(root);
            restart();
            break;
        case 3:
            mode_choose();
            start_time = time(NULL);
            decsion(root);
            restart();
        case 4:
            mode_choose();
            start_time = time(NULL);
            multi();
            restart();
        break;
        default:
            restart();
    }
}

// Displays the Quit menu and handles user input for the choice.
int quit_menu() {
    time_of_turn();
    int num;
    printf("---------------------------------------------\n");
    printf("Enter a number to \n");
    printf("0 quit\n1 print tree\n2 Restart same mode in solo \n3 restart with solo \n4 restart with multi\n");
    scanf("%d",&num);
    if(num == 2||num == 0||num==1||num==3||num==4) {
        return num;
    }
    else {
        printf("Invalid input.\n");
        fflush(stdin);
        return quit_menu();
    }
}

// Frees allocated memory and terminates the program.
void quit() {
    free_tree(root);
    exit(EXIT_SUCCESS);
}


// Handles decision-making during the guessing game and updates the tree.
void decsion(nodptr n) {
    // Clear the screen and display rules for input.
    system("cls");
    if (n== NULL) {
        printf("Node is NULL. Returning.\n");
        return;
    }
    printf("---------------------------------------------\n");
    printf("Make a guess in ur mind and we will know it\n");
    printf("---------------------------------------------\n");
    printf("Rules of input:\n\n\"yes\" for YES\n\"no\" for NO \n\"undo\" for return Back\n\nLet's play\n\n");
    printf("---------------------------------------------\n");
    char ans[10];
    if (n->yes == NULL && n->no == NULL) {
        printf("Guess is %s.\n",n->q);
        printf("Is The guess correct?\n");
        fflush(stdin);// clear of the buffer
        scanf("%s",ans);
        if(!strcmp(ans,"yes")){
            printf("Got it!\n");
            return;
        }
        if(!strcmp(ans,"no")){
            updatetree(&n);
            return;
        }
        if(!strcmp(ans,"undo")){
            decsion(Undo());
            return;
        }
        else {
            printf("invalid input\n");
            decsion(n);
            return;
        }
    }
    // Traverse the tree based on user input.
    printf("%s : ",n->q);
    scanf("%s",ans);
    if(!strcmp(ans,"yes")) {
        push(n);
        decsion(n->yes);
    }
    else if (!strcmp(ans,"no")) {
        push(n);
        decsion(n->no);
    }
    else if(!strcmp(ans,"undo")){
        decsion(Undo());
    }
    else {
        printf("invalid input, retry with yes / no\n");
        decsion(n);
    }
}

// Updates the decision tree with a new question and answers.
void updatetree(nodptr* n){
    char question[100];
    char course_yes[100];
    char course_no[100];
    printf("---------------------------------------------\n");
    printf("Please enter a question to distinguish this Guess:\n");
    printf("---------------------------------------------\n");

    scanf(" %[^\n]%*c", question);

    printf("What is the Answer if yes?\n");
    scanf(" %[^\n]%*c", course_yes);

    printf("What is the Answer if no?\n");
    scanf(" %[^\n]%*c", course_no);
    for(int i=0;i<arr_c;i++) {
        if(strcmp(arr[i],course_yes)==0) {
            printf("the course you entered to be yes for the question is already exists\n");
            return;
        }
    }
    strcpy((*n)->q, question);
    (*n)->yes = newnode(course_yes);
    (*n)->no = newnode(course_no);
    save_changes();
}



// Saves the updated tree structure to a file for future turns.
void save_changes() {
    printf("Do you want to save changes for next times ? yes/no \n");
    fflush(stdin);
    char ans[10];
    scanf("%s",ans);
    if(strcmp(ans,"yes")==0) {
        FILE *f = fopen(path, "w");
        if(f == NULL) {
            printf("File could not be opened\n");
        }
        else{
            update_tree_file(f,root);
            printf("The changes were saved\n");
            fclose(f);
        }
    }
}

//free allocate the memory in order traveral
void free_tree(nodptr n_free) {
    if (n_free == NULL) {return;}
    free_tree(n_free->yes);
    free_tree(n_free->no);
    free(n_free);
}


void cour(nodptr ll){
    if(ll->yes == NULL&&ll->no==NULL) {
        arr[arr_c] = ll->q;
        arr_c++;
        return;
    }
    cour(ll->yes);
    cour(ll->no);
}