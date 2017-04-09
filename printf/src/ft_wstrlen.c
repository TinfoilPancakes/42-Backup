#include "ft_string.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	wchar_t	*i;

	i = (wchar_t *)s;
	while (*i != L'\0')
		i++;
	return (i - s);
}
