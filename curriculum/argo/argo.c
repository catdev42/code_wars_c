#include "argo.h"

int g_erro  = 0;

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
/*
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
}*/

bool isnum(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

//void or not void?
json parsenum(FILE *stream)
{
	json num;
	int howmany;
	char c;

	num.type = INTEGER;
	num.integer = 0;
	if(fscanf(stream, "%d", &num.integer) <= 0)
		g_erro = 1;
	// for (int i = 0; i < howmany; i++)
	// {
	// 	c = peek(stream);
	// 	if (isdigit(c))
	// 		if (expect(stream, c) == 0)
	// 			g_erro = 1;
	// }
	return num;

	//char c;

	//c = peek(stream);
	//accept(stream, c);

}

json parse_j(FILE *str)
{
	json crazy;

	if (peek(str) == '-' || isdigit(peek(str)))
		return(parsenum(str));
	crazy.type = STRING;
	crazy.string = NULL;
	g_erro = 1;
	return (crazy);
}

int	argo(json *dst, FILE *stream)
{
	*dst = parse_j(stream);
	//json tempnode;

	//skipspaces(stream);
	//do we have only one line or endtire file
	//if file, we need a while loop until EOF
	//if (peek(stream) == '{')
	//	dst = parsemap(stream);
	//else if (peek(stream) == '"')
	//	dst = parsestring(stream);
	
	//if (peek(stream) == '-' || isdigit(peek(stream)))
	//	tempnode = parsenum(stream);
	if (g_erro)
	{
		unexpected(stream);
		return (-1);
	}
	return (1);


}