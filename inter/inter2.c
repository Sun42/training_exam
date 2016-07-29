void	my_putstr(char *str);
void	my_putchar(char c);


int	main(int ac, char **av)
{
  return (0);
}


int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
}


void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
