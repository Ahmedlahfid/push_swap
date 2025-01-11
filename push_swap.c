/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:56:00 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/10 16:29:38 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_stack(t_list **stack, char **arg)
{
    int i = 0;
    int *value;

    while (arg[i])
    {
        value = malloc(sizeof(int)); // Dynamically allocate memory for the integer
        if (!value) // Check for allocation failure
            msg_err();
        *value = ft_atoi(arg[i]); // Convert string to integer and store it in allocated memory

        t_list *new_node = ft_lstnew(value); // Create a new node with the pointer to the integer
        if (!new_node) // Check for node creation failure
        {
            free(value); // Free allocated memory if node creation fails
            msg_err();
        }

        ft_lstadd_back(stack, new_node); // Add the new node to the stack
        free(arg[i]); // Free the string from arg after processing
        i++;
    }
    free(arg); // Free the array of strings after processing all elements
}

char	*joinargs(int argc, char **argv)
{
	int		i;
	int		j;
	char	*args;
	char	*temp;

	i = 1;
	args = ft_strdup(""); // Initialize with an empty string
	if (!args) // Check for allocation failure
		msg_err();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ') // Skip leading spaces
			j++;
		if (argv[i][j] == '\0') // Empty argument
        {
            free(args);
			msg_err();
        }
		temp = args; // Save the current pointer
		args = ft_strjoin(args, argv[i] + j); // Concatenate the trimmed argument
		free(temp); // Free the old string to avoid memory leaks
		temp = args; // Save the current pointer again
		args = ft_strjoin(args, " "); // Add a space after the argument
		free(temp); // Free the old string to avoid memory leaks
		i++;
	}
	return (args);
}


void *arg_checker(int ac, char **av)
{
    int i;
    char *join_args;
    char **split_args;

    if (ac < 2)
        exit(0);
    join_args = joinargs(ac, av);
    if (!join_args) // Check if joinargs failed
        msg_err();
    split_args = ft_split(join_args, ' ');
    if (!split_args) // Check if ft_split failed
    {
        free(join_args);
        msg_err();
    }
    i = 0;
    while (split_args[i])
    {
        is_nbr(split_args[i]); // Validate number
        is_duplicated(split_args); // Check for duplicates
        i++;
    }
    free(join_args);
    return split_args;
}

// Print stack contents (fixed dereferencing issue)
void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", *(int *)(stack->content)); // Properly cast content to int* and dereference it
        stack = stack->next; // Move to the next node
    }
}

// Free all nodes in the stack (fixed double free issue)
void free_stack(t_list *stack)
{
    t_list *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;

        free(temp->content); // Free dynamically allocated content (integer)
        free(temp);          // Free the node itself
    }
}

int main(int ac, char **av)
{
    t_list *a_stack = NULL;
    t_list *b_stack = NULL;
    char **args;

    if (ac < 2)
        exit(0);

    args = arg_checker(ac, av);
    push_to_stack(&a_stack, args);
    
    int size = ft_lstsize(a_stack);
    if (size == 2)
        sort_two(&a_stack);
    else if (size == 3)
        sort_three(&a_stack);
    else if (size == 4)
        sort_four(&a_stack, &b_stack);
    else if (size == 5)
        sort_five(&a_stack, &b_stack);
    // Check and process arguments
    
    //sort_five(&a_stack, &b_stack);
    //sort_three(&a_stack);
    // Push valid arguments to the stack
                        
    // Print the stack contents
    printf("Stack a contents:\n");
    print_stack(a_stack);
    // Free all nodes in the stack
    free_stack(a_stack);

    return 0;
}


