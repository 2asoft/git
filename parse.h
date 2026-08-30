#ifndef PARSE_H
#define PARSE_H

int git_parse_signed(const char *value, intmax_t *ret, intmax_t max);
int git_parse_unsigned(const char *value, uintmax_t *ret, uintmax_t max);
int git_parse_ssize_t(const char *, ssize_t *);
int git_parse_size_t(const char *, size_t *);
int git_parse_ulong(const char *, unsigned long *);
int git_parse_uint(const char *value, unsigned int *ret);
int git_parse_int(const char *value, int *ret);
int git_parse_int64(const char *value, int64_t *ret);
int git_parse_double(const char *value, double *ret);

/*
 * Parse an unsigned duration with an optional suffix of "s", "m", "h", "d",
 * or "w". Values without a suffix are seconds.
 */
int git_parse_duration(const char *value, timestamp_t *ret);

/**
 * Same as `git_config_bool`, except that it returns -1 on error rather
 * than dying.
 */
int git_parse_maybe_bool(const char *);
int git_parse_maybe_bool_text(const char *value);

int git_env_bool(const char *, int);
unsigned long git_env_ulong(const char *, unsigned long);

#endif /* PARSE_H */
