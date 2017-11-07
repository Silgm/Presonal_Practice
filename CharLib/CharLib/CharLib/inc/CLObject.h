#ifndef _CL_OBJECT_H_
#define _CL_OBJECT_H_

#include "cl_tool.h"

namespace cl 
{
	class CLObject 
	{
	public:
		using char_type = wchar_t;
		using str_type = std::wstring;
		CLObject();
		virtual ~CLObject();
	private:

	};

}


#endif
