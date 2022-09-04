// volatile!

/* This check is unusual in that for a positive answer (the compiler supports
   volatile) we undefine volatile to allow the compiler to recognize it as a
   keyword and for a negative answer we define it to nothing so that volatile
   is effectively removed from the user code. */

#undef volatile
