#include <Eigen/Core>
#include <Eigen/Geometry>

#include <iostream>

using namespace std;

int main(){
	Eigen::Quaterniond tmpQ;
	Eigen::Vector3d g{0,0,9.8};

	cout<<"tmpQ:"<<tmpQ.coeffs()<<endl;
	cout<<"tmpQ x g:"<<tmpQ*g<<endl;;

	return 0;
}