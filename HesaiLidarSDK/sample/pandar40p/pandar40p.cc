#include "hesaiLidarSDK.h"

void gpsCallback(int timestamp)
{
    printf("gps: %d" , timestamp);
}



void lidarCallback(boost::shared_ptr<PPointCloud> cld, double timestamp)
{
	// char *fileName = new char[30];
	// sprintf(fileName,"../data/lidarcord_%lf", timestamp);
	// FILE* lidarXYZFile = fopen(fileName, "wb");
    printf("lidar: time %lf , points size: %d, cld width: %d, cld height: %d\n", timestamp , cld->points.size(), cld->width, cld->height);
	
	// printf("x: %f, y: %f, z: %f\n", cld->points[0].x, cld->points[0].y, cld->points[0].z);
	FILE* lidarXYZFile = fopen("../data/lidarcord.xyz", "wb");
	if(!lidarXYZFile)
		printf("open failed\n");

	for(auto point:cld->points){
		if(point.intensity>0)
			fprintf(lidarXYZFile,"%f,%f,%f\n", point.x, point.y, point.z);
	}
	//delete [] fileName;
}

int main(int argc, char **argv)
{
    HesaiLidarSDK psdk(
	2368				/* lidar data port */, 
	10110				/* gps data port */, 
	std::string("correction.csv")	/* calibration file of lidar */, 
	lidarCallback 			/* point cloud data call back */, 
	gpsCallback 			/* gps data callback */, 
	HESAI_LIDAR_RAW_DATA_STRCUT_DUAL_RETURN/* Return Mode: Dual Return data structure */, 
	40				/* laser counter */, 
	HESAI_LIDAR_PCL_DATA_TYPE_REDUCED/* pcl data alignment */
	);
    psdk.start();
    while(true)
    {
        sleep(100);
    }
}