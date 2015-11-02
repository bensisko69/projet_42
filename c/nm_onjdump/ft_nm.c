/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 12:16:18 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 18:40:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	**ft_tab(t_nl64 *array, char *str, int nsyms)
{
	char	**tab;
	int		i;

	i = 0;
	while (i < nsyms)
		i++;
	i += 1;
	tab = (char**)malloc(sizeof(char*) * i);
	tab[i] = NULL;
	i = 0;
	if (tab)
	{
		while (i < nsyms)
		{
			if (array[i].n_desc == 256)
				tab[i] = ft_strdup(str + array[i].n_un.n_strx, "U ");
			else if (array[i].n_desc == 0 || array[i].n_desc == 16)
				tab[i] = ft_strdup(str + array[i].n_un.n_strx, "T ");
			i++;
		}
	}
	return (tab);
}

void		print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	char	*str;
	char	**tab;
	t_nl64	*array;
	int 	i;

	i = 0;
	array = ptr + symoff;
	str = ptr + stroff;
	tab = ft_tab(array, str, nsyms);
	tab = ft_sort(tab);
	while (i < nsyms)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		handle_64(void *ptr)
{
	int		nb_load_cmd;
	t_h69	*header;
	t_lc	*lc;
	t_sc	*sym;
	int		i;

	i = 0;
	header = (t_h69 *)ptr;
	nb_load_cmd = header->ncmds;
	lc = ptr + sizeof(*header);
	if (header->filetype == MH_OBJECT)
		ft_putchar('l');
	while (i < nb_load_cmd)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (t_sc *)lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

void		nm(void *ptr)
{
	int	magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(ptr);
}

int			ft_nm(int fd)
{
	struct stat	buf;
	void		*ptr;

	if (fstat(fd, &buf) == -1)
	{
		ft_error(3);
		return (1);
	}
	if (buf.st_size == 0)
	{
		ft_error(8);
		return (1);
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == 0)
	{
		ft_error(5);
		return (1);
	}
	nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
	{
		ft_error(4);
		return (1);
	}
	return (0);
}

int			open_out(void)
{
	int	fd;

	if ((fd = open("a.out", O_RDONLY)) >= 0)
	{
		if (fd < 0)
		{
			ft_error(7);
			return (1);
		}
		if (ft_nm(fd == 1))
			return (1);
	}
	ft_error(6);
	return (1);
}

int			main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 1;
	if (ac == 1)
	{
		if (open_out() == 1)
			return (1);
		return (0);
	}
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) >= 0)
		{
			if (ft_nm(fd) == 1)
				return (1);
		}
		else
			ft_error(7);
		close(fd);
		i++;
	}
	return (0);
}
