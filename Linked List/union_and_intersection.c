#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int dat;
    struct node* next;
} node;

int test(struct {int x,y; char c;} p, double y){
    return printf("%lf", p.x+y);
}

node* union_and_intersection(node* a, node* b){
    node un, in;
}