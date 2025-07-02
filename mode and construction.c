#include "5leha 3la allah.h"

// Global variables Definition

string path;
nodptr root = NULL;
//Rules of create game from scratch
string info_create_game="Info for entering guesses and questions\n Is they a boy?\nprogrammer?\nEng.Gomaa \n-1\n -1 \nSeif\n-1\n-1\nIs they Dr?\nDr.Fatmaa\n-1\n-1\nEng.Shaimaa\n-1\n-1\n";

// Returns the path to a specific game file based on the user's choice
string path_choose(int number_selection) {
    string course_guess="D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\course_guess.txt";
    string country_guess="D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\country_guess.txt";
    string club_guess="D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\club_guess.txt";
    string car_guess="D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\car_guess.txt";
    string programming_guess="D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\programming_guess.txt";
    string build_new_tree = "D:\\programming\\Uni courses\\2nd year\\Advanced prog\\23-101279\\Game guess final\\new_tree.txt";

    // Select path based on user input
    switch (number_selection) {
         case 1:
             return course_guess;
         case 2:
             return country_guess;
         case 3:
            return programming_guess;
         case 4:
             return club_guess;
         case 5:
            return car_guess;
         case 6:
            return build_new_tree;
         default:
             return NULL;
    }
}

// Allows the user to choose the mode and constructs the corresponding decision tree
void mode_choose() {
    system("cls");// Clear the console screen
    int number;
        system("cls");
        printf("---------------------------------------------\n");
        printf("Select the next game thematic\n");
        printf("---------------------------------------------\n");
        printf("1.Course\n2.Country\n3.Programming language\n4.Foot Club\n5.Car\n6.Create ur Guess game\n");
        scanf("%d",&number);
        system("cls");
        switch (number){
            case 1:
                path=path_choose(1);
                root=construction();
            break;
            case 2:
                path=path_choose(2);
                root=construction();
            break;
            case 3:
                path=path_choose(3);
                root=construction();
            break;
            case 4:
                path=path_choose(4);
                root=construction();
            break;
            case 5:
                path=path_choose(5);
                root=construction();
            break;
            case 6:
                printf("%s",info_create_game);
                path=path_choose(6);
                root = build_tree();
            break;
            default:
                printf("Wrong choice\n");
        }
    cour(root);
        system("cls");
    }

// Creates a new node for the decision tree
nodptr newnode(const string q) {
    nodptr n = (nodptr) malloc(sizeof(node));
    if (n != NULL) {
        strcpy(n->q,q);
        n->yes = NULL;
        n->no = NULL;
        return n;
    }
    else {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// Reads a single question/guess string from the file
string read_tree(FILE* file_temp) {
    string q = (string) malloc(256);
    fscanf(file_temp,"%[^\n]%*c", q);//newline not included
    return q;
}
// Recursively constructs the decision tree from a file
void construct_tree(nodptr *n,FILE *f) {
    string q =read_tree(f);
    if (q == NULL) {
        printf("File could not be opened\n");
        return;
    }
    if(!strcmp(q,"-1")) {
        free(q);
        *n=NULL;
        return;
    }
    //preorder traversal
    *n = newnode(q);
    free(q);
    construct_tree(&(*n)->yes,f);// Construct the "yes" branch
    construct_tree(&(*n)->no,f);// Construct the "no" branch
}

// Initializes the decision tree by reading from the selected file
nodptr construction() {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("File does not exist\n");
        exit(0);
    }
    nodptr n;
    construct_tree(&n,file);
    fclose(file);
    return n;
}

// Writes a single question/guess string to the file
void print_file(FILE* f,const string q) {
    fprintf(f,"%s\n",q);
}

// Updates the decision tree file based on the current tree structure
void update_tree_file(FILE* file,nodptr n) {
    print_file(file,n->q);
    if (n->yes == NULL&&n->no == NULL) {
        print_file(file,"-1");
        print_file(file,"-1");
        return;
    }
    update_tree_file(file,n->yes);
    update_tree_file(file,n->no);
}



