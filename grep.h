//
//  grep.h
//  grep
//
//  Created by Anette Ulrichsen on 4/10/19.
//  Copyright © 2019 Anette Ulrichsen. All rights reserved.
//

#ifndef grep_h
#define grep_h

extern const int BLKSIZE; extern const int NBLK; extern const int FNSIZE; extern const int LBSIZE;
extern const int ESIZE; extern const int GBSIZE; extern const int NBRA; extern const int KSIZE; extern const int CBRA;
extern const int CCHR; extern const int CDOT;  extern const int CCL;  extern const int NCCL;  extern const int CDOL;
extern const int CEOF;  extern const int CKET;  extern const int CBACK;  extern const int CCIRC;  extern const int STAR;
extern const int READ;  extern const int WRITE;  /* const int EOF = -1; */

extern int  vflag; extern int tfile; extern int iblock; extern int oblock; extern int  names[26]; extern int bpagesize;
extern unsigned nlall; extern char  *linp; extern char ssbuf[]; extern char inputbuf[];

extern char  Q[]; extern char T[]; extern char savedfile[]; extern char file[];
extern char linebuf[]; extern char rhsbuf[]; extern char expbuf[]; extern char  genbuf[]; extern char tmpXXXXX[];
extern char ibuff[]; extern char obuff[]; extern char WRERR[]; extern char *braslist[]; extern char *braelist[];

typedef void  (*SIG_TYP)(int);
extern SIG_TYP  oldhup, oldquit;

extern char grepbuf[];
extern jmp_buf  savej;
extern int bp;

extern int peekc, lastc, given, ninbuf, io, pflag;
extern int oflag, listf, listn, col, tline, ichanged, nleft;
extern unsigned int  *addr1, *addr2, *dot, *dol, *zero;
extern int anymarks, nbra, subnewa, subolda, fchange, wrapp;
extern long  count;
extern char *nextip, *linebp, *globp, *mktemp(char *);
extern char  *tfname, *loc1, *loc2;
extern char line[];
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
void greperror(char);  void grepline(void);
void copyclargs(const char* fname, const char* sstring);
int grabchar(void);
void openfile(void);
void search_file(const char* filename, const char* searchfor);
void process_dir(const char* dir, const char* searchfor, void (*fp)(const char*, const char*));
int star(char *lp, char *ep, char *curlp);
void cerror(void);

#endif /* grep_h */
