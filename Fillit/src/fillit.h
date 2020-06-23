#ifndef FILLIT_H
#define  FILLIT_H
#include <string.h>

typedef struct s_data
{
	int firstposition;
	int lastposition;
	int secondposition;
	int thirdposition;
	char structarr[17];
	int status;
	char finarr[4][4];
	char coords[3][2];
	int numoftet;
	char letter;
	int perfectnum;
}               t_data;

t_data validate_map(t_data contents);
char *readdata(int fd, char *argv);
t_data checktetrisymbol(t_data contents);
t_data findsecondandthird(t_data contents);
t_data countdifferences(t_data contents);
void readandassign(char *carr, t_data *arr);
int numoftetrimino(char *arr);
void uni_to_bi(t_data *arr);
int findmin(t_data *arr, int arrindex);
void adjust_positions_first(t_data *arr, int arrindex);
void pre_adjust(t_data *arr, int arrindex);
int swap_first(t_data *arr, int arrindex);
void swap_first_left(t_data *arr, int arrindex, int count);
void start_all_left(t_data *arr);
void start_all(t_data *arr);
char **malloc_matrix(char **final, int num);
void assign_dots(char **final, int num);
char **add_more_space(t_data *arr, char **final, int count);
char **start_and_malloc(char **final, int num, t_data *arr);
t_data *find_size(t_data *arr);
void loop(t_data *arr);
int solve(t_data *arr, char **final, int indexx);
char **init_solve(t_data *arr, char **final);

int check_status(t_data *arr);
int check_file_existance(int argc);
void print_map(t_data *arr, char **final);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *str);


#endif