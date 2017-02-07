# show_image
Super SUPER **SUPER** Basic imshow() demonstration for OpenCV


# Get OpenCV
## Get deps

* `sudo apt-get update`

* `sudo apt-get upgrade`

### Dev tools
* `sudo apt-get install build-essential cmake pkg-config`

* `sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev`

* `sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev`

* `sudo apt-get install libgtk-3-dev`

* `sudo apt-get install libatlas-base-dev gfortran`

* `sudo apt-get install python2.7-dev python3.5-dev`

### Build OpenCV from source
* `git clone https://github.com/opencv/opencv.git`

* `cd opencv`

* `mkdir build`

* `cd build`

* `cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local .. `
  * You can add more flags to the above, YMMV

* `make -j`
* `sudo make install`
* `sudo ldconfig`

# Build this project

When everything is installed for OpenCV, you should be able to just:
 * `mkdir build`
 * `cd build`
 * `cmake ..`
 * `make -j`
