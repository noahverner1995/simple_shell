#include "main.h"

/**
 * free_list - Free the all the nodes in the list
 * @head: Pointer to the linked list
 *
 * Return: nothing.
 */
void free_list(Node *head)
{
Node *temp;

while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
free(head);
}
