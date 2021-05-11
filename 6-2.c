#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
static char buffer;
int bufsize = 0;

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

char get_ch()
{

    if (bufsize == 0)
        return getchar();
    --bufsize;
    return buffer;
}

void unget_ch(char w)
{
    buffer = w;
    bufsize = 1;
}

int get_word(char *word)
{
    int c;
    char *p = word;
    while (isspace(c = get_ch()));
    if (c != EOF)
        *p++ = c;
    if (!isalpha(c)) {
        *p = '\0';
        return c;
    }
    for (int nwords = 0; nwords < MAXWORD; ++nwords, p++) {
        if (!isalnum(*p = get_ch())) {
            unget_ch(*p);
            break;
        }
    }
    *p = '\0';
    return word[0];
}

struct tnode *talloc()
{
    return ((struct tnode *) malloc(sizeof(struct tnode)));
}

char *str_dup(char *w)
{
    char *p = (char *) malloc(strlen(w) + 1);
    if (p != NULL)
        strcpy(p, w);
    return p;
}

int check_for_similar_chars(char *w1, char *w2, int sc)
{
    int counter = 0;
    while (*w1 != '\0' && *w2 != '\0' && *w1++ == *w2++ && ++counter)
        if (counter >= sc)
            return 1;
    return (counter >= sc);
}

struct tnode *addtree(struct tnode *p, char *w, int samechars, int prev_p_match)
{
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = str_dup(w);
        p->match = prev_p_match;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->match = 1;
    }
    else if (cond < 0) {
        if (check_for_similar_chars(p->word, w, samechars))
            p->match = 1;
        p->left = addtree(p->left, w, samechars, p->match);
    }
    else {
        if (check_for_similar_chars(p->word, w, samechars))
            p->match = 1;
        p->right = addtree(p->right, w, samechars, p->match);
    }
    return p;
}

void print_matched_tree(struct tnode *root)
{
    if (root != NULL) {
        print_matched_tree(root->left);
        if (root->match == 1)
            printf("%s\n", root->word);
        print_matched_tree(root->right);
    }
}


void print_unmatched_tree(struct tnode *root)
{
    if (root != NULL) {
        print_unmatched_tree(root->left);
        if (root->match == 0)
            printf("%s\n", root->word);
        print_unmatched_tree(root->right);
    }
}

void print_words(struct tnode *root)
{
    printf("-----------Matched-----------\n");
    print_matched_tree(root);
    printf("----------Unmatched----------\n");
    print_unmatched_tree(root);
}

int main(int argc, char *argv[])
{
    int samechars = 6;
    for (int i=1; i < argc; ++i) {
        if (!strcmp(argv[i], "-n"))
            samechars = atoi(argv[i+1]);
        else {
            printf("Usage <programName>.exe -n <n>");
            return 0;
        }
    }
    char word[MAXWORD];
    struct tnode *root = NULL;
    while (get_word(word) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, samechars, 0);
    print_words(root);
    return 0;
}
