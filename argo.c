#include "argo.h"

int	peek(FILE *stream)
{
	int	c;

	c = getc(stream);
	ungetc(c, stream);
	return (c);
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return (1);
	}
	return (0);
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return (1);
	unexpected(stream);
	return (0);
}

void skipspaces(stream)
{
	int c;

	while (1)
	{
		c = getc(stream);
		if ((c < 9 || c > 13) && c != 32)
		{
			ungetc(c, stream);
			break ;
		}
	}
}

int	argo(json *dst, FILE *stream)
{
	json tempnode;
	skipspaces(stream);
	if (peek(stream) == '{')
		parsemap
}