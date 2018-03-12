#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ifstream ifile("../lidardata.pcap");
	if(!ifile){
		cerr<<"open failed"<<endl;
		return 0;
	}

	ifile.seekg(0,ifile.end);
	int length = ifile.tellg();
	ifile.seekg(0,ifile.beg);
	cout<<"file length: "<<length<<" bytes"<<endl;

	unsigned char buf[16];

	ofstream ofile("o.dat");
	// for(int i=0;i<10;i++){
	// 	//cout<<ifile.get()<<endl;
	// 	//ofile<<ifile.get();
	// 	buf[i] = ifile.get();
	// 	ofile<<buf[i];
	// }

	//ifile.seekg(0,ifile.beg);
	length = 200;
	char *bufp = new char [length];
	// ifile.read(bufp,length);
	// int bufstart = 0;
	// int bufend = 0;
	// //while(bufend<length){
	// 	//unsigned short tmp = bufp[bufstart] & 0xff | ((bufp[bufstart+1] & 0xff) << 8);
	// 	unsigned char a = (bufp[0]);
	// // unsigned char a=0xd4;
	// printf("%x\n",a);
	// 	cout<<setw(2)<<hex<<(int)(a)<<endl;
	// 	unsigned short tmp = ((bufp[bufstart] & 0xff )<< 8)| ((bufp[bufstart+1] & 0xff)  );
	// //}

	// 	tmp = 0xc3d4;
		unsigned short *pu16 = (unsigned short*)bufp;
	// 	cout<<"pu16: "<<hex<<setw(4)<<setfill('0')<<pu16[0]<<endl;
	// cout<<"tmp: "<<hex<<tmp<<endl;
	// cout<<(pu16[0]==tmp)<<endl;

	while(*pu16 != 0xeeff){
		ifile.read(bufp,2);
		pu16 = (unsigned short*)bufp;
	}

	ifile.seekg(-2,ifile.cur);
	ifile.read(bufp,1240);






	//cout<<"asdad"<<memcmp(bufp,&tmp,2)<<endl;

	ofile.write(bufp,1240);
	//ofile<<bufp;
	cout<<ofile.good()<<ifile.good()<<endl;
	cout<<"ffee pos: "<<ifile.tellg()<<endl;

	// ifile.seekg(0,ifile.beg);
	// unsigned short tmp; 
	// while(tmp!=0xffee){
	// 	ifile.read((char*)&tmp,2);
	// 	cout<<hex<<tmp<<endl;
	// }
	// cout<<"ffee pos: "<<ifile.tellg()<<endl;

	delete[] bufp;
	return 0;
}