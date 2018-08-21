#include "KronosTime.h"
#include "stdafx.h"

KronosTime::KronosTime()			// gets current time and rounds it like Kronos
	: mHour(0), mMinute(0), mLunch(false), mKeepWorking(0) {
	int hour, minute;
	this->getCurrentTime(hour, minute);
	mHour = hour;
	mMinute = minute;
}

void KronosTime::getCurrentTime( int& hour, int& minute ) {
	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now, &t);
	hour = now.tm_hour;
	minute = now.tm_min;
	round(hour, minute);
}

void KronosTime::round(int& hour, int& minute) {
	if (minute <= 7) {
		minute = 0;
	}
	else if (minute >= 8 && minute <= 22) {
		minute = 15;
	}
	else if ((minute >= 23) && (minute <= 37)) {
		minute = 30;
	}
	else if ((minute >= 38) && (minute <= 52)) {
		minute = 45;
	}
	else {
		hour += 1;
		minute = 0;
	}
}
KronosTime::KronosTime( int& hour,  int& minute, const bool& lunch)
	: mHour(0), mMinute(0), mLunch(true), mKeepWorking(0) {
	round(hour, minute);
	setTime(hour, minute);
	setLunch(lunch);
}

int KronosTime::getKeepWorking() const {
	return mKeepWorking;
}

bool KronosTime::getLunch() const {
	return mLunch;
}

int KronosTime::getHour() const {
	return mHour;
}

int KronosTime::getMinute() const {
	return mMinute;
}

int KronosTime::getTime() const {
	return 0;
}

void KronosTime::setKeepWorking(const int& value) {
	mKeepWorking = value;
}

void KronosTime::setHour(const int& hour) {
	if (hour >= 0 && hour <= 23) {
		mHour = hour;
	}
}

void KronosTime::setLunch(const bool& lunch) {
	mLunch = lunch;
}

void KronosTime::setMinute(const int& minute) {
	if (minute >= 0 && minute <= 59) {
		mMinute = minute;
	}
}

void KronosTime::setTime(const int& hour, const int& minute) {
	setHour(hour);
	setMinute(minute);
}

std::ostream& operator<<(std::ostream& os, const KronosTime& kt) {
	std::string hours = std::to_string(kt.getHour());
	std::string minutes = std::to_string(kt.getMinute());
	if (minutes.length() == 1) {
		minutes.insert(0, "0");
		os << hours << ":" << minutes << std::endl;
	}
	else {
		os << hours << ":" << minutes << std::endl;
	}
	return os;
}

//TODO fix calcRange, probably pass in 2 KT objects and then print them out at the end.
void KronosTime::calcRange( const int& hour, const int& min) {
	if (min == 0) {
		hour -= 1, 53], [hour, '07']];
	}
	else if (min == 15) {
		return[[hour, '08'], [hour, 22]];
	}
	else if (min == 30) {
		return[[hour, 23], [hour, 37]];
	}
	else {
		return[[hour, 38], [hour, 52]];
	}
}

KronosTime KronosTime::operator-(const KronosTime& rhs) const {
	int minutes, hours;
	int lhs_seconds = (this->mMinute * 60) + (this->mHour * 3600);
	int rhs_seconds = (rhs.mMinute * 60) + (rhs.mHour * 3600);
	lhs_seconds -= rhs_seconds;
	if (rhs.mLunch == true && lhs_seconds >= 21600) {
		lhs_seconds -= 1800;
	}
	minutes = lhs_seconds / 60;
	hours = minutes / 60;
	minutes %= 60;
	KronosTime result(hours, minutes, this->getLunch());
	return result;
}
