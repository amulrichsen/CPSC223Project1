//
//  grep.h
//  grep
//
//  Created by Anette Ulrichsen on 4/10/19.
//  Copyright © 2019 Anette Ulrichsen. All rights reserved.
//

#ifndef grep_h
#define grep_h

const int BLKSIZE = 4096;  const int NBLK = 2047;  const int FNSIZE = 128;  const int LBSIZE = 4096;
const int ESIZE = 256; const int GBSIZE = 256;  const int NBRA = 5;  const int KSIZE = 9;  const int CBRA = 1;
const int CCHR = 2;  const int CDOT = 4;  const int CCL = 6;  const int NCCL = 8;  const int CDOL = 10;
const int CEOF = 11;  const int CKET = 12;  const int CBACK = 14;  const int CCIRC = 15;  const int STAR = 01;
const int READ = 0;  const int WRITE = 1;  /* const int EOF = -1; */

int  peekc, lastc, given, ninbuf, io, pflag;
int  vflag  = 1, oflag, listf, listn, col, tfile  = -1, tline, iblock  = -1, oblock  = -1, ichanged, nleft;
int  names[26], anymarks, nbra, subnewa, subolda, fchange, wrapp, bpagesize = 20;
unsigned nlall = 128;  unsigned int  *addr1, *addr2, *dot, *dol, *zero;

long  count;
char  Q[] = "", T[] = "TMP", savedfile[FNSIZE], file[FNSIZE], linebuf[LBSIZE], rhsbuf[LBSIZE/2], expbuf[ESIZE+4];
char  genbuf[LBSIZE], *nextip, *linebp, *globp, *mktemp(char *), tmpXXXXX[50] = "/tmp/eXXXXX";
char  *tfname, *loc1, *loc2, ibuff[BLKSIZE], obuff[BLKSIZE], WRERR[]  = "WRITE ERROR", *braslist[NBRA], *braelist[NBRA];
char  line[70];  char  *linp  = line;
void commands(void); void add(int i);  unsigned int *address(void);  int advance(char *lp, char *ep);
int append(int (*f)(void), unsigned int *a);  int backref(int i, char *lp);
void blkio(int b, char *buf, long (*iofcn)(int, void*, unsigned long));  void callunix(void);
int cclass(char *set, int c, int af);  void compile(int eof);
int compsub(void);  void dosub(void);  void error(char *s);  int execute(unsigned int *addr);  void exfile(void);
void filename(int comm);  void gdelete(void);  char *getblock(unsigned int atl, int iof); int getchr(void);
int getcopy(void);  int getfile(void);  char *getline_blk(unsigned int tl);  int getnum(void);  int getsub(void);
int gettty(void);  int gety(void);  void global(int k);  void init(void);
void join(void);  void move_(int cflag);  void newline(void);  void nonzero(void);  void onhup(int n);
void onintr(int n);  char *place(char *sp, char *l1, char *l2);  void print(void);  void putchr_(int ac);
void putd(void);  void putfile(void);  int putline(void);  void puts_(char *sp); void quit(int n);
void rdelete(unsigned int *ad1, unsigned int *ad2);
void setwide(void);  void setnoaddr(void);  void squeeze(int);  void substitute(int inglob);
jmp_buf  savej;
char grepbuf[GBSIZE];
void greperror(char);  void grepline(void);

typedef void  (*SIG_TYP)(int);
SIG_TYP  oldhup, oldquit;
char ssbuf[ESIZE];
int bp = 0;
void copyclargs(const char* fname, const char* sstring);
int grabchar(void);
void openfile(void);
void search_file(const char* filename, const char* searchfor);
void process_dir(const char* dir, const char* searchfor, void (*fp)(const char*, const char*));
int star(char *lp, char *ep, char *curlp);
void cerror(void);

#endif /* grep_h */
