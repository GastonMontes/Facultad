//
//  list_node.h
//  TP1
//
//  Created by Gastón Montes on 13/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#ifndef TP1_list_node_h
#define TP1_list_node_h

#include "DNA_sequence.h"

struct ListNode {
    DNASequence sequence;
    struct ListNode *next;
};

/**
 * Create a new node with the sequence asociated.
 * @params - sequence: The sequence asociated to the new node.
 */
struct ListNode *listNodeCreate(DNASequence sequence);

/**
 * Free the resources allocated by the creation of a new node.
 */
void listNodeDestroy(struct ListNode *node);

#endif
