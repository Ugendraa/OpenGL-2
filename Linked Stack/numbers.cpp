#include<string.h>

int itoa(int n, char s[])
{
    int i, sign,len;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
	len=strlen(s);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
	return len;
}

