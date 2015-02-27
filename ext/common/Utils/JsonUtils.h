/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2014-2015 Phusion
 *
 *  "Phusion Passenger" is a trademark of Hongli Lai & Ninh Bui.
 *
 *  See LICENSE file for license information.
 */
#ifndef _PASSENGER_UTILS_JSON_UTILS_H_
#define _PASSENGER_UTILS_JSON_UTILS_H_

#include <string>
#include <cstdio>
#include <cstddef>
#include <StaticString.h>
#include <Utils/json.h>
#include <Utils/StrIntUtils.h>

namespace Passenger {

using namespace std;


/**************************************************************
 *
 * Methods for generating JSON.
 *
 **************************************************************/

/**
 * Returns a JSON document as its string representation.
 * This string is not prettified and does not contain a
 * trailing newline.
 *
 *     Json::Value doc;
 *     doc["foo"] = "bar";
 *     cout << stringifyJson(doc) << endl;
 *     // Prints:
 *     // {"foo": "bar"}
 */
inline string
stringifyJson(const Json::Value &value) {
	Json::FastWriter writer;
	string str = writer.write(value);
	str.erase(str.size() - 1, 1);
	return str;
}

/**
 * Encodes the given string as a JSON string. `str` MUST be NULL-terminated!
 *
 *     cout << jsonString("hello \"user\"") << endl;
 *     // Prints:
 *     // "hello \"user\""
 */
inline string
jsonString(const Passenger::StaticString &str) {
	return stringifyJson(Json::Value(Json::StaticString(str.data())));
}

/**
 * Encodes the given Unix timestamp into a JSON object that
 * describes it.
 *
 *     timeToJson(time(NULL) - 10);
 *     // {
 *     //   "timestamp": 1424887842,
 *     //   "local": "Wed Feb 25 19:10:34 CET 2015",
 *     //   "relative": "10s ago"
 *     // }
 */
inline Json::Value
timeToJson(unsigned long long timestamp) {
	Json::Value doc;
	time_t time = (time_t) timestamp / 1000000;
	char buf[32];
	size_t len;

	doc["timestamp"] = timestamp / (double) 1000000;

	ctime_r(&time, buf);
	len = strlen(buf);
	if (len > 0) {
		// Get rid of trailing newline
		buf[len - 1] = '\0';
	}
	doc["local"] = buf;
	doc["relative"] = distanceOfTimeInWords(time) + " ago";

	return doc;
}

inline string
formatFloat(double val) {
	char buf[64];
	int size = snprintf(buf, sizeof(buf), "%.1f", val);
	return string(buf, size);
}

inline Json::Value
byteSizeToJson(size_t size) {
	Json::Value doc;
	doc["bytes"] = (Json::UInt64) size;
	if (size < 1024) {
		doc["human_readable"] = toString(size) + " bytes";
	} else if (size < 1024 * 1024) {
		doc["human_readable"] = formatFloat(size / 1024.0) + " KB";
	} else {
		doc["human_readable"] = formatFloat(size / 1024.0 / 1024.0) + " MB";
	}
	return doc;
}

inline Json::Value
signedByteSizeToJson(long long size) {
	Json::Value doc;
	long long absSize = (size < 0) ? -size : size;
	doc["bytes"] = (Json::Int64) size;
	if (absSize < 1024) {
		doc["human_readable"] = toString(size) + " bytes";
	} else if (absSize < 1024 * 1024) {
		doc["human_readable"] = formatFloat(size / 1024.0) + " KB";
	} else {
		doc["human_readable"] = formatFloat(size / 1024.0 / 1024.0) + " MB";
	}
	return doc;
}


} // namespace Passenger

#endif /* _PASSENGER_UTILS_JSON_UTILS_H_ */
