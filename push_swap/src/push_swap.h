/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:27:14 by aabdou            #+#    #+#             */
/*   Updated: 2022/02/06 08:27:16 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

# define	ON 1
# define	OFF 0

typedef struct array
{
   
    int size;
    int used_size;
    int *array;
}               s_array;

typedef struct stack 
{
    s_array stack_a;
    s_array stack_b;
}               s_stacks;



int			ft_get_biggest_index(s_array *stack_b);

int			ft_count_numbers(char *string);
int			ft_check_sorted(s_array *array);
int			ft_check_duplicates(s_stacks *stacks, int number);
int			ft_check_number(char *number);
int			ft_err_and_free(s_stacks *stacks, char *message, int ret);
int			*ft_save_list(s_array *stack_a);
int			*ft_sort_array(s_array *stack_a);
int			ft_search_index(s_stacks *stacks, int key_number);
int			ft_get_smallest_index(s_array *stack_a);
int         ft_check_arg(char *av);
int			ft_find_key_number(int *sorted_list, int size,
				int divided, int chunks);
 

void	ft_read_from_ps(char *line, s_stacks *stacks);

void		ft_arrange_rest_of_numbers(s_stacks *stacks, int size);
void		ft_find_biggest_number(s_stacks *stacks);
void		ft_find_smallest_number(s_stacks *stacks);
void		ft_arrange_five_numbers(s_stacks *stacks);
void		ft_move_to_top(s_stacks *stacks, int index);
void		ft_push_index(s_stacks *stacks, int key_number);
void		ft_arrange_one_handred(s_stacks *stacks);
void		ft_arrange_five_handred(s_stacks *stacks);

char		*ft_arg_to_string(char **av);
s_stacks	ft_create_stack(char *str);
int			ft_size_of_av(char **av);
char		**ft_stacks_init(char *string, s_stacks *stacks);


int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t ds);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

//sorting
void		ft_remove_first_elm(int *array, int used_size);
void		ft_clear_first_elm(int *array, int used_size);
void		ft_pa(s_stacks *stacks, int type);
void		ft_pb(s_stacks *stacks, int type);
void		ft_rra(s_array *stack_a, int type);
void		ft_rrb(s_array *stack_b, int type);
void		ft_rra_and_rrb(s_stacks *stacks, int type);
void		ft_sa_or_sb(s_array *array, int type, char stack);
void		ft_sa_and_sb(s_stacks *stacks, int type);
void		ft_ra(s_array *stack_a, int type);
void		ft_rb(s_array *stack_b, int type);
void		ft_ra_and_rb(s_stacks *stacks, int type);


void		ft_swap(int *left, int *right);
void		ft_arrange_rest(s_stacks *stacks);
void		ft_arrange_more_then_handred(s_stacks *stacks);
void		ft_find_smallest_number_ten(s_stacks *stacks);
void		ft_arrange_ten_numbers(s_stacks *stacks);
void		ft_arrange_three_numbers(s_array *stack_a);

#endif