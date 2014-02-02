/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_lime.h"

/* If you declare any globals in php_lime.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(lime)
*/

/* True global resources - no need for thread safety here */
static int le_lime;

/* {{{ lime_functions[]
 *
 * Every user visible function must have an entry in lime_functions[].
 */
const zend_function_entry lime_functions[] = {
	PHP_FE(pr,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in lime_functions[] */
};
/* }}} */

/* {{{ lime_module_entry
 */
zend_module_entry lime_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"lime",
	lime_functions,
	PHP_MINIT(lime),
	PHP_MSHUTDOWN(lime),
	PHP_RINIT(lime),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(lime),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(lime),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_LIME_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LIME
ZEND_GET_MODULE(lime)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("lime.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_lime_globals, lime_globals)
    STD_PHP_INI_ENTRY("lime.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_lime_globals, lime_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_lime_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_lime_init_globals(zend_lime_globals *lime_globals)
{
	lime_globals->global_value = 0;
	lime_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(lime)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(lime)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(lime)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(lime)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(lime)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "lime support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */



PHP_FUNCTION(pr) 
{

	zval *var;
	zend_bool do_return = 0;

	const char *file="";
	int line=0;
	int l;
	char *tmp = NULL;

	l = spprintf(&tmp, 0, "pr trace : %s on line %d", 
		zend_get_executed_filename(TSRMLS_C), 
		zend_get_executed_lineno(TSRMLS_C)
	);

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|b", &var, &do_return) == FAILURE) {
		RETURN_FALSE;
	}


	PUTS("\n<pre>");
	PUTS("\n----------------------------------------------------------------------");
	PUTS("\n");
	PUTS(tmp);
	PUTS("\n----------------------------------------------------------------------");
	PUTS("\n");
	zend_print_zval_r(var, 0 TSRMLS_CC);

	PUTS("</pre>\n");
		RETURN_TRUE;
}



/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
