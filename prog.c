#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
  struct list List;

struct node{
  int value;
  struct node* next;
};

struct list{
  struct node* head;
  int size;
};

void add(struct node *noode, int value){
  if(noode->next==NULL){
    struct node *last = NULL;
    last = malloc(sizeof(struct node));
    last->value = value;
    last->next = NULL;
    noode->next = last;
  }else{
    add(noode->next, value);
  }
}

int pushfront(int value){
  if(List.size == 0){
    struct node *head = NULL;
    head = malloc(sizeof(struct node));
    head->value = value;
    head->next = NULL;
    List.head = head;
  }else{
    add(List.head ,value);
  }
  List.size += 1;
  return value;
}

int peekback(struct node Node){
  if(Node.next == NULL){
    return Node.value;
  }else{
    return peekback(*Node.next);
  }
}

void freeall(struct node Node){
  while(Node.next != NULL){
    struct node *last = NULL;
    last = malloc(sizeof(struct node));
    last = &Node;
    Node = *Node.next;
    free(last);
  }
}

void dump(struct node Node){
  if(Node.next == NULL){
    printf("%d ", Node.value);
  }else{
    printf("%d ", Node.value);
    dump(*Node.next);
  }
}

struct node* get(struct node *noode, int i){
  if(i==0){
    return noode;
  }else{
    return get(noode->next,i-1);
  }
}

int main() {
  char str[100];
  char out[100];
  int value[100];
  int i = 0;
  while(scanf("%s", str) != EOF){
   if(strcmp(str,"push-back")==0){
     int a;
     scanf("%d", &a);
     printf("%d\n", pushfront(a));
   }else if(strcmp(str,"pop-front")==0){
    if(List.size==0){
      printf("empty");
    }else{
      printf("%d", List.head->value);
      List.head = List.head->next;
      List.size--;
    }
   }else if(strcmp(str,"push-front")==0){
     int a;
     scanf("%d", &a);
     printf("%d", a);
     struct node *last = NULL;
     last = malloc(sizeof(struct node));
     last->next = List.head;
     last->value = a;
     List.head = last;
     List.size++;
   }else if(strcmp(str,"peek-front")==0){
     if(List.size==0){
        printf("empty");
     }else{
        printf("%d", List.head->value);
     }
   }else if(strcmp(str,"peek-back")==0){
     if(List.size == 0){
       printf("empty");
     }else{
       printf("%d", peekback(*List.head));
     }
   }else if(strcmp(str,"size")==0){
     printf("%d", List.size);
   }else if(strcmp(str,"clear")==0){
     freeall(*List.head);
     printf("empty");
   }else if(strcmp(str,"dump")==0){
     if(List.size == 0){
      printf("empty");
     }else{
       dump(*List.head);
     }
   }
  }
}
