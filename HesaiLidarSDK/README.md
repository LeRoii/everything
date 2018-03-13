# Dependencies
## Clone
```
git clone https://github.com/HesaiTechnology/HesaiLidarSDK.git --recursive
```

## Only Lidar
```
sudo apt install cmake libproj-dev libpcap-dev libboost-all-dev libyaml-cpp-dev libjpeg-dev libgdal-dev libpq-dev libvtk6-dev libvtk6-qt-dev libpcl-dev 
```

## Camera + Lidar

```
sudo apt install cmake libproj-dev libcv-dev libpcap-dev libboost-all-dev libyaml-cpp-dev libjpeg-dev libgdal-dev libpq-dev libvtk6-dev libvtk6-qt-dev libpcl-dev 
```
# build
```
mkdir build
cd build 
 (Lidar )cmake ..  / cmake -DCamera_Enable=ON .. (Lidar + Camera)
make -j4
```

# Add to your project
```
add_subdirectory(<path to>HesaiLidarSDK)

target_link_libraries(${PROJECT_NAME}
  ...
  hesaiLidarSDK
  ...
}

```

## Note
```
(Only Camera+Lidar) add_definitions("-DHESAI_WITH_CAMERA")
```
