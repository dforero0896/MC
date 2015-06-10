# script for testing that programs compile correctly (see README)

#! /bin/tcsh

set CFLAGS = "-I./src"

#set LFLAGS = "-L/usr/local/mpi/lib -lmpich -lpthread -lm"
set LFLAGS = "-lm"

foreach f ( src/pr_* )

  echo $f
  gcc $CFLAGS $f $LFLAGS
  rm a.out

end
