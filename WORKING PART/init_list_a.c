/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:51:18 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/21 18:26:35 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_list_a(t_list **a, char **argv) //Define a function that initiates list `a` 
												//by handling any errors and appending required nodes to complete a list
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i])) //input_checker
			free_errors(a);			//free list + print error
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Check for overflow
			free_errors(a);			//free list + print error
		if (error_duplicate(*a, (int)n))	//nodouble
			free_errors(a);			//free list + print error
		append_node(a, (int)n); //If no errors, append the node to the linked list by,     			//lst_add_back mais plus complet
								// taking a pointer to list `a`, create a new node and assign `n` to that new node
		i++;
	}
}




t_list *find_last(t_list *list)
{
    while(list->next)
    {
        list = list->next;
    }
    return (list);
}

static void	append_node(t_list **list, int n) //Define a function that searches for the last node to append to the linked list
{
	t_list	*node; //To store a pointer to the new node to be created with the value `n`
	t_list	*last_node; //To store a pointer to the current last node of the list

	if (!list)
		return ;
	node = malloc(sizeof(t_list)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->nbr = n; //Set the `next` data of of the new node to `n` value
	if (!(*list)) //Check if the list is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*list = node; //If empty, update the pointer *list to point to the node, effectively making it the new head of the linked list
		node->prev = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the list is not empty, it means there are existing nodes in the linked list
	{
		last_node = find_last(*list); //In which case, find the last node 
		last_node->next = node; //Append the new node to the last node
		node->prev = last_node; //Update the previous pointer of the new node and complete the appending
	}
}






int	error_syntax(char *s) //Define a funtion to handle syntax errors, and returns `1` 
								//for `error` should any of the following conditions are met
{
	if (!(*s == '+'
			|| *s == '-'
			|| (*s >= '0' && *s <= '9'))) //Check if the first character of the input 
													//string does not contain a sign or a digit
		return (1);
	if ((*s == '+'
			|| *s == '-')
		&& !(s[1] >= '0' && s[1] <= '9')) //Check if the first character of the input 
													//string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++s) //If the error conditions above are passed, pre-increment to point 
						//to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*s >= '0' && *s <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}


int	error_duplicate(t_stack_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
	if (!a) //Check for an empty stack
		return (0);
	while (a) //Loop until the end of stack `a` is reached
	{
		if (a->nbr == n) //Check if the current node's value is equal to `n`. Refer to `init_stack_a()`
			return (1);
		a = a->next; //Move to the next node to check for duplicates
	}
	return (0);
}