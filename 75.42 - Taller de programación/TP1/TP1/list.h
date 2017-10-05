//
//  list.h
//  TP1
//
//  Created by Gastón Montes on 14/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_list_h
#define TP1_list_h

#include "list_node.h"

typedef struct {
    struct ListNode *head_node;
} LinkedList;

/**
 * Create a new linkedList with the first node that contains sequence.
 * @params - sequence: The sequence for the head node.
 */
void linkedListCreate(LinkedList **linked_list);

/**
 * Add node to the linked_list in order.
 * @params - sequence: The sequence to the new node.
 */
void linkedListAddNode(LinkedList *linked_list, DNASequence sequence);

/**
 * Free all the resources allocated by the list.
 */
void linkedListDestroy(LinkedList *linked_list);

#endif
