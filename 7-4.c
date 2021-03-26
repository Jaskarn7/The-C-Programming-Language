void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int *ival;

	va_start(ap, fmt);

	for (p = fmt; *p != '\0'; ++p) {
		if (*p == '%') {
			switch (*++p) {
				case 'd':
					ival = va_arg(ap, int *);
					scanf("%d", ival);
					break;
				case 's':
					sval = va_arg(ap, char *);
					scanf("%s", sval);
					break;
				default:
					break;
			}
		}
	}
	va_end(ap);
}
