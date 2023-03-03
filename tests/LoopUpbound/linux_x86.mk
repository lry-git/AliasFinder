SRC_DIR=$(SOURCE_BASE)
CC=/home/xwc/Documents/Clang-12.0.0/llvm-project-12.0.0.src/llvm/build/bin/clang
CPLUS=/home/xwc/Documents/Clang-12.0.0/llvm-project-12.0.0.src/llvm/build/bin/clang++
LD=ld
VXPOFILE_PRJ_DIR = $(SRC_DIR)
			 
DRV_CFLAGS =   -msoft-float  -fno-zero-initialized-in-bss  -fno-common -fno-builtin -Wall -fno-strict-aliasing \
	       -fsigned-char -Wno-unused  -Wpointer-arith -O2 -DOS_LINUX -emit-ast
			 

VXCFLAGS         =  $(DRV_CFLAGS) 	\
		 -I$(VXPOFILE_PRJ_DIR)/src/TestCase.h 	\
		 -I. \
		 
VXPROFILE_OBJS = TestCase.o                 \
 		 BigLoop_Check_TestCase8.1.o \
		 BigLoop_Check_TestCase8.o \
                BigLoop_Check_TestCase7.1.o 	\
                BigLoop_Check_TestCase7.o 	\
                BigLoop_Check_TestCase6.o	\
                BigLoop_Check_TestCase5.o	\
                BigLoop_Check_TestCase4.o	\
                BigLoop_Check_TestCase3.o	\
                BigLoop_Check_TestCase2.1.o	\
                BigLoop_Check_TestCase2.o	\
                BigLoop_Check_TestCase1.1.o     \
                BigLoop_Check_TestCase1.o     \
                
                	
image.o:$(VXPROFILE_OBJS)
	$(LD) -o image.o -r $(VXPROFILE_OBJS)

TestCase.o:$(VXPOFILE_PRJ_DIR)/src/TestCase.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/TestCase.c

BigLoop_Check_TestCase8.1.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase8.1.cpp
	$(CPLUS)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase8.1.cpp

BigLoop_Check_TestCase8.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase8.cpp
	$(CPLUS)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase8.cpp

BigLoop_Check_TestCase7.1.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase7.1.cpp
	$(CPLUS)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase7.1.cpp

BigLoop_Check_TestCase7.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase7.cpp
	$(CPLUS)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase7.cpp

BigLoop_Check_TestCase6.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase6.cpp
	$(CPLUS)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase6.cpp

BigLoop_Check_TestCase5.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase5.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase5.c

BigLoop_Check_TestCase4.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase4.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase4.c

BigLoop_Check_TestCase3.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase3.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase3.c
	
BigLoop_Check_TestCase2.1.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase2.1.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase2.1.c
	
BigLoop_Check_TestCase2.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase2.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase2.c
	
BigLoop_Check_TestCase1.1.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase1.1.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase1.1.c

BigLoop_Check_TestCase1.o:$(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase1.c
	$(CC)   $(VXCFLAGS)  -c $(VXPOFILE_PRJ_DIR)/src/BigLoop_Check/BigLoop_Check_TestCase1.c

