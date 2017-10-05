//
//  list_node.c
//  TP1
//
//  Created by Gastón Montes on 13/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

struct ListNode *listNodeCreate(DNASequence sequence) {
    struct ListNode *new_node;
    new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->sequence  = sequence;
    new_node->next      = NULL;
    
    return new_node;
}

void listNodeDestroy(struct ListNode *node) {
    free(node);
}
