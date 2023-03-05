#include <stdio.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
  struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
void ShowBack(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **node, char name[20], int age, char sex, float gpa);
void InsNode(struct studentNode *node, char name[20], int age, char sex, float gpa);
void GoBack(struct studentNode **node);
void DelNode(struct studentNode **node);

int main() {
  struct studentNode *start, *now;
  start = NULL;
  now = AddNode(&start, "one", 6, 'M', 3.11);
  ShowAll(start);
  now = AddNode(&start, "two", 8, 'F', 3.22);
  ShowAll(start);
  InsNode(now, "three", 10, 'M', 3.33);
  ShowAll(start);
  InsNode(now, "four", 12, 'F', 3.44);
  ShowAll(start);
  GoBack(&now);
  DelNode(&now);
  ShowAll(start);
  DelNode(&now);
  ShowAll(start);
  DelNode(&now);
  ShowAll(start);
  return 0;
} // end function

void ShowAll(struct studentNode *walk) {
  while (walk != NULL) {
    printf("%s ", walk->name);
    walk = walk->next;
  } // end while
  printf("\n");
} // end function

void ShowBack(struct studentNode *walk) {
  while (walk != NULL) {
    printf("form showback %s ", walk->name);
    walk = walk->back;
  } // end while
  printf("\n");
}

struct studentNode *AddNode(struct studentNode **node, char name[20], int age, char sex, float gpa) {
  struct studentNode *temp = *node;
  struct studentNode *newnode = new struct studentNode;
  strcpy(newnode->name, name);
  newnode->age = age;
  newnode->sex = sex;
  newnode->gpa = gpa;
  newnode->next = NULL;
  if (*node == NULL) { // If current node is NULL set newnode to current node and newnode->back to NULL
    newnode->back = NULL;
    *node = newnode;
    return newnode;
  }
  while (temp != NULL) { // To find node before the current node
    if (temp->next == NULL) { // To check if it's NULL or not
      break; // If it break out form while
    } 
    temp = temp->next; 
  }
  newnode->back = temp; // Make newnode->back point to current node
  temp->next = newnode; // Make current node->next point to newnode
  return newnode;
}

void InsNode(struct studentNode *now, char name[20], int age, char sex, float gpa) {
  now->back->next = new struct studentNode; // Create another node on in front of node now
  strcpy(now->back->next->name, name);
  now->back->next->age = age;
  now->back->next->sex = sex;
  now->back->next->gpa = gpa;
  now->back->next->back = now->back;
  now->back->next->next = now;
  now->back = now->back->next;
}

void GoBack(struct studentNode **node) {
  *node = (*node)->back; // Move now to another node
}

void DelNode(struct studentNode **node) {
  if ((*node)->next == NULL) { // Check if next node is NULL or not
    (*node)->back->next = NULL; // Change pointing of back->next to NULL
    delete *node;
    *node = (*node)->back;
    return;
  }
  (*node)->back->next = (*node)->next; // Make the previous node->next point to the next node of current
  (*node)->next->back = (*node)->back; // Make the posterior node->back point to the node before current node
  delete *node;
  *node = (*node)->next;
}
