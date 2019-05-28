yum install openssh-server -y


#开源版编译
更换镜像源
yum install wget git gcc gcc-c++  make bzip2 -y
wget https://github.com/Kitware/CMake/releases/download/v3.14.3/cmake-3.14.3.tar.gz
tar xvf cmake-3.14.3.tar.gz
cd cmake-3.14.3
./bootstrap
gmake
gmake install

yum install  python-devel

wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.bz2
yum install boost boost-devel boost-doc
tar -zxvf boost_1_62_0.tar.bz2
cd boost_1_62_0
./bootstrap.sh --with-libraries=all --with-toolset=gcc

./b2 install --prefix=/usr



wget https://sourceforge.net/projects/log4cplus/files/log4cplus-stable/2.0.4/log4cplus-2.0.4.tar.gz
yum -y install bzip2
tar -xjf log4cplus-2.0.4.tar.gz
cd log4cplus-2.0.4
./configure --prefix=/usr/local
make
make install
ldconfig

ln -s /usr/lib64/libpython2.7.so /usr/lib/libpython.so

yum install -y rpm-build 

修改cmake
SET(TOOLCHAIN_DIR "/usr")

SET(BOOST_INCLUDEDIR "${TOOLCHAIN_DIR}/include/boost/")
SET(BOOST_LIBRARYDIR "${TOOLCHAIN_DIR}/lib")

yum -y install epel-release
yum -y install python-pip
pip install rfoo
pip install pid 
pip install supervisor

pip install Cython
git clone https://github.com/aaiyer/rfoo.git
cd rfoo/
python setup.py install