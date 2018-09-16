#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>


#define CHECK(LINE, EXPECTED)	\
{								\
	int rc = LINE;				\
	if (rc != EXPECTED) {		\
		ut_abort(__FILE__, __LINE__, #LINE, rc, EXPECTED);}}


void ut_abort(char *file, int ln, char *line, int rc, int exp)
{
	fprintf(stderr, "%s line %d\n'%s': expected %d, got %d\n", file, ln, line, exp, rc);
	exit(1);
}


int main(int argc, char const *argv[])
{
	struct stat* stat_buff;
	CHECK(stat("/tmp", &stat_buff), 0);
	CHECK(stat("/non-exist-path", &stat_buff), 0);

	return 0;
}


/*
$ gcc -o CHECK CHECK.c
CHECK.c: 在函数‘main’中:
CHECK.c:23:21: 警告：传递‘stat’的第 2 个参数时在不兼容的指针类型间转换 [-Wincompatible-pointer-types]
  CHECK(stat("/tmp", &stat_buff), 0);
                     ^
CHECK.c:8:11: 附注：in definition of macro ‘CHECK’
  int rc = LINE;    \
           ^~~~
In file included from CHECK.c:3:0:
/usr/include/sys/stat.h:152:5: 附注：需要类型‘struct stat * restrict’，但实参的类型为‘struct stat **’
 int stat (const char *__restrict __path, struct stat *__restrict __sbuf );
     ^~~~
CHECK.c:24:32: 警告：传递‘stat’的第 2 个参数时在不兼容的指针类型间转换 [-Wincompatible-pointer-types]
  CHECK(stat("/non-exist-path", &stat_buff), 0);
                                ^
CHECK.c:8:11: 附注：in definition of macro ‘CHECK’
  int rc = LINE;    \
           ^~~~
In file included from CHECK.c:3:0:
/usr/include/sys/stat.h:152:5: 附注：需要类型‘struct stat * restrict’，但实参的类型为‘struct stat **’
 int stat (const char *__restrict __path, struct stat *__restrict __sbuf );
     ^~~~

kolya@asusn43sl ~/src/ThePragmaticProgrammer/ch3
$ ./CHECK
CHECK.c line 24
'stat("/non-exist-path", &stat_buff)': expected 0, got -1
*/