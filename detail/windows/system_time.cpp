#include "../platform_defines.hpp"
#if defined(TRACE_OUT_WINDOWS)

#include <windows.h>

#include "../system_time.hpp"


namespace trace_out { namespace detail
{

	uint64_t time_in_milliseconds()
	{
		FILETIME file_time;
		ULARGE_INTEGER large_integer;

		GetSystemTimeAsFileTime(&file_time);
		large_integer.LowPart = file_time.dwLowDateTime;
		large_integer.HighPart = file_time.dwHighDateTime;

		uint64_t milliseconds = (large_integer.QuadPart - 116444736000000000LL) / 10000;

		return milliseconds;
	}

}
}


#endif // defined(TRACE_OUT_WINDOWS)

