# get_next_line

The third project at school 42 requires you to build a function that reads a file up to the next newline character, building a string of its text up to this point, and assigning this string to a pointer given as a parameter. For the full brief see the get_next_line.en.pdf.

The function is dependent on usage of functions created in our first project ‘libft’, which is included in this repository. 

My version uses a linked list to build the string produced by calls to read. When a new-line character is found in the sring built by read, its index is stored, and the string before this index is assigned to *line. The string after is assigned to the static char pointer *leftover, which is checked during successive calls to get_next_line, before read is called again.

Prototype: 

int	get_next_line(int fd, char **line)

Return value:

Get next line returns (1) if there is still more of the file to read, (0) if the whole file has been read, and (-1) if there are any errors.
