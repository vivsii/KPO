#include "stdafx.h"


void Serealizer::SerealizeData()
{
	file = ofstream("D:\\уник\\кпо\\лабораторные работы\\asm04\\SE_Asm04\\Serializer\\Serializer.bin");

	file.clear();


	file.write((char*)&longMarker, 1);
	file.write((char*)&longLength, 1);
	file.write(reinterpret_cast<char*>(&Long), longLength);

	file.write((char*)&byteMarker, 1);
	file.write((char*)&byteLength, 1);
	file.write(reinterpret_cast<char*>(&byte), byteLength);


	file.close();
}
