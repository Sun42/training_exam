#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER 1024 * 1024

int	my_strlen(char *str);
void	my_putstr(char *str);
int	count_l(char buf[], int size);
int	count_taille(char buf[], int size);
void	aff_tab(char **tab, int nbl);
char	**mktab(char buf[], int size, int taillel, int nbl);
void	my_strncpy(char *dest, char *src, int max);
void	transform(char **tab, int taillel, int nbl);
void	propage(char ***tab, int i, int j, int taillel, int nbl, int cpt);

int	main(int ac, char **av)
{
  if (ac == 2 && av[1] != NULL)
    {
      count(av[1]);
    }
}

void	count(char *filename)
{
  int	fd;
  char	buf[BUFFER];
  int	i;
  int	size;
  char	**tab;
  int	nbl;
  int	taillel;
  void	my_strncpy(char *dest, char *src, int max);

  
  i = 0;

  fd = open(filename, O_RDONLY);
  if (fd == -1)
    return ;
  size = read(fd, buf, BUFFER);
  if (size == -1)
    return ;
  taillel = count_taille(buf, size); 
  nbl = count_l(buf, size);
  tab = mktab(buf, size, taillel, nbl);
  transform(tab, taillel, nbl);
  aff_tab(tab, nbl);
 close(fd);
}



void	transform(char **tab, int taillel, int nbl)
{
  int	i;
  int	j;
  int	cpt;

  cpt = 0;
  i = 0;
  while (i < nbl)
    {
      j = 0;
      while (j < taillel)
	{
	  if (tab[i][j] == 'X')
	    {
	      propage(&tab, i, j, taillel, nbl, cpt);
	      cpt++;
	    }
	  j++;
	}
      i++;
    }
}

void	propage(char ***tab, int i, int j, int taillel, int nbl, int cpt)
{
  char	**tab2;
  
  tab2 = *tab;

  tab2[i][j] = cpt + '0';
  if ((i > 0) && tab2[i - 1][j] == 'X')
    propage(tab, i - 1 , j, taillel ,nbl, cpt);
  if ((i < nbl - 1) && tab2[i + 1][j] == 'X')
  propage(tab, i + 1 , j, taillel ,nbl, cpt);
  if ((j > 0) && tab2[i][j - 1] == 'X')
    propage(tab, i , j - 1, taillel ,nbl, cpt);
if ((j < taillel - 1) && tab2[i][j + 1] == 'X')
    propage(tab, i , j + 1, taillel , nbl, cpt);
}


void	aff_tab(char **tab, int nbl)
{
  int	i;

  i = 0;
  while (i < nbl)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
}

int	count_taille(char buf[], int size)
{
  int	cpt;

  cpt = 0;
  while (cpt < size)
    {
      if (buf[cpt] == '\n')
	return (cpt);
      cpt++;
    }
  return (-1);
}

int	count_l(char buf[], int size)
{
  int	i;
  int	cpt;

  cpt = 0;
  i = 0;
  while (i < size)
    {
      if (buf[i] == '\n')
	cpt++;
      i++;
    }
  return (cpt);
}


char	**mktab(char buf[], int size, int taillel, int nbl)
{
  char	**tab;
  int	i;

  i = 0;
  tab = malloc(nbl * sizeof(*tab));
  while (i  < nbl)
    {
      tab[i] = malloc((taillel + 1) * sizeof(**tab));
      my_strncpy(tab[i] , buf, taillel);
      i++;
      buf += taillel + 1;
    }
  return (tab);
}


void	my_strncpy(char *dest, char *src, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      dest[i] = src[i];
      i++;
    }
  dest[max] = '\0';
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strlen(char *str)
{
  int	i;
  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
