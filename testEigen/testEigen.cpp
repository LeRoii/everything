#include <Eigen/Core>
#include <Eigen/Geometry>

#include <iostream>

using namespace std;

int main(){
	Eigen::AngleAxisd rotation_vector(M_PI/4,Eigen::Vector3d(0,0,1));
	Eigen::Quaterniond q(rotation_vector);
	Eigen::Vector3d v{1,0,0};
	Eigen::Quaterniond p(0,1,0,0);

	Eigen::Vector3d v_rotated = q*v;	// vector v rotated by q
	//Eigen::Vector3d v_rotated = v*q;	//error 
	//Eigen::Vector3d v_rotated = q*v*q.inverse();	error
	Eigen::Quaterniond p_rotated = q*p;
	//Eigen::Quaterniond p_rotated = p*q;
	
	cout<<"Quaterniond q:"<<q.coeffs()<<endl;
	cout<<"Quaterniond p:"<<p.coeffs()<<endl;
	cout<<"v_rotated:"<<v_rotated.transpose()<<endl;
	cout<<"p_rotated:"<<p_rotated.coeffs()<<endl;;

	return 0;
}