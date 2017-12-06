int		ft_sqrt(int nb)
{
	int a;
	int b;
	int c;
	int	nb_entier;

	nb_entier = 0;
	a = 0;
	b = nb / 2;
	if (nb <= 0)
		return (0);
	if (nb > 46340)
		b = 46340;
	else
		b = nb;
	while (a < b)
	{
		c = (a + b) / 2;
		if (c * c < nb)
			a = c + 1;
		else
			b = c;
	}
	if (a * a == nb)
		return (a);
	else while (nb_entier < a)
	{
		nb_entier++;
	}
	return (nb_entier);
}