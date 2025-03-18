#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *const morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
	".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
	".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
	"----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.",
	"-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-",
	".-..-.", "...-..-", ".--.-.", "...---..."};
const char *const ascii[55] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
	"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
	"Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'",
	"!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@",
	"SOS"};

char	*strjoin(char *s1, const char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = strlen(s1) + strlen(s2);
	i = 0;
	str = calloc(len + 1, sizeof(char));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	return (str);
}

const char	*get_str(char *mor_char)
{
	int	i;

	i = 0;
	while (i < 55)
	{
		if (strcmp(morse[i], mor_char) == 0)
			return (ascii[i]);
		i++;
	}
	return (0);
}

char	*decode_morse(const char *morse_code) //".... . -.--   .--- ..- -.. ."
{
	char curr_arr[10];
	char *oldline;
	char *line;
	const char *str;
	str = morse_code;
	int i = 0;
	int j;

	line = calloc(1, sizeof(char));

	while (str[i])
	{
		memset(curr_arr, 0, sizeof(curr_arr));
		for (int k = 0; str[i] && str[i] == ' '; k++)
			i++;
		j = 0;
		while (str[i] != ' ' && str[i])
		{
			curr_arr[j] = str[i];
			j++;
			i++;
		}
		if (strlen(curr_arr))
		{
			oldline = line;
			const char *chars = get_str(curr_arr);

			line = strjoin(line, chars);
			free(oldline);
			memset(curr_arr, 0, sizeof(curr_arr));
		}
		j = 0;
		while (str[i] && str[i] == ' ')
		{
			if (str[i + 1] != ' ' && j == 0)
			{
				i++;
				break ;
			}
			i++;
			j++;
		}
		if (str[i] == 0)
			return (line);
		if (j == 3)
		{
			oldline = line;
			line = strjoin(line, " ");
			free(oldline);
		}
	}

	// return a heap-allocated string:
	return (line);
}

// int	main(void)
// {
// 	char *line = decode_morse("      ...---... -.-.--
//			- .... .   --.- ..- ..
// 			-.-. -.-   -... .-. --- .-- -.   ..-. ---
// 			-..-   .--- ..- -- .--. ...   --- ...- . .-.
// 			- .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-  ");
// 	printf("%s\n", line);
// 	free(line);
// }