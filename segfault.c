/* segfault extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_segfault.h"
#include "segfault_arginfo.h"
#include <signal.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void kkthxbye() */
PHP_FUNCTION(kkthxbye)
{
	ZEND_PARSE_PARAMETERS_NONE();

    raise(SIGSEGV);
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(segfault)
{
#if defined(ZTS) && defined(COMPILE_DL_SEGFAULT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(segfault)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "segfault support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ segfault_module_entry */
zend_module_entry segfault_module_entry = {
	STANDARD_MODULE_HEADER,
	"segfault",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(segfault),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(segfault),			/* PHP_MINFO - Module info */
	PHP_SEGFAULT_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SEGFAULT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(segfault)
#endif
