About pretty_output
===================

This is a library for pretty printing information about a code. Those who prefer using console output for debugging purposes might consider this library as a more useful alternative to printf/std::cout/whatever.


Features:

* Easy to use, but right now not easy to extend
* Uses only C++/C++11. Does not use any additional preprocessors or libraries, except standard library
* Crossplatform. Tested on Clang 600.0.56, MVS 2010/2013, MinGW 4.9.smth
* No license, free for all



Usage
=====

`$w(<expression>)` - print value of `expression` and returns that value, so can be used inside other expression.
The name is an abbreviation of 'watch'.
<br></br>

`$c(<function>)(<arguments>)` - print `function` arguments and return value. Should be used at function call. Automatically shifts indentation of the output.
The name is an abbreviation of 'call'.
<br></br>

`$cm(<object>, <function_name>)(<arguments>)` - print member-function arguments and return value. Should be used at member-function call. `object` argument can be of a pointer or non-pointer type.
The name is an abbreviation of 'call member-function'.
<br></br>

`$m(<pointer>, <size>, <options>)` - print memory under the `pointer`.

`pointer` - address of the memory to be printed. The type of the pointer determines the grouping of bytes and default `base`. For example memory under the `unsigned char*` pointer will be grouped by 1 byte and use hexadecimal numbers; memory under `int*` will be grouped by 4 bytes and use signed decimal numbers. For unknown types default grouping is by 1 byte and base is hexadecimal.

`size` - size of memory is bytes.

`options` (optional) - numeric base for value representation and order of the bytes to use when converting bytes to the numeric values.

Base flags:
* `pretty_output::BIN` - binary
* `pretty_output::SDEC` - signed decimal
* `pretty_output::UDEC` - unsigned decimal
* `pretty_output::HEX` - hexadecimal (default)
* `pretty_output::FLT` - single precision floating point number
* `pretty_output::DBL` - double precision floating point number
* `pretty_output::LDBL` - floating point number with precision equal to 'long double' for current platform

Byte order flags (default value is determined automatically):
* `pretty_output::LITTLE` - big-endian byte order
* `pretty_output::BIG` - little-endian byte order

The name is an abbreviation of 'memory'.
<br></br>

`$f` - print function or member-function call and return labels. Should be used inside a function or member-function. Automatically shifts indentation of the output.
The name is an abbreviation of 'function'.
<br></br>

`$return expression` - print value of `epxression` passed to return statement.
<br></br>

`$if (<condition>)` - print value of the if `condition`. Automatically shifts indentation of the output.
<br></br>

`$for (<statements>)` - print iteration numbers of the for loop. Automatically shifts indentation of the output.
<br></br>

`$while (<condition>)` - print iteration conditions of the while loop. Automatically shifts indentation of the output.
<br></br>

`$p(<format>, ...)` - like printf. The name is an abbreviation of 'printf'.
<br></br>

`$t(<thread_name>)` - set thread name, that will be printed in the thread header. The name is an abbreviation of 'thread'.
<br></br>



Options
=======

`PRETTY_OUTPUT_ON` - turn pretty_output on.

`PRETTY_OUTPUT_OFF` - turn pretty_output off.

`PRETTY_OUTPUT_WIDTH` - width, to which output is wrapped (actually wrapping only a thread header and memory output). Default is 79.

`PRETTY_OUTPUT_INDENTATION` - string, that is used as an indentation for the actual output. Default is `"    "` (4 spaces).

`PRETTY_OUTPUT_NO_OUTPUT_SYNC` - disables output syncronization. Read details in the 'Notes' section.

`PRETTY_OUTPUT_REDIRECTION_H` - header file, which contains overrided printing routines. Read details in the 'Notes' section.



Notes
=====

* `$w`, `$c`, `$mc`, `$return`, `$if` and `$while` macros support printing of all fundamental types, iterable types (for which `std::begin()` and `std::end()` are defined), `std::pair`, `std::tuple`. Printing values of iterable types and macros `$c`, `$cm` are enabled only with C++11 and later.

* If macro `NDEBUG` is not defined or `PRETTY_OUTPUT_ON` is defined then the pretty_output is turned on. If `NDEBUG` or `PRETTY_OUTPUT_OFF` is defined then the pretty_output is turned off.

* There is an output synchronization that prevents outputs from different threads mixing up. By default this feature is turned on. To disable this synchronization define macro `PRETTY_OUTPUT_NO_OUTPUT_SYNC`.

* Output redirection is done in a following way: first, the functions `void print(const char *)` and `void flush()` should be defined within some namespace; second, macro `PRETTY_OUTPUT_REDIRECTION` should be defined with a name of the namespace where these functions are defined. For convinience there's already files for redirecting output to a file (pretty_output_to_file.cpp) and for printing to MVS debug output (pretty_output_to_mvs.cpp). When using pretty_output_to_file, you can define macro `PRETTY_OUTPUT_TO_FILE` with the name of the destination file (default is 'pretty_output_log.txt').



Compiler Warnings
=================

Using Clang with `-pedantic` option on: '$' in identifier
Using MinGW ...
Using Visual Studio ...



Troubleshooting
===============

...

