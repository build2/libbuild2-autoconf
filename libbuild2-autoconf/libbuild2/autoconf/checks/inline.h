// inline!

/* This check is unusual in that for a positive answer (the compiler supports
   inline) we undefine inline to allow the compiler to recognize it as a
   keyword and for a negative answer we define it to nothing so that inline is
   effectively removed from the user code. */

#undef inline
