#pragma once
#include "stdafx.h"

class Serealizer
{
private:

	std::ofstream file;
	unsigned char longMarker = 0x01;
	unsigned char byteMarker = 0x02;
	unsigned char longLength = sizeof(long);
	unsigned char byteLength = sizeof(unsigned char);
	long Long;
	unsigned char byte;

public:

	Serealizer(long Long, int byte)
	{
		this->Long = Long;
		this->byte = (unsigned char)byte;
	}

	void SerealizeData();

};

