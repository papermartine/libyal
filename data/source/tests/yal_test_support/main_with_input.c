/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc,
     wchar_t * const argv[] )
#else
int main(
     int argc,
     char * const argv[] )
#endif
{
	system_character_t *source = NULL;
	system_integer_t option    = 0;

	while( ( option = ${library_name_suffix}_test_getopt(
	                   argc,
	                   argv,
	                   _SYSTEM_STRING( "" ) ) ) != (system_integer_t) -1 )
	{
		switch( option )
		{
			case (system_integer_t) '?':
			default:
				fprintf(
				 stderr,
				 "Invalid argument: %" PRIs_SYSTEM ".\n",
				 argv[ optind - 1 ] );

				return( EXIT_FAILURE );
		}
	}
	if( optind < argc )
	{
		source = argv[ optind ];
	}

	${library_name_suffix_upper_case}_TEST_RUN(
	 "${library_name}_get_version",
	 ${library_name_suffix}_test_get_version );

	${library_name_suffix_upper_case}_TEST_RUN(
	 "${library_name}_get_access_flags_read",
	 ${library_name_suffix}_test_get_access_flags_read );

	${library_name_suffix_upper_case}_TEST_RUN(
	 "${library_name}_get_codepage",
	 ${library_name_suffix}_test_get_codepage );

	${library_name_suffix_upper_case}_TEST_RUN(
	 "${library_name}_set_codepage",
	 ${library_name_suffix}_test_set_codepage );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	if( source != NULL )
	{
		${library_name_suffix_upper_case}_TEST_RUN_WITH_ARGS(
		 "${library_name}_check_${signature_type}_signature",
		 ${library_name_suffix}_test_check_${signature_type}_signature,
		 source );

#if defined( HAVE_WIDE_CHARACTER_TYPE )

		${library_name_suffix_upper_case}_TEST_RUN_WITH_ARGS(
		 "${library_name}_check_${signature_type}_signature_wide",
		 ${library_name_suffix}_test_check_${signature_type}_signature_wide,
		 source );

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

		${library_name_suffix_upper_case}_TEST_RUN_WITH_ARGS(
		 "${library_name}_check_${signature_type}_signature_file_io_handle",
		 ${library_name_suffix}_test_check_${signature_type}_signature_file_io_handle,
		 source );
	}
#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

