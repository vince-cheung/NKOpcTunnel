/*	This file is part of NKOpcTunnel.
*
*	Copyright (c) Henryk Anschuetz 
*	Berlin, Germany
*
*	mailto:uzuul23@online.de
*
*	NKOpcTunnel is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   NKOpcTunnel is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with NKOpcTunnel.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#pragma once
#include <wtypes.h>

#ifndef MYDLLEXPORT
#define MYDLLEXPORT
#endif

namespace NkStream
{
	class CStreamIODevice;
	class MYDLLEXPORT CStream
	{
	public:
		CStream(CStreamIODevice* p = 0, size_t cb_buffer_size = 8192, ULONG32 id = 0);
		CStream(const CStream&) = delete;
		CStream &operator =(const CStream&) = delete;
		virtual ~CStream(void);

		void stream_device(CStreamIODevice* p);
		CStreamIODevice* stream_device();

		void flush();
		void close() throw();

		CStream& operator>>(bool& l);
		CStream& operator>>(char& l);
		CStream& operator>>(unsigned char& l);
		CStream& operator>>(short& l);
		CStream& operator>>(unsigned short& l);
		CStream& operator>>(int& l);
		CStream& operator>>(unsigned int& l);
		CStream& operator>>(long& l);
		CStream& operator>>(unsigned long& l);
		CStream& operator>>(float& l);
		CStream& operator>>(double& l);
		CStream& operator>>(CLSID& clsid);
		CStream& operator>>(FILETIME& ft);
		CStream& operator>>(LONGLONG& l);
		CStream& operator>>(ULONGLONG& l);

		CStream& operator<<(const bool& l);
		CStream& operator<<(const char& l);
		CStream& operator<<(const unsigned char& l);
		CStream& operator<<(const short& l);
		CStream& operator<<(const unsigned short& l);
		CStream& operator<<(const int& l);
		CStream& operator<<(const unsigned int& l);
		CStream& operator<<(const long& l);
		CStream& operator<<(const unsigned long& l);
		CStream& operator<<(const float& l);
		CStream& operator<<(const double& l);
		CStream& operator<<(const CLSID& clsid);
		CStream& operator<<(const FILETIME& ft);
		CStream& operator<<(const LONGLONG& l);
		CStream& operator<<(const ULONGLONG& l);

		void write_type(VARTYPE vt);
		void check_type(VARTYPE vt) const;

		void write(const void* p, size_t cb);
		void read(void* p, size_t cb);

		void write(const wchar_t* psz, size_t cch = -1);
		size_t read(wchar_t* psz, size_t cch);

		void write_count(size_t count);
		size_t read_count();

	protected:
		class CImpl;
		CImpl* _Impl;
	};
}
