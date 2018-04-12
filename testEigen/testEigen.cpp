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
	Eigen::Quaterniond q_multi_p = q*p;
	Eigen::Quaterniond p_multi_q = p*q;
	Eigen::Quaterniond p_minus_q = q.inverse()*p;
	Eigen::Quaterniond p_rotatedby_q = q*p*q.inverse();
	
	cout<<"Quaterniond q:"<<endl<<q.coeffs()<<endl;
	cout<<"Quaterniond p:"<<endl<<p.coeffs()<<endl;
	cout<<"v_rotated:"<<v_rotated.transpose()<<endl;
	cout<<"q_multi_p:"<<endl<<q_multi_p.coeffs()<<endl;
	cout<<"p_multi_q:"<<endl<<p_multi_q.coeffs()<<endl;
	cout<<"p_rotatedby_q:"<<endl<<p_rotatedby_q.coeffs()<<endl;
	cout<<"p_minus_q:"<<endl<<p_minus_q.coeffs()<<endl;;

	return 0;
}