
/* From: gemini@homxb.UUCP (Rick Richardson)
 * Newsgroups: net.sources
 * Subject: Dhrystone Version 1.1 Source
 * Message-ID: <1369@homxb.UUCP>
 * Date: 1 Apr 86 01:58:37 GMT
 * Date-Received: 2 Apr 86 22:32:20 GMT
 * Organization: PC Research, Inc.
 */

/*  EVERBODY:       Please read "APOLOGY" below. -rick 01/06/85
 *                  See introduction in net.arch, or net.micro
 *
 *  "DHRYSTONE" Benchmark Program
 *
 *  Version:        C/1.1, 12/01/84
 *
 *  Date:           PROGRAM updated 01/06/86, RESULTS updated 03/31/86
 *                  Timer routines added 26 Sep 1992.
 *
 *  Author:         Reinhold P. Weicker, CACM Vol 27, No 10, 10/84,pg.1013
 *                  Translated from ADA by Rick Richardson
 *                  Every method to preserve ADA-likeness has been used,
 *                  at the expense of C-ness.
 *
 *  Compile:        (1) Registers, NO optimization, 'UNIX' timer option.
 *                      cc -DUNIX -DROPT dhry11.c -o dhryr
 *
 *                  (2) Registers, optimization, 'UNIX' timer option.
 *                      cc -DUNIX -DROPT -O dhry11.c -o dhryro
 *
 *                  (3) NO registers, NO optimization,'UNIX' timer option.
 *                      cc -DUNIX dhry11.c -o dhry
 *
 *                  (4) NO registers, optimization, 'UNIX' timer option.
 *                      cc -DUNIX -O dhry11.c -o dhryo
 *
 *  The following program contains statements of a high-level programming
 *  language (C) in a distribution considered representative:
 *
 *  assignments                     53%
 *  control statements              32%
 *  procedure, function calls       15%
 *
 *  100 statements are dynamically executed.  The program is balanced with
 *  respect to the three aspects:
 *          - statement type
 *          - operand type (for simple data types)
 *          - operand access
 *            operand global, local, parameter, or constant.
 *
 *  The combination of these three aspects is balanced only approximately.
 *
 *  The program does not compute anything meaningfull, but it is
 *  syntactically and semantically correct.
 *
 */

#include <stdio.h>

#ifndef ROPT
#define REG
#else
#define REG register
#endif

/* Compiler dependent options */
#undef  NOENUM            /* Define if compiler has no enum's */
#undef  NOSTRUCTASSIGN    /* Define if compiler can't assign structures */

/* for compatibility with goofed up version */
/* #define GOOF           /* Define if you want the goofed up version */

#ifdef GOOF
char    Version[] = "1.0";
#else
char    Version[] = "1.1";
#endif

char    Reg_Define[] = "Register option selected.";

#ifdef  NOSTRUCTASSIGN
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s)      d = s
#endif

#ifdef  NOENUM
#define Ident1  1
#define Ident2  2
#define Ident3  3
#define Ident4  4
#define Ident5  5
typedef int     Enumeration;
#else
typedef enum    {Ident1, Ident2, Ident3, Ident4, Ident5} Enumeration;
#endif

typedef int     OneToThirty;
typedef int     OneToFifty;
typedef char    CapitalLetter;
typedef char    String30[31];
typedef int     Array1Dim[51];
typedef int     Array2Dim[51][51];

struct  Record
{
	struct Record           *PtrComp;
	Enumeration             Discr;
	Enumeration             EnumComp;
	OneToFifty              IntComp;
	String30                StringComp;
};

typedef struct Record   RecordType;
typedef RecordType *    RecordPtr;
typedef int             boolean;

#define NULL            0
#define TRUE            1
#define FALSE           0

extern Enumeration      Func1();
extern boolean          Func2();

double dhry, mips;

void main()
{
	Proc0();
	exit(0);
}

/*
 * Package 1
 */
int             IntGlob;
boolean         BoolGlob;
char            Char1Glob;
char            Char2Glob;
Array1Dim       Array1Glob;
Array2Dim       Array2Glob;
RecordPtr       PtrGlb;
RecordPtr       PtrGlbNext;

