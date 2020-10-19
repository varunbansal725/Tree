#include <stdio.h>
#include <stdlib.h>


int * create() {
    int x,z, y, size, i;
    int left_child=2i;
    int right_child=2i+1;
    printf("Enter the no. of nodes of the tree: ");
    scanf("%d", &size);
    int tree[size];
    printf("Enter the root value: ");
    scanf("%d", &x);
    tree[0]=NULL;
    tree[1]=x;

    for(i=1; i<=size; i++) {
        printf("Enter left child of %d: ", tree[i]);
        scanf("%d", &z);
        if(z!=-1)
            tree[2*i]=z;
        printf("Enter right child of %d: ", tree[i]);
        scanf("%d", &y);
        if(y!=-1)
            tree[2*i+1]=y;
    }
    return tree;
}


void main()
{
    int *p;
    p=create();
}
