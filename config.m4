dnl $Id$
dnl config.m4 for extension lime

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(lime, for lime support,
dnl Make sure that the comment is aligned:
dnl [  --with-lime             Include lime support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(lime, whether to enable lime support,
dnl Make sure that the comment is aligned:
dnl [  --enable-lime           Enable lime support])

if test "$PHP_LIME" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-lime -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/lime.h"  # you most likely want to change this
  dnl if test -r $PHP_LIME/$SEARCH_FOR; then # path given as parameter
  dnl   LIME_DIR=$PHP_LIME
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for lime files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LIME_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LIME_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the lime distribution])
  dnl fi

  dnl # --with-lime -> add include path
  dnl PHP_ADD_INCLUDE($LIME_DIR/include)

  dnl # --with-lime -> check for lib and symbol presence
  dnl LIBNAME=lime # you may want to change this
  dnl LIBSYMBOL=lime # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIME_DIR/lib, LIME_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LIMELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong lime lib version or lib not found])
  dnl ],[
  dnl   -L$LIME_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(LIME_SHARED_LIBADD)

  PHP_NEW_EXTENSION(lime, lime.c, $ext_shared)
fi
