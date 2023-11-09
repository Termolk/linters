#include "list.h"

struct node* init(struct door* door) {
  struct node* root = malloc(sizeof(struct node));
  root->data = door;
  root->next = NULL;
  return root;
}

struct node* add_door(struct node* elem, struct door* door) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data = door;
  new_node->next = elem->next;
  elem->next = new_node;
  return new_node;
}

struct node* find_door(int door_id, struct node* root) {
  struct node* curr = root;
  while (curr != NULL) {
    if (curr->data->id == door_id) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
  if (elem == root) {
    struct node* new_root = root->next;
    free(root);
    return new_root;
  }

  struct node* curr = root;
  while (curr->next != elem) {
    curr = curr->next;
  }
  
  curr->next = elem->next;
  free(elem);
  return root;
}

void destroy(struct node* root) {
  struct node* curr = root;
  while (curr != NULL) {
    struct node* temp = curr;
    curr = curr->next;
    free(temp);
  }
}
