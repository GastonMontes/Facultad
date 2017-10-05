//
//  list.c
//  TP1
//
//  Created by Gastón Montes on 14/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include "list.h"
#include "files.h"

#include <stdio.h>
#include <stdlib.h>

void linkedListCreate(LinkedList **linked_list) {
    LinkedList *new_list    = (LinkedList *)malloc(sizeof(LinkedList));
    new_list->head_node     = NULL;
    *linked_list = new_list;
}

void linkedListInsertNode(LinkedList *list, 
                          struct ListNode *previous_node, 
                          struct ListNode *current_node, 
                          struct ListNode *new_node) {
    // Insert the new node at the beginning or as next of the list head node.
    if (previous_node == NULL) {
        int current_node_comparison = current_node->sequence.comparison_value;
        int new_node_comparison_value = new_node->sequence.comparison_value;
        if (current_node_comparison == new_node_comparison_value) {
            long current_node_pos = current_node->sequence.position_in_file;
            long new_node_pos = new_node->sequence.position_in_file;
            if (current_node_pos > new_node_pos) {
                new_node->next  = current_node;
                list->head_node = new_node;
            } else {
                new_node->next      = current_node->next;
                current_node->next  = new_node;
            }
        } else {
            // Current node comparison value < New node comparison value.
            new_node->next  = current_node;
            list->head_node = new_node;
        }
    } else if (current_node == NULL) {
        // Insert at the end.
        previous_node->next = new_node;
    } else {
        int current_node_comparison = current_node->sequence.comparison_value;
        int new_node_comparison_value = new_node->sequence.comparison_value;
        if (current_node_comparison == new_node_comparison_value) {
            long current_node_pos = current_node->sequence.position_in_file;
            long new_node_pos = new_node->sequence.position_in_file;
            if (current_node_pos > new_node_pos) {
                new_node->next      = current_node;
                previous_node->next = new_node;
            } else {
                new_node->next      = current_node->next;
                current_node->next  = new_node;
            }
        } else {
            // Current node comparison value < New node comparison value.
            new_node->next      = current_node;
            previous_node->next = new_node;
        }
    }
}

void linkedListAddNode(LinkedList *linked_list, DNASequence sequence) {
    // Create the new node.
    struct ListNode *new_node = listNodeCreate(sequence);
    
    if (linked_list->head_node == NULL) {
        linked_list->head_node = new_node;
    } else {
        // Nodes for iteration.
        struct ListNode *prev_node      = NULL;
        struct ListNode *current_node   = linked_list->head_node;
        
        // Search through to find correct position to insert the new node.
        int new_node_value = new_node->sequence.comparison_value;
        int current_node_value = current_node->sequence.comparison_value;
        while (current_node != NULL && new_node_value < current_node_value) {
            prev_node       = current_node;
            current_node    = current_node->next;
        }
        
        linkedListInsertNode(linked_list, prev_node, current_node, new_node);
    }
}

void linkedListDestroy(LinkedList *linked_list) {
    struct ListNode *current_node = linked_list->head_node;
    struct ListNode *next_node;
    
    while (current_node != NULL) {
        next_node = current_node->next;
        
        listNodeDestroy(current_node);
        
        current_node = next_node;
    }
    
    free(linked_list);
}
