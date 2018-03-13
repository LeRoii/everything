#include <fstream>
#include <iostream>
#include "LidarTools.h"

using namespace std;

int main(){
	ifstream OpenFile("../lidardata.pcap");
	ofstream of("out.dat");
	if(!OpenFile){
		cout<<"open failed"<<endl;
	}
	unsigned char buf[10];
	unsigned char ch;
	int i=0;

	OpenFile.seekg(0,OpenFile.end);
	int length = OpenFile.tellg();
	OpenFile.seekg(0,OpenFile.beg);

	cout<<"file length: "<<length<<" bytes"<<endl;

	while(i<10){
		buf[i] = OpenFile.get();
		of<<buf[i++];
		//cout<<hex<<buf[i++]<<endl;;
	}

	int HS_Pandar40P_Parse(HS_Pandar40P_Packet *packet , const unsigned char* recvbuf , const int len);

	return 0;
}