#pragma once
#ifndef KRONOSTIME_H
#define KRONOSTIME_H

#include "stdafx.h"

class KronosTime {

public:
	KronosTime();   // sets time to current time 
	KronosTime(  int& hour,  int& minute, const bool& lunch );
	int getHour() const;
	int getMinute() const;
	int getTime() const;
	int getKeepWorking() const;

	bool getLunch() const;
	void getCurrentTime(int& hour, int& minute);

	void setHour( const int& hour );
	void setMinute( const int& minute );
	void setLunch(const bool& lunch);
	void setKeepWorking(const int& value);
	void setTime( const int& hour, const int& minute );
	void round(int& hour, int& minute);
	void calcRange(const int& hour, const int& min);

	KronosTime operator-(const KronosTime& rhs) const;

private:
	int mHour;
	int mMinute;
	bool mLunch;
	int mKeepWorking;
};

std::ostream& operator<<(std::ostream& os, const KronosTime& kt);

#endif 