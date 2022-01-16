/* segfault extension for PHP */

#ifndef PHP_SEGFAULT_H
# define PHP_SEGFAULT_H

extern zend_module_entry segfault_module_entry;
# define phpext_segfault_ptr &segfault_module_entry

# define PHP_SEGFAULT_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_SEGFAULT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SEGFAULT_H */
