`widcc` is a stable branch of [`slimcc`](https://github.com/fuhsnn/slimcc) that
 - does not attempt to optimize codegen 
 - does not introduce new features (unless I really want certain projects to build)
 - would rather remove a feature than to support it incorrectly (not a motto but to avoid giving autoconf the wrong idea)
 
`slimcc` has accomplished a fairly good collection of real world projects it can build and 100% pass tests. `widcc` in turn is to maintain that status while being simpler-to-port and easier-to-modify.

The following C11 features are removed: `_Alignof` `_Atomic` `_Generic`. These are not seen commonly in use, therefore widcc still declare itself a C11 compiler. 

wid stands for "When in doubt" from the famous quote.

`widcc` is based on [Rui Ueyama's `chibicc`](https://github.com/rui314/chibicc), if you are familiar with chibicc and would like to know what's different here, refer [below](#changes-over-chibicc).

# Building & Running
 - Should just work on recent glibc-based (2.28+) x86-64 Linux.
 - Test script needs `bash`; depending on the distro, `file` and/or `glibc-static` packages may be required.
```
git clone --depth 1 https://github.com/fuhsnn/widcc
cd widcc
make test-stage2 -j
```
Run it in base directory like `CC=~/widcc/widcc`

# Building real-world projects

(package dependencies are assumed to be present)

`curl 8.8.0`
```
git clone --depth 1 https://github.com/curl/curl --branch curl-8_8_0
mkdir curl/cmakebuild
cd curl/cmakebuild
cmake ../ -DCMAKE_C_COMPILER=/full/path/to/widcc -DCMAKE_C_FLAGS=-fPIC
make -j
make quiet-test -j
```
`gcc 4.7.4`
```
mkdir gccbuild gccinstall
wget https://ftp.gnu.org/gnu/gcc/gcc-4.7.4/gcc-4.7.4.tar.bz2
tar -xf gcc-4.7.4.tar.bz2
cd gcc-4.7.4
find . -name 'configure' -exec sh ~/widcc/add_wl_pic.sh {} \;
sed -i 's/^\extern const unsigned int $/const unsigned int/g' ./gcc/c-family/c-opts.c
sed -i 's/^\s*struct ucontext/ucontext_t/g' ./libgcc/config/i386/linux-unwind.h
cd ../gccbuild
CC=~/widcc/widcc MAKEINFO=missing ../gcc-4.7.4/configure --prefix=$HOME/gccinstall/ --enable-languages=c,c++ --disable-multilib --disable-bootstrap
make -j
make install
```
`git 2.45.2`
```
git clone --depth 1 https://github.com/git/git --branch v2.45.2
cd git
make CC=~/widcc/widcc V=1 test -j
```
`PostgreSQL 15.7`
```
git clone --depth 1 https://github.com/postgres/postgres --branch REL_15_7
cd postgres
CC=~/widcc/widcc ./configure --disable-spinlocks --disable-atomics
make check -j
```
`Python 3.11.9`
```
git clone --depth 1 https://github.com/python/cpython --branch v3.11.9
cd cpython
CC=~/widcc/widcc ./configure
make test -j
```
`sqlite 3.46.0`
```
git clone --depth 1 https://github.com/sqlite/sqlite/ --branch version-3.46.0
cd sqlite
sh ~/widcc/add_wl_pic.sh ./configure
CC=~/widcc/widcc CFLAGS=-D_GNU_SOURCE ./configure
make testrunner
```
`TinyCC mob branch`
```
git clone --depth 1 https://repo.or.cz/tinycc.git
cd tinycc
CC=~/widcc/widcc ./configure
make -j
cd tests/tests2/
make
```
`vim trunk`
```
git clone --depth 1 https://github.com/vim/vim
cd vim
CC=~/widcc/widcc ./configure
make -j
make testtiny
```

# Changes over chibicc
- A stack manager for temporaries is introduced to avoid clobbering when setjmp/longjmp happen between pairs of push-pop, by translating push-pop's into mov's. `slimcc` took this further and added register allocation on top of the manager.
- Local variables of parallel scopes are folded into the same stack space, this dramatically eliminated segfaults in projects that do recursive calls a lot, and is about the only optimization worth mentioning in `widcc`.
- `chibicc`'s preprocessor hideset algorithm had issues with some obscure macro expansion tricks, I moved to a simple-but-dirtier design that avoid building hidesets altogether, but apparently [n0tknowing's chibicc fork](https://github.com/n0tknowing/chibicc) worked that out.
- `chibicc` had a tricky implementation of function call procedure, by interleaving argument-pushing with evaluation, then popping only the pass-by-reg ones off. I simplified the process by storing evaluated arguments to temporary variables, then copy into the right spots; it's inefficient, but the reduction in conceptual load worth it.
- The evaluation order of binary arithmetic operators are enforced left-right. Although it's implementation-defined behavior in C, I decided to reduce future surprises after encountering a test failing since git 2.43 because certain message output expressions are made on both sides of `|` and the validation script expect left-right behavior.
