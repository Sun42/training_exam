#include <stdlib.h>
int	is_alpha(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
void	rotone(char *str);

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char **av)
{
  if (ac == 2) 
    {
      if (av[1] != NULL)
	rotone(av[1]);
    }
  my_putchar('\n');
  return (0);
}


void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_alpha(str[i]))
	{
	  if (str[i] == 'z')
	    my_putchar('a');
	  else if (str[i] == 'Z')
	    my_putchar('A');
	  else
	    my_putchar(str[i] + 1);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

int	is_alpha(char c)
{
  if ((c >= 'a') && (c <= 'z'))
    return (1);
  if ((c >= 'A') && (c <= 'Z'))
    return (1);
  return (0);
}
