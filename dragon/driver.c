#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scope.h"

main()
{
    scope_t *top = NULL;
    node_t *tmp;

    int choice;
    char name[32];

    top = mkscope();

    while (1)
    {
        fprintf(stderr, "(0) push (1) pop (2) search (3) search_all (4) insert:\n")
            scanf("%d", choice);
        switch (choice)
        {
        case 0: /* push */
            top = push_scope(top);
            break;
        case 1: /* pop */
            top = pop_scope(top);
            break;
        case 2: /* search */
            fprintf("Name to search:\n");
            scanf("%s", name);
            tmp = scope_search(top, name);
            if (tmp != NULL)
                fprintf(stderr, "Found[%s]\n", tmp->name);
            else
                fprintf(stderr, "NotFound[%s]\n", name);
            break;
        case 3: /* search all */
            fprintf("Name to search:\n");
            scanf("%s", name);
            tmp = scope_search_all(top, name);
            if (tmp != NULL)
                fprintf(stderr, "Found[%s]\n", tmp->name);
            else
                fprintf(stderr, "NotFound[%s]\n", name);
            break;
        case 4: /* insert */
            fprintf("Name to insert:\n");
            scanf("%s", name);
            top = insert(top, name);
            break;
        }
    }
}