#include "../includes/cub3d.h"

char	*ft_strjoin_delimiter(char const *s1, char const *s2, char del)
{
	char	*str;
	int		total;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(str = (char*)malloc(total * sizeof(char))))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
    str[i++] = del;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void remove_spaces(char* s) {
    int count;
    int i;

    count = 0;
    i = 0;
    while(s[i])
    {
        if (s[i] != ' ')
            s[count++] = s[i];
        i++;
    }
    s[count] = '\0';
}


int parse_map_pattern(char *buff, t_map_data *data, int fd)
{
    char *tmp;
    int ret;

    if(buff[0] == '\0')
        error("map not found");
    remove_spaces(buff);
    tmp = space_to_wall(buff);
    printf("%s", buff);
    while ((ret = get_next_line(fd, &buff)) >= 0)
		{   
            remove_spaces(buff);
            printf("%s", buff);
            tmp = ft_strjoin_delimiter(tmp, space_to_wall(buff), '|');
            free(buff);
			if(ret == 0)
				break;
		}
    ret = 0;
    data->pattern = ft_split(tmp, '|');
    free(tmp);
    get_map_height(data);
    return 0;
}

char *space_to_wall(char *line)
{
    int i;
    char *new;

    i = 0;
    if(!(new = (char*)malloc(sizeof(char)*(ft_strlen(line) + 1))))
        return NULL;
    while(line[i])
    {
        if(line[i] == ' ')
            new[i] = 'X';
        else 
            new[i] = line[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

