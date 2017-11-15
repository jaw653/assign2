/* Author: Jake Wachs
 * Date: November 13, 2017
 *
 * The University of Alabama
 */

#include <stdio.h>
#include "bst.h"
#include "real.h"

static void displayTree(BST *);
static void insertValue(BST *, int);
static void printStatistics(BST *);

int main(void) {
    BST *tree = newBST(displayREAL, compareREAL, NULL);
    printf("\nTree successfully initiailized\n");

    displayTree(tree);

    insertValue(tree, 4);
    insertValue(tree, 5);
    insertValue(tree, 7);
    insertValue(tree, 3);
    insertValue(tree, 2);
    insertValue(tree, 8);
    insertValue(tree, 6);
    insertValue(tree, 9);
    insertValue(tree, 1);
    insertValue(tree, 0);

    displayTree(tree);

    printStatistics(tree);

    printf("deleting the root via getBSTroot method...\n");
    deleteBST(tree, getBSTNODE(getBSTroot(tree)));

    displayTree(tree);

    printStatistics(tree);

    printf("attempting to find value 2...\n");
    BSTNODE *foundNode = findBST(tree, newREAL(2));
    if (foundNode)
      printf("node found! accessed value is: %lf\n", getREAL(getBSTNODE(foundNode)));
    else
      printf("node not found :(\n");

    printf("\n");

    printf("Attempting to delete all values in tree, then make it display EMPTY\n");
    printf("original size is: %d\n", sizeBST(tree));
    while (sizeBST(tree) > 0) {
      printf("deleting: %lf\n", getREAL(getBSTNODE(getBSTroot(tree))));
      deleteBST(tree, getBSTNODE(getBSTroot(tree)));
      printf("size is: %d\n", sizeBST(tree));
      displayTree(tree);
    }
    deleteBST(tree, getBSTNODE(getBSTroot(tree)));

    displayTree(tree);

    printf("attempting to add nodes back to bst after removing to empty...\n");
    insertBST(tree, newREAL(55));
    printf("insert successful.\n");

    displayTree(tree);


    return 0;
}

static void displayTree(BST *tree) {
  printf("tree is:\n");
  displayBST(stdout, tree);
  printf("\n\n");
}

static void insertValue(BST *tree, int a) {
  printf("Inserting %d...\n", a);
  insertBST(tree, newREAL(a));
  printf("Insert of %d successful.\n", a);
}

static void printStatistics(BST *tree) {
  printf("printing statistics...\n");
  statisticsBST(stdout, tree);
  printf("\n");
}
