#include <Eigen/Core>
#include <Eigen/Geometry>

#include <iostream>

using namespace std;

int main(){
	Eigen::AngleAxisd rotation_vector_q(M_PI/4,Eigen::Vector3d(0,0,1));		//rotate 45deg around axis z
	Eigen::AngleAxisd rotation_vector_p(-M_PI/4,Eigen::Vector3d(0,0,1));	//rotate -45deg around axis z
	Eigen::Quaterniond q(rotation_vector_q);								//rotation expressed by Quaternion
	Eigen::Quaterniond p(rotation_vector_p);
	Eigen::Vector3d v{1,0,0};												//vector v along axis x
	Eigen::Quaterniond Quater_v(0,1,0,0);									//vector v expressed by Quaternion
	
	cout<<"Quaterniond q:"<<endl<<q.coeffs()<<endl;
	cout<<"Quaterniond p:"<<endl<<p.coeffs()<<endl;

	Eigen::Vector3d v_rotated = q*v;										
	//Eigen::Vector3d v_rotated = v*q;	//error 
	//Eigen::Vector3d v_rotated = q*v*q.inverse();	error

	cout<<"v rotated by q:"<<(q*v).transpose()<<endl;						// vector v rotated by q
	cout<<"Quater_v rotated by q:"<<endl<<(q*Quater_v*q.inverse()).coeffs()<<endl;	//same as above

	Eigen::Quaterniond q_multi_p = q*p;										//first rotate p(-45deg along z) then rotate q(45deg along z) 
	Eigen::Quaterniond p_multi_q = p*q;										//first rotate q(45deg along z) then rotate p(-45deg along z)
	
	cout<<"v rotated by q_multi_p:"<<(q_multi_p*v).transpose()<<endl;		//result:(1,0,0)
	cout<<"v rotated by p_multi_q:"<<(p_multi_q*v).transpose()<<endl;		//same result


	Eigen::Quaterniond p_minus_q = q.inverse()*p;							//rotate -90deg around axis z
	Eigen::Quaterniond q_minus_p = p.inverse()*q;							//rotate 90deg around axis z

	cout<<"v rotated by p_minus_q:"<<(p_minus_q*v).transpose()<<endl;		//result:(0,-1,0)
	cout<<"v rotated by q_minus_p:"<<(q_minus_p*v).transpose()<<endl;		//result:(0,1,0)

	

	return 0;
}

Quaterniond q:
       0
       0
0.382683
 0.92388
Quaterniond p:
       -0
       -0
-0.382683
  0.92388
v rotated by q:0.707107 0.707107        0
Quater_v rotated by q:
0.707107
0.707107
       0
       0
v rotated by q_multi_p:1 0 0
v rotated by p_multi_q:1 0 0
v rotated by p_minus_q:-2.22045e-16           -1            0
v rotated by q_minus_p:-2.22045e-16            1            0
