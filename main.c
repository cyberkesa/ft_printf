

#include "ft_printf.h"
#include "stdio.h"

//void	test(int n)
//{
//	write(1, "1: ", 3);
//	printf("%s", pf_itoa_base(n, 16));
//	printf("\n");
//	printf("2: %x\n\n", n);
//}

int		main()
{
	int		v;
	int		m;
	v = 0;
	m = 0;
	char *str;
	str = "you are my baby";

	//test(0);
	//test(1);
	//test(9);
	//test(10);
	//test(15);
	//test(16);
	//test(20);
	//test(0xFF);
	//test(0xFFF);

	//printf("\n\033[0;33mTest ----'di'----	\033[0m#1\n");
	//printf("1real:			|%9.i|\n", v + m);
	//ft_printf("1my:			|%9.i|\n", v + m);

	//printf("\nTest 'di' #2\n");
	//printf("2real:			|%1.i|\n", 12);
	//ft_printf("2my:			|%1.i|\n", 12);

	//printf("\nTest 'di' #3\n");
	//printf("3real:			|%10.i|\n", m);
	//ft_printf("3my:			|%10.i|\n", m);

	//printf("\nTest 'di' #4\n");
	//printf("4real:			|%1i|\n", m);
	//ft_printf("4my:			|%1i|\n", m);

	//printf("\nTest 'di' #5\n");
	//printf("5real:			|%-.5i|\n", v);
	//ft_printf("5my:			|%-.5i|\n", v);

	//printf("\nTest 'di' #6\n");
	//printf("6real:			|%909.99i|\n", v);
	//ft_printf("6my:			|%909.99i|\n", v);

	//printf("\nTest 'di' #7\n");
	//printf("7real:			|%.8i|\n", v);
	//ft_printf("7my:			|%.8i|\n", v);

	//printf("\nTest 'di' #8\n");
	//printf("8real:			|%-.d|\n", m);
	//ft_printf("8my:			|%-.d|\n", m);

	//printf("\nTest 'di'		#9\n");
	//printf("9real:			|%8.6i|\n", v);
	//ft_printf("9my:			|%8.6i|\n", v);

	//printf("\nTest 'di'		#10\n");
	//printf("10real:			|%-89.5i|\n", v);
	//ft_printf("10my:			|%-89.5i|\n", v);

	//printf("\nTest 'di'		#11\n");
	//printf("11real:			|%0*i|\n", 21, 54);
	//ft_printf("11my:			|%0*i|\n", 21, 54);

	//printf("\nTest 'di'		#12\n");
	//printf("real:			|%0112.5i|\n", m);
	//ft_printf("my:			|%0112.5i|\n", m);

	//printf("\nTest 'di'		#13\n");
	//printf("real:			|%-89.590i|\n", m);
	//ft_printf("my:			|%-89.590i|\n", m);

	//printf("\nTest 'di'		#14\n");
	//ft_printf("real:	|%----------------*i|\n", 0, 13);
	//printf("my:	|%----------------*i|\n", 0, 13);

	//printf("\nTest 'di'		#15\n");
	//printf("real:			|%-.5i|\n", m);
	//ft_printf("my:			|%-.5i|\n", m);

	//printf("\nTest 'di'		#16\n");
	//printf("real:			|%092.5i|\n", m);
	//ft_printf("my:			|%092.5i|\n", m);

	//printf("\nTest 'di'		#17\n");
	//printf("real:			|%12.7i|\n", m);
	//ft_printf("my:			|%12.7i|\n", m);

	//printf("\nTest 'di'		#18\n");
	//printf("real:			|%-.58i|\n", m);
	//ft_printf("my:			|%-.58i|\n", m);

	//printf("\nTest 'di'		#19\n");
	//printf("real:			|%010i|\n", m);
	//ft_printf("my:			|%010i|\n", m);

	//printf("\nTest 'di'		#20\n");
	//printf("real:			|%014i|\n", m);
	//ft_printf("my:			|%014i|\n", m);

	//printf("\nTest 'di'		#21\n");
	//printf("real:			|%010i|\n", v);
	//ft_printf("my:			|%010i|\n", v);

	//printf("\nTest 'di'		#22\n");
	//printf("real:			|%014i|\n", v);
	//ft_printf("my:			|%014i|\n", v);

	//printf("\nTest 'di'		#23\n");
	//printf("real:			|%-*i|\n", -1, m);
	//ft_printf("my:			|%-*i|\n", -1, m);

	//printf("\nTest 'di'		#24\n");
	//printf("real:			|%*.*i|\n", -1, -1, -0);
	//ft_printf("my:			|%*.*i|\n", -1, -1, -0);

	//printf("\nTest 'di'		#25\n");
	//printf("real:			|%*i|\n", 393, v);
	//ft_printf("my:			|%*i|\n", 393, v);

	//printf("\nTest 'di'		#26\n");
	//printf("real:			|%194i|\n", v);
	//ft_printf("my:			|%194i|\n", v);

	//printf("\nTest 'di'		#27\n");
	//printf("real:			|%*.*i|\n", 1, 41, 4);
	//ft_printf("my:			|%*.*i|\n", 1, 41, 4);

	//printf("\nTest 'di'		#28\n");
	//printf("real:			|%*.i|\n", 0, -4);
	//ft_printf("my:			|%*.i|\n", 0, -4);

	//printf("\nTest 'di'		#29\n");
	//printf("real:			|%*.*i|\n", 21, 34, 54);
	//ft_printf("my:			|%*.*i|\n", 21, 34, 54);

	//printf("\nTest 'di'		#30\n");
	//ft_printf("real:			|%*.d%i%d|\n", 1, 2, 3, 4);
	//printf("real:			|%*.d%i%d|\n", 1, 2, 3, 4);

	//printf("\nTest 'di'		#31\n");
	//printf("real:			|%*.d%i%d%i%d%i%d%d%d%d%d%d%d%.d%i%d%i%d%i%d%d%d%d%d%d%d%.d%i%d%i%d%i%d%d%d%d%d%d%d|\n", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 11, 12, 14, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14);
	//ft_printf("my:			|%*.d%i%d%i%d%i%d%d%d%d%d%d%d%.d%i%d%i%d%i%d%d%d%d%d%d%d%.d%i%d%i%d%i%d%d%d%d%d%d%d|\n", 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 11, 12, 14, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14);

	//printf("\nTest 'di'		#32\n");
	//printf("real:	|%*%|\n", 88);
	//ft_printf("34my:	|%*%|\n", 88);

	//printf("\nTest 'di'		#33\n");
	//printf("real:	|-%*%|\n", 88);
	//ft_printf("35my:	|-%*%|\n", 88);

	//printf("\nTest 'di'		#34\n");
	//printf("real::	|-%*%%*%|\n", 88, 21);
	//ft_printf("36my:	|-%*%%*%|\n", 88, 21);

	//printf("\nTest 'di'		#35\n");
	//printf("real::	|%*d %*d|\n", 32, 21, 77, 99);
	//ft_printf("37my:	|%*d %*d|\n", 32, 21, 77, 99);

	//printf("\nTest 'di'		#36\n");
	//printf("real:	|%*.*d %*.*i|\n", 32, 21, 77, 99, 88, 9);
	//ft_printf("my:	|%*.*d %*.*i|\n", 32, 21, 77, 99, 88, 9);

	//printf("\nTest 'di'		#37\n");
	//printf("real:	|%*.*d %*.*i|\n", -32, -21, -77, -99, -88, -9);
	//ft_printf("my:	|%*.*d %*.*i|\n", -32, -21, -77, -99, -88, -9);

	//printf("\nTest 'di'		#38\n");
	//printf("real:	|%0*.*d %-*.*i %*.*d %*.*i %*.*d %*.*i%*.*d %*.*i %*.*d %*.*i %*.*d %*.*i%*.*d %*.*i %*.*d %*.*i %*.*d %*.*i*rljnthoy|\n", 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 1);
	//ft_printf("my:	|%0*.*d %-*.*i %*.*d %*.*i %*.*d %*.*i%*.*d %*.*i %*.*d %*.*i %*.*d %*.*i%*.*d %*.*i %*.*d %*.*i %*.*d %*.*i*rljnthoy|\n", 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 9, 32, 21, 77, 99, 88, 1);

	//printf("\nTest 'di'		#39\n");
	//ft_printf("my:	|%.*d|\n", 40, 20);
	//printf("real:	|%.*d|\n", 40, 20);

	//printf("\nTest 'di'		#40\n");
	//ft_printf("my:	|%.*i|\n", 0, 7);
	//printf("real:	|%.*i|\n", 0, 7);

	//printf("\nTest 'di'		#41\n");
	//ft_printf("my:	|%7.*i|\n", 9, 7);
	//printf("real:	|%7.*i|\n", 9, 7);

	//printf("\nTest 'di'		#42\n");
	//ft_printf("my:	|%0.*i|\n", 9, 7);
	//printf("real:	|%0.*i|\n", 9, 7);

	//printf("\nTest 'di'		#43\n");
	//ft_printf("my:	|%.*d|\n", 0, 7);
	//printf("real:	|%.*d|\n", 0, 7);

	//printf("\nTest 'di'		#44\n");
	//ft_printf("my:	|%7.*d|\n", 9, 7);
	//printf("real:	|%7.*d|\n", 9, 7);

	//printf("\nTest 'di'		#45\n");
	//ft_printf("my:	|%0.*d|\n", 9, 7);
	//printf("real:	|%0.*d|\n", 9, 7);

	//printf("\nTest 'di'		#46\n");
	//printf("real:			|%*.80d88-|\n", 1, 8);
	//ft_printf("my:			|%*.80d88-|\n", 1, 8);

	//printf("\nTest 'di'		#47\n");
	//printf("real:			|%-*.*d|\n", 1, 8, 8);
	//ft_printf("my:			|%-*.*d|\n", 1, 8, 8);

	//printf("\nTest 'di'		#48\n");
	//ft_printf("my:	|%*.0i|\n", 9, 8);
	//printf("real:	|%*.0i|\n", 9, 8);

	//printf("\nTest 'di'		#49\n");
	//ft_printf("MY;	|%0d%-i\nHey%098d%5%|\n", 55, 2, 3);
	//printf("REAL;	|%0d%-i\nHey%098d%5%|\n", 55, 2, 3);

	//printf("\nTest 'di'		#50\n");
	//ft_printf("MY;	|%0d%-i\n%098d%5%|\n", 55, 2, 3);
	//printf("REAL;	|%0d%-i\n%098d%5%|\n", 55, 2, 3);

	//printf("\nTest 'di'		#51\n");
	//ft_printf("MY;	|%-------------0-0--*%хуй пизда|\n", 0);
	//printf("REAL;	|%-------------0-0--*%хуй пизда|\n", 0);

	//printf("\nTest 'di'		#52\n");
	//ft_printf("my:	|%*.*i|\n", 10, 9, 7);
	//printf("real:	|%*.*i|\n", 10, 9, 7);

	//printf("\nTest 'di'		#53\n");
	//ft_printf("my:	|%*.*i|\n", 0, 9, 7);
	//printf("real:	|%*.*i|\n", 0, 9, 7);

	//printf("\nTest 'di'		#54\n");
	//ft_printf("my:	|%*.*i|\n", 88, 9, 7);
	//printf("real:	|%*.*i|\n", 88, 9, 7);

	//printf("\nTest 'di'		#55\n");
	//ft_printf("my:	|%*.*i|\n", -1, 9, 7);
	//printf("real:	|%*.*i|\n", -1, 9, 7);

	//printf("\nTest 'di'		#56\n");
	//ft_printf("my:	|%*.*i|\n", -0, 9, 7);
	//printf("real:	|%*.*i|\n", -0, 9, 7);

	//printf("\nTest 'di'		#57\n");
	//ft_printf("my:	|%-*.99i|\n", -10, 9);
	//printf("real:	|%-*.99i|\n", -10, 9);

	//printf("\nTest 'di'		#58\n");
	//ft_printf("my:	|%iхуй пизда99|.*77\n", 42);
	//printf("real:	|%iхуй пизда99|.*77\n", 42);

	//printf("\nTest 'di'		#59\n");
	//ft_printf("real:	|%----------------*.*iHello, bitch|\n", 0, 13, 343);
	//printf("my:	|%----------------*.*iHello, bitch|\n", 0, 13, 343);

	//printf("\nTest 'di'		#60\n");
	//ft_printf("my:	|%0*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i|\n", m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m);
	//printf("my:	|%0*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i%*.*i|\n", m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m);

	//printf("\nTest 'di'		#61\n");
	//ft_printf("my:	|%io99|.*77\n", 42);
	//printf("real:	|%io99|.*77\n", 42);

	//printf("\nTest 'di'		#62\n");
	//ft_printf("my:	|%idcpiusx99|.*77\n", 42);
	//printf("real:	|%idcpiusx99|.*77\n", 42);

	//printf("\nTest 'di'		#63\n");
	//ft_printf("my:	|%0idcp0iu**************srhtek56j4h  x9iiiiiiii9|*.*77\n", 4002);
	//printf("real:	|%0idcp0iu**************srhtek56j4h  x9iiiiiiii9|*.*77\n", 4002);

	//printf("\nTest 'di'		#64\n");
	//ft_printf("my:	|%0-8.5d|\n", 34);
	//printf("real:	|%0-8.5d|\n", 34);

	//printf("\n\033[0;33mTest ----'s'----	\033[0m#1\n");
	//printf("real	|%-.s|\n", "fdf");
	//ft_printf("my	|%-.s|\n", "fdf");

	//printf("\nTest 's'		#2\n");
	//printf("real	|%40s|\n", str);
	//ft_printf("my	|%40s|\n", str);

	//printf("\nTest 's'		#3\n");
	//printf("real	|%-40s|\n", str);
	//ft_printf("my	|%-40s|\n", str);

	//printf("\nTest 's'		#4\n");
	//printf("real	|%*s|\n", 20, str);
	//ft_printf("my	|%*s|\n", 20, str);

	//printf("\nTest 's'		#5\n");
	//printf("real	|%*s|\n", 9, str);
	//ft_printf("my	|%*s|\n", 9, str);

	//printf("\nTest 's'		#6\n");
	//printf("real	|%-*.3s|\n", 9, str);
	//ft_printf("my	|%-*.3s|\n", 9, str);

	//printf("\nTest 's'		#7\n");
	//printf("real	|%2s|\n", str);
	//ft_printf("my	|%2s|\n", str);

	//printf("\nTest 's'		#8\n");
	//printf("real	|%-*.3s|\n", 9, str);
	//ft_printf("my	|%-*.3s|\n", 9, str);

	printf("\nTest 's'		#9\n");
	printf("real	|%0*.*s|\n", 21, m, str);
	ft_printf("my	|%0*.*s|\n", 21, m, str);

	printf("\nTest 's'		#10\n");
	printf("real	|%*.*s|\n", -8, -8, str);
	ft_printf("my	|%*.*s|\n", -8, -8, str);

	printf("\nTest 's'		#11\n");
	printf("real	|%*s|\n", -20, str);
	ft_printf("my	|%*s|\n", -20, str);

	//printf("\nTest 's'		#12\n");
	//printf("real	|%.0s|\n", str);
	//ft_printf("my	|%.0s|\n", str);

	//printf("\nTest 's'		#13\n");
	//printf("real	|%.*s|\n", -3, str);
	//ft_printf("my	|%.*s|\n", -3, str);

	//printf("\nTest 's'		#14\n");
	//printf("real	|%.s|\n", str);
	//ft_printf("my	|%.s|\n", str);

	//printf("\nTest 's'		#15\n");
	//printf("real	|%99s|\n", str);
	//ft_printf("my	|%99s|\n", str);

	//printf("\nTest 's'		#16\n");
	//printf("real	|%.s|\n", str);
	//ft_printf("my	|%.s|\n", str);

	//printf("\nTest 's'		#17\n");
	//printf("real	|%.9s|\n", str);
	//ft_printf("my	|%.9s|\n", str);

	//printf("\nTest 's'		#18\n");
	//ft_printf("my:	|%s0idcp0iu**************srhtek56j4h  x9iiiiiiii9ss|*.*77\n","fuck you");
	//printf("real:	|%s0idcp0iu**************srhtek56j4h  x9iiiiiiii9ss|*.*77\n","fuck you");

	//printf("\nTest 's'		#19\n");
	//printf("real	|%s|\n", NULL);
	//ft_printf("my	|%s|\n", NULL);

	//printf("\n\033[0;33mTest ----'c'----	\033[0m#1\n");
	//printf("real	|%12c|\n", 'd');
	//ft_printf("my	|%12c|\n", 'd');

	//printf("\n			#2\n");
	//printf("real	|%-12c|\n", 'd');
	//ft_printf("my	|%-12c|\n", 'd');

	//printf("\n			#3\n");
	//printf("real	|%12c|\n", 'd');
	//ft_printf("my	|%12c|\n", 'd');

	//printf("\n			#4\n");
	//printf("real	|%-12.c|\n", ' ');
	//ft_printf("my	|%-12.c|\n", ' ');

	//printf("\n			#5\n");
	//printf("real	|%1s|\n", NULL);
	//ft_printf("my	|%1s|\n", NULL);

	//printf("\n			#6\n");
	//printf("real	|%.s|\n", NULL);
	//ft_printf("my	|%.s|\n", NULL);

	//printf("\n			#7\n");
	//printf("real	|%s|\n", NULL);
	//ft_printf("my	|%s|\n", NULL);

	//printf("\n			#8\n");
	//printf("real	|%.0s|\n", NULL);
	//ft_printf("my	|%.0s|\n", NULL);

	//printf("\n			#8.1\n");
	//printf("real	|%10.10000000s|\n", NULL);
	//ft_printf("my	|%10.10000000s|\n", NULL);

	//printf("\n			#9\n");
	//printf("real	|%.99s|\n", NULL);
	//ft_printf("my	|%.99s|\n", NULL);

	//printf("\n			#9.1\n");
	//printf("real	|%9s|\n", NULL);
	//ft_printf("my	|%9s|\n", NULL);

	//printf("\n			#9.2\n");
	//printf("real	|%10.s|\n", NULL);
	//ft_printf("my	|%10.s|\n", NULL);

	//printf("\n			#10\n");
	//printf("real	|%.99s%s%7s|\n", "lol", "kek");
	//ft_printf("my	|%.99s%s%7s|\n", "lol", "kek");

	//printf("\n			#11\n");
	//printf("real	|%d|\n", INT_MAX + 1);
	//ft_printf("my	|%d|\n", INT_MAX + 1);

	//printf("\n			#12\n");
	//printf("real	|%d|\n", INT_MAX + 1);
	//ft_printf("my	|%d|\n", INT_MAX + 1);

	//printf("\n			#13\n");
	//printf("real	|%-5.0d|\n", 0);
	//ft_printf("my	|%-5.0d|\n", 0);

	//printf("\n			#14\n");
	//printf("real	|%d|\n", 0);
	//ft_printf("my	|%d|\n", 0);

	//printf("\n			#15\n");
	//printf("real	|%0.0d|\n", 0);
	//ft_printf("my	|%0.0d|\n", 0);


	//printf("\n\033[0;33mTest ----'multuply'----	\033[0m#1\n");
	//printf("real	|%-12.cjhsh%0100d%0*d%%%%99999%%%%lkf0d%s%-s6699906%0d0.*|\n", ' ', 100, 994, 800, "Hello", "azzaza", -1);
	//ft_printf("my	|%-12.cjhsh%0100d%0*d%%%%99999%%%%lkf0d%s%-s6699906%0d0.*|\n", ' ', 100, 994, 800, "Hello", "azzaza", -1);

	//printf("\n			#1 LOL\n");
	//printf("real	|%.5s%7s|\n", "yo", "boi");
	//ft_printf("my	|%.5s%7s|\n", "yo", "boi");

	//printf("\n			#2 LOL\n");
	//printf("real	|%.5s|\n", "yo");
	//ft_printf("my	|%.5s|\n", "yo");

	//printf("\n			#3 LOL\n");
	//printf("real	|%.5s%7s|\n", "yo", "boi");
	//ft_printf("my	|%.5s%7s|\n", "yo", "boi");

	//printf("\n			#4 LOL\n");
	//printf("real	|%.7s%.2s|\n", "hello", "world");
	//ft_printf("my	|%.7s%.2s|\n", "hello", "world");

	//printf("\n			#5 LOL\n");
	//printf("real	|%.2s%.7s|\n", "hello", "world");
	//ft_printf("my	|%.2s%.7s|\n", "hello", "world");

	//printf("\n			#6 LOL\n");
	//printf("real	|%.7s|\n", "hello");
	//ft_printf("my	|%.7s|\n", "hello");

	//printf("\n			#7 LOL\n");
	//printf("real	|%7.5s|\n", "yolo");
	//ft_printf("my	|%7.5s|\n", "yolo");

	//printf("\n			#2 LOL\n");
	//printf("real	|%d|\n", 0);
	//ft_printf("my	|%d|\n", 0);

	//printf("\n			#3 LOL\n");
	//printf("real	|%0.0d|\n", 0);
	//ft_printf("my	|%0.0d|\n", 0);

	//printf("\n			#1 NUUUULLLL\n");
	//printf("real	|%.5s%7s|\n", "yo", "boi");
	//ft_printf("my	|%.5s%7s|\n", "yo", "boi");

	//printf("\n			#2 NUUUULLLL\n");
	//printf("real	|%.03s|\n", NULL);
	//ft_printf("my	|%.03s|\n", NULL);

	//printf("\n			#3 NUUUULLLL\n");
	//printf("real	|%.5s%7s|\n", "yo", "boi");
	//ft_printf("my	|%.5s%7s|\n", "yo", "boi");

	//printf("\n			#4 NUUUULLLL\n");
	//printf("real	|%.7s%.2s|\n", "hello", "world");
	//ft_printf("my	|%.7s%.2s|\n", "hello", "world");

	//printf("\n			#5 NUUUULLLL\n");
	//printf("real	|%.2s%.7s|\n", "hello", "world");
	//ft_printf("my	|%.2s%.7s|\n", "hello", "world");

	//printf("\n			#6 NUUUULLLL\n");
	//printf("real	|%.7s|\n", "hello");
	//ft_printf("my	|%.7s|\n", "hello");

	//printf("\n			#7 NUUUULLLL\n");
	//printf("real	|%7.5s|\n", "yolo");
	//ft_printf("my	|%7.5s|\n", "yolo");



	//printf("\n			#1 uuuuu\n");
	//printf("real	|this %u number|\n", 0);
	//ft_printf("my	|this %u number|\n", 0);

	//printf("\n			#2  uuuuu\n");
	//printf("real	|%u|\n", 4294967295u);
	//ft_printf("my	|%u|\n", 4294967295u);

	//printf("\n			#3 uuuuu\n");
	//printf("real	|%3u|\n", 0);
	//ft_printf("my	|%3u|\n", 0);

	//printf("\n			#4  uuuuu\n");
	//printf("real	|%-3u|\n", 0);
	//ft_printf("my	|%-3u|\n", 0);

	//printf("\n			#5 uuuuu\n");
	//printf("real	|%03u|\n", 0);
	//ft_printf("my	|%03u|\n", 0);

	//printf("\n			#6 uuuuu\n");
	//printf("real	|%8.5u|\n", 0);
	//ft_printf("my	|%8.5u|\n", 0);

	//printf("\n			#7  uuuuu\n");
	//printf("real	|%-8.5u|\n", 0);
	//ft_printf("my	|%-8.5u|\n", 0);

	//printf("\n			#8 uuuuu\n");
	//printf("real	|%08.5u|\n", 0);
	//ft_printf("my	|%08.5u|\n", 0);

	//printf("\n			#9 uuuuu\n");
	//printf("real	|%0-8.5u|\n", 0);
	//ft_printf("my	|%0-8.5u|\n", 0);

	//printf("\n			#10  uuuuu\n");
	//printf("real	|%.3u|\n", 0);
	//ft_printf("my	|%.3u|\n", 0);

	//unsigned int	u;
	//u = 100;
	//unsigned int	j;
	//j = -100;

	//printf("\n\033[0;33mTest ----'u'----	\033[0m#1\n");
	//printf("real	|%77.9u|\n", u);
	//ft_printf("my	|%77.9u|\n", u);

	//printf("\nTest 'u'		#2\n");
	//printf("real	|%-99u|\n", u);
	//ft_printf("my	|%-99u|\n", u);

	//printf("\nTest 'u'		#3\n");
	//printf("real	|%-77.9u|\n", u);
	//ft_printf("my	|%-77.9u|\n", u);

	//printf("\nTest 'u'		#4\n");
	//printf("real	|%-99u|\n", j);
	//ft_printf("my	|%-99u|\n", j);

	//printf("\nTest 'u'		#5\n");
	//printf("real	|%u|\n", -2);
	//ft_printf("my	|%u|\n", -2);

	//printf("\n\033[0;33mTest ----'p'----	\033[0m#1\n");
	//printf("real	|%08p|\n", str);
	//ft_printf("my	|%08p|\n", str);

	//printf("\n\033[0;33mTest ----'x'----	\033[0m#1\n");
	//printf("real	|%x|\n", u);
	//ft_printf("my	|%x|\n", u);

	//printf("\nTest 'x'		#2\n");
	//printf("real	|%x|\n", -6);
	//ft_printf("my	|%x|\n", -6);

	//printf("\nTest 'x'		#3\n");
	//printf("real	|%x|\n", 5);
	//ft_printf("my	|%x|\n", 5);

	//printf("\n\033[0;33mTest ----'X'----	\033[0m#1\n");
	//printf("real	|%X|\n", 160000);
	//ft_printf("my	|%X|\n", 160000);

	//printf("\nTest 'X'		#2\n");
	//printf("real	|%X|\n", -1);
	//ft_printf("my	|%X|\n", -1);






//	void		print_s(t_t *t)
//{
//	if (t->wight < 0)
//		t->wight = -t->wight;
//	t->len_s = ft_strlen(t->data_s);
//	if (t->precision > 0 && t->precision < t->len_s)
//	{
//		t->nspace = t->wight - t->precision;
//		pf_ret(t->precision, 0);
//	}
//	else if (t->precision <= 0 || t->precision > t->len_s)
//	{
//		t->nspace = t->wight - t->len_s;
//	}
//	if (t->precision > t->len_s)
//		pf_ret(t->len_s, 0);
//	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
//	if (t->minus == 0 && t->nspace)
//		pf_print(' ', t->nspace);
//	post_print_s(t);
//}

//void		post_print_s(t_t *t)
//{
//	if (t->precision < 0 || t->p_yes == 0)
//	{
//		ft_putstr_fd(t->data_s, 1);
//		pf_ret(t->len_s, 0);
//	}
//	if (t->precision > 0 && t->precision <= t->len_s)
//		pf_print_char(t->data_s, t->precision);
//	if (t->precision > 0 && t->precision > t->len_s)
//		pf_print_char(t->data_s, t->len_s);
//	if (t->minus == 1 && t->nspace)
//		pf_print(' ', t->nspace);
//	pf_ret(t->nspace, 0);
//}

	return (0);
}
