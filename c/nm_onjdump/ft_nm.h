/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 12:42:44 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 17:31:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# define ERROR_FILE "ft_nm : NO_ARGUMENT\n"
# define FILES_ERROR "ft_nm : NO SUCH FILE OR DIRECTORY\n"
# define FSTAT_ERROR "ft_nm : ERROR_FSTAT\n"
# define MUMMAP_ERROR "ft_nm : MUMMAP_ERROR\n"
# define MMAP_ERROR "ft_nm : MMAP_ERROR\n"
# define OUT_FAILED "ft_nm : can't open file: a.out (No such file or directory)\n"
# define OPEN_FAILED "ft_nm : OPEN FAILED\n"
# define FILE_EMPTY "ft_nm : FILE EMPTY\n"
# define NO_ARCHI "ft_nm : NO_ARCHITECTURE 64 BITES\n"

typedef struct mach_header_64	t_h69;
typedef struct load_command		t_lc;
typedef struct symtab_command	t_sc;
typedef struct nlist_64			t_nl64;

void	ft_error(int nb);
char	**ft_sort(char **f_tab);
#endif