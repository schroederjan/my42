#include <stdlib.h>
#include <string.h>

static int  count_words(char const *s, char c) {
    int count = 0;
    while (*s != '\0') {
        while (*s == c) s++;
        if (*s != '\0') {
            count++;
            while (*s != '\0' && *s != c) s++;
        }
    }
    return count;
}

static char *make_word(char const *s, char c) {
    char *word;
    int i = 0;

    while (s[i] != '\0' && s[i] != c)
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (s[i] != '\0' && s[i] != c) {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

char **ft_split(char const *s, char c) {
    char **words;
    int i = 0;

    if (!s) return NULL;
    words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!words) return NULL;
    while (*s != '\0') {
        while (*s == c) s++;
        if (*s != '\0') {
            words[i] = make_word(s, c);
            i++;
            while (*s != '\0' && *s != c) s++;
        }
    }
    words[i] = NULL;
    return words;
}
