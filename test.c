#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
    int             data;
    struct s_node   *next;
}               t_node;

t_node *ft_lstnew(int content)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->data = content;
    new_node->next = NULL;
    return (new_node);
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node *tmp;

    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void swap(t_node **stack)
{
    t_node *tmp;

    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
}

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

void push(t_node **a_stack, t_node **b_stack)
{
	t_node *tmp;

	while (*a_stack)
	{
		tmp = *a_stack;
		*a_stack = (*a_stack)->next;
		tmp->next = *b_stack;
		*b_stack = tmp;
	}

}

int main(int argc, char *argv[])
{
    t_node *a_stack = NULL;
    t_node *b_stack = NULL;
    t_node *tmp;
    int i = 1;

    if (argc < 2)
    {
        printf("Usage: ./program num1 num2 ... numN\n");
        return (1);
    }

    // Convert the arguments to a linked list
    while (i < argc)
    {
        tmp = ft_lstnew(atoi(argv[i]));
        ft_lstadd_back(&a_stack, tmp);
        i++;
    }

    // Print the initial state of the stack
    // printf("Stack A before swap:\n");
    // print_stack(a_stack);

    // // Call the swap function on stack A
    // swap(&a_stack);
    // printf("Stack A after swap:\n");
    // print_stack(a_stack);

    printf("======>Stack A befor push:");
    print_stack(a_stack);
    printf("======>Stack B befor push:");
    print_stack(b_stack);
    // Call the push function to move elements from a_stack to b_stack
    push(&a_stack, &b_stack);

    // Print the final state of the stacks
    printf("======>Stack A after push:");
    print_stack(a_stack);
    printf("======>Stack B after push:");
    print_stack(b_stack);

    return 0;
}
