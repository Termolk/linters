#include "list.h"

int main() {
    struct door door1 = {1, 0};
    struct door door2 = {2, 1};
    struct door door3 = {3, 0};
    
    struct node* root = init(&door1);
    struct node* list_head = root;
    
    root = add_door(root, &door2);
    root = add_door(root, &door3);

    struct node* found = find_door(2, list_head);
    if (found != NULL) {
      printf("Door id 2 found!\n");
    }
    else
        printf("Door id 2 NOT found!\n");

    struct node* curr = list_head;
    while (curr != NULL) {
      printf("Door id: %d, status: %d\n", curr->data->id, curr->data->status);
      curr = curr->next;
    }

    root = remove_door(found, list_head);
    curr = list_head;
    while (curr != NULL) {
      printf("Door id: %d, status: %d\n", curr->data->id, curr->data->status);
      curr = curr->next;
    }
    
    
    destroy(list_head);
    
    return 0;
    
    
    
    
    
    return 0;
}
