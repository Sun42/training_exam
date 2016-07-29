#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void  infin(char *str1, char *str2);
void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(char *str);
void	revstr(char *str);
char	*add(char *str1, char *str2);
void	cleanstr(char *str);
char	*min(char *str1, char *str2);
int	is_sup(char *str1, char *str2);

int	main(int ac, char **av)
{
  
  if (ac == 3)
    {
      if ((av[1] != NULL) && (av[2] != NULL))
	infin(av[1], av[2]); 
    }
  my_putchar('\n');
  return (0);
}

void	infin(char *str1, char *str2)
{
  int	flag1;
  int	flag2;
  char	*added;
  char	*mined;
  int	flagsup;
 
  flag1 = 0;
  flag2 = 0;
  while (*str1 == '-')
    {
      flag1 = 1;
      str1++;
    }
  while (*str2 == '-')
  {
    flag2 = 1;
    str2++;
  }
  if (!flag1 && !flag2)
    {
      revstr(str1);
      revstr(str2);
      added = add(str1, str2);
      revstr(added);
      while (*added == '0' && *(added + 1) != '\0')
	added++;
      my_putstr(added);
    }
  else if (flag1 && flag2)
    {
      revstr(str1);
      revstr(str2);
      added = add(str1, str2);
      revstr(added);
      while (*added == '0' && *(added + 1) != '\0')
	added++;
      if (added[0] != '0' || my_strlen(added) != 1)
	my_putchar('-');
      my_putstr(added);
    }
  /* -4 2 -2 4*/
  else if (flag1 && !flag2)
    {
      while (*str1 == '0' && *(str1 + 1) != '\0')
	str1++;
      while (*str2 == '0' && *(str2 + 1) != '\0')
	str2++;
      flagsup = is_sup(str1, str2);
      revstr(str2);
      revstr(str1);

      /*-4 3 */
      if (flagsup)
	{
	  mined = min(str1, str2);
	  revstr(mined);
	  while (*mined == '0' && *(mined + 1) != '\0')
            mined++;
	  if (mined[0] != '0' || my_strlen(mined) != 1)
	    my_putchar('-');
	  my_putstr(mined);
	}
      /*-3 4 */
      else
	{
	  mined = min(str2, str1);
	  revstr(mined);
	  while (*mined == '0' && *(mined + 1) != '\0')
	    mined++;
	  my_putstr(mined);
	}
    }
  else if (!flag1 && flag2)
    {
      while (*str1 == '0' && *(str1 + 1) != '\0')
	str1++;
      while (*str2 == '0' && *(str2 + 1) != '\0')
	str2++;
      flagsup = is_sup(str1, str2);
      revstr(str2);
      revstr(str1);
      /* 4 -3*/
      if (flagsup)
	{
	  mined = min(str1, str2);
	  revstr(mined);
	  while (*mined == '0' && *(mined + 1) != '\0')
	    mined++;
	  my_putstr(mined);
	}
      /*-3 4 */
      else
	{
	  mined = min(str2, str1);
	  revstr(mined);
	  while (*mined == '0' && *(mined + 1) != '\0')
	    mined++;
	  if (mined[0] != '0' || my_strlen(mined) != 1)
	    my_putchar('-');
	  my_putstr(mined);
	}
    }
}


int	is_sup(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str1) > my_strlen(str2))
    return (1);
  if (my_strlen(str1) < my_strlen(str2))
    return (0);
  while (i < my_strlen(str1))
    {
      if (str1[i] > str2[i])
	return (1);
      if (str1[i] < str2[i])
	return (0);
      i++;
    }
  return (0);
}

char	*min(char *str1, char *str2)
{
  char	*buf;
  int	max;
  int	i;
  int	min;
  int	retenue;
  char	c1;
  char	c2;
  
  i = 0;
  max = my_strlen(str1) - 1;
  retenue = 0;
  buf = malloc(my_strlen(str1) + my_strlen(str2) +  4);
  while (i <= max)
    {
      min = 0;
      if (i < my_strlen(str1))
	c1 = str1[i] - '0';
      else
	c1  = 0;
      if (i < my_strlen(str2))
	c2 = str2[i] - '0';
      else
	c2 = 0;
      min = (c1) - (c2 + retenue);
      if (min < 0)
	{
	  retenue = 1;
	  buf[i] = (10 +  min) + '0';
	}
      else
	{
	  retenue = 0;
	  buf[i] =  min + '0';
	}
      i++;
    }
  if (retenue != 0)
    {
      buf[i] = (10 -  min) + '0';
      i++;
    }
  buf[i] = '\0';
  return (buf);
}


void	cleanstr(char *str)
{
  while (*str == '0' && *(str + 1) != '\0')
    str++;
}

char	*add(char *str1, char *str2)
{
  int	max1;
  int	max2;
  int	max;
  int	i;
  char	*buf;
  int	retenue;
  int	add;
  
  buf = malloc(max1 + max2 + 4);
  i = 0;
  retenue = 0;
  add = 0;
  max1 = my_strlen(str1) - 1;
  max2 = my_strlen(str2) - 1;
  max = (max1 > max2 ? max1 : max2);
  while (i <= max)
    {
      add = 0;
      add += retenue;
      if (i <= max1)
	add += str1[i] - '0';
      if (i <= max2)
	add += str2[i] - '0';
      if (add >= 10)
	{
	  retenue = 1;
	  add -= 10;
	}
      else
	retenue = 0;
      buf[i] = add + '0';
      i++;
    }
  if (retenue != 0)
    {
      buf[i] = retenue + '0';
      i++;
    }
  buf[i] = '\0';
  return (buf);
}


void	revstr(char *str)
{
  int	i;
  int	j;
  char	swap;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      swap = str[i];
      str[i] = str[j];
      str[j] = swap;
      i++;
      j--;
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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