Proc0()
{
	OneToFifty              IntLoc1;
	REG OneToFifty          IntLoc2;
	OneToFifty              IntLoc3;
	REG char                CharLoc;
	REG char                CharIndex;
	Enumeration             EnumLoc;
	String30                String1Loc;
	String30                String2Loc;
	extern char             *malloc();

	double                  dtime();
	double                  starttime;
	double                  benchtime;
	double                  nulltime;
	long                    LOOPS;
	register unsigned int   i;
	FILE                    *Ap;

	if ((Ap = fopen("dhry.res","a+")) == NULL)
	  {
	    printf("Can not open dhry.res\n\n");
	    exit(1);
	  }

	printf("Enter number of loops (500000 or more): ");
	{
	int n;
	scanf("%d",&n);
	LOOPS = n;
	}
	printf("\n");

	starttime = dtime();
	for (i = 0; i < LOOPS; ++i);
	nulltime = dtime() - starttime;
	/* Computes overhead of looping */

	PtrGlbNext = (RecordPtr) malloc(sizeof(RecordType));
	PtrGlb = (RecordPtr) malloc(sizeof(RecordType));
	PtrGlb->PtrComp = PtrGlbNext;
	PtrGlb->Discr = Ident1;
	PtrGlb->EnumComp = Ident3;
	PtrGlb->IntComp = 40;
	strcpy(PtrGlb->StringComp, "DHRYSTONE PROGRAM, SOME STRING");
#ifndef GOOF
	strcpy(String1Loc, "DHRYSTONE PROGRAM, 1'ST STRING");   /*GOOF*/
#endif
	Array2Glob[8][7] = 10;  /* Was missing in published program */

/*****************
-- Start Timer --
*****************/
	starttime = dtime();

	for (i = 0; i < LOOPS; ++i)
	{

		Proc5();
		Proc4();
		IntLoc1 = 2;
		IntLoc2 = 3;
		strcpy(String2Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
		EnumLoc = Ident2;
		BoolGlob = ! Func2(String1Loc, String2Loc);
		while (IntLoc1 < IntLoc2)
		{
			IntLoc3 = 5 * IntLoc1 - IntLoc2;
			Proc7(IntLoc1, IntLoc2, &IntLoc3);
			++IntLoc1;
		}
		Proc8(Array1Glob, Array2Glob, IntLoc1, IntLoc3);
		Proc1(PtrGlb);
		for (CharIndex = 'A'; CharIndex <= Char2Glob; ++CharIndex)
			if (EnumLoc == Func1(CharIndex, 'C'))
				Proc6(Ident1, &EnumLoc);
		IntLoc3 = IntLoc2 * IntLoc1;
		IntLoc2 = IntLoc3 / IntLoc1;
		IntLoc2 = 7 * (IntLoc3 - IntLoc2) - IntLoc1;
		Proc2(&IntLoc1);
	}

/*****************
-- Stop Timer --
*****************/
	
	benchtime = dtime() - starttime - nulltime;

	if ( benchtime < 2.0 )
	{
	printf("Runtime < 2 sec. Abort run. Please re-run and enter\n");
	printf("                 larger number of loops.\n");
	exit(1);
	}

	printf("Dhrystone( %s) time for %ld passes = %7.1lf\n",
	Version,
	(long) LOOPS, benchtime);

#ifdef ROPT        
	printf("Register option selected?  YES\n");
#else
	printf("Register option selected?  NO\n");
	strcpy(Reg_Define, "Register option not selected.");
#endif

dhry = (double)LOOPS / benchtime;
printf("This machine benchmarks at %10.1lf dhrystones/second\n",dhry);
mips = dhry / 1757.0;
printf("VAX MIPS rating = %10.3lf\n\n",mips);

fprintf(Ap,"\n");
fprintf(Ap,"Dhrystone Benchmark, Version 1.1 (Language: C)\n");
fprintf(Ap,"%s\n",Reg_Define);
fprintf(Ap,"Number of loops: %ld\n",LOOPS);
fprintf(Ap,"Runtime (sec): %8.1lf\n",benchtime);
fprintf(Ap,"Dhrystones/sec: %10.1lf\n",dhry);
fprintf(Ap,"VAX MIPS rating: %10.3lf\n",mips);
fclose(Ap);

}

Proc1(PtrParIn)
REG RecordPtr   PtrParIn;
{
#define NextRecord      (*(PtrParIn->PtrComp))

	structassign(NextRecord, *PtrGlb);
	PtrParIn->IntComp = 5;
	NextRecord.IntComp = PtrParIn->IntComp;
	NextRecord.PtrComp = PtrParIn->PtrComp;
	Proc3(NextRecord.PtrComp);
	if (NextRecord.Discr == Ident1)
	{
		NextRecord.IntComp = 6;
		Proc6(PtrParIn->EnumComp, &NextRecord.EnumComp);
		NextRecord.PtrComp = PtrGlb->PtrComp;
		Proc7(NextRecord.IntComp, 10, &NextRecord.IntComp);
	}
	else
		structassign(*PtrParIn, NextRecord);

#undef  NextRecord
}

Proc2(IntParIO)
OneToFifty      *IntParIO;
{
	REG OneToFifty          IntLoc;
	REG Enumeration         EnumLoc;

	IntLoc = *IntParIO + 10;
	for(;;)
	{
		if (Char1Glob == 'A')
		{
			--IntLoc;
			*IntParIO = IntLoc - IntGlob;
			EnumLoc = Ident1;
		}
		if (EnumLoc == Ident1)
			break;
	}
}

Proc3(PtrParOut)
RecordPtr       *PtrParOut;
{
	if (PtrGlb != NULL)
		*PtrParOut = PtrGlb->PtrComp;
	else
		IntGlob = 100;
	Proc7(10, IntGlob, &PtrGlb->IntComp);
}

Proc4()
{
	REG boolean     BoolLoc;

	BoolLoc = Char1Glob == 'A';
	BoolLoc |= BoolGlob;
	Char2Glob = 'B';
}

Proc5()
{
	Char1Glob = 'A';
	BoolGlob = FALSE;
}

extern boolean Func3();

Proc6(EnumParIn, EnumParOut)
REG Enumeration EnumParIn;
REG Enumeration *EnumParOut;
{
	*EnumParOut = EnumParIn;
	if (! Func3(EnumParIn) )
		*EnumParOut = Ident4;
	switch (EnumParIn)
	{
	case Ident1:    *EnumParOut = Ident1; break;
	case Ident2:    if (IntGlob > 100) *EnumParOut = Ident1;
			else *EnumParOut = Ident4;
			break;
	case Ident3:    *EnumParOut = Ident2; break;
	case Ident4:    break;
	case Ident5:    *EnumParOut = Ident3;
	}
}

Proc7(IntParI1, IntParI2, IntParOut)
OneToFifty      IntParI1;
OneToFifty      IntParI2;
OneToFifty      *IntParOut;
{
	REG OneToFifty  IntLoc;

	IntLoc = IntParI1 + 2;
	*IntParOut = IntParI2 + IntLoc;
}

Proc8(Array1Par, Array2Par, IntParI1, IntParI2)
Array1Dim       Array1Par;
Array2Dim       Array2Par;
OneToFifty      IntParI1;
OneToFifty      IntParI2;
{
	REG OneToFifty  IntLoc;
	REG OneToFifty  IntIndex;

	IntLoc = IntParI1 + 5;
	Array1Par[IntLoc] = IntParI2;
	Array1Par[IntLoc+1] = Array1Par[IntLoc];
	Array1Par[IntLoc+30] = IntLoc;
	for (IntIndex = IntLoc; IntIndex <= (IntLoc+1); ++IntIndex)
		Array2Par[IntLoc][IntIndex] = IntLoc;
	++Array2Par[IntLoc][IntLoc-1];
	Array2Par[IntLoc+20][IntLoc] = Array1Par[IntLoc];
	IntGlob = 5;
}

Enumeration Func1(CharPar1, CharPar2)
CapitalLetter   CharPar1;
CapitalLetter   CharPar2;
{
	REG CapitalLetter       CharLoc1;
	REG CapitalLetter       CharLoc2;

	CharLoc1 = CharPar1;
	CharLoc2 = CharLoc1;
	if (CharLoc2 != CharPar2)
		return (Ident1);
	else
		return (Ident2);
}

boolean Func2(StrParI1, StrParI2)
String30        StrParI1;
String30        StrParI2;
{
	REG OneToThirty         IntLoc;
	REG CapitalLetter       CharLoc;

	IntLoc = 1;
	while (IntLoc <= 1)
		if (Func1(StrParI1[IntLoc], StrParI2[IntLoc+1]) == Ident1)
		{
			CharLoc = 'A';
			++IntLoc;
		}
	if (CharLoc >= 'W' && CharLoc <= 'Z')
		IntLoc = 7;
	if (CharLoc == 'X')
		return(TRUE);
	else
	{
		if (strcmp(StrParI1, StrParI2) > 0)
		{
			IntLoc += 7;
			return (TRUE);
		}
		else
			return (FALSE);
	}
}

boolean Func3(EnumParIn)
REG Enumeration EnumParIn;
{
	REG Enumeration EnumLoc;

	EnumLoc = EnumParIn;
	if (EnumLoc == Ident3) return (TRUE);
	return (FALSE);
}

#ifdef  NOSTRUCTASSIGN
memcpy(d, s, l)
register char   *d;
register char   *s;
register int    l;
{
	while (l--) *d++ = *s++;
}
#endif
