# simple-error-check
a simple error handling check macro set.

## usage
just add err.h to you include path and provide TRACE_MACRO which get an err_t and print it the way you want.
you can also define:
- HANDLE_MACRO how you want to handle error, defaults to goto cleanup
- SYSTEM you can use that in oreder to later handle this error on a higher level, defaults to 0
- SUBSYSTEM you can define that to further conrole you error systems, defaults to 0
- FILE_ID a uniq id for each c and cpp file, defaults to 0
- DEFAULT_ERRORCODE the error code to use if none is specified defaults to errno

when you use any of the CHECK macros you should declare a err_t err, and a cleanup label.
since this is a header only you can define the macros per src file or wrap it with your on header to get the best resultes.
