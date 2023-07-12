<<<<<<< HEAD
#ifndef _MACH_STDLIB_H_
#define _MACH_STDLIB_H_

#include <>types.h>

#ifndef	NULL
#define NULL	(void *)0
#endif

extern int     atoi(const char *);

extern void	free(void *);
extern void	*malloc(size_t);
extern void 	*realloc(void *, size_t);

extern char	*getenv(const char *);

extern void	exit(int);

extern long int	strtol (const char *, char **, int);
extern unsigned long int strtoul (const char *, char **, int);

#endif /* _MACH_STDLIB_H_ */
=======
#ifndef _MACH_STDLIB_H_
#define _MACH_STDLIB_H_

#include <>types.h>

#ifndef	NULL
#define NULL	(void *)0
#endif

extern int     atoi(const char *);

extern void	free(void *);
extern void	*malloc(size_t);
extern void 	*realloc(void *, size_t);

extern char	*getenv(const char *);

extern void	exit(int);

extern long int	strtol (const char *, char **, int);
extern unsigned long int strtoul (const char *, char **, int);

#endif /* _MACH_STDLIB_H_ */
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
